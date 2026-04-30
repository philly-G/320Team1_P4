/*
 * SpeakEasy — Arduino Backend
 *
 * WIRING:
 *   GSR Sensor Signal → A0
 *   Motor 1 Signal    → A1  (via NPN transistor — do NOT wire direct)
 *   Motor 2 Signal    → A2  (via NPN transistor — do NOT wire direct)
 *   Debug LED         → Pin 13 (onboard)
 *
 * TRANSISTOR WIRING (per motor):
 *   Arduino pin → 1kΩ resistor → Base (2N2222 or similar)
 *   Collector → Motor negative lead
 *   Motor positive lead → 5V
 *   Emitter → GND
 *   Flyback diode across motor terminals (cathode to 5V side)
 *
 * SERIAL PROTOCOL:
 *   Sends:    GSR:<int>\n          e.g. "GSR:512\n"
 *   Receives: ALERT_ON\n | ALERT_OFF\n
 */

const int GSR_PIN    = A0;
const int MOTOR_1    = A1;
const int MOTOR_2    = A2;
const int DEBUG_LED  = 13;

// ---- Haptic timing (non-blocking) ----
const unsigned long BUZZ_INTERVAL  = 180;
const unsigned long VIBE_DURATION  = 30;

bool  shouldVibrate = false;
bool  motorActive   = false;
int   motorTurn     = 1;      // which motor fires next: 1 or 2
int   activeMotor   = 0;
unsigned long lastBuzzTime  = 0;
unsigned long motorOnTime   = 0;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(50);   // Don't stall waiting for newline — critical fix

  pinMode(MOTOR_1,   OUTPUT);
  pinMode(MOTOR_2,   OUTPUT);
  pinMode(DEBUG_LED, OUTPUT);

  digitalWrite(MOTOR_1,   LOW);
  digitalWrite(MOTOR_2,   LOW);
  digitalWrite(DEBUG_LED, LOW);

  // Startup pulse — confirms motors are wired and responding
  digitalWrite(MOTOR_1,   HIGH);
  digitalWrite(MOTOR_2,   HIGH);
  digitalWrite(DEBUG_LED, HIGH);
  delay(200);
  digitalWrite(MOTOR_1,   LOW);
  digitalWrite(MOTOR_2,   LOW);
  digitalWrite(DEBUG_LED, LOW);
  delay(800);   // brief pause so startup pulse is distinct from session buzz
}

void loop() {
  // 1. Read & smooth GSR (10 samples, 5ms apart = ~50ms total read time)
  long sum = 0;
  for (int i = 0; i < 10; i++) {
    sum += analogRead(GSR_PIN);
    delay(5);
  }
  int gsrAverage = (int)(sum / 10);

  // 2. Transmit to browser & heartbeat LED
  Serial.print("GSR:");
  Serial.println(gsrAverage);
  digitalWrite(DEBUG_LED, !digitalRead(DEBUG_LED));

  // 3. Read incoming command (non-blocking — returns immediately if nothing there)
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim();

    if (command == "ALERT_ON") {
      shouldVibrate = true;
    } else if (command == "ALERT_OFF") {
      shouldVibrate = false;
      // Immediately cut any active motor
      if (motorActive) {
        digitalWrite(activeMotor, LOW);
        motorActive = false;
      }
      digitalWrite(MOTOR_1, LOW);
      digitalWrite(MOTOR_2, LOW);
    }
  }

  // 4. Non-blocking haptic alternation
  unsigned long now = millis();

  if (shouldVibrate) {
    // Turn off motor if its on-time has elapsed
    if (motorActive && (now - motorOnTime >= VIBE_DURATION)) {
      digitalWrite(activeMotor, LOW);
      motorActive  = false;
      lastBuzzTime = now;     // start counting the gap from here
    }

    // Fire next motor once the gap interval has passed
    if (!motorActive && (now - lastBuzzTime >= BUZZ_INTERVAL)) {
      activeMotor = (motorTurn == 1) ? MOTOR_1 : MOTOR_2;
      digitalWrite(activeMotor, HIGH);
      motorOnTime = now;
      motorActive = true;
      motorTurn   = (motorTurn == 1) ? 2 : 1;
    }
  } else {
    // shouldVibrate turned false mid-buzz — kill immediately
    if (motorActive) {
      digitalWrite(activeMotor, LOW);
      motorActive = false;
    }
  }

  // 5. Short pause before next read cycle
  //    Total loop time ≈ 50ms (reads) + 50ms (here) = ~10 Hz sample rate
  delay(50);
}

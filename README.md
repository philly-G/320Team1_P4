# 320Team1_P4
Project title: SpeakEasy

Project description: A wearable that monitors physiological stress in real time and gives the user a private buzz to pause, breathe, and recenter before anxiety takes over their presentation.

## Libraries Used

### speakeasy.ino (Arduino)
- **Arduino Core (built-in)** — Provides pinMode, digitalWrite, analogRead, 
  millis, and Serial. Everything the sketch runs on. No installation needed.
- **Serial (built-in)** — Streams smoothed GSR readings to the browser over 
  USB as GSR:<value> and listens for ALERT_ON / ALERT_OFF commands back from 
  the dashboard to trigger the haptic motors.

### dashboard.html (Browser)
- **Web Serial API (browser built-in)** — Connects the browser directly to the 
  Arduino over USB. Reads the GSR data stream and sends haptic trigger commands 
  back. Requires Chrome or Edge — does not work in Firefox or Safari.
- **Web Speech API (browser built-in)** — Runs live speech-to-text in the 
  browser with no external service. Detects speaking vs. silence, identifies 
  filler words, and tags words spoken during high-EDA moments.
- **Chart.js (loaded via CDN)** — Renders the real-time EDA line chart in the 
  session report and the multi-session trends chart.
- **Google Fonts (loaded via CDN)** — Typography for the dashboard UI. 
  Requires an internet connection to load.


## Setup instructions: Installing dependencies ➡️ connecting hardware ➡️ running the system
1. Download and install the Arduino IDE.
2. Clone the repository:
   git clone https://github.com/philly-G/320Team1_P4.git
3. Open the speakeasy.ino sketch from the repository in Arduino IDE.
4. Open index.html to view the SpeakEasy website (optional).
5. Open dashboard.html via a local server (see step 10).
6. Attach EDA sensors to the index and middle fingers
7. Put on the pillow, ensuring the haptic buzz motor is on your shoulders 
8. Connect the Arduino to the EDA sensors and haptic motor following the wiring diagram in p4sketch2.png
9. Plug the Arduino board into your computer via USB.
10. In your terminal, navigate to the project folder and run python3 -m http.server. Then open Chrome or Edge and go to http://localhost:8000/dashboard.html. Click Connect Arduino, select your board from the popup, and live EDA data will begin streaming automatically.
You should see live EDA and speech data streaming into the dashboard once everything is connected and you begin speaking

## Usage instructions
1. Once the EDA sensors and Arduino hardware are connected to your computer and dashboard.html is streaming correctly, begin the callibration period by playing the matching game. This sets a personal baseline.
2. Begin presenting/speaking. When your EDA rises above the configured threshold or when speech analysis detects a cluster of filler words or unnatural pauses, the haptic motors at your shoulder will buzz gently.
3. After presenting, review the session summary in the dashboard: EDA over time, words per minute, pause count, and filler word frequency.

## Credits: 
Philly Stanley, Aubrey Cantrell, Finn Kingsbury
ClaudeAI
CoPilot
Notion's AI Chat

## Annotated Bibliography: Biofeedback and Physiological Regulation
Gallego, Sergio, et al. “Embodied Strategies for Public Speaking Anxiety: Evaluation of the Corp-Oral Program.” Frontiers in Human Neuroscience, vol. 17, Nov. 2023, https://doi.org/10.3389/fnhum.2023.1268798.
This study evaluates a program designed to use physiological measures, including EDA and heart rate, to mitigate public speaking anxiety through "Corp-Oral" (body-voice) interventions. It provides critical empirical support for SpeakEasy’s premise that physical interventions can significantly reduce self-perceived and physiological distress during live performances.

Goessl, V. C., et al. “The Effects of Heart Rate Variability Biofeedback on Anxiety and Stress: A Systematic Review.” Psychological Medicine, vol. 47, no. 12, 2017, pp. 1950-1960, https://doi.org/10.1017/S0033291717001003.
This meta-analysis confirms that biofeedback is a robust tool for reducing general anxiety and physiological stress markers. It provides high-level scientific consensus that supports the technical logic of SpeakEasy: that monitoring and responding to autonomic data is an evidence-based method for improving emotional regulation.

Lonsdale, Chris, et al. “Short-Term Effects of Heart Rate Variability Biofeedback on Working Memory.” Applied Psychophysiology and Biofeedback, vol. 41, no. 3, 2013, pp. 241-250, https://doi.org/10.5298/1081-5937-41.3.01.
This research investigates how biofeedback training can enhance cognitive performance and working memory by regulating autonomic responses. It serves as a foundational source for SpeakEasy, justifying the use of haptic cues to trigger a "re-centering" that preserves the user's cognitive capacity and focus under pressure.

Mehler, K., et al. “Biofeedback and Mindfulness-Based Stress Reduction for Management of Anxiety.” Journal of Psychology & Psychotherapy, vol. 2, no. 17, 2014, https://doi.org/10.1186/2050-2974-2-17.
This study explores the synergy between biofeedback and mindfulness for long-term anxiety management. For SpeakEasy, this research supports the "Future Work" goals of providing users with post-session analytics to build long-term physiological resilience beyond the immediate presentation.

Peper, Erik, et al. “The Effects of Posture on Mental Recall and Anxiety.” Applied Psychophysiology and Biofeedback, vol. 37, no. 3, 2012, pp. 241-250, https://doi.org/10.1007/978-981-32-9705-0_16.
This paper demonstrates that closed, "collapsed" postures increase the accessibility of negative thoughts and anxiety, while upright postures improve confidence and cognitive performance. This validates SpeakEasy’s use of a neck-based haptic nudge, which naturally prompts the user to straighten their posture and open their chest.

Wells, Ruth, et al. “Matter Over Mind: A Randomised-Controlled Trial of Single-Session Biofeedback Training on Performance Anxiety and Heart Rate Variability in Musicians.” PLOS ONE, vol. 7, no. 10, 2012, https://doi.org/10.1371/journal.pone.0046597.
The authors demonstrate that a single session of biofeedback-assisted slow breathing is effective in controlling physiological arousal in high-stress performance environments. This validates the SpeakEasy feedback loop, suggesting that even brief, discrete interventions can effectively break the cycle of sympathetic nervous system arousal.

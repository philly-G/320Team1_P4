# 320Team1_P4
Project title: SpeakEasy

Project description: A wearable that monitors physiological stress in real time and gives the user a private buzz to pause, breathe, and recenter before anxiety takes over their presentation.

Libraries used in index.html:
HTML/CSS/JavaScript: Languages used to create our project website
Google Fonts: Typography used for project website

Libraries used in dashboard.html:
Arduino IDE/Serial communication: Used to program the Arduino board and stream EDA data over USB to the dashboard

Setup instructions (in order): how to install dependencies, connect hardware, and run the system
1. Download and install the Arduino IDE.
2. Open the speakeasy.ino sketch from the repository.
3. Clone the repository: git clone https://github.com/philly-G/320Team1_P4.git
4. Open index.html to view the SpeakEasy website (optional)
5. Open dashboard.html to view the SpeakEasy interface
6. Attach EDA sensors to the index and middle fingers
7. Put on the pillow, ensuring the haptic buzz motor is on your shoulders 
8. Connect the Arduino to the EDA sensors and haptic motor following the wiring diagram in p4sketch2.png
9. Plug the Arduino board into your computer via USB.
10. Connect to the serial ... via Bluetooth
You should see live EDA and speech data streaming into the dashboard once everything is connected and you begin speaking

Usage instructions: how to interact with your TUI
1. Once the EDA sensors and Arduino hardware are connected to your computer and dashboard.html is streaming correctly, begin the callibration period by playing the matching game. This sets a personal baseline.
2. Begin presenting/speaking. When your EDA rises above the configured threshold or when speech analysis detects a cluster of filler words or unnatural pauses, the haptic motors at your shoulder will buzz gently.
3. After presenting, review the session summary in the dashboard: EDA over time, words per minute, pause count, and filler word frequency.

Credits: 
Philly Stanley, Aubrey Cantrell, Finn Kingsbury
ClaudeAI
CoPilot
Notion's AI Chat

Annotated Bibliography: Biofeedback and Physiological Regulation
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

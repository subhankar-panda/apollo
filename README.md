# Apollo

## Inspiration
Designing for accessibility has been a huge trend in Interaction Design in the last few years, but as we move away from contemporary media -smartphones and tablets- to more advanced computational systems like robotics, the body of work dwindles significantly. Personal robots have immense potential to change lives on an individual level, especially for the differently abled who can use them to augment their interaction with the outside world. This potential calls for the development and establishment of universal design systems, interaction protocols and accessibility guidelines for robotic media. 

## What it does
We prototyped two different interaction paradigms on a three wheel drive vectoring robot, using natural motion and natural language. The motion and language protocols use gesture and speech driven interfaces to control motor functionality of the robot. The code provides a boilerplate more accessible robotic control interfaces.

## How we built it
To build the robot, we used an Arduino Uno, an Adafruit Motor Shield, 3 12V DC Motors and 3 64mm Omnidirectional Wheels mounted on a laser cut chassis. The robot communicates via Bluetooth with a Python script for gesture control and an Android app for speech control. Bluetooth on the robot is handled by an SP Protocol HC-05 Bluetooth module through BLE. For gesture control, we use a Myo armband that communicates pose data to the Arduino through a Python script. For speech control, we use Google's Speech-to-Text API on an Android app.

## Challenges we ran into
The primary constraint in the hackathon format was the inability to go through a rigorous human-centered design process and conduct user interviews and user tests. Since we were dealing with accessibility issues, it would have been beneficial to collect data from people that could potentially face them. Furthermore, one of the interfaces we experimented with was a brain-computer interface with signals from the motor cortex. We couldn't prototype it fast enough because our EEG data was unreliable and often gave us high impedance values. We also wrote code for simultaneous control with 2 Myo armbands but were unable to test in time due to a hardware shortage.

## Accomplishments that we're proud of
- Rapid prototyping ability
- Iterating through our ideas super quickly
- Getting a working demo up
- Having negligible amounts of lag on Myo control

## What we learned
- Robotic accessibility is too big a challenge to solve in 36 hours
- Myo has great community developer support
- EEGs can be really annoying

## What's next for Apollo
Our immediate next steps involve a heavy round of user research, (successful) experimentation with other interfaces such as BCI's and multiple Myos and the development of formal accessibility guidelines for robotic interfaces. We also want to expand these interfaces to the domain of robotic gameplay, specifically collaborative and competitive multi-human multi-robot settings.
`


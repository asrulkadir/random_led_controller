# RandomLEDController

This project is an Arduino program that controls 5 LEDs. When a push button is pressed, one of these LEDs will light up randomly.

## Requirements

- Arduino Uno (or similar model)
- 5 LEDs
- 1 push button
- Jumper wires and breadboard

## Circuit Setup

Connect the 5 LEDs and the push button to your Arduino. In this example, the LEDs are connected to pins 2 to 6 and the push button to pin 7.

## Usage

1. Set up the circuit as described above.
2. Load the program code to your Arduino using the Arduino IDE.
3. After the code is uploaded, press the push button. One of the 5 LEDs will light up randomly.
4. Each time the push button is pressed, another LED will light up randomly, but the LEDs that have previously lit up will not light up again.
5. After pressing the push button 5 times, on the 6th button press, the process will be repeated from the beginning.

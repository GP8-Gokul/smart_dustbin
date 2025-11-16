# Smart Dustbin

A smart dustbin project using ESP8266, a servo motor, ultrasonic and IR sensors, buzzer, and integrated with the Blynk IoT platform. The hardware automatically opens the dustbin lid when a hand is detected and monitors the bin's fill status via an ultrasonic sensor, providing real-time notifications and alerts.

## Features

- **Automatic Lid Opening**: Lid opens when hand is detected by the IR sensor.
- **Trash Level Monitoring**: Ultrasonic sensor checks bin fullness.
- **Buzzer Alert**: When the bin is full, an audible alert is triggered.
- **Blynk Dashboard**: View real-time status and notifications on your phone (requires Blynk app).
- **WiFi Enabled**: Remotely monitor bin status.

## Hardware Requirements

- ESP8266 microcontroller (e.g., NodeMCU)
- Servo motor
- Ultrasonic sensor (HC-SR04)
- IR sensor
- Buzzer
- Jumper wires
- Dustbin enclosure (modified to fit hardware)

### Pin Connections

| Component         | ESP8266 Pin |
|-------------------|-------------|
| IR Sensor         | D7          |
| Servo Motor       | D3          |
| Ultrasonic Trigger| D1          |
| Ultrasonic Echo   | D5          |
| Buzzer            | D6          |

## Software Setup

1. **Install Arduino IDE**
2. **Add ESP8266 Board Support**:
   - In Arduino IDE, go to *File > Preferences* and add `http://arduino.esp8266.com/stable/package_esp8266com_index.json` to *Additional Board Manager URLs*.
   - Open *Tools > Board > Board Manager*, search for `esp8266`, and install it.
3. **Libraries Needed**:
   - `Servo`
   - `ESP8266WiFi`
   - `BlynkSimpleEsp8266`

4. **Blynk Setup**:
   - Create a project in Blynk (https://blynk.cloud/)
   - Add widgets for V0 (`distance`) and V1 (`status`)
   - Obtain your Auth Token and insert it into the code

## Usage

1. Assemble the hardware as per the connections above.
2. Flash the `smart_dustbin.ino` code onto your ESP8266.
3. Connect the ESP8266 to WiFi (edit `ssid` and `pass` variables in the code).
4. Open the Blynk app and monitor:
   - Distance to trash
   - Status (`Full` or distance in cm)
   - The lid will open automatically when a hand is detected

## Code

See [smart_dustbin.ino](https://github.com/GP8-Gokul/smart_dustbin/blob/main/smart_dustbin.ino) for the full Arduino code.

## Author

Created by GP8-Gokul

## License

MIT License (add the LICENSE file if applicable)

---

Feel free to add hardware diagrams, wiring images, or troubleshooting tips as needed!

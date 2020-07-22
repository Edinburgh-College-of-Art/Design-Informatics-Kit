# Design-Informatics-Kit

Documentation and Code Examples for Design Informatics Home Kit

## Contents

<!-- TOC depthFrom:1 depthTo:6 withLinks:1 updateOnSave:1 orderedList:0 -->

- [Design-Informatics-Kit](#design-informatics-kit)
	- [Contents](#contents)
	- [Whats in the kit](#whats-in-the-kit)
	- [Additional notes](#additional-notes)
	- [Code Examples](#code-examples)
		- [Sensors](#sensors)
		- [Capacitive Sensing](#capacitive-sensing)
		- [BLE](#ble)
			- [Bluetooth Spy](#bluetooth-spy)
			- [Unity Controller](#unity-controller)
			- [Talk to Phone](#talk-to-phone)
		- [MQTT](#mqtt)
			- [Remote Send / Receive](#remote-send-receive)
			- [Sensor Logger](#sensor-logger)
		- [Chat Server](#chat-server)
		- [APIs](#apis)
		- [IFTTT](#ifttt)
		- [ThingSpeak](#thingspeak)

<!-- /TOC -->

## Whats in the kit

list of components

| Component                | documentation | Use case |
| ------------------------ | ------------- | -------- |
| Arduino Nano 33 IoT      |               |          |
| Servo                    |               |          |
| Temperature Sensor       |               |          |
| Display + SD Card holder |               |          |
| RFID                     |               |          |
| Copper tape              |               |          |
| Velostat                 |               |          |
| Buttons                  |               |          |
| NeoPixel Ring            |               |          |
| conductive fabric        |               |          |
| conductive thread        |               |          |
| Polymorph                |               |          |

## Additional notes

Notes on usage and helpful techniques

## Code Examples

Example project code

### Sensors

### Capacitive Sensing

(although we might need some 1M resistors...)
Use the copper tape to make a 3D controller, connect to something interesting

### BLE

#### Bluetooth Spy

Get the Arduino to look for all the bluetooth devices in range. Light up a certain colour if particular devices are there

#### Unity Controller

Get unity responding to data coming in from the Arduino to move 3d objects around

#### Talk to Phone

Send some data to a phone app, or respond to it in some way – pretend to be a smart light.

- LightBlue: [iPhone](https://apps.apple.com/us/app/lightblue/id557428110) / [Android](https://play.google.com/store/apps/details?id=com.punchthrough.lightblueexplorer&hl=en_US)

### MQTT

#### Remote Send / Receive

Get Arduino talking with MQTT to send data (e.g. from a knob or or temp sensor) and receive it (e.g. set servo position, flash LEDs)

#### Sensor Logger

Send the output of a sensor to a cloud service for later analysis

Services:

- Adafruit IO
- ThingSpeak

### Chat Server

Take text over the serial input, display it on the screen and send it out over MQTT. Display incoming text on the display in a different colour

### APIs

### IFTTT

Connect the Arduino to an IFTTT recipe

### ThingSpeak

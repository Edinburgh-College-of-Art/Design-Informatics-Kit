# Design-Informatics-Kit

Documentation and Code Examples for Design Informatics Home Kit

## Contents

<!-- TOC depthFrom:1 depthTo:6 withLinks:1 updateOnSave:1 orderedList:0 -->

- [Design-Informatics-Kit](#design-informatics-kit)
	- [Contents](#contents)
	- [Whats in the kit](#whats-in-the-kit)
	- [Setup](#setup)
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
			- [List of APIs](#list-of-apis)
		- [IFTTT](#ifttt)
		- [ThingSpeak](#thingspeak)
	- [Extras](#extras)
		- [Nano Pinout](#nano-pinout)

<!-- /TOC -->

## What is in the kit?

| Component                | documentation | Use case |
| ------------------------ | ------------- | -------- |
| Arduino Nano 33 IoT      | [Getting started with the Arduino NANO 33 IoT](https://www.arduino.cc/en/Guide/NANO33IoT)          |          |
| Servo                    |               |          |
| Temperature Sensor       | [Grove DHT11](https://wiki.seeedstudio.com/Grove-TemperatureAndHumidity_Sensor/)              |          |
| Display + SD Card holder |       [Adafruit 1.44" Colour TFT with Micro SD Socket](https://learn.adafruit.com/adafruit-1-44-color-tft-with-micro-sd-socket)        |          |
| RFID                     |               |          |
| Copper tape              |               |          |
| Velostat                 |               |          |
| Buttons                  |      [Grove Dual Buttons](https://wiki.seeedstudio.com/Grove-Dual-Button/)         |          |
| NeoPixel Ring            |      [The Magic of NeoPixels](https://learn.adafruit.com/adafruit-neopixel-uberguide/the-magic-of-neopixels)         |          |
| conductive fabric        |               |          |
| conductive thread        |               |          |
| Polymorph                |               |          |


## Setup

See the [Getting Started guide](./getting-started.md) for instructions on setting up to use your kit.

## Additional notes

Notes on usage and helpful techniques

## Code Examples

Example project code

### Sensors

#### Capacitive Sensing

(although we might need some 1M resistors...)
Use the copper tape to make a 3D controller, connect to something interesting

### BLE

#### Bluetooth Spy

Get the Arduino to look for all the bluetooth devices in range. Light up a certain colour if particular devices are there

#### Unity Controller

Get unity responding to data coming in from the Arduino to move 3d objects around

  - [Ardity](https://ardity.dwilches.com)

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

#### Chat Server

Take text over the serial input, display it on the screen and send it out over MQTT. Display incoming text on the display in a different colour

### APIs

#### List of APIs

[See the Public list APIs](https://public-apis.io) for some inspiration

### IFTTT

Connect the Arduino to an IFTTT recipe

### ThingSpeak

## Extras

Some extra tidbits to make life easier

### Nano Pinout

Pins on the nano are labelled in such small typeface it can be difficult to read. [This .pdf](./extras/Nano_33_IoT_Pinout_cheatsheet.pdf) can be printed out, placed over your breadboard and the Arduino can plugged in on top. Get creative and try making your own.


![](https://content.arduino.cc/assets/Pinout-NANO33IoT_latest.png)

## Further Resources

### LinkedIn Learning Courses

- [Learning Arduino: Foundations](https://www.linkedin.com/learning/learning-arduino-foundations-2/getting-started-with-arduino?u=50251009&auth=true)
- [Learning Arduino: Interfacing with Hardware](https://www.linkedin.com/learning/learning-arduino-interfacing-with-hardware/open-up-your-digital-world-with-arduino?u=50251009&auth=true)
- [C++ Essentials](https://www.linkedin.com/learning/c-plus-plus-essential-training-2/about-this-course?u=50251009&auth=true)

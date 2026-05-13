<img width="1292" height="767" alt="image" src="https://github.com/user-attachments/assets/45a13076-9dd6-40f6-a0fc-7694aecfc17f" />
Smart Home Automation System (Arduino)
Overview

This project is a simple Home Automation system using Arduino.
It allows controlling 4 devices using both manual switches and an IR remote control through relay modules.

Features
Control 4 appliances independently
Dual control: IR Remote + Push Buttons
Toggle ON/OFF system for each relay
Serial Monitor status messages
Easy to expand for more devices
Components
Arduino Uno
4-Channel Relay Module
IR Receiver Module
IR Remote Control
4 Push Buttons
Jumper wires
Pin Configuration
Relays
Relay 1 → Pin 12
Relay 2 → Pin 11
Relay 3 → Pin 10
Relay 4 → Pin 9
Switches
Switch 1 → Pin 8
Switch 2 → Pin 7
Switch 3 → Pin 6
Switch 4 → Pin 5
IR Receiver
Signal Pin → Pin 3
How It Works
Manual Control

Pressing a push button toggles the corresponding relay ON/OFF.

IR Control

The IR receiver reads signals from the remote and toggles the assigned relay based on the received HEX code.

Libraries Used
IRremote
SPI
Wire
Applications
Smart lighting system
Fan control
Home appliance automation
IoT learning project
Author

Arduino-based Home Automation Project for learning embedded systems and IoT basics.

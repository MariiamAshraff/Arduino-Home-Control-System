<img width="1292" height="767" alt="image" src="https://github.com/user-attachments/assets/45a13076-9dd6-40f6-a0fc-7694aecfc17f" />
# 🏠 Smart Home Automation System using Arduino

> A dual-mode home automation system that controls electrical devices using **IR Remote** and **manual switches** with relay-based switching.

---

## 🚀 Overview
This project is a simple yet powerful **Home Automation System** built using Arduino.  
It allows controlling 4 independent loads (lights, fans, etc.) using:

- 📡 IR Remote Control  
- 🔘 Manual Push Buttons  

The system uses a relay module to safely control high-voltage devices.

---

## ✨ Features
- 🔌 Control 4 different appliances independently  
- 📡 IR remote-based wireless control  
- 🔘 Manual switch control (hardware backup)  
- 🔄 Toggle ON/OFF functionality for each device  
- 📊 Real-time feedback via Serial Monitor  
- ⚡ Expandable design (can add more devices easily)

---

## 🧰 Components Used
- Arduino Uno  
- 4-Channel Relay Module  
- IR Receiver Module  
- IR Remote Control  
- 4 Push Buttons  
- Jumper Wires  
- (Optional loads: LEDs / lamps / fans)

---

## 🔌 Circuit Connections

### ⚡ Relay Module
| Relay | Arduino Pin |
|------|------------|
| Relay 1 | D12 |
| Relay 2 | D11 |
| Relay 3 | D10 |
| Relay 4 | D9 |

### 🔘 Manual Switches
| Switch | Arduino Pin |
|--------|------------|
| Switch 1 | D8 |
| Switch 2 | D7 |
| Switch 3 | D6 |
| Switch 4 | D5 |

### 📡 IR Receiver
| Signal Pin | Arduino Pin |
|------------|------------|
| OUT | D3 |

---

## ⚙️ Working Principle

### 🔘 Manual Mode
Each push button toggles its corresponding relay:
- First press → ON  
- Second press → OFF  

### 📡 IR Remote Mode
- IR receiver captures signals from the remote  
- Arduino decodes HEX codes  
- Each code controls a specific relay  

Example:
```cpp
case 0xEF10BF00:
    relayOnOff(1);
    break;

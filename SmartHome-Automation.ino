#include <SPI.h>
#include <Wire.h>
#include <IRremote.h>

// ================= RELAY PINS =================
const int relay_1 = 12;
const int relay_2 = 11;
const int relay_3 = 10;
const int relay_4 = 9;

// ================= SWITCH PINS =================
const int mswitch_1 = 8;
const int mswitch_2 = 7;
const int mswitch_3 = 6;
const int mswitch_4 = 5;

// ================= IR RECEIVER =================
const int RECV_PIN = 3;

// ================= TOGGLE STATES =================
bool toggleState_1 = false;
bool toggleState_2 = false;
bool toggleState_3 = false;
bool toggleState_4 = false;

// ==================================================
// SETUP
// ==================================================
void setup() {

  Serial.begin(9600);

  IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK);

  pinMode(relay_1, OUTPUT);
  pinMode(relay_2, OUTPUT);
  pinMode(relay_3, OUTPUT);
  pinMode(relay_4, OUTPUT);

  pinMode(mswitch_1, INPUT_PULLUP);
  pinMode(mswitch_2, INPUT_PULLUP);
  pinMode(mswitch_3, INPUT_PULLUP);
  pinMode(mswitch_4, INPUT_PULLUP);

  digitalWrite(relay_1, LOW);
  digitalWrite(relay_2, LOW);
  digitalWrite(relay_3, LOW);
  digitalWrite(relay_4, LOW);

  Serial.println("===== HOME AUTOMATION STARTED =====");
}

// ==================================================
// RELAY FUNCTION
// ==================================================
void relayOnOff(int relayNumber) {

  switch (relayNumber) {

    case 1:
      toggleState_1 = !toggleState_1;
      digitalWrite(relay_1, toggleState_1);
      Serial.println(toggleState_1 ? "Relay 1 ON" : "Relay 1 OFF");
      break;

    case 2:
      toggleState_2 = !toggleState_2;
      digitalWrite(relay_2, toggleState_2);
      Serial.println(toggleState_2 ? "Relay 2 ON" : "Relay 2 OFF");
      break;

    case 3:
      toggleState_3 = !toggleState_3;
      digitalWrite(relay_3, toggleState_3);
      Serial.println(toggleState_3 ? "Relay 3 ON" : "Relay 3 OFF");
      break;

    case 4:
      toggleState_4 = !toggleState_4;
      digitalWrite(relay_4, toggleState_4);
      Serial.println(toggleState_4 ? "Relay 4 ON" : "Relay 4 OFF");
      break;
  }

  delay(200);
}

// ==================================================
// LOOP
// ==================================================
void loop() {

  // ================= MANUAL SWITCH =================
  if (digitalRead(mswitch_1) == LOW) {
    relayOnOff(1);
    while (digitalRead(mswitch_1) == LOW);
  }

  if (digitalRead(mswitch_2) == LOW) {
    relayOnOff(2);
    while (digitalRead(mswitch_2) == LOW);
  }

  if (digitalRead(mswitch_3) == LOW) {
    relayOnOff(3);
    while (digitalRead(mswitch_3) == LOW);
  }

  if (digitalRead(mswitch_4) == LOW) {
    relayOnOff(4);
    while (digitalRead(mswitch_4) == LOW);
  }

  // ================= IR REMOTE =================
  if (IrReceiver.decode()) {

    unsigned long receivedCode =
      IrReceiver.decodedIRData.decodedRawData;

    Serial.print("Received Code: ");
    Serial.println(receivedCode, HEX);

    switch (receivedCode) {

      case 0xEF10BF00:
        relayOnOff(1);
        break;

      case 0xEE11BF00:
        relayOnOff(2);
        break;

      case 0xED12BF00:
        relayOnOff(3);
        break;

      case 0xEB14BF00:   
        relayOnOff(4);
        break;

      default:
        Serial.println("Unknown Button");
        break;
    }

    IrReceiver.resume();
  }
}
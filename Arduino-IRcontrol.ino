/*
 * @file Arduino-IRcontrol.ino
 *
 * @author StruDJA
 * Contact: strubot@gmail.com
 * 
 * For more details visit the blog post (https://strumag.tn/remote-control-your-appliance-part-1-infra-red)
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY. See the GNU General Public License for
 * more details.
*/

#include <IRremote.h> // Include the IRremote library

const uint32_t BUTTON_POWER = 0xB54A58A7; // IR code sent from the remote, change the value by yours

int RECV_PIN = 8; // IR reciever pin
int RELAY_PIN = 4; // Relay pin

IRrecv irrecv(RECV_PIN); // Initialize the irrecv part of the IRremote library
decode_results results; // This will store our IR received codes

int on = 0; // This keeps track of the last code RX'd
unsigned long last = millis(); // This will help us prevent the on/off if the button kept pressed

void setup() {
  pinMode(RELAY_PIN, OUTPUT); // Relay pin as output
  pinMode(13, OUTPUT);
  irrecv.enableIRIn(); // Start the receiver
  Serial.begin(9600); // Use serial to debug
}

void loop() {
  if (irrecv.decode(&results)) {
    /* If the spisefic IR code was sent and it's been at least 1/4 second since the last
       IR received, toggle the relay */
    if (results.value == BUTTON_POWER && millis() - last > 250) {
      on = !on;
      digitalWrite(RELAY_PIN, on ? HIGH : LOW);
      digitalWrite(13, on ? HIGH : LOW);
      Serial.println(on ? "PowerOn" : "PowerOff");
    }
    last = millis();
    irrecv.resume(); // Receive the next value
  }
}

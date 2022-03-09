# Arduino-IRcontrol 🎛️

## Introduction

This is the code for the project from [StruMAG's](https://strumag.tn/remote-control-your-appliance-part-1-infra-red) post, Remote Control Your Appliance Part 1 Infra Red, it represents an entry point to start with if you're looking to control or play with [Arduino](https://www.arduino.cc/) via Infra-Red.

You'll be adding Infra-Red to turn on/off your room light 💡️

## Main Files: Project Structure

  ```sh
  ├── Arduino-IRcontrol.ino *** The main code to run after getting the IR codes
  ├── dump_codes.ino *** First thing to run to get your IR remote controller codes
  └── README.md
  ```

## Key Dependencies

- [Arduino-IRremote](https://github.com/Arduino-IRremote/Arduino-IRremote) Infra-Red remote library for Arduino: send and receive infra-red signals with multiple protocols.
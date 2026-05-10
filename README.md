# SEN66 Particle Accuracy Test

This project is used to test the particle measurement accuracy of multiple Sensirion SEN66 sensors at the same time.

The test setup uses a custom ESP32-based sensor PCB with four I2C sensor connections. The goal is to compare the readings from up to four SEN66 sensors against a calibrated reference particle measurement device placed in the same test box.

This repository is meant as a handover and explanation document for the student who will continue the project. Coding will be done in the Arduino IDE.

---

## Project Goal

The goal of this project is to check how accurate the SEN66 sensors are when measuring particulate matter.

The test compares:

- SEN66 sensor 1
- SEN66 sensor 2
- SEN66 sensor 3
- SEN66 sensor 4
- One calibrated reference particle measurement device

All sensors and the reference device will be placed inside the same closed test box so they measure the same air conditions.

---

## Test Setup

The test will be done inside a box.

Inside the box there will be:

- Up to four SEN66 sensors
- One calibrated and highly accurate reference particle measurement device
- A ventilator / fan to move air through the box
- The ESP32-based sensor PCB
- Cables from the PCB to the sensors

The ventilator is important because it helps mix the air inside the box. This makes sure all sensors are exposed to similar air conditions.

The calibrated reference device is used as the trusted measurement. The SEN66 readings will be compared to this reference.

---

## Hardware Used

### Main Control Board

The project uses this ESP32-based sensor PCB:

https://github.com/blazjerman/ESP32-Based-Sensor-PCB

Important board features used in this project:

- ESP32 microcontroller
- I2C multiplexer: TCA9548APWR
- I2C multiplexer address: `0x70`
- ESP32 I2C SDA pin: `IO21`
- ESP32 I2C SCL pin: `IO22`
- Four I2C output channels:
  - Channel 0: `SD0 / SC0`
  - Channel 1: `SD1 / SC1`
  - Channel 2: `SD2 / SC2`
  - Channel 3: `SD3 / SC3`
- RGB status LEDs for easier debugging

### Sensors

The tested sensors are Sensirion SEN66 sensors.

The reason an I2C multiplexer is needed is that multiple identical I2C sensors usually have the same I2C address. If they are connected to the same I2C bus directly, the ESP32 cannot know which one it is talking to.

The multiplexer solves this problem by connecting only one sensor channel at a time.

---

## RGB Status LEDs

The PCB also includes RGB LEDs that can be used for easier debugging.

These LEDs are useful because they can show the current state of the program without needing to constantly look at the Serial Monitor.

For example, the RGB LEDs can be used to show:

- Program started successfully
- I2C multiplexer was found
- SEN66 sensor was detected
- Sensor reading was successful
- Sensor reading failed
- Test is currently running
- Error state

An example for controlling the RGB LEDs is included in the board repository in the `led_example` folder.

Use this example first to understand how the RGB LEDs are connected and how they can be controlled from the Arduino IDE.

Suggested debug colors:

| LED Color | Meaning |
|---|---|
| Green | Sensor read successful |
| Red | Sensor read failed or sensor not found |
| Blue | I2C multiplexer channel selected |
| Yellow | Test is running |
| Purple | Setup / initialization |
| Off | Idle or finished |

The exact colors can be changed in the code. The important thing is to use the LEDs to make debugging easier while testing multiple SEN66 sensors inside the box.

---

## I2C Explanation

I2C uses two signal wires:

- `SDA` - data line
- `SCL` - clock line

On this ESP32 board:

```cpp
#define I2C_SDA 21
#define I2C_SCL 22

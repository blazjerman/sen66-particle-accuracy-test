# SEN66 Particle Accuracy Test

This project tests the particle measurement accuracy of up to four Sensirion SEN66 sensors at the same time.

The sensors are connected to an ESP32-based sensor PCB with four I2C connections. The SEN66 readings will be compared with a calibrated reference particle measurement device inside the same test box.

Coding for this project will be done in the Arduino IDE.

---

## Test Goal

The goal is to compare the particle measurements from the SEN66 sensors with a calibrated reference device.

The test will compare:

- SEN66 sensor on I2C channel 0
- SEN66 sensor on I2C channel 1
- SEN66 sensor on I2C channel 2
- SEN66 sensor on I2C channel 3
- Calibrated reference particle measurement device

---

## Test Setup

The test will be done inside a box.

Inside the box:

- Up to four SEN66 sensors
- One calibrated reference particle measurement device
- A ventilator / fan to mix the air
- ESP32-based sensor PCB
- Sensor cables

The reference device is the trusted measurement. SEN66 data will be compared to it.

---

## Hardware

Main board:

https://github.com/blazjerman/ESP32-Based-Sensor-PCB

Important board information:

- ESP32 microcontroller
- I2C multiplexer: `TCA9548APWR`
- I2C multiplexer address: `0x70`
- ESP32 I2C SDA pin: `IO21`
- ESP32 I2C SCL pin: `IO22`
- Four I2C sensor channels:
  - Channel 0: `SD0 / SC0`
  - Channel 1: `SD1 / SC1`
  - Channel 2: `SD2 / SC2`
  - Channel 3: `SD3 / SC3`
- RGB LEDs for easier debugging

---

## Arduino IDE Setup

### 1. Install Arduino IDE

Download Arduino IDE:

https://www.arduino.cc/en/software

---

### 2. Install ESP32 Board Support

Arduino IDE needs ESP32 board support.

In Arduino IDE:

1. Open `File > Preferences`
2. Find **Additional boards manager URLs**
3. Add this URL:

```text
https://github.com/stm32duino/BoardManagerFiles/raw/main/package_stmicroelectronics_index.json
```

Then:

1. Open `Tools > Board > Boards Manager`
2. Search for `esp32`
3. Install **esp32 by Espressif Systems**

After that, select the ESP32 board under:

```text
Tools > Board
```

If unsure, try:

```text
ESP32 Dev Module
```

Also select the correct USB port under:

```text
Tools > Port
```

---

### 3. Install SEN66 Library

The SEN66 sensor needs the official Sensirion Arduino library:

https://github.com/Sensirion/arduino-i2c-sen66

It can also be installed directly from Arduino IDE:

1. Open `Sketch > Include Library > Manage Libraries`
2. Search for `Sensirion I2C SEN66`
3. Install the library
4. Install any dependencies if Arduino IDE asks

Example code should then appear under:

```text
File > Examples > Sensirion I2C SEN66
```

---

## I2C and Multiplexer

I2C uses two wires:

- `SDA` - data
- `SCL` - clock

On this board:

```cpp
#define I2C_SDA 21
#define I2C_SCL 22
```

The four SEN66 sensors are connected through the I2C multiplexer. This is needed because identical sensors usually have the same I2C address.

Before reading a sensor, select the correct multiplexer channel.

## SEN66 wiring to the ESP board

Each SEN66 sensor uses four wires:

- `Red` → `3.3V`
- `Brown` → `GND`
- `Yellow` → `SDn`
- `Black` → `SCn`

The `Red` and `Brown` wires are shared the same way for all sensors:

- all `Red` wires go to `3.3V`
- all `Brown` wires go to `GND`

The `Yellow` and `Black` wires are sensor-specific and connect to the corresponding multiplexer channel:

| Sensor | Yellow wire | Black wire |
|---|---|---|
| SEN66 #1 | `SD0` | `SC0` |
| SEN66 #2 | `SD1` | `SC1` |
| SEN66 #3 | `SD2` | `SC2` |
| SEN66 #4 | `SD3` | `SC3` |

So for sensor `n`, connect:

- `Yellow` → `SDn`
- `Black` → `SCn`

## RGB LEDs

The PCB has RGB LEDs that can be used for simple debugging.

An example is available in the board repository in the `led_example` folder.

Use it first to test the RGB LEDs.

- Arduino IDE
- ESP32 board support in Arduino IDE
- Sensirion SEN66 Arduino library

---

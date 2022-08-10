| <center><img src="./assets/rakstar.jpg" alt="RAKstar" width=25%></center>  | ![RAKWireless](./assets/RAK-Whirls.png) | [![Build Status](https://github.com/RAKWireless/RAK13005-TLE7259-Library/workflows/RAK%20Library%20Build%20CI/badge.svg)](https://github.com/RAKWireless/RAK13005-TLE7259-Library/actions) |
| -- | -- | -- |

# <RAK13010>

RAK13010-SDI12 is a library written based on EnviroDIY Arduino-SDI-12, adding support for RAK4631 and RAK1330. This library is used for SDI-12 communication with various environmental sensors. It provides a general software solution, without requiring any additional hardware, to implement the SDI-12 communication protocol between an Arduino-based data logger and SDI-12-enabled sensors.

[SDI-12](http://www.sdi-12.org/) is an asynchronous, ASCII, serial communications protocol that was developed for intelligent sensory instruments that typically monitor environmental data.
[Advantages of SDI-12](http://en.wikipedia.org/wiki/SDI-12) include the ability to use a single available data channel for many sensors.

[*RAKWireless RAK13010 SDI-12*](https://store.RAKWireless.com/products/RAK13010-SDI12)

# Documentation

* **[Product Repository](https://github.com/RAKWireless/RAK13010-SDI12)** - Product repository for the RAKWireless RAK13010 SDI12 module.
* **[Documentation](https://docs.RAKWireless.com/Product-Categories/WisBlock/RAK13010/Overview/)** - Documentation and Quick Start Guide for the RAK13010 SDI12 module.

# Installation

In Arduino IDE open Sketch->Include Library->Manage Libraries then search for RAK13010.

In PlatformIO open PlatformIO Home, switch to libraries and search for RAK13010.
Or install the library project dependencies by adding

```log
lib_deps =
  RAKWireless/RAKWireless RAK13010 SDI12 library
```

into **`platformio.ini`**

For manual installation download the archive, unzip it and place the RAK13010-SDI12 folder into the library directory.
In Arduino IDE this is usually <arduinosketchfolder>/libraries/
In PlatformIO this is usually <user/.platformio/lib>

# Usage

This library provides the RAK_SDI12 class, which can be used to communicate with sensors interfaced with SDI-12. These examples show how to use RAK13010.

- [RAK13010_SDI_12_Address_Change](./examples/RAK13010_SDI_12_Address_Change) Changing the Address of your SDI-12 Sensor. It discovers the address of the attached sensor and allows you to change it.

- [RAK13010_SDI_12_Basic_Data_Request](./examples/RAK13010_SDI_12_Basic_Data_Request) Basic Data Request to a Single Sensor. This is a very basic (stripped down) example where the user initiates a measurement and receives the results to a terminal window without typing numerous commands into the terminal.

- [RAK13010_SDI_12_Check_All_Addresses](./examples/RAK13010_SDI_12_Check_All_Addresses) Check all Addresses for Active Sensors and Print Status. It discovers the address of all sensors active and attached to the board. Each sensor should have a unique address already - if not, multiple sensors may respond simultaenously to the same request and the output will not be readable by the Arduino.

- [RAK13010_SDI_12_Concurrent_Logger](./examples/RAK13010_SDI_12_Concurrent_Logger) Concurrent Measurements. Finding all attached sensors and logging data from them. Example waits for each sensor to complete a measurement, this asks all sensors to take measurements concurrently and then waits until each is finished to query for results. This can be much faster than waiting for each sensor when you have multiple sensor attached.

- [RAK13010_SDI_12_Interface](./examples/RAK13010_SDI_12_Interface)  Arduino-based USB dongle translates serial comm from PC to SDI-12 (electrical and timing)

  1. Allows user to communicate to SDI-12 devices from a serial terminal emulator (e.g. PuTTY).

  2. Able to spy on an SDI-12 bus for troubleshooting comm between datalogger and sensors.

  3. Can also be used as a hardware middleman for interfacing software to an SDI-12 sensor. 

      For example, implementing an SDI-12 datalogger in Python on a PC. Use verbatim mode with feedback off in this case.					

- [RAK13010_SDI_12_Slave](./examples/RAK13010_SDI_12_Slave) Example sketch demonstrating how to implement an arduino as a slave on an SDI-12 bus. This may be used, for example, as a middleman between an I2C sensor and an SDI-12 datalogger.

## This class provides the following methods:

**void begin()**

Begin the SDI-12 object.

This is called to begin the functionality of the SDI-12 object.  It sets the object as the active object, sets the stream timeout to 150ms to match SDI-12 specs, sets the timeout return value to SDI12::TIMEOUT, and configures the timer prescaler.

#### Parameters:

| Direction | Name | Function |
| --------- | ---- | -------- |
| return    |      | none     |

**void begin(int8_t dataPin)**

Set the SDI12::_datapin and begin the SDI-12 object.

If the SDI-12 instance is created using the empty constuctor, this must be used to set the data pin.

#### Parameters:

| Direction | Name    | Function                           |
| --------- | ------- | ---------------------------------- |
| in        | dataPin | The data pin's digital pin number. |
| return    |         | none                               |

**void end()**

Disable the SDI-12 object (but do not destroy it).

Set the SDI-12 state to disabled, set the pointer to the current active instance to null, and then, for AVR boards, unset the timer prescaler. This can be called to temporarily cease all functionality of the SDI-12 object. It is not as harsh as destroying the object with the destructor, as it will maintain the memory buffer.

#### Parameters:

| Direction | Name | Function |
| --------- | ---- | -------- |
| return    |      | none     |

**void setDataPin(int8_t dataPin)**

Set the data pin for the current SDI-12 instance.

#### Parameters:

| Direction | Name | Function                           |
| --------- | ---- | ---------------------------------- |
| return    |      | The data pin's digital pin number. |

**int8_t getDataPin()**

Get the data pin for the current SDI-12 instance.

#### Parameters:

| Direction | Name | Function             |
| --------- | ---- | -------------------- |
| return    |      | The data pin number. |

**void forceHold()**

Set line state to SDI12_HOLDING.

A public function which forces the line into a "holding" state. This is generally unneeded, but for deployments where interference is an issue, it should be used after all expected bytes have been returned from the sensor.

#### Parameters:

| Direction | Name | Function |
| --------- | ---- | -------- |
| return    |      | none     |

**void forceListen()**

Set line state to SDI12_LISTENING.

A public function which forces the line into a "listening" state.  This may be needed for implementing a slave-side device, which should relinquish control of the data line when not transmitting.

#### Parameters:

| Direction | Name | Function |
| --------- | ---- | -------- |
| return    |      | none     |

**int8_t getDataPin()**

Get the data pin for the current SDI-12 instance.

#### Parameters:

| Direction | Name | Function         |
| --------- | ---- | ---------------- |
| return    |      | Data pin number. |

**bool setActive()**

Set this instance as the active SDI-12 instance.

A method for setting the current object as the active object; returns TRUE if the object was not formerly the active object and now is.

   * Promoting an inactive to the active instance will start it in the SDI12_HOLDING state and return TRUE.
   * Otherwise, if the object is currently the active instance, it will remain unchanged and return FALSE.

#### Parameters:

| Direction | Name | Function                                                     |
| --------- | ---- | ------------------------------------------------------------ |
| return    |      | True: indicates that the current SDI-12 instance was not formerly the active one and now is.  <br />False: indicates that the current SDI-12 instance *is already the active one* and the state was not changed. |

**bool isActive()**

Check if this instance is active.

isActive() is a method for checking if the object is the active object.  Returns true if the object is currently the active object, false otherwise.

#### Parameters:

| Direction | Name | Function                                                     |
| --------- | ---- | ------------------------------------------------------------ |
| return    |      | True indicates that the curren SDI-12 instace is the active one. |

**long parseInt(LookaheadMode lookahead = SKIP_ALL, char ignore = NO_IGNORE_CHAR) **

Return the first valid (long) integer value from the current position.

#### Parameters:

| Direction | Name      | Function                                                     |
| --------- | --------- | ------------------------------------------------------------ |
| in        | lookahead | The mode to use to look ahead in the stream, default is LookaheadMode::SKIP_ALL. |
| in        | ignore    | A character to ignore in the stream, default is '\\x01'.     |
| return    |           | The first valid integer in the stream.                       |

**float parseFloat(LookaheadMode lookahead = SKIP_ALL, char ignore = NO_IGNORE_CHAR) **

Return the first valid float value from the current position.

#### Parameters:

| Direction | Name      | Function                                                     |
| --------- | --------- | ------------------------------------------------------------ |
| in        | lookahead | The mode to use to look ahead in the stream, default is LookaheadMode::SKIP_ALL. |
| in        | ignore    | A character to ignore in the stream, default is '\\x01'.     |
| return    |           | The first valid float in the stream.                         |

**void writeChar(uint8_t out)**

Used to send a character out on the data line.

This function writes a character out to the data line.  SDI-12 specifies the general transmission format of a single character as:

   * 10 bits per data frame
   * 1 start bit
   * 7 data bits (least significant bit first)
   * 1 even parity bit
   * 1 stop bit

     Recall that we are using inverse logic, so HIGH represents 0, and LOW represents a 1.

#### Parameters:

| Direction | Name | Function                |
| --------- | ---- | ----------------------- |
| in        | out  | The character to write. |
| return    |      | none                    |

**void sendCommand(String& cmd, int8_t extraWakeTime = SDI12_WAKE_DELAY)**

**void sendCommand(const char* cmd, int8_t extraWakeTime = SDI12_WAKE_DELAY)**

**void sendCommand(FlashString cmd, int8_t extraWakeTime = SDI12_WAKE_DELAY)**

Send a command out on the data line, acting as a datalogger (master).

#### Parameters:

| Direction | Name          | Function                                                     |
| --------- | ------------- | ------------------------------------------------------------ |
| in        | cmd           | The command to send.                                         |
| in        | extraWakeTime | The amount of additional time in milliseconds that the sensor takes to wake before being ready to receive a command.  Default is 0ms - meaning the sensor is ready for a command by the end of the 12ms break.  Per protocol, the wake time must be less than 100 ms. |
| return    |               | none                                                         |

**void sendResponse(String& resp)**

**void sendResponse(const char* resp)**

**void sendResponse(FlashString resp)**

Send a response out on the data line (for slave use).

#### Parameters:

| Direction | Name | Function              |
| --------- | ---- | --------------------- |
| in        | resp | The response to send. |
| return    |      | none                  |

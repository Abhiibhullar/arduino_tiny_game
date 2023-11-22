## Arduino Tiny Game
A simple flappy bird game for arduino with ST7789 display and a single button.

## Table of contents
 * [Connections](#connections)
 * [Libraries](#libraries)
 * [Uploading](#uploading)
 * [Contribution](#contribution)

## Connections
ST7789 To Arduino Nano.
| Display | Arduino |
| -------| --------|
|SCLK | D13 |
|MISO | D12 | 
|MOSI | D11 | 
|CS | D10 | 
|RST | D9 | 
|DC | D8 |
|VCC | 5V |
|GND | GND |

*(CS, RST, DC) can be updated in code. And other pins are specific to board you are using.*

Button is connected to D2 in Arduino NANO. *[Follow this tutorial](https://docs.arduino.cc/built-in-examples/digital/Button)*

## Libraries
[Adafruit ST7735 and ST7789 Library](https://downloads.arduino.cc/libraries/github.com/adafruit/Adafruit_ST7735_and_ST7789_Library-1.10.3.zip)

[Guide to installing libraries.](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries)

## Uploading
 * Load the sketch into Arduino IDE or Visual Studio Code or any IDE that supports Arduino.
 * Select your board.
 * Connect the board to pc using usb.
 * Select the COM PORT
 * Upload the Sketch to board
 * Enjoy.

## Contribution 
This games has many flaws, if you want to contribute open an issue, Thanks.

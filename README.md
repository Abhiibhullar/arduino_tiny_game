## Arduino Tiny Game
A simple flappy bird game for arduino with ST7789 display and button.

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

*(CS, RST, DC) can be updated in code. And other pins are specific to board you are using.*

Button is connected to D2 in Arduino NANO. *[Follow this tutorial](https://docs.arduino.cc/built-in-examples/digital/Button)*

## Libraries
[Adafruit ST77355 and ST7789 Library](https://downloads.arduino.cc/libraries/github.com/adafruit/Adafruit_ST7735_and_ST7789_Library-1.10.3.zip)

## Contribution 
This games has many flaws, if you want to contribute open an issue, Thanks.

# Microcontroller and Interfacing Project ( cse 4112 )
## Project Name: Auto Motor Control with temparature sensor

Used Components:
1. STM32F103C8T6 ( blue pill ) microcontroller
2. ST-link Boot loader
3. DHT11 Temparature sensor
4. Submersible 3V Mini DC Water Pump
5. 1 channel 5v relay module
6. 3.7v Battery
7. Breadboard
8. Wires 
9. 16*2 LCD display 
10. potentiometer

Used Software:
1. Arduino

<br>
# N.B : 
STM32F103C8T6 (Blue pill) microcontroller is not directed supported to Arduino. First need to configure ST-link. 

<br>
# Introduction
In that project, We used Arduino IDE for coding and programming language was Embedded C. Mainly our program is control 
a water pump in a particular Temparture. 

<br>
# Working steps
1. Sense current tempareture (2 sec interval) and display it to LCD
2. If and only if current temparature reached to target temparature pump will be on. Otherwise, Always pump keep off.
3. Once the pump on, then start a timer. Timer will count pump running duration. If particular duration reached pump 
will off autometically.

<br>
# Wire Connection ( LCD )
<code>LCD - Microcontroller</code>
GND - GND
VDD - 5v
VS - potentiometer output
rs - PA5
en - PA4
d0 - none
d1 - none
d2 - none
d3 - none
d4 - PA3
d5 - PA2
d6 - PA1
d7 - PA0

A(second last) - 5v
K(last pin) - GND
Other pins - GND

# DHT11 sensor connection
plus pin - 5v
Minus pin - GND
Out pin - C13

# Relay Module connection (2 led side)
VCC - 3.3v 
GND - GND
In - A7

# Relay Module connection (Opossite side)
Open - Enternal bettery red wire
common - Pump black wire

# pump motor connection
pump red wire - Enternal bettery black wire
pump black wire - Relay common

<br>
# Instructions for implement 
1. Set up ST-link bootloader for a computer. Help: <a href="https://gist.github.com/mmattamala/41e048692bd66cffbeaaae2787b6a287">https://gist.github.com/mmattamala/41e048692bd66cffbeaaae2787b6a287</a>
2. Install Arduino IDE and open it.
3. In Ardunio IDE, go Tools > Manage Libraries > Search("DHT sensor library") by Adafruit and install
4. Install another library > Search ("LiquidCrystal") by Arduino, Adafruit
5. Copy the code of main.ino
6. Upload the code.


# Done!!!
If any issue left. You can follow the repo <a href="https://github.com/tonmoy-1705025/microcontroller-cse-4112">Project Repo</a>



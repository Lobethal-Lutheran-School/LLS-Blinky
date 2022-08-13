LLS-Blinky

This repository contains the schematic, layout and gerber files for Lobethal Lutheran School's themed Blinky PCB.

The Blinky project allows students to try soldering, and learn about algorithms and coding of embedded devices; in this case, an Atmel attiny13/45/85 eight pin microcontroller.

Others hoping to do a similar project can use the same schematic file, and PCB layout template to design their own bespoke layout.

Those seeking to creat customised line art for their own version of the PCB can use https://github.com/erichVK5/inkscape2pcb to generate footprints with elements that be used on the silkscreen, copper or solder mask layers.

The attiny13a used in this project was programmed using the arduino programming environment and extensions from MCUdude available on github

see: https://github.com/MCUdude/MicroCore

A programmer such as an inexpensive USBasp and a zero insertion force (ZIF) socket programming fixture are ideal for programming the microcontrollers prior to insertion in the PCB.

Bill of materials:

5 x 3mm white LED
5 x 100 ohm resistors for curremt limiting of white LEDs
4 x 10k resistors
180 degree vertical through hole Type B USB socket
8 pin DIP socket
8 pin Atmel microcontroller, i.e. attiny13a, attiny45 or attinty85

A soldering iron and solder will be needed to assemble the board.

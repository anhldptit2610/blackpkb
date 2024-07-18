# blackpkb

A custom macropad made for daily use.

<!-- ![blackpkb PCB](/images/blackpkb.jpeg =280x280) -->
<img src="/images/blackpkb.jpeg" width="256" height="256">

Having a macro pad which we can customize how it works is amazing, especially when working
with CAD softwares. As a electronic hobbyist, I always use KiCAD to draw the PCB for my projects. 
Pressing hotkeys when drawing schematic or PCB is a nuisance if using regular keyboard(in 
my opinion); so I created this project.

## Features

- [x] Customizable function for each key
- [x] Custom profiles(see [this docs](/docs/create-profile.md) for a howto)
- [x] Switch between profiles by pressing built-in rotary encoder button
- [x] adjust volume up/down(You need to map custom key shortcut for volume up/down)

## Requirements

### Hardware
 
 * 1x WeAct's STM32F411CEU6 development board(the BlackPill one)
 * 6x 1N4148 diodes
 * key switches(I desoldered these from a broken keyboard lol)
 * 3x 1kOhm resistor
 * 3x 3mm LEDs, different color(mine is green, red and yellow)
 * a rotary encoder

### Software

 * arm-none-eabi-gcc(my version is 10.3.1)
 * make

You can install above dependencies by using these commands(Ubuntu/any Debian based Linux distro):

    $ sudo apt update
    $ sudo apt install arm-none-eabi-gcc build-essential

## Build steps

    $ git clone https://github.com/anhldptit2610/blackpkb.git
    $ cd blackpkb/firmware/blackpkb
    $ make

You can use the ST's STM32CubeProgrammer to flash the binary.

## TODO

- [x] Use rotary encoder to adjust volume
- [ ] Add LED for each key
- [ ] Make a 3D printed case
# blackpkb

A custom macropad made for daily use.

<!-- ![blackpkb PCB](/images/blackpkb.jpeg =280x280) -->
<img src="/images/blackpkb.jpeg" width="192" height="256">

Having a keyboard which we can customize how it works is amazing, especially when working
with CAD softwares. As a electronic hobbyist, I use KiCAD to draw the PCB for my projects. 
Pressing hotkeys when drawing schematic or PCB is a nuisance if using regular keyboard(in 
my opinion); so I created this macropad. It is just a regular macropad; user can customize 
the functionality of each key, or create a specific profile. Profiles can be switched by 
pressing 4 keys on the left simultaneously.

## Dependencies

 * arm-none-eabi-gcc
 * make

You can install above dependencies by using these commands(Ubuntu/any Debian based Linux distro):

    $ sudo apt update
    $ sudo apt install arm-none-eabi-gcc build-essential

## Build steps

    $ git clone https://github.com/anhldptit2610/blackpkb.git
    $ cd blackpkb/firmware/blackpkb
    $ make

You can use ST's STM32CubeProgrammer to flash the binary.

## TODO

- [ ] Use rotary encoder to adjust volume
- [ ] Add LED for each key
- [ ] Make a 3D printed case
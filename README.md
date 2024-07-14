# blackpkb

A custom macropad made for daily use.

![blackpkb PCB](/images/blackpkb.jpeg)

## dependencies

 * arm-none-eabi-gcc

## Build steps

    $ git clone https://github.com/anhldptit2610/blackpkb.git
    $ cd blackpkb/firmware/blackpkb
    $ make

You can use ST's STM32CubeProgrammer to flash the binary.

## TODO

 * Use rotary encoder to adjust volume
 * Add LED for each key
 * Make a 3D printed case
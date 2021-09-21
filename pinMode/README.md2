# Programming the Arduino Uno in Pure C
* [Arduino in C | Freedom Embedded](https://balau82.wordpress.com/arduino-in-c/)
* https://www.xanthium.in/atmega328p-10bit-sar-adc-usart-serial-transmit-to-pc-data-acquisition-tutorial
* https://www.arduino.cc/en/Tutorial/BuiltInExamples/ArduinoISP
* https://github.com/rsbohn/ArduinoISP
* https://stackoverflow.com/questions/1588788/wrapping-c-class-api-for-c-consumption
* https://github.com/balau/arduino_c
* https://johanneshoff.com/arduino-command-line.html
* https://avogadrosnumber.wordpress.com/2017/09/02/blink-and-led-in-c-on-the-arduino-uno/
* http://audiodiwhy.blogspot.com/2019/01/programming-arduino-in-pure-c-now-were.html
* https://www.tderflinger.com/en/arduino-blinking-led-pure-c
* https://github.com/sagarsp/arduino-blink-c



## Instructions for tool chain installation
```
sudo pkcon install gcc-avr binutils-avr gdb-avr avr-libc avrdude
```

## Instructions for reflashing bootloader onto Atmega328P chip
```
# 0. Connect the Dragon to the Uno. ICSP cable, pin 1 to pin 1, USB to Dragon, USB to Uno
# 1. Test the connection
avrdude -p m328p -P usb  -c dragon_isp -t
part
quit
# 2. Set fuses and lock bits to enable re-loading of boot loader
avrdude -p atmega328p  -c dragon_isp -P usb -e -u -U lock:w:0x3f:m -U efuse:w:0x05:m -U hfuse:w:0xDE:m -U lfuse:w:0xFF:m
# 3. Copy hex file to desktop
cp /Applications/Arduino.app/Contents/Java/hardware/arduino/avr/bootloaders/optiboot/optiboot_atmega328.hex ~/Desktop/
# 4. Burn Arduino bootloader & set lock bits to lockbootloader section
avrdude -p atmega328p  -c dragon_isp -P usb -U flash:w:./optiboot_atmega328.hex -U lock:w:0x0f:m
```

## Instructions for simple compile/link/load on Arduino Uno
```
avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o led.o led.c
avr-gcc -mmcu=atmega328p led.o -o led
avr-objcopy -O ihex -R .eeprom led led.hex
avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:led.hex
```

## Instructions for Using Makefile
Current version uses Makefile from Maker Media book Make: AVR Programming.
https://github.com/hexagon5un/AVR-Programming
Be sure to make/confirm changes to makefile regarding setup, programmer etc
```
make flash
```
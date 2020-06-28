# arduino_alarm
Arduino with LCD Keypad Shield alarm clock made from scratch.

Author: Yaroslava Tkachuk, BSc student of the University of Silesia, Katowice, Poland.

An alarm with simple GUI implemented with the use of LCD Keypad Shield.

Main thing I enjoy about this little project: hand made threading! All classes' methods are implemented in a way that their conditions are checked once per main loop iteration. Thus, we get all the following functionality done simultaneously with no delays or unneeded interrupts:
- displaying data and time
- changing date and time
- setting alarm (date, time, and melody)
- playing alarm sound until turned off

Caution: when doing so You should make sure execution time of all functions used in the main Arduino loop does not exceed the main loop single iteration time (based on used processor frequency).

Files:
- a_notes.ino - notes defines taken from https://www.arduino.cc/en/Tutorial/toneMelody (thank You, guys, for developing this cool project)
- b_sound_class.ino - class responsible for sound managing
- c_clock_class.ino - made from scratch clock: yes, a proper real time clock module could be used, but the project was done purely for learning purposes :)
- d_alarm_class.ino - alarm implementation
- e_button_class.ino - button managing class: voltage ranges of the buttons have been read from A0 analogue pin
- f_screen_class.ino - GUI
- h_alarm_program.ino - integrates all the above mentioned classes
- z_clock_project.ino - program main loop 

Hardware:
- Arduino Uno R3
- LCD Keypad Shield 1602
- passive buzzer without generator 5 V
- breadboard
- USB cable (to burn the script on the board as well as to feed Your Arduino if no additional power supply is used)
- 2 Arduino cables

Quick testing has shown that the time shift of the alarm is up to few minutes per day, which means it is awfully imprecise... But yeah, time accuracy was not an aim here :) A better quality silicon chip or just an Arduino real time module would fix the issue. 

Here You can see a video showing the clock in action:
<br>https://www.youtube.com/watch?v=EpnY3sS503Y&list=PLtJUFm0bXNwasr-G3iWJ3LP29yKfUD6Ik&index=2
P.S. Terrible buzzer sound warning! It is so bad, it could actually be used to torture people. Enjoy (if You can)!

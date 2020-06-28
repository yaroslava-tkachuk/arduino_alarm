#include <LiquidCrystal.h>

#include "C:\Users\mrbin\Desktop\z_clock_project\b_sound_class.ino"
#include "C:\Users\mrbin\Desktop\z_clock_project\c_clock_class.ino"
#include "C:\Users\mrbin\Desktop\z_clock_project\d_alarm_class.ino"
#include "C:\Users\mrbin\Desktop\z_clock_project\e_button_class.ino"
#include "C:\Users\mrbin\Desktop\z_clock_project\f_screen_class.ino"
#include "C:\Users\mrbin\Desktop\z_clock_project\h_alarm_program.ino"


LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
Sound sound;
Clock clock (0, 0, 0, 1, 1, 2020);
Alarm alarm (0, 0, 1, 1, 2020);
Screen screen;
Button up (50, 199);
Button down (200, 299);
Button left (400, 499);
Button right (0, 49);
Button select (600, 699);
AlarmProgram alarm_program;


void setup()
{
  lcd.begin(16, 2);
  lcd.display();
  pinMode(3, OUTPUT);
}


void loop() 
{ 
  alarm_program.update_time(clock, screen, alarm, sound, lcd);
  alarm_program.update_buttons(up, down, left, right, select, screen, clock, alarm, sound, lcd); 
  alarm_program.update_alarm(clock, alarm, sound);
}

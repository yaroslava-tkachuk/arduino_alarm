#ifndef alarm_program_class
#define alarm_program_class

class AlarmProgram
//Klasa, obslugujaca program budzika
{
  public:
    void update_screen(Screen& screen, Clock& clock, Alarm& alarm, Sound& sound, LiquidCrystal& lcd)
    //Wykonuje update ekranu przy zmianie stanu jednego z monitorowanych obiektow
    {
      switch (screen.get_mode()) 
        {
          case 0:
            screen.show(screen.int_to_string(clock.get_hs())+":"+screen.int_to_string(clock.get_mins())+":"+screen.int_to_string(clock.get_s()),
                        screen.int_to_string(clock.get_days())+"/"+screen.int_to_string(clock.get_months())+"/"+String(clock.get_years()), lcd);
            break;
          case 1:
            screen.show("SET MINUTES:",
                        screen.int_to_string(clock.get_mins()), lcd);
            break;
          case 2:
            screen.show("SET HOURS:",
                        screen.int_to_string(clock.get_hs()), lcd);
            break;
          case 3:
            screen.show("SET DAYS:",
                        screen.int_to_string(clock.get_days()), lcd);
            break;
          case 4:
            screen.show("SET MONTHS:",
                        screen.int_to_string(clock.get_months()), lcd);
            break;
          case 5:
            screen.show("SET YEARS:",
                        screen.int_to_string(clock.get_years()), lcd);
            break;
          case 6:
            screen.show("ALARM MINUTES:",
                        screen.int_to_string(alarm.get_mins()), lcd);
            break;
          case 7:
            screen.show("ALARM HOURS:",
                        screen.int_to_string(alarm.get_hs()), lcd);
            break;
          case 8:
            screen.show("ALARM DAYS:",
                        screen.int_to_string(alarm.get_days()), lcd);
            break;
          case 9:
            screen.show("ALARM MONTHS:",
                        screen.int_to_string(alarm.get_months()), lcd);
            break;
          case 10:
            screen.show("ALARM YEARS:",
                        screen.int_to_string(alarm.get_years()), lcd);
            break;
          case 11:
            screen.show("ALARM STATE:",
                        screen.bool_to_string(alarm.get_state()), lcd);
            break;
          case 12:
            screen.show("ALARM TRACK:",
                        String(sound.get_track()), lcd);
            break;
        }  
    }
  
  void update_buttons(Button& up, Button& down, Button& left, Button& right, Button& select, Screen& screen, Clock& clock, Alarm& alarm, Sound& sound, LiquidCrystal& lcd)
  //Sprawdza stan przyciskow i reaguje na ich nacisniecie
  {
      if (up.check_state() == true)
      {
          screen.inc_mode();
          update_screen(screen, clock, alarm, sound, lcd);
      }
      else if (down.check_state() == true)
      {
          screen.dec_mode();
          update_screen(screen, clock, alarm, sound, lcd);
      } 
      else if (right.check_state() == true)
      {
        switch (screen.get_mode())
        {
          case 1:
            clock.inc_mins();
            break;
          case 2:
            clock.inc_hs();
            break;
          case 3:
            clock.inc_days();
            break;
          case 4:
            clock.inc_months();
            break;
          case 5:
            clock.inc_years();
            break;
          case 6:
            alarm.inc_mins();
            break;
          case 7:
            alarm.inc_hs();
            break;
          case 8:
            alarm.inc_days();
            break;
          case 9:
            alarm.inc_months();
            break;
          case 10:
            alarm.inc_years();
            break;
          case 11:
            alarm.set_state(true);
            break;
          case 12:
            sound.inc_track();
            break;
        }
        update_screen(screen, clock, alarm, sound, lcd);
      }
      else if (left.check_state() == true)
      {
        switch (screen.get_mode()) 
        {
          case 1:
            clock.dec_mins();
            break;
          case 2:
            clock.dec_hs();
            break;
          case 3:
            clock.dec_days();
            break;
          case 4:
            clock.dec_months();
            break;
          case 5:
            clock.dec_years();
            break;
          case 6:
            alarm.dec_mins();
            break;
          case 7:
            alarm.dec_hs();
            break;
          case 8:
            alarm.dec_days();
            break;
          case 9:
            alarm.dec_months();
            break;
          case 10:
            alarm.dec_years();
            break;
          case 11:
            alarm.set_state(false);
            break;
          case 12:
            sound.dec_track();
            break;
        }
        update_screen(screen, clock, alarm, sound, lcd);
      }
      else if (select.check_state() == true)
      {
        alarm.set_state(false);
        sound.reset();
      }
  }
  
  void update_alarm(Clock& clock, Alarm& alarm, Sound& sound)
  //Wykonuje update stanu budzika
  {
      if (not sound.get_state())
      {
          if (alarm.get_state()&&(alarm.get_mins() == clock.get_mins())&&(alarm.get_hs() == clock.get_hs())&&(alarm.get_days() == clock.get_days())
               &&(alarm.get_months() == clock.get_months())&&(alarm.get_years() == clock.get_years())&&(clock.get_s()==0))
          {
            sound.set_state(true);
            alarm.set_state(false);  
          }
       }
       else
       {
          sound.play_melody(); 
       }  
  }
  
  void update_time(Clock& clock, Screen& screen, Alarm& alarm, Sound& sound, LiquidCrystal& lcd)
  //Wykonuje update czasu
  {
    clock.count_time();
    if (clock.get_changed()&&(screen.get_mode() == 0))
    {
      update_screen(screen, clock, alarm, sound, lcd);
      clock.set_changed(false);   
    }  
  }
};

#endif

#ifndef sound_class
#define sound_class

#include "C:\Users\mrbin\Desktop\z_clock_project\a_notes.ino"

class Sound
//Klasa, obslugujaca dzwiek
{
  public:

    int count_note_duration(int note)
    //Oblicza czas trwania nuty
    {
      return 1000/this->get_note_durations()[note];
    }

    void play_note(int note)
    //Gra jedna podana nute
    {
      tone(this->get_piezo_pin(), this->get_melody()[note], this->count_note_duration(note));
    }

    void play_melody()
    //Gra podana melodie
    {
      if (this->get_is_playing()&&this->get_state())
      {
        if (this->get_note_over())
        { 
          if ((this->get_current_note()+1)<this->get_melody_length())
          {
            this->set_current_note(this->get_current_note()+1);
            this->play_note(this->get_current_note());
            this->set_start_time(millis());
            this->set_note_over(false);
          }
          else
          {
            this->set_is_playing(false);
            this->set_current_note(-1);
            if (this->get_state())
            {
              this->set_is_playing(true);  
            }
          }   
        }
        else
        {
          this->set_current_time(millis());
          if ((this->get_current_time()-this->get_start_time())>=this->count_note_duration(get_current_note())) 
          {
            this->set_note_over(true);  
          } 
        }  
      }  
    }

    void reset()
    //Wykonuje reset flag, kiedy dzwiek jest wylaczany
    {
      this->set_state(false);
      this->set_current_note(-1);
      this->set_is_playing(true);
      this->set_note_over(true);  
    }
    
    //Getters
    int get_piezo_pin()
    {
      return this->piezo_pin;  
    }

    int* get_melody()
    {
      switch (this->get_track())
      {
        case 1:
          return this->melody_1;
          break;
        case 2:
          return this->melody_2;
          break;
        case 3:
          return this->melody_3;
          break;
      }  
    }

    int* get_note_durations()
    {
      switch (this->get_track())
      {
        case 1:
          return this->note_durations_1;
          break;
        case 2:
          return this->note_durations_2;
          break;
        case 3:
          return this->note_durations_3;
          break;
      }    
    }

    int get_melody_length()
    {
      switch (this->get_track())
      {
        case 1:
          return this->melody_1_length;
          break;
        case 2:
          return this->melody_2_length;
          break;
        case 3:
          return this->melody_3_length;
          break;
      }  
    }

    int get_current_note()
    {
      return this->current_note;  
    }

    bool get_is_playing()
    {
      return this->is_playing;  
    }

    bool get_note_over()
    {
      return this->note_over;  
    }

    unsigned long get_start_time()
    {
      return this->start_time;  
    }

    unsigned long get_current_time()
    {
      return this->current_time;  
    }

    bool get_state()
    {
      return this->state;  
    }

    int get_track()
    {
      return this->track;  
    }

    //Setters
    void set_current_note(int new_note)
    {
      this->current_note = new_note;  
    }

    void set_is_playing(bool new_state)
    {
      this->is_playing = new_state;  
    }

    void set_note_over(bool new_state)
    {
      this->note_over = new_state;  
    }

    void set_start_time(unsigned long new_time)
    {
      this->start_time = new_time;  
    }

    void set_current_time(unsigned long new_time)
    {
      this->current_time = new_time;  
    }

    void set_state(bool new_state)
    {
      this->state = new_state;  
    }

    void set_track(int new_track)
    {
      this->track = new_track;  
    }

    void inc_track()
    //Zwieksza numer aktualnie wybranej melodii
    {
      if (((this->get_track()+1)%4)!=0)
      {
        this->set_track((this->get_track()+1)%4);  
      }
      else
      {
        this->set_track(1);  
      } 
    }

    void dec_track()
    //Zmniejsza numer aktualnie wybranej melodii
    {
      if ((this->get_track()-1)>0)
      {
        this->set_track(this->get_track()-1);  
      }
      else
      {
        this->set_track(3);
      }  
    }
    
private:
  int piezo_pin = 3;
  
  int melody_1[8] = {NOTE_C7, NOTE_G6, NOTE_G6, NOTE_A6, NOTE_G6, 0, NOTE_B6, NOTE_C7};
  int note_durations_1[8] = {4, 8, 8, 4, 4, 4, 4, 4};
  int melody_1_length = 8;

  int melody_2[12] = {NOTE_CS6,  NOTE_B6, NOTE_G6, NOTE_CS6, NOTE_B6, NOTE_E6, NOTE_AS6, NOTE_CS6, NOTE_C6, NOTE_G6, NOTE_A6, NOTE_CS6};
  int note_durations_2[12]  = {16, 16, 16, 8, 8, 16, 32, 16, 16, 16, 8, 8};
  int melody_2_length = 12;

  int melody_3[30] = {NOTE_C6, 0, NOTE_D6, 0, NOTE_F6, 0, NOTE_D6, 0, NOTE_F6, 0, NOTE_G6, 0, NOTE_F6, 0,
                      NOTE_G6, 0, NOTE_A6, 0, NOTE_G6, 0, NOTE_A6, 0, NOTE_B6, 0, NOTE_A6, 0, NOTE_B6, 0, NOTE_C7, 0};
  int note_durations_3[30] = {8, 8, 8, 8, 8, 4, 8, 8, 8, 8, 8, 4, 8, 8, 8, 8, 8, 4, 8, 8, 8, 8, 8, 4, 8, 8, 8, 8, 8, 4};
  int melody_3_length = 30;

  int track = 1;
  
  int current_note = -1;
  bool is_playing = true;
  bool note_over = true;
  bool state = false;

  unsigned long start_time = 0;
  unsigned long current_time = 0;
};

#endif

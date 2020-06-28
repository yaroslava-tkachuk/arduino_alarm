#ifndef clock_class
#define clock_class

class Clock
//Klasa, obslugujaca zegar
{
  public:
    Clock (int s, int mins, int hs, int days, int months, int years)
    {
      this->s = s;
      this->mins = mins;
      this->hs = hs;
      this->days = days;
      this->months = months;
      this->years = years;
    }

    void count_time()
    //Oblicza aktualny czas
    {
      int sec = millis()/1000;
      if (sec!=this->get_prev_s())
      {
        this->set_s(this->get_s()+1);
        this->set_prev_s(sec);
        this->set_changed(true);
        this->count_mins();
      }
    }

    void count_mins()
    //Oblicza minuty
    {
      if (this->get_s() == 60)
        {
          this->set_s(0);
          this->set_mins(this->get_mins()+1);
          this->count_hs();
        }  
    }
    
    void count_hs()
    //Oblicza godziny
    {
      if (this->get_mins() == 60)
      {
        this->set_mins(0);
        this->set_hs(this->get_hs()+1);
        this->count_days();
      }  
    }

    void count_days()
    //Oblicza dni
    {
      if (this->get_hs() == 24)
      {
        this->set_hs(0);
        this->set_days(this->get_days()+1);
        this->count_months();
      } 
    }
    
    void count_months()
    //Oblicza miesiace
    {
      if (this->get_days() == this->eval_month_days())
        {
          this->set_days(1);
          this->set_months((this->get_months() + 1) % 12);
          this->count_years();
        }
    }
   
    void count_years()
    //Oblicza lata
    {
      if (this->get_months() == 1)
      {
        this->set_years(this->get_years()+1);  
      }      
    }
    
    bool leap(int years)
    //Sprawdza, czy rok jest przestepny
    {
      return ((years % 4 == 0) && (years % 100 != 0)) || (years % 400 == 0);  
    }

    int eval_month_days()
    //Zwraza ilosc dni w podanym miesiacu
    {
      int numb_days;
      if ((this->get_months() != 2) || not (this->leap(this->get_years())))
        {
          numb_days = this->get_months_days()[this->get_months()-1]+1;  
        }
      else
        {
          numb_days = this->get_months_days()[this->get_months()-1]+2;  
        }
      return numb_days;
    }

    //Getters
    int get_prev_s()
    {
      return this->prev_s;  
    }
    
    int get_s()
    {
      return this->s;  
    }

    int get_mins()
    {
      return this->mins;  
    }

    int get_hs()
    {
      return this->hs;  
    }

    int get_days()
    {
      return this->days;  
    }

    int get_months()
    {
      return this->months;  
    }

    int get_years()
    {
      return this->years;  
    }

    int* get_months_days()
    {
      return this->months_days;  
    }

    bool get_changed()
    {
      return this->changed;
    }

    //Seters
    void set_prev_s(int new_prev_s)
    {
      this->prev_s = new_prev_s;  
    }
    
    void set_s(int new_s)
    {
      this->s = new_s;  
    }

    void set_mins(int new_mins)
    {
      this->mins = new_mins;  
    }

    void set_hs(int new_hs)
    {
      this->hs = new_hs;  
    }

    void set_days(int new_days)
    {
      this->days = new_days;  
    }

    void set_months(int new_months)
    {
      this->months = new_months;  
    }

    void set_years(int new_years)
    {
      this->years = new_years;  
    }

    void set_changed(bool new_state)
    {
      this->changed = new_state;
    }
    
    //Increment attributes
    void inc_mins()
    {
      this->set_mins((this->get_mins()+1)%60);  
    }
    
    void inc_hs()
    {
      this->set_hs((this->get_hs()+1)%24);  
    }
    
    void inc_days()
    {
      if (((this->get_days()+1)%this->eval_month_days())!=0)
      {
        this->set_days((this->get_days()+1)%this->eval_month_days());  
      }
      else
      {
        this->set_days(1);
      }
    }
    
    void inc_months()
    {
      if (((this->get_months()+1)%13)!=0)
      {
        this->set_months((this->get_months()+1)%13);  
      }
      else
      {
        this->set_months(1);  
      } 
    }
    
    void inc_years()
    {
      this->set_years(this->get_years()+1);  
    }
    
    //Decrement attributes
    void dec_mins()
    {
      if ((this->get_mins()-1)>=0)
      {
        this->set_mins(this->get_mins()-1);  
      }
      else
      {
        this->set_mins(59);
      }
    }
    
    void dec_hs()
    {
      if ((this->get_hs()-1)>=0)
      {
        this->set_hs(this->get_hs()-1);  
      }
      else
      {
        this->set_hs(23);
      }  
    }
    
    void dec_days()
    {
      if ((this->get_days()-1)>0)
      {
        this->set_days(this->get_days()-1);  
      }
      else
      {
        this->set_days(this->eval_month_days()-1);
      }  
    }
    
    void dec_months()
    {
      if ((this->get_months()-1)>0)
      {
        this->set_months(this->get_months()-1);  
      }
      else
      {
        this->set_months(12);
      }  
    }
    
    void dec_years()
    {
      this->set_years(this->get_years()-1);  
    }
    
private:
    int prev_s = 0;
    int s;
    int mins;
    int hs;
    int days;
    int months;
    int years;

    int months_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    bool changed = true;
};

#endif

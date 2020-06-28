#ifndef alarm_class
#define alarm_class

class Alarm
//Klasa, obslugujaca budzik
{
  public:
    Alarm (int mins, int hs, int days, int months, int years)
    {
      this->mins = mins;
      this->hs = hs;
      this->days = days;
      this->months = months;
      this->years = years;
    }

    //Getters
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

    bool get_state()
    {
      return this->is_on;  
    }

    //Seters
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

    void set_state(bool new_state)
    {
      this->is_on = new_state;  
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
    int mins;
    int hs;
    int days;
    int months;
    int years;
    int months_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    bool is_on = false;
};

#endif

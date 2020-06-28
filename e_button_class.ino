#ifndef button_class
#define button_class

class Button
//Klasa, obslugujaca przycisk
{
  public:
    Button (int lower_voltage, int higher_voltage)
    {
      this->lower_voltage = lower_voltage;
      this->higher_voltage = higher_voltage;
      this->state_1 = false;
      this->state_2 = false;
      this->state_3 = false;
    }

    //Getters
    int get_lower_voltage()
    {
      return this->lower_voltage;  
    }

    int get_higher_voltage()
    {
      return this->higher_voltage;  
    }

    bool get_state_1()
    {
      return this->state_1;  
    }

    bool get_state_2()
    {
      return this->state_2;  
    }

    bool get_state_3()
    {
      return this->state_3;  
    }

    void set_state_1(bool new_state)
    {
      this->state_1 = new_state;  
    }

    void set_state_2(bool new_state)
    {
      this->state_2 = new_state;  
    }

    void set_state_3(bool new_state)
    {
      this->state_3 = new_state;  
    }

    bool check_voltage()
    //Odczytuje napiecie na pinie A0 i ustawia jeden z atrybutow state na true (jezeli był na false)
    {
      if ((analogRead(A0) >= this->get_lower_voltage())&&(analogRead(A0) <= this->get_higher_voltage()))
      {
        if (not this->get_state_1())
        {
          this->set_state_1(true);
        }
        else if (not this->get_state_2())
        {
          this->set_state_2(true);
        }
        else if (not this->get_state_3())
        {
          this->set_state_3(true);
        } 
        return true;  
      }
      else
      {
        return false;  
      }
    }

    bool check_state()
    {
      this->check_voltage();
      if ((this->get_state_1() == true)&&(this->get_state_2() == true)&&(this->get_state_3() == true)&&(this->check_voltage() == false))
      {
        this->set_state_1(false);
        this->set_state_2(false);
        this->set_state_3(false);
        return true;  
      }
      else if ((this->check_voltage() == false)&&not((this->get_state_1() == true)&&(this->get_state_2() == true)&&(this->get_state_3() == true)))
      {
        this->set_state_1(false);
        this->set_state_2(false);
        this->set_state_3(false);
      }
      else
      {
        return false;  
      }
    }
    
private:
    int lower_voltage;
    int higher_voltage;

    bool state_1;
    bool state_2;
    bool state_3;
};

#endif

#ifndef screen_class
#define screen_class

class Screen
//Klasa, obslugujaca ekran
{
  public:
    int get_mode()
    {
      return this->mode;  
    }

    void inc_mode()
    {
      this->mode = (this->get_mode()+1)%13; 
    }

    void dec_mode()
    {
      if ((this->get_mode()-1)>=0)
      {
        this->mode = this->get_mode()-1;
      }
      else
      {
        this->mode = 12;
      }  
    }

    void show(String first_row, String second_row, LiquidCrystal& lcd)
    //Wypisuje podane stringi na ekranie
    {
      lcd.clear();
      lcd.print(first_row);
      lcd.setCursor(0, 1);
      lcd.print(second_row);      
    }  

    String int_to_string(int int_val)
    //Przeksztalca podany int String
    {
      if (String(int_val).length() > 1)
      {
        return String(int_val); 
      }
      else
      {
        return "0"+String(int_val);
      }  
    }

    String bool_to_string(bool bool_val)
    //Przeksztalca bool na stringi ON i OFF
    {
      if (bool_val == true)
      {
        return "ON"; 
      }
      else
      {
        return "OFF";
      }  
    }
    
private:    
    int mode = 0;
};

#endif

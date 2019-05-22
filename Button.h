#ifndef _BUTTON_H_
#define _BUTTON_H_

#define DEBOUNCE_DELAY 30 // 防抖时间

//button  class:
class Button {
  public:
    Button(const int pin);
    //initialize button instance
    void init();
    //Read button state - without debounce
    bool read();
    //return True on both button events, Press or Release
    bool onChange(unsigned long currentTime);
    //return True only on Press
    bool onPress(unsigned long currentTime);
    //return True only on Release
    bool onRelease(unsigned long currentTime);
    //
    int getStat();


  private:
    const int m_pin;
    bool m_lastButtonState; //state variables
    unsigned long m_lastDebounceTime = 0;  // the last time the output pin was toggled
    bool m_pressFlag = 0;
    int m_stat;

};

#endif //_BUTTON_H_

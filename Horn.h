#ifndef HORN_H
#define HORN_H

#define DEFAULT_BRIGHTNESS (255*0.1)
#define MAX_BRIGHTNESS 255

class Horn
{
	public:
		Horn(const int pin);

    // Turn pin on
    void on();

    // Turn pin off
    void off();

    // Toggle pin
    void toggle();

    // Get current state
    bool getState();

    // Set state with bool variable
    void setState(bool state);

  private:
    const int m_pin;  //output pin
    bool m_state;   //current state
};

#endif //HORN_H

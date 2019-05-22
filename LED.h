#ifndef LED_H
#define LED_H

#define DEFAULT_BRIGHTNESS (255*0.1)
#define MAX_BRIGHTNESS 255

class LED
{
	public:
		LED(const int pin);

    // Turn pin on
    void on(int brightness = MAX_BRIGHTNESS);

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

#endif //__LED_H

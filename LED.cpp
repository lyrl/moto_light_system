#include "LED.h"
#include <Arduino.h>

LED::LED(const int pin) : m_pin(pin)
{
  // Set pin as output
  pinMode(m_pin, OUTPUT);
  // Start state if off
  off();
}

//turn on:
void LED::on(int brightness)
{
  analogWrite(m_pin, brightness); //high
  m_state = true;
}

//turn off:
void LED::off()
{
  analogWrite(m_pin, DEFAULT_BRIGHTNESS); //low
  m_state = false;
}

void LED::toggle()
{
  analogWrite(m_pin, m_state == true ? DEFAULT_BRIGHTNESS : MAX_BRIGHTNESS);
  m_state = !m_state;
}

bool LED::getState()
{
  return m_state;
}

void LED::setState(bool state)
{
  if (state)
    on();
  else
    off();

  m_state = state;
}

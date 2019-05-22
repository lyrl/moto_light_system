#include "Horn.h"
#include <Arduino.h>

Horn::Horn(const int pin) : m_pin(pin)
{
  // Set pin as output
  pinMode(m_pin, OUTPUT);
  // Start state if off
  off();
}

//turn on:
void Horn::on()
{
  digitalWrite(m_pin, HIGH); //high
  m_state = true;
}

//turn off:
void Horn::off()
{
  digitalWrite(m_pin, LOW); //low
  m_state = false;
}

void Horn::toggle()
{
  digitalWrite(m_pin, m_state ? HIGH : LOW);
  m_state = !m_state;
}

bool Horn::getState()
{
  return m_state;
}

void Horn::setState(bool state)
{
  if (state)
    on();
  else
    off();

  m_state = state;
}

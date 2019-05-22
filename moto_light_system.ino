/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/

#include "LED.h"
#include "Button.h"
#include "MotoSoundLightMgr.h"


/*
 * OUTPUT PIN 输出
 *
 * led 9
 * horn 10
 */
#define LEDPIN     9
#define HORN_O 10

/*
 * INPUT PIN BUTTONS 输入按键
 *
 * horn         2
 * pass         3
 * high_beam    4
 * addition     5
 */
#define HORN_I      2
#define PASS        5
#define HIGH_BEAM   4
#define ADDITION       3



MotoSoundLightMgr motoMgr(
  HORN_I,
  PASS,
  HIGH_BEAM,
  ADDITION,
  HORN_O,
  LEDPIN
);



void setup() {
Serial.begin(9600);
}


void loop() {
  motoMgr.update();
}

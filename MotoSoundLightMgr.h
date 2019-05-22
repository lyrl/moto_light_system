#ifndef _MOTO_SOUND_LIGHT_MGR_H_
#define _MOTO_SOUND_LIGHT_MGR_H_

#define FADE_DELAY 80 // 80毫秒变更间隔
#define FADE_STEP 1 // 步进5

#include "Horn.h"
#include "LED.h"
#include "Button.h"




//button  class:
class MotoSoundLightMgr {
public:
  MotoSoundLightMgr(
      const int m_i_horn_pin,
      const int m_i_pass_pin,
      const int m_i_high_beam_pin,
      const int m_i_addition_pin,

      const int m_o_horn_pin,
      const int m_o_led_pin
  );
  //initialize button instance
  void init();

  void update();
  void blink(unsigned long currentTime);
  void pollStat(unsigned long currentTime);
  void hihgBeamContrl();
  void idleContrl(unsigned long currentTime);

private:
  // 输入
  const int m_i_horn_pin;
  const int m_i_pass_pin;
  const int m_i_high_beam_pin;
  const int m_i_addition_pin;
  // 输出
  const int m_o_horn_pin;
  const int m_o_led_pin;

  LED* m_led;
  Horn* m_horn;
  Button* m_hornButton;
  Button* m_passButton;
  Button* m_highBeamButton;
  Button* m_additionButton;


  bool m_high_beam_stat = false;
  bool m_horn_stat = false;
  bool m_pass_stat = false;
  bool m_addition_stat = false;

  int m_horn_blink_count = 0;
  unsigned long m_horn_last_blink_time = 0;

  int m_led_blink_count = 0;
  unsigned long m_led_last_blink_time = 0;

  unsigned long m_led_last_fade_time = 0;
  int m_fade_brightness = 0;
  int m_fade_step = FADE_STEP;

};

#endif //_MOTO_SOUND_LIGHT_MGR_H_

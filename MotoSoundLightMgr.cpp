#include <Arduino.h>
#include "MotoSoundLightMgr.h"

MotoSoundLightMgr::MotoSoundLightMgr(
  const int m_i_horn_pin,
  const int m_i_pass_pin,
  const int m_i_high_beam_pin,
  const int m_i_addition_pin,

  const int m_o_horn_pin,
  const int m_o_led_pin) :
  m_i_horn_pin(m_i_horn_pin),
  m_i_pass_pin(m_i_pass_pin),
  m_i_high_beam_pin(m_i_high_beam_pin),
  m_i_addition_pin(m_i_addition_pin),
  m_o_horn_pin(m_o_horn_pin),
  m_o_led_pin(m_o_led_pin)

{
  m_led = new LED(m_o_led_pin);
  m_horn = new Horn(m_o_horn_pin);
  m_hornButton = new Button(m_i_horn_pin);
  m_passButton = new Button(m_i_pass_pin);
  m_highBeamButton = new Button(m_i_high_beam_pin);
  m_additionButton = new Button(m_i_addition_pin);

  m_hornButton->init();
  m_passButton->init();
  m_highBeamButton->init();
  m_additionButton->init();
}

void MotoSoundLightMgr::pollStat(unsigned long currentTime) {

  // 喇叭按钮状态变更
  if(m_hornButton->onChange(currentTime)) {
    Serial.println("horn button press!");
    Serial.println(m_hornButton->getStat() == LOW ? "on" : "off");

    if (m_hornButton->getStat() == LOW) {
      m_led_blink_count = 6;
      m_horn_blink_count = 6;
      m_horn_stat = true;
    } else {
      m_horn_stat = false;
      //m_led->off();
    }
  }

  // 超车按钮 状态变更
  if(m_passButton->onChange(currentTime)) {
    Serial.println("pass button press!");
    Serial.println(m_passButton->getStat() == LOW ? "on" : "off");

    if (m_passButton->getStat() == LOW) {
      m_led_blink_count = 6;
      m_pass_stat = true;
    } else {
      m_pass_stat = false;
      //m_led->off();
    }
  }

  // 远光灯按钮
  if(m_highBeamButton->onChange(currentTime)) {
    Serial.println("high beam button press!");
    Serial.println(m_passButton->getStat() == LOW ? "on" : "off");

    if (m_highBeamButton->getStat() == LOW) {
      m_high_beam_stat = true;
    } else {
      m_high_beam_stat = false;
      //m_led->off();
    }
  }

}


void MotoSoundLightMgr::update() {
  unsigned long currentTime = millis();
  pollStat(currentTime);
  blink(currentTime);
  hihgBeamContrl();
  idleContrl(currentTime);
}

/**
 * 空闲状态下的射灯控制 优先级低
 */
void MotoSoundLightMgr::idleContrl(unsigned long currentTime) {
  // 闪烁记数为空、远光灯为关闭状态
  if (m_led_blink_count <= 0 && !m_high_beam_stat) {
    if (currentTime - m_led_last_fade_time > FADE_DELAY) {
      m_led->on(m_fade_brightness);

      m_fade_brightness+=FADE_STEP;

      if (m_fade_brightness <= 0 || m_fade_brightness >= 100) {
        m_fade_brightness-=FADE_STEP;
      }
      // m_led->set
    }
  }
}

/**
  * 远光灯状态控制 优先级中
  */
void MotoSoundLightMgr::hihgBeamContrl() {
   if (m_led_blink_count <= 0) {
    // 远光灯开启
    if (m_high_beam_stat)
      m_led->on();
    else // 远光灯关闭
      m_led->off();
   }
}

/**
  * 爆闪控制 优先级最高
  */
void MotoSoundLightMgr::blink(unsigned long currentTime) {

  if (m_led_blink_count > 0 && (currentTime - m_led_last_blink_time) > 50) {
    m_led->toggle();
    m_led_blink_count--;
    m_led_last_blink_time = currentTime;
  }


  if (m_horn_blink_count > 0 && (currentTime - m_horn_last_blink_time) > 50) {
    m_horn->toggle();
    m_horn_blink_count--;
    m_horn_last_blink_time = currentTime;
  }

}

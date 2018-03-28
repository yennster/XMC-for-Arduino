#include <BGT24LTR11.h>

BGT24LTR11 RadarBGT24LTR11 = BGT24LTR11();

#define SAMPLES 128

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  RadarBGT24LTR11.begin();

  Serial.println("Init done!");

  RadarBGT24LTR11.start(BGT24LTR11_CONTIGUOUS_ACQ);
}

void loop() {
  // put your main code here, to run repeatedly:
  uint16_t ch_i[SAMPLES] = {};
  uint16_t ch_q[SAMPLES] = {};
  
  if(RadarBGT24LTR11.dataAvailable())
  {
    RadarBGT24LTR11.getChannelData(ch_i, ch_q);
    
    Serial.println("CH_I\tCH_Q");
    for(uint16_t i = 0; i<SAMPLES; i++)
    {
      Serial.print(ch_i[i]);
      Serial.print("\t");
      Serial.println(ch_q[i]);
    }
  }  
}
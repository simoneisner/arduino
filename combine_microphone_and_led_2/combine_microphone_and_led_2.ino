//Tutorial on DIY TECH TUBE
//https://youtu.be/gQ3qVFU4RZk
#include <FastLED.h>

int r=252;
int g=0;
int b=0;

#define LED_PIN     5
#define NUM_LEDS    20

CRGB leds[NUM_LEDS];
CRGB led[NUM_LEDS];
int s=0;

void setup() {

  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  for (int i = 29; i >= 0; i--) 
  {
     leds[i] = CRGB ( r,g,b);
     leds[19-i] = CRGB (r,g,b );
     delay(40);
    FastLED.show();
  }
  Serial.begin(9600);
   pinMode(A0,INPUT);

}
void loop()
{
  s=analogRead(A0);
 
  if((s>=535)&&(s<=540))
  {
    leds[9]=CRGB (20, 135, 217);
    leds[10]=CRGB (20, 135, 217);
  }
  else if((s>=530)&&(s<=535))
   {
     leds[9]=CRGB (20, 217, 30);
    leds[10]=CRGB (20, 217, 30);
   }
  else
  {
     leds[9] = CRGB ( r,g,b);
     leds[10] = CRGB ( r,g,b);
  }
    for (int i = 0; i <= 8; i++) 
  {
     leds[i] = leds[i+1];
     leds[19-i] = leds[18-i];
     
  }
 FastLED.show();
 delay(30);

  
  
 
}

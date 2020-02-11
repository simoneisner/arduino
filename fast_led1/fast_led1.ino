
#include <FastLED.h>

#define LED_PIN   5
#define NUM_LEDS  4

CRGB leds[NUM_LEDS];

void setup() {

  Serial.begin(9600);
  
  // put your setup code here, to run once:
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  // put your main code here, to run repeatedly:
  leds[0] = CRGB(100,100,100);
  FastLED.show();
  delay(500);    

  Serial.print("test");

  leds[0] = CRGB::Black;
  leds[1] = CRGB(0,0,255);
  FastLED.show();
  delay(500);

  Serial.print("test");
  leds[1] = CRGB::Black;
  leds[2] = CRGB(150,0,255);
   FastLED.show();
  delay(500);

  leds[2] = CRGB::Black;
  leds[3] = CRGB(255,200,20);
  FastLED.show();
  delay(500);
  leds[3] = CRGB::Black;
  
  
}

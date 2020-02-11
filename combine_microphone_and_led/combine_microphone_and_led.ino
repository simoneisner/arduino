/****************************************
Example Sound Level Sketch for the 
Adafruit Microphone Amplifier
****************************************/
#include <FastLED.h>

#define LED_PIN 5
#define NUM_LEDS 5


CRGB leds[NUM_LEDS];


const int sampleWindow = 50; // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;
const double threshold = 3.30;

void setup() 
{
   Serial.begin(9600);
   FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
}


void loop() 
{
   unsigned long startMillis= millis();  // Start of sample window
   unsigned int peakToPeak = 0;   // peak-to-peak level

   unsigned int signalMax = 0;
   unsigned int signalMin = 1024;

    leds[0] = CRGB::Black;
    leds[1] = CRGB::Black;
    leds[2] = CRGB::Black;
    leds[3] = CRGB::Black;
    leds[4] = CRGB::Black;
    


   // collect data for 50 mS
   while (millis() - startMillis < sampleWindow)
   {
      sample = analogRead(0);
      if (sample < 1024)  // toss out spurious readings
      { 
         if (sample > signalMax)
         {
            signalMax = sample;  // save just the max levels
         }
         else if (sample < signalMin)
         {
            signalMin = sample;  // save just the min levels
         }        
      }
   }
   peakToPeak = signalMax - signalMin;  // max - min = peak-peak amplitude
   double volts = (peakToPeak * 3.3) / 1024;  // convert to volts
    

    double threshold_1 = 0.50;
    double threshold_2 = 1.00;
    double threshold_3 = 1.50;
    double threshold_4 = 2.00;
    
    if(volts > threshold_1)
    {
        Serial.println("fuck");
        leds[1] = CRGB::Black;
        
        leds[1] = CRGB(50,100,20);
        FastLED.show();
        delay(100);
        leds[1] = CRGB::Black;
        FastLED.show();
        
    }   

    
    if(volts > threshold_2 && volts<threshold_3)
    {
        Serial.println("shit");
        leds[2] = CRGB(51,255,255);
        FastLED.show();
        delay(100);
        leds[2] = CRGB::Black;
        FastLED.show();
        
    }   

    
     if(volts > threshold_3 && volts<threshold_4)
    {
        Serial.println("buddy");
        leds[3] = CRGB(255,255,255);
        FastLED.show();
        delay(100);
        leds[3] = CRGB::Black;
        FastLED.show();
        
    }   

    
    if(volts > threshold_4)
    {
        Serial.println("sugar plum");
        leds[4] = CRGB(102,0,102);
        FastLED.show();
        delay(100);
        leds[4] = CRGB::Black;
        FastLED.show();
        
    }   
    
//        delay(500);    
//      
//        Serial.print("test");
//      
//        leds[0] = CRGB::Black;
//        leds[1] = CRGB(0,0,255);
//        FastLED.show();
//        delay(500);
//      
//        Serial.print("test");
//        leds[1] = CRGB::Black;
//        leds[2] = CRGB(150,0,255);
//         FastLED.show();
//        delay(500);
//      
//        leds[2] = CRGB::Black;
//        leds[3] = CRGB(255,200,20);
//        FastLED.show();
//        delay(500);
//        leds[3] = CRGB::Black;



    Serial.println(volts);
}

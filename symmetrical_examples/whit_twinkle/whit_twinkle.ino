#define USE_OCTOWS2811
#include <OctoWS2811.h>
#include <FastLED.h>

#define NUM_LEDS_PER_STRIP (4*60)
#define NUM_STRIPS 8

CRGB leds[NUM_STRIPS * NUM_LEDS_PER_STRIP];

// Pin layouts on the teensy 3:
// OctoWS2811: 2,14,7,8,6,20,21,5

void setup() {
  LEDS.addLeds<OCTOWS2811>(leds, NUM_LEDS_PER_STRIP);
  LEDS.setBrightness(32);
  
  Serial.begin(115200);  // start serial for output  
  
}

void loop() {
  static uint8_t hue = 0;
  
  for(int i = 0; i < NUM_STRIPS; i++) {
    for(int j = 0; j < NUM_LEDS_PER_STRIP; j++) {   
      if (random(256) >245){
        leds[(i*NUM_LEDS_PER_STRIP) + j] = CHSV(random(256),random(256),random(256));
      } else {
        Serial.print(leds[(i*NUM_LEDS_PER_STRIP) + j].r);
        Serial.print("\t\t");
        leds[(i*NUM_LEDS_PER_STRIP) + j].r = leds[(i*NUM_LEDS_PER_STRIP) + j].r/1.2;
        leds[(i*NUM_LEDS_PER_STRIP) + j].g = leds[(i*NUM_LEDS_PER_STRIP) + j].g/1.2;
        leds[(i*NUM_LEDS_PER_STRIP) + j].b = leds[(i*NUM_LEDS_PER_STRIP) + j].b/1.2;
        Serial.println(leds[(i*NUM_LEDS_PER_STRIP) + j].r);
        delayMicroseconds(2);
      }
    }
  }

  // Set the first n leds on each strip to show which strip it is
  for(int i = 0; i < NUM_STRIPS; i++) {
    for(int j = 0; j <= i; j++) {
      leds[(i*NUM_LEDS_PER_STRIP) + j] = CRGB::Red;
    }
  }

 

  LEDS.show();
  LEDS.delay(10);
}

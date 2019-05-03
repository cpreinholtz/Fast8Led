# Fast8Led

 PLEASE BEAR IN MIND: 

 - ALMOST NONE OF THIS CODE WAS WRITTEN BY ME. 

 - ALL CREDIT AND BLAME FOR THIS CODE SHOULD GO TO THE AUTHORS OF THE OCTO AND FASTLED LIBRARIES.

https://github.com/FastLED/

https://www.arduinolibraries.info/libraries/octo-ws2811


 ## Dependencies: ##

**FastLed:**

1 Click https://github.com/FastLED/FastLED/archive/master.zip to download the FastLED library. You should have a .zip folder in your Downloads folder

2 Unzip the .zip folder and you should get FastLED-master folder

3 Rename your folder from FastLED-master to FastLED

4 Move the FastLED folder to your Arduino IDE installation libraries folder

5 Finally, re-open your Arduino IDE


**OCTOWS2102020238957_or_whatever**

This library is included with the teensy loader...

1 go here https://www.pjrc.com/teensy/td_libs_OctoWS2811.html

2 and/or here https://www.pjrc.com/teensy/td_download.html


 ## Clark's Personal Favs: ##
  - sweepAll (realley cool colors, fast and slow)
  - exaples/FadeAll (SLow and sweet)
  - SpectrumAnalyzer (Potentially If We can get like a mike???)
  
 ## DoDeCaHeIdRoN Ideas ##
  
  - Randomeness across all colors and brightness
  - LightSpeed type spaceflight thing
  - Fireworks Display
  - ** twinkling white stars **
  
## Changing FastLED to OCTO: ##

#define USE_OCTOWS2811

#include <OctoWS2811.h>

#include <FastLED.h>

#define NUM_LEDS_PER_STRIP 64

#define NUM_STRIPS 8

CRGB leds[NUM_STRIPS * NUM_LEDS_PER_STRIP];

LEDS.addLeds<OCTOWS2811>(leds, NUM_LEDS_PER_STRIP);
 
   for(int i = 0; i < NUM_STRIPS; i++) {
    for(int j = 0; j < NUM_LEDS_PER_STRIP; j++) {      
      leds[(i*NUM_LEDS_PER_STRIP) + j] = CHSV((32*i) + hue+j,192,255);
    }
  }
 
 

  

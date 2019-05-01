#include "Arduino.h"
#include "array.h"


DMAMEM int displayMemory[ledsPerStrip*6];
int drawingMemory[ledsPerStrip*6];




    ledArray::ledArray()
      :leds(ledsPerStrip, displayMemory, drawingMemory, config)
    {
      int i;
      int arrayLed=0;
      for (i=0;i<8;i++){
        int j;
        for( j=0;j<ledsPerStrip; j++){
          toLed[arrayLed]= j+ ledsPerStrip*stripOrder[i];
          arrayLed++;
        }
      }
      
    }

    void ledArray::show(){
      leds.show();
    }
    
    void ledArray::begin(){
      leds.begin();
    }

    int ledArray::numPixels(){
      return leds.numPixels();
    }
    
    void ledArray::setPixel(int array_pixel, int color){
      int i= toLed[array_pixel];
      leds.setPixel(i, color);
    }


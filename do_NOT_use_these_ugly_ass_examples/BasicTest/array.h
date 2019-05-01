#ifndef array_h
#define array_h 1

#include "Arduino.h"
#include <OctoWS2811.h>


#define ledsPerStrip 16
#define config  (WS2811_GRB | WS2811_800kHz)
extern DMAMEM int displayMemory[ledsPerStrip*6];
extern int drawingMemory[ledsPerStrip*6];








class ledArray{

  public:
  
    ledArray();

    void show();
    
    void begin();
    
    int numPixels();
      
    
    void setPixel(int array_pixel, int color);
    
  private:
    OctoWS2811 leds;



    //lookup table
    //when input an array based index from 0 to (ledsPerStrip*8)-1 
    //the value in the table will be the pixel number of the led WRT
    //the octo wiring, utilises "stripOrder" to construct
    int toLed[ledsPerStrip*8];

    //top to bottom based on the order of flashing in the BasicTest Example
    const int stripOrder[8]={
      6,5,4,7,2,1,0,3
    };

  
};



#endif

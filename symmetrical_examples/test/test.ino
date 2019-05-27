#define USE_OCTOWS2811
#include <OctoWS2811.h>
#include <FastLED.h>
#include "pix.h"

// Pin layouts on the teensy 3:
// OctoWS2811: 2,14,7,8,6,20,21,5

#define NUM_LEDS_PER_STRIP 16
#define NUM_STRIPS 8
#define NUM_LEDS (NUM_LEDS_PER_STRIP * NUM_STRIPS)

unsigned long long startMillis=0;
unsigned long long lastSecondHand=0;
CRGB leds[NUM_STRIPS * NUM_LEDS_PER_STRIP];
Pix pix(NUM_LEDS);


PixArray<NUM_LEDS> pixArray(NUM_LEDS);
PixArray<NUM_LEDS> pixArray2(NUM_LEDS);

void setup() {
  LEDS.addLeds<OCTOWS2811>(leds, NUM_LEDS_PER_STRIP);
  LEDS.setBrightness(32); 
  randomSeed(analogRead(0)); 
  pix.setValue(CRGB::Red);
  reRand();
  startMillis=millis();
  lastSecondHand= (millis() / 1000) % 60;
  
}





void loop() { 


  doubleSpin();
  //whiteRandDim();
  //whiteDim();
  //randEffect();
 



  
}








//////////////////////////////////////////////////
//Random Effects

void randEffect(){
  int num_effects=10;
  int effect = random(num_effects);
  switch (effect){
    case 0:
      spinArray(8); pix.addToIndex(1);
      break;
    case 1:
      twirlArray(); pix.addToIndex(1);
      break;
    case 2:
      spinEvenly(-1); pix.addToIndex(1);
      break; 
    case 3: 
      spinEvenlySlowing(1,-1); pix.addToIndex(1);
      break; 
         
    default:
      reRand();
      break;      
  }
}


void reRand(){
  //pix.randomValue();
  pixArray.randomValue();
  pixArray.randomIndex();
  
}



//////////////////////////////////////////////////
//Base Effects

void twirlArray(){
  pixArray.setActivePIX(8);
  pixArray.setIndexToIndex(); 
  pixArray.applyTo(leds); 
  showAndClear(); delay(80);
 

  //for max=arraylen*2^i
  //8*2^4=8*16=128

  //30*80= 2.4sec
  for(int i=0; i<30; i++){
    pixArray.squareIndex();
    pixArray.applyTo(leds); 
    showAndClear(); delay(80);
  }

  //reRand();
  
}




void doubleSpinSaturated(){

  //purple array
  //pixArray.setActivePIX(5);
  pixArray.setActivePIX(15);
  pixArray.setValue(CRGB::Blue);  
  pixArray.spreadEvenly(); 

  //green pix
  //pixArray2.setActivePIX(7);
  pixArray2.setActivePIX(23);
  pixArray2.setValue(CRGB::Green);  
  pixArray2.spreadEvenly(); 
  

  
  pixArray.applyTo(leds); 
  pixArray2.applyTo(leds);
  showAndClear(); delay(80);
 

  //for max=arraylen*2^i
  //8*2^4=8*16=128

  int dimBy=10+random(10);
  //30*80= 2.4sec
  for(int i=0; i<160; i++){
    //spin array +
    pixArray.addToIndex(1);
    //spin pix -
    pixArray2.addToIndex(-1);
    
    pixArray.applyTo(leds); 
    pixArray2.applyTo(leds);
    show(); dimAll(dimBy);
    delay(50);
  }

  //reRand();
  
}

void doubleSpin(){

  //purple array
  pixArray.setActivePIX(5);
  pixArray.setValue(CRGB::Red);  
  pixArray.spreadEvenly(); 

  //green pix
  pixArray2.setActivePIX(7);
  pixArray2.setValue(CRGB::Blue);  
  pixArray2.spreadEvenly(); 
  

  
  pixArray.applyTo(leds); 
  pixArray2.applyTo(leds);
  showAndClear(); delay(80);
 

  //for max=arraylen*2^i
  //8*2^4=8*16=128

  int dimBy=10+random(10);
  //30*80= 2.4sec
  for(int i=0; i<160; i++){
    //spin array +
    pixArray.addToIndex(1);
    //spin pix -
    pixArray2.addToIndex(-1);
    
    pixArray.applyToAdditive(leds); 
    pixArray2.applyToAdditive(leds);
    show(); dimAll(dimBy);
    delay(50);
  }

  //reRand();
  
}
void whiteRandDim(){

  //set all pix and spreadum
  pixArray.setAllActivePIX();
  pixArray.setIndexToIndex(); 

  //set to white
  pixArray.setValue(CRGB::White); 
  pixArray.applyTo(leds); 
  
  //hold for .5 to 1 sec
  showAndClear(); 
  delay(random(500)+500);



  int numdims=450;
  // delay*numdims=period    eg period/numdims=delay
  int dela=random(3)+1500/numdims;

  
  
  for(int i=1; i<numdims; ){
    //dim less as i increases (always dim under a certain cut off)
    if( random(i)<numdims/3)i++;
    pixArray.dimAllRandColor(1);
    pixArray.applyTo(leds); 
    showAndClear(); delay(dela);

    
  }
  
  pixArray.applyTo(leds); 
  //hold for .5 to 1 sec
  showAndClear(); delay(random(500)+500);

}



void whiteDim(){
  //set all pix and spreadum
  pixArray.setAllActivePIX();
  pixArray.setIndexToIndex(); 

  //set to white
  pixArray.setValue(CRGB::White); 
  pixArray.applyTo(leds); 
  
  //hold for .5 to 1 sec
  showAndClear(); 
  delay(random(500)+500);

  //loop for 2.5 to 4 sec while dimming
  int dela=random(3)+5;
  for(int i=0; i<500; i++){
    pixArray.dimAll(1);
    pixArray.applyTo(leds); 
    showAndClear(); delay(dela);
  }
  
  //hold for .5 to 1 sec
  showAndClear(); delay(random(500)+500);

}














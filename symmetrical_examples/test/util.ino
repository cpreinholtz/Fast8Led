



////////////////////////////////////////////////////
//
//sets all led values to 0, does not effect pix objects stored memory
void clearAll(){
  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(0,0,0);      
  }
}


///////////////////////////////////////////////////////
//Utility
  
// Set the first n leds on each strip to show which strip it is
void setNum(){    
  int sec=3;
  if (millis()-startMillis<sec*1000) {
    for(int i = 0; i < NUM_STRIPS; i++) {
      for(int j = 0; j <= i; j++) {
        leds[(i*NUM_LEDS_PER_STRIP) + j] = CRGB::Red;
      }
    }
  }
}


void showAndClear(){
  pix.applyTo(leds);  
  if (millis()-startMillis<10000) setNum();
  LEDS.show();
  clearAll();
}


void showAndDim(){
  pix.applyTo(leds);  
  if (millis()-startMillis<10000) setNum();
  LEDS.show();
  dimAll(1);
}

void show(){
  pix.applyTo(leds);  
  if (millis()-startMillis<10000) setNum();
  LEDS.show();
}


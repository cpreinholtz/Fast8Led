
////////////////////////////////////////////////////////////////////////////////////////////
void pulse(){

  pixArray.setActivePIX(NUM_LEDS);
  pixArray.setIndexToIndex(); 



  for(int led=0; led<NUM_LEDS; led++ ){ 
    switch(led%3){
      case 0:
        pixArray.setSingleValue(CRGB::Red,led);
        break;
      case 1:
        pixArray.setSingleValue(CRGB::Orange,led);
        break;
      case 2:
        pixArray.setSingleValue(CRGB::Yellow,led);
        break;
      case 3:
        pixArray.setSingleValue(CRGB::Orange,led);
        break;
    }
  }



  

delay(1000);
  //pulse
  int fadeW=15;  
  long long startT=millis();
  
  while (millis()<startT+10000){
    for(int strip=0; strip<NUM_STRIPS; strip++ ){ 
      for(int i=0; i<NUM_LEDS_PER_STRIP; i++ ){ 
        int led=strip*NUM_LEDS_PER_STRIP+i;
        for (int subLed=0; subLed< fadeW; subLed++){
          int dimby =9;
          if (led+subLed< NUM_LEDS) pixArray.dimSingleBrightest(led+subLed,-dimby);
          if (led>subLed)pixArray.dimSingleBrightest(led-subLed,dimby);
        }
      }               
    }  
    pixArray.applyTo(leds);
    showAndClear(); delay(10);
  }
  
}

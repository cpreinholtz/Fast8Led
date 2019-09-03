
////////////////////////////////////////////////////////////////////////////////////////////
void pulse(){

  pixArray.setAllActivePIX();
  pixArray.setIndexToIndex(); 



  for(int led=0; led<pixArray.getActivePIX(); led++ ){ 
    switch(led%6){      
      case 0:
        pixArray.setSingleValue(CRGB::Orange,led);
        break;
      case 1:
        pixArray.setSingleValue(CRGB::MediumVioletRed,led);
        break;
      case 2:
        pixArray.setSingleValue(CRGB::SteelBlue,led);
        break;
      case 3:
        pixArray.setSingleValue(CRGB::MediumVioletRed,led);
        break;
      case 4:
        pixArray.setSingleValue(CRGB::SteelBlue,led);
        break;
      case 5:
        pixArray.setSingleValue(CRGB::Orange,led);
        break;
    }
    if (led%16==14)pixArray.setSingleValue(CRGB::Red,led);
    if (led%16==10)pixArray.setSingleValue(CRGB::Orchid,led);
    if (led%32==27)pixArray.setSingleValue(CRGB::FireBrick,led);
    if (led%32==13)pixArray.setSingleValue(CRGB::DarkViolet,led);
     
  }

  
  pixArray.dimAll(100);
  pixArray.applyTo(leds);
  show();
  delay(3000);


  
  //pulse
  int fadeW=10;
  int dimby =5; 
  long long startT=millis();
  
  while (millis()<startT+10000){
    
    for(int i=0; i<NUM_LEDS_PER_STRIP; i++ ){ 
      for(int strip=0; strip<NUM_STRIPS; strip++ ){       
        int led=strip*NUM_LEDS_PER_STRIP+i;
        for (int subLed=0; subLed< fadeW; subLed++){          
          if (led+subLed< NUM_LEDS) pixArray.dimSingle(led+subLed%NUM_LEDS,-dimby);          
          if (led>subLed+1)pixArray.dimSingle(led-subLed,dimby);
        }
      }   
      pixArray.applyTo(leds);
      showAndClear(); delay(3);      
    }      
    
  }
  
}



////////////////////////////////////////////////////////////////////////////////////////////
void pulseBrightest(){

  pixArray.setAllActivePIX();
  pixArray.setIndexToIndex(); 



  for(int led=0; led<pixArray.getActivePIX(); led++ ){ 
    switch(led%6){      
      case 0:
        pixArray.setSingleValue(CRGB::Orange,led);
        break;
      case 1:
        pixArray.setSingleValue(CRGB::MediumVioletRed,led);
        break;
      case 2:
        pixArray.setSingleValue(CRGB::SteelBlue,led);
        break;
      case 3:
        pixArray.setSingleValue(CRGB::MediumVioletRed,led);
        break;
      case 4:
        pixArray.setSingleValue(CRGB::SteelBlue,led);
        break;
      case 5:
        pixArray.setSingleValue(CRGB::Orange,led);
        break;
    }
    if (led%16==14)pixArray.setSingleValue(CRGB::Red,led);
    if (led%16==10)pixArray.setSingleValue(CRGB::Orchid,led);
    if (led%32==27)pixArray.setSingleValue(CRGB::FireBrick,led);
    if (led%32==13)pixArray.setSingleValue(CRGB::DarkViolet,led);
     
  }

  
  pixArray.dimAll(100);
  pixArray.applyTo(leds);
  show();
  delay(1000);


  
  //pulse
  int fadeW=10;
  int dimby =10; 
  long long startT=millis();
 
  
  while (millis()<startT+10000){
    
    for(int i=0; i<NUM_LEDS_PER_STRIP; i++ ){ 
      for(int strip=0; strip<NUM_STRIPS; strip++ ){       
        int led=strip*NUM_LEDS_PER_STRIP+i;
        for (int subLed=0; subLed< fadeW; subLed++){          
          if (led+subLed< NUM_LEDS) pixArray.dimSingleBrightest(led+subLed%NUM_LEDS,-dimby);          
          if (led>subLed)pixArray.dimSingleBrightest(led-subLed,dimby);
        }
      }   
      pixArray.applyTo(leds);
      showAndClear(); delay(3);      
    }      
    
  }
  
}

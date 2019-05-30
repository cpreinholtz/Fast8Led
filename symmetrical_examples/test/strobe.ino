

void strobeColor(){


  pixArray.setActivePIX(194);
  pixArray.setValue(CRGB::White); 
  pixArray.useSingleStripIndexing();
  pixArray.setIndexToIndex(); 
  
  pixArray.applyToAllStrips(leds);

  long long startT=millis();
  while(millis()<startT+10000){
    int strip=random(8);
    if (random(1000)>300){
      CRGB rando;
      rando.r=random(256);
      rando.g=random(256);
      rando.b=random(256);
      pixArray.setValue(rando);
      pixArray.applyToStrip(leds,strip);
    }
    showAndClear();delay(random(100)+30);
  }
  
  pixArray.useAbsoluteIndexing();
  pixArray2.useAbsoluteIndexing();
  
}





void strobeColorQuickening(){


  pixArray.setActivePIX(194);
  pixArray.setValue(CRGB::White); 
  pixArray.useSingleStripIndexing();
  pixArray.setIndexToIndex(); 
  
  pixArray.applyToAllStrips(leds);

  long long startT=millis();
 
  int cutOff=700;
  int loopC=0;
  while(millis()<startT+5000 || cutOff>0){
    int strip=random(8);
    if (random(1000)>cutOff){
      CRGB rando;
      rando.r=random(256);
      rando.g=random(256);
      rando.b=random(256);
      pixArray.setValue(rando);
      pixArray.applyToStrip(leds,strip);
    }
    //if (loopC++%20==0){
      if(cutOff==1) startT=millis();
      if (cutOff>100)cutOff-=10;
      else if(cutOff>0)cutOff--;
    //}
      
    
    showAndClear();delay(random(100)+30);
  }
  
  pixArray.useAbsoluteIndexing();
  pixArray2.useAbsoluteIndexing();
  
}




void strobeStrip(){


  pixArray.setActivePIX(194);
  pixArray.setValue(CRGB::White); 
  pixArray.useSingleStripIndexing();
  pixArray.setIndexToIndex(); 
  
  pixArray.applyToAllStrips(leds);

  long long startT=millis();
  while(millis()<startT+10000){
    int strip=random(8);
    if (random(1000)>300){
      CRGB rando;
      rando.r=random(256);
      rando.g=random(256);
      rando.b=random(256);
      pixArray.setValue(CRGB::White);
      pixArray.applyToStrip(leds,strip);
    }
    showAndClear();delay(random(100)+30);
  }
  
  pixArray.useAbsoluteIndexing();
  pixArray2.useAbsoluteIndexing();
  
}



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

  int randdel=100;
  int del=30;
  
 
  int cutOff=1500;//start here out of 1000
  int loopC=0;
  
  while(millis()<startT+10000 || cutOff>0){
    int strip=random(8);
    if (random(2000)>cutOff){
      CRGB rando;
      rando.r=random(256);
      rando.g=random(256);
      rando.b=random(256);
      pixArray.setValue(rando);
      pixArray.applyToStrip(leds,strip);
    }
    //if (loopC++%20==0){
      if(cutOff==1) startT=millis();
      if (cutOff>800) cutOff-=2;
      else if (cutOff>600){
        cutOff-=2;
        del=20;
        randdel=100;
      }
      else if (cutOff>100){
        cutOff-=2;
        del=10;
        randdel=80;
      }
      else if (cutOff>50){
        cutOff-=2;
        del=7;
        randdel=60;
      }
      else if(cutOff>0){
        cutOff--;
        del=4;
        randdel=40;
      }
      else if(cutOff==0){
        del=1;
        randdel=20;
      }
      
      Serial.println(cutOff);
    //}
          
    showAndClear();delay(random(randdel)+del);
  }


  pixArray.setValue(CRGB::White);
  pixArray.applyToAllStrips(leds);
  showAndClear();
  delay(3000);

  
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

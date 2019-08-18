





void harmonicWave(){
int del=20;
  pixArray.useAbsoluteIndexing();
  pixArray.setAllActivePIX();
  pixArray.setIndexToIndex();
  
  CRGB temp; 
  int rStart, gStart, bStart;

  
  int rWaveLength=8, gWaveLength=16, bWaveLength=32;
  
  
  long long statT=millis();
  for(;millis()<10000+statT;rStart+=3,gStart+=2,bStart+=1) {    
    for (int pix=0;pix<pixArray.getActivePIX();pix++){
      
      if (pix>=rStart) pixArray.setSingleRValue( sin8(256/rWaveLength*(pix-rStart)%255), pix);
      else pixArray.setSingleRValue( sin8((rStart-pix)%255), pix);
      
      if (pix>=gStart)pixArray.setSingleGValue( sin8(256/gWaveLength*(pix-gStart)%255), pix);
      else pixArray.setSingleGValue( sin8(256/gWaveLength*(gStart-pix)%255), pix);
      
      if (pix>=bStart)pixArray.setSingleBValue( sin8(256/bWaveLength*(pix-bStart)/3%255), pix);
      else pixArray.setSingleBValue( sin8(256/bWaveLength*(bStart-pix)%255), pix);
    }   
    
    pixArray.applyTo(leds);
    showAndClear();
    delay(del);
  }
  
  pixArray.applyTo(leds);
  showAndClear();

  
}


void colorWaveChangeAll(){
  int del=1;
  pixArray.useAbsoluteIndexing();
  pixArray.setAllActivePIX();
  pixArray.setIndexToIndex();
  
  long long statT=millis();
  for(int i=0; millis()<10000+statT; i++) { 
    int ri=i*1%255;
    int gi=i*2%255;
    int bi=i*3%255;
    CRGB temp;
    temp.r=sin8(ri);
    temp.g=sin8(gi);
    temp.b=sin8(bi);
    pixArray.setValue(temp);
    pixArray.applyTo(leds);
    showAndClear();
    delay(del);
  }

  


  
}






void colorWaveStatic(int fundameltalWavelength){

  pixArray.useAbsoluteIndexing();
  pixArray.setAllActivePIX();
  pixArray.setIndexToIndex();
  

  for (int i=0; i<pixArray.getActivePIX();i++){
    CRGB temp;
    temp.r=sin8(256/fundameltalWavelength*i%256);
    temp.g=sin8(256/fundameltalWavelength*i*2%256);
    temp.b=sin8(256/fundameltalWavelength*i*3%256);
    pixArray.setSingleValue(temp,i);  
    Serial.println(i);
        
  }
  pixArray.applyTo(leds);
  showAndClear();

  
}



void blueWaveStatic(){
  int fundameltalWavelength=16;
  pixArray.useAbsoluteIndexing();
  pixArray.setAllActivePIX();
  pixArray.setIndexToIndex();
  

  for (int i=0; i<pixArray.getActivePIX();i++){
    CRGB temp;
    temp.r=0;
    temp.g=0;
    temp.b=sin8(256/fundameltalWavelength*i%256);
    pixArray.setSingleValue(temp,i);  
  }
  pixArray.applyTo(leds);
  showAndClear();

  
}



void blueWaveTemporal(){
int fundameltalWavelength=16;
int del=0;
  pixArray.useAbsoluteIndexing();
  pixArray.setAllActivePIX();
  pixArray.setIndexToIndex();
  

  long long statT=millis();
  for(int loopC=0; millis()<20000+statT; loopC+=10) { 

    for (int i=0; i<pixArray.getActivePIX();i++){
      int bdivider=cos8(loopC%256)/12; if (bdivider==0) bdivider=1;

      
      CRGB temp;
      temp.r=0;
      temp.g=0;
      temp.b=sin8(256/fundameltalWavelength*i%256)/bdivider;
      pixArray.setSingleValue(temp,i);            
    }
    pixArray.applyTo(leds);
    showAndClear();
    delay(del);
  }
}


void colorWaveTemporal(){

int fundameltalWavelength=16; int del=10;
  pixArray.useAbsoluteIndexing();
  pixArray.setAllActivePIX();
  pixArray.setIndexToIndex();
  

  long long statT=millis();
  for(int loopC=0; millis()<20000+statT; loopC+=2) { 

    for (int i=0; i<pixArray.getActivePIX();i++){
      
      int bdivider=cos8(loopC%256)/12; if (bdivider==0) bdivider=1;//blue is slowest flash
      int gdivider=cos8(loopC*2%256)/12; if (gdivider==0) gdivider=1;
      int rdivider=cos8(loopC*3%256)/12; if (rdivider==0) rdivider=1;

      
      CRGB temp;
      temp.r=sin8(256/3*fundameltalWavelength*i%256)/rdivider;
      temp.g=sin8(256/2*fundameltalWavelength*i%256)/gdivider;
      temp.b=sin8(256/fundameltalWavelength*i%256)/bdivider;
      
      pixArray.setSingleValue(temp,i);            
    }
    pixArray.applyTo(leds);
    showAndClear();
    delay(del);
  }
}
void blueWaveMovingTemporal(){
  int fundameltalWavelength=16;
  int del=1;
  pixArray.useAbsoluteIndexing();
  pixArray.setAllActivePIX();
  pixArray.setIndexToIndex();
  

  long long statT=millis();
  for(int loopC=0; millis()<20000+statT; loopC++) { 

    for (int i=0; i<pixArray.getActivePIX();i++){
      int divider=cos8(loopC%256); if (divider==0) divider=1;

      
      CRGB temp;
      temp.r=0;
      temp.g=0;
      temp.b=sin8(256/fundameltalWavelength*i%256)-divider;
      pixArray.setSingleValue(temp,i);            
    }
    pixArray.applyTo(leds);
    showAndClear();
    delay(del);
  }
}


void colorWaveMove(){

  colorWaveStatic(256);
  moveUp(5,10000);//del, loopmillis
}

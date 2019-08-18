


//////////////////////////////////////////////////
//Base Effects

void twirlArray(){
  pixArray.setActivePIX(128);
  pixArray.setIndexToIndex(); 
//if (pixArray.isBlack()) pixArray.interpolateRand();
  //for max=arraylen*2^i
  //8*2^4=8*16=128

  //30*80= 2.4sec
  long long startT=millis();
  for(int i=0; millis()<startT+10000; i++){    
    pixArray.applyTo(leds); 
    showAndClear(); delay(80);
    pixArray.squareIndex();

  }

  //reRand();
  
}

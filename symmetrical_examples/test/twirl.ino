


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






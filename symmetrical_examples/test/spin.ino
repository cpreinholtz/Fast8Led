


/////////////////////////////////////
//SPIN ARRAY IN A SINGLE BLOCK
void spinArray(int activeLeds){
  if (activeLeds>0 ) pixArray.setActivePIX(activeLeds);  
  else pixArray.setAtLeastActivePIX();//Random number of pixels
  
  pixArray.setIndexToIndex();
  showAndClear(); delay(20);
  //20*128 = 2.5 sec
  for(int i=0; i<NUM_LEDS; i++){
    pixArray.addToIndex(1);
    pixArray.applyTo(leds); 
    showAndClear(); delay(20);
  }  
}





/////////////////////////////////////
//Spread ARRAY then spin it
void spinEvenly(int activeLeds){
  if (activeLeds>0 ) pixArray.setActivePIX(activeLeds);  
  else pixArray.setAtLeastActivePIX();//Random number of pixels
  
  pixArray.spreadEvenly();
  showAndClear(); delay(20);
  //20*128 = 2.5 sec
  for(int i=0; i<NUM_LEDS; i++){
    pixArray.addToIndex(1);
    pixArray.applyTo(leds); 
    showAndClear(); delay(20);
  }  
}



void spinEvenlySlowing(int spinRate, int activeLeds){
  if (activeLeds>0 ) pixArray.setActivePIX(activeLeds);  
  else pixArray.setAtLeastActivePIX();//Random number of pixels
  
  pixArray.spreadEvenly();
  showAndClear(); delay(20);
  //20*128 = 2.5 sec
  
  for(int VARdelay=20; VARdelay<80; VARdelay++){
    pixArray.addToIndex(spinRate);
    pixArray.applyTo(leds); 
    showAndClear(); delay(VARdelay);    
  }  
}

void spinEvenlyQuickening(int spinRate, int activeLeds){
  if (activeLeds>0 ) pixArray.setActivePIX(activeLeds);  
  else pixArray.setAtLeastActivePIX();//Random number of pixels
  
  pixArray.spreadEvenly();
  showAndClear(); delay(20);
  //20*128 = 2.5 sec
  
  for(int VARdelay=80; VARdelay>20; VARdelay++){
    pixArray.addToIndex(spinRate);
    pixArray.applyTo(leds); 
    showAndClear(); delay(VARdelay);    
  }  
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







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







////////////////////////////////////////////////////////////////////////////////////
void whiteDim(){
  //set all pix and spreadum
  pixArray.setAllActivePIX();
  pixArray.setIndexToIndex(); 

  //set to white
  pixArray.setValue(CRGB::White); 
  pixArray.applyTo(leds); 
  
  //hold for .5 to 1 sec
  showAndClear(); 
  delay(random(500)+500);

  //loop for 2.5 to 4 sec while dimming
  int dela=random(3)+5;
  for(int i=0; i<500; i++){
    pixArray.dimAll(1);
    pixArray.applyTo(leds); 
    showAndClear(); delay(dela);
  }
  
  //hold for .5 to 1 sec
  showAndClear(); delay(random(500)+500);

}



///////////////////////////////////////////////////////////////////////////////////
void whiteRandDim(){
  //loop for 2.5 to 4 sec while dimming
  int dela=random(3)+5;
  for(int i=0; i<500; i++){
    pixArray.dimAll(1);
    pixArray.applyTo(leds); 
    showAndClear(); delay(dela);
  }
  
  //hold for .5 to 1 sec
  showAndClear(); delay(random(500)+500);
  
  //set all pix and spreadum
  pixArray.setAllActivePIX();
  pixArray.setIndexToIndex(); 
  
  //set to white
  pixArray.setValue(CRGB::White); 
  pixArray.applyTo(leds); 
  
  //hold for .5 to 1 sec
  showAndClear(); 
  delay(random(500)+500);



  int numdims=450;
  // delay*numdims=period    eg period/numdims=delay
  dela=random(3)+1500/numdims;

  
  
  for(int i=1; i<numdims; ){
    //dim less as i increases (always dim under a certain cut off)
    if( random(i)<numdims/3)i++;
    pixArray.dimAllRandColor(1);
    pixArray.applyTo(leds); 
    showAndClear(); delay(dela);

    
  }
  
  pixArray.applyTo(leds); 
  //hold for .5 to 1 sec
  showAndClear(); delay(random(500)+500);

}

////////////////////////////////////////////////////////////////////////////////////////////
void whiteRandDimToGlow(){
  //loop for 2.5 to 4 sec while dimming
  int dela=random(3)+5;
  for(int i=0; i<500; i++){
    pixArray.dimAll(1);
    pixArray.applyTo(leds); 
    showAndClear(); delay(dela);
  }
  
  //hold for .5 to 1 sec
  showAndClear(); delay(random(500)+500);
  //set all pix and spreadum
  pixArray.setAllActivePIX();
  pixArray.setIndexToIndex(); 

  //set to white //hold for .5 to 1 sec
  pixArray.setValue(CRGB::White); 
  pixArray.applyTo(leds); 
  showAndClear(); 
  delay(random(500)+500);


  int numdims=450;
  // delay*numdims=period    eg period/numdims=delay
  dela=random(3)+1500/numdims;

  
  //dim
  for(int i=1; i<numdims; ){
    //dim less as i increases (always dim under a certain cut off)
    if( random(i)<numdims/3)i++;
    pixArray.dimAllRandColor(1);
    pixArray.applyTo(leds); 
    showAndClear(); delay(dela);
  }

  


  //pulse (goes around singularly
  int del=1;
  int fadeW=15;  
  for(int led=0; led<NUM_LEDS; led++ ){ 

    for (int subLed=0; subLed< fadeW; subLed++){
      int dimby =9;
      if (led+subLed< NUM_LEDS) pixArray.dimSingleBrightest(led+subLed,-dimby);
      if (led>subLed)pixArray.dimSingleBrightest(led-subLed,dimby);
    }    
    pixArray.applyTo(leds);
    showAndClear(); delay(del);     
  }
  //back of pulse
  for(int led=NUM_LEDS-fadeW; led<NUM_LEDS; led++ ){
    for (int subLed=led; subLed< NUM_LEDS; subLed++){
      int dimby =9;
      pixArray.dimSingleBrightest(subLed,dimby);
    }
    pixArray.applyTo(leds);
    showAndClear(); delay(del);
  }
  

 
  

  pixArray.applyTo(leds); 
  //hold for .5 to 1 sec
  showAndClear(); delay(random(500)+500);

  
  //glow
  for(int i=1; i<50;i++ ){
    pixArray.dimAllBrightest(-1);
    pixArray.applyTo(leds); 
    showAndClear(); delay(20);    
  }

  pixArray.applyTo(leds); 
  //hold for .5 to 1 sec
  showAndClear(); delay(random(500)+500);

}


////////////////////////////////////////////////////////////////////////////////////////////
void whiteRandDimToAllGlow(){
  //loop for 2.5 to 4 sec while dimming
  int dela=random(3)+5;
  for(int i=0; i<500; i++){
    pixArray.dimAll(1);
    pixArray.applyTo(leds); 
    showAndClear(); delay(dela);
  }
  
  //hold for .5 to 1 sec
  showAndClear(); delay(random(500)+500);
  //set all pix and spreadum
  pixArray.setAllActivePIX();
  pixArray.setIndexToIndex(); 

  //set to white //hold for .5 to 1 sec
  pixArray.setValue(CRGB::White); 
  pixArray.applyTo(leds); 
  showAndClear(); 
  delay(random(500)+500);


  int numdims=450;
  // delay*numdims=period    eg period/numdims=delay
  dela=random(3)+1500/numdims;

  
  //dim
  for(int i=1; i<numdims; ){
    //dim less as i increases (always dim under a certain cut off)
    if( random(i)<numdims/3)i++;
    pixArray.dimAllRandColor(1);
    pixArray.applyTo(leds); 
    showAndClear(); delay(dela);
  }

  


  //pulse (goes around singularly
  int del=1;
  int dimby =30;
  int fadeW=15;  
  for(int led=0; led<pixArray.get_NUM_PIX(); led++ ){ 
    for(int strip=0; strip<8; strip++ ){ 
      
      int thisled=led%NUM_LEDS_PER_STRIP*strip;
      
      pixArray.dimSingleBrightest(thisled,-dimby);

      
      
    } 
    //applies to all stips       
    pixArray.applyTo(leds);
    showAndDimBy(9); delay(del);     
  }


  




  //hold for .5 to 1 sec
  showAndClear(); delay(random(500)+500);

  
  //glow
  for(int i=1; i<50;i++ ){
    pixArray.dimAllBrightest(-1);
    pixArray.applyTo(leds); 
    showAndClear(); delay(20);    
  }


  pixArray.applyTo(leds); 
  //hold for .5 to 1 sec
  showAndClear(); delay(random(500)+1500);

}






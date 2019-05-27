
void fireworks(int activeLeds){

  reRand();
  
  pixArray.setActivePIX(activeLeds);
  showAndClear(); delay(20);

  //del*loops=time mS
  int del=5;
  int loops=2000;
  for(int i=0; i<loops; i++){
    for(int i=0; i<activeLeds; i++){
      if (random(10000)>9995) {
        leds[i]=CRGB::White;
      }
    }
    int dec=1;
    pixArray.applyToword(leds,dec);
    showAndDim(); delay(del);
  }  


  
}




void fireworksColor(int activeLeds){

  reRand();
  CRGB temp=CRGB::Orange;
  
  CRGB temp2=CRGB::Purple;
  
  pixArray.setValue(temp);
  pixArray.setActivePIX(activeLeds);
  showAndClear(); delay(20);

  //del*loops=time mS
  int del=0;
  int loops=2000;
  for(int i=0; i<loops; i++){
    if (temp.r<temp2.r)temp.r+=10;
    else temp.r-=10;

    if (temp.g<temp2.g)temp.g+=10;
    else temp.g-=10;

    if (temp.b<temp2.b)temp.b+=10;
    else temp.b-=10;
    
    pixArray.setSingleValue(temp,i % activeLeds);
    
    
    for(int i=0; i<activeLeds; i++){
      if (random(10000)>9980) {
        leds[i]=CRGB::White;
      }
    }
    int dec=1;
    pixArray.applyToword(leds,dec);
    showAndDimBy(10);delay(del);
  }  
}



void fireworks(int activeLeds){

  reRand();
  pixArray.dimAllRed(50);
  pixArray.setActivePIX(activeLeds);
  showAndClear(); delay(20);

  //del*loops=time mS
  int del=0;
  int loops=2000;
  for(int i=0; i<loops; i++){
    for(int i=0; i<activeLeds; i++){
      if (random(10000)>9980) {
        leds[i]=CRGB::White;
      }
    }
    int dec=1;
    pixArray.applyToword(leds,dec);
    showAndDimBy(10);delay(del);
  }  
  
}


void fireworksClear(int activeLeds){

  
  
  pixArray.setActivePIX(activeLeds);
  reRand();
  pixArray.dimAllRed(50);
  showAndClear(); delay(20);

  //del*loops=time mS
  int del=1;
  int loops=2000;
  for(int i=0; i<loops; i++){
    for(int i=0; i<activeLeds; i++){
      if (random(10000)>9995) {
        leds[i]=CRGB::White;
      }
    }
    int dec=1;
    pixArray.applyToword(leds,dec);
    showAndClear(); delay(del);
  }  


  
}

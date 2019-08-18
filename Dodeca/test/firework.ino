

void fireworksColor(){
  int activeLeds=NUM_LEDS/2;
  reRand();
  CRGB temp=CRGB::Orange;
  
  CRGB temp2=CRGB::Purple;
  
  pixArray.setValue(temp);
  pixArray.setActivePIX(activeLeds);
  showAndClear(); delay(20);

  //del*loops=time mS
  int del=0;
  int VARdelay =10;
  long long startT = millis();
  while(millis()<startT+15000){
    static int i=0;
    if (temp.r<temp2.r)temp.r+=10;
    else temp.r-=10;

    if (temp.g<temp2.g)temp.g+=10;
    else temp.g-=10;

    if (temp.b<temp2.b)temp.b+=10;
    else temp.b-=10;
    
    pixArray.setSingleValue(temp,i++ % activeLeds);
    
    
    for(int i=0; i<NUM_LEDS; i++){
      if (random(10000)>9980) {
        leds[i]=CRGB::White;
      }
    }


    
    int dec=1;
    pixArray.applyToword(leds,dec);
    showAndDimBy(10);delay(del);
  }  
}







void fireworks(){
  int activeLeds=NUM_LEDS/2;
  reRand();
  pixArray.dimAllRed(50);
  pixArray.setActivePIX(activeLeds);
  showAndClear(); delay(20);

  //del*loops=time mS
  int del=0;
  long long startT = millis();
  while(millis()<startT+7000){
    for(int i=0; i<NUM_LEDS; i++){
      if (random(10000)>9980) {
        leds[i]=CRGB::White;
      }
    }
    int dec=1;
    pixArray.applyToword(leds,dec);
    showAndDimBy(10);delay(del);
  }  
  
}





void sparkle(){
  reRand();
  pixArray.applyTo(leds);
  
  int blk=1;
  int wht=930;
  
  long long startT=millis();
  for (int loopC=0; millis()<startT+20000; loopC++ ) {
    for (int i = 0; i < pixArray.getActivePIX(); i++) {
      int n =  random(1000);
      if (n<blk){
        pixArray.setSingleValue(CRGB::Black,i);
        //if (blk<wht) blk+=1;
      }
      else if(n>=wht) {
        pixArray.sparkleSingleWhite(leds,i);
        //if (wht<990) wht+=10;
      }      
    }

    if (loopC%100==20 && blk<wht) blk+=5;
    
    if (loopC%30==20 && wht<990) wht+=10;
    else if (loopC%10==9 && wht>= 990 && wht<1000) wht+=1;
    
    /*Serial.print("wht: ");
    Serial.print(wht);
    Serial.print("\t\tblk: ");
    Serial.println(blk);*/
    
    showAndDimBy(16); 
    pixArray.applyTo(leds);
    delay(50);
  }


  
}







void fireworksClear(){

  int activeLeds=NUM_LEDS;
  
  pixArray.setActivePIX(activeLeds);
  reRand();
  pixArray.dimAllRed(50);
  showAndClear(); delay(20);

  //del*loops=time mS
  int del=1;
  long long startT = millis();
  while(millis()<startT+7000){
    
    for(int i=0; i<activeLeds; i++){
      if (random(10000)>9250) {
        leds[i]=CRGB::White;
      }
    }
    int dec=1;
    pixArray.applyToword(leds,dec);
    showAndClear(); delay(del);
  }  


  
}

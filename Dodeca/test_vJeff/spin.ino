


/////////////////////////////////////
//SPIN ARRAY IN A SINGLE BLOCK
void spinArray() {
  int activeLeds=500; int del=1;
  if (activeLeds > 0 ) pixArray.setActivePIX(activeLeds);
  else pixArray.setAtLeastActivePIX();//Random number of pixels
  pixArray.setIndexToIndex();

  if (pixArray.isBlack()) pixArray.interpolateValue(CRGB::Cyan,CRGB::Pink);
  //20*128 = 2.5 sec
  for (int i = 0; i < NUM_LEDS; i++) {
    pixArray.addToIndex(1);
    pixArray.applyTo(leds);
    showAndClear(); delay(del);
  }
}


void testFixBlack(){
  pixArray.setAtLeastActivePIX();//Random number of pixels
  pixArray.spreadEvenly();
  pixArray.setValue(CRGB::Black);
  spinEvenly();
}



/////////////////////////////////////
//Spread ARRAY then spin it
void spinEvenly() {
  int activeLeds=-1; 
  int del=20;
  
  if (activeLeds > 0 ) pixArray.setActivePIX(activeLeds);
  else pixArray.setAtLeastActivePIX();//Random number of pixels
  pixArray.spreadEvenly();
  if (pixArray.isBlack()) pixArray.interpolateRand();
  //20*128 = 2.5 sec

  long long startT=millis();
  while(millis()<startT+10000) {
    pixArray.addToIndex(1);
    pixArray.applyTo(leds);
    showAndClear(); delay(del);
  }
}


void spinEvenlySlowing() {
  int spinRate=1; int activeLeds=-1;
  if (activeLeds > 0 ) pixArray.setActivePIX(activeLeds);
  else pixArray.setAtLeastActivePIX();//Random number of pixels
  if (pixArray.isBlack()) pixArray.interpolateRand();
  pixArray.spreadEvenly();
  //20*128 = 2.5 sec


  int VARdelay =10;
  long long startT=millis();
  while(millis()<startT+3000){
    pixArray.addToIndex(spinRate);
    pixArray.applyTo(leds);
    showAndClear(); delay(VARdelay);
  }

  for (; VARdelay < 200; VARdelay++) {
    pixArray.addToIndex(spinRate);
    pixArray.applyTo(leds);
    showAndClear(); delay(VARdelay);

    if (VARdelay > 100)VARdelay +=5;
  }
  delay(500);
}

void spinEvenlyQuickening() {
  int spinRate=1; int activeLeds=180;
  if (activeLeds > 0 ) pixArray.setActivePIX(activeLeds);
  else pixArray.setAtLeastActivePIX();//Random number of pixels
  if (pixArray.isBlack()) pixArray.interpolateRand();
  pixArray.spreadEvenly();
  //20*128 = 2.5 sec

  int VARdelay = 200;
  for (;VARdelay > 0; ) {
    static int loopC=0;
    pixArray.addToIndex(spinRate);
    pixArray.applyTo(leds);
    showAndClear(); delay(VARdelay);
    if (VARdelay > 100)VARdelay -=5;
    else if (VARdelay > 50) VARdelay --;
    else if (VARdelay > 25 && loopC++%5==0) VARdelay --;
    else if (VARdelay > 10 && loopC++%25==0) VARdelay --;
    else if (VARdelay > 4 && loopC++%125==0) VARdelay --;
    else if (loopC++%200==0) VARdelay --;
    Serial.println(VARdelay);
  }


  long long startT=millis();
  while(millis()<startT+7000){
    pixArray.addToIndex(spinRate);
    pixArray.applyTo(leds);
    showAndClear(); delay(VARdelay);
  }

  startT=millis();
  while(millis()<startT+10000){
    pixArray.addToIndex(spinRate);
    pixArray.applyTo(leds);
    showAndDimBy(5); delay(VARdelay);
  }
  
  delay(500);
}

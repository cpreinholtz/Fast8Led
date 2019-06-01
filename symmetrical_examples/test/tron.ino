
/////////////////////////////////////
//Spread ARRAY then spin it
void spinEvenlyInGroupsOf(int activeLeds, int numGroups) {
  if (activeLeds > 0 ) pixArray.setActivePIX(activeLeds);
  else pixArray.setAtLeastActivePIX();//Random number of pixels

  pixArray.setValue(CRGB::Cyan);

  pixArray.spreadEvenlyInGroupsOf(numGroups);
  pixArray.applyTo(leds);
  showAndClear(); delay(1000);

  //spin while quickening
  for (int i = 200; i > 5;  ) {
    pixArray.addToIndex(1);
    pixArray.applyTo(leds);
    showAndClear(); delay(i);
    if (i>100) i-=20;
    else if (i>20) i-=5;
    else i--;    
  }



  //divide numgroups till single
  while (numGroups > 0) {


    pixArray.applyTo(leds);
    showAndClear(); delay(20);

    //takes about 12 sec each for full num leds
    for (int i = 0; i < NUM_LEDS/2; i++) {
      pixArray.addToIndex(1);
      pixArray.applyTo(leds);
      showAndClear(); delay(5);
    }

    numGroups = numGroups / 2;
    if (numGroups > 0)pixArray.spreadEvenlyInGroupsOf(numGroups);
  }

  //spin slw (darastic slow)
  long long startT=millis();
  for (int i = 20; millis()<startT+10000; ) {
    pixArray.addToIndex(1);
    pixArray.applyTo(leds);
    showAndClear(); delay(i);
  }
  
  //spin while quickening (darastic slow)
  for (int i = 20; i >= 0; ) {
    static int loopC = 0;
    pixArray.addToIndex(1);
    pixArray.applyTo(leds);
    showAndClear(); delay(i);
    if (loopC++ % 50 == 0 ) i--;
  }


  //spin while slowing
  for (int i = 0; i < 60; ) {
    static int loopC = 1;
    pixArray.addToIndex(1);
    pixArray.applyTo(leds);
    showAndClear(); delay(i);
    if (i < 20 && loopC++ % 50 == 0 ) i++;
    else if (i >= 20 && i < 50 && loopC++ % 15 == 0 )i++;
    else if (i >= 50)i++;
  }

//spin while quickening
for (int i = 80; i > 15; i--) {
    pixArray.addToIndex(1);
    pixArray.applyTo(leds);
    showAndClear(); delay(i);
  }


  //squish to 0
  while (pixArray.squishIndexTowords(NUM_LEDS - 1) > 0) {
    pixArray.applyTo(leds);
    showAndClear(); delay(15);
  }


  //squish to Spread
  while (pixArray.squishIndexTowordsSpreadEvenly() > 0) {
    pixArray.applyTo(leds);
    showAndClear(); delay(2);
  }


  ////////////////////
  //ADD SPARKLE HERE


  int statT=millis();
  int blk=100;
  int wht=800;
  for (int i = 0; millis()<startT+4000; i++) {
    for (int i = 0; i < pixArray.getActivePIX(1); i++) {
      int n =  random(1000);
      if (n<blk){
        pixArray.sparkleSingleBlack(leds,i);
        if (blk<wht) blk++;
      }
      else if(n>=wht) {
        pixArray.sparkleSingleWhite(leds,i);
        if (wht<990) wht++;
      }      
    }
    pixArray.applyTo(leds);
    showAndDim(); delay(5);
  }
  





  

  pixArray.applyTo(leds);
  showAndClear(); delay(800);

  for (int i = 0; i < 255; i++) {
    pixArray.dimAll(1);
    pixArray.applyTo(leds);
    showAndClear(); delay(20);
  }

  pixArray.applyTo(leds);
  showAndClear(); delay(5000);

}




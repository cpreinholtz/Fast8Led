


/////////////////////////////////////
//SPIN ARRAY IN A SINGLE BLOCK
void spinArray(int activeLeds) {
  if (activeLeds > 0 ) pixArray.setActivePIX(activeLeds);
  else pixArray.setAtLeastActivePIX();//Random number of pixels

  pixArray.setIndexToIndex();
  showAndClear(); delay(20);
  //20*128 = 2.5 sec
  for (int i = 0; i < NUM_LEDS; i++) {
    pixArray.addToIndex(1);
    pixArray.applyTo(leds);
    showAndClear(); delay(20);
  }
}





/////////////////////////////////////
//Spread ARRAY then spin it
void spinEvenly(int activeLeds) {
  if (activeLeds > 0 ) pixArray.setActivePIX(activeLeds);
  else pixArray.setAtLeastActivePIX();//Random number of pixels

  pixArray.spreadEvenly();
  showAndClear(); delay(20);
  //20*128 = 2.5 sec
  for (int i = 0; i < NUM_LEDS; i++) {
    pixArray.addToIndex(1);
    pixArray.applyTo(leds);
    showAndClear(); delay(20);
  }
}


/////////////////////////////////////
//Spread ARRAY then spin it
void spinEvenlyInGroupsOf(int activeLeds, int numGroups) {
  if (activeLeds > 0 ) pixArray.setActivePIX(activeLeds);
  else pixArray.setAtLeastActivePIX();//Random number of pixels

  pixArray.setValue(CRGB::Cyan);

  pixArray.spreadEvenlyInGroupsOf(numGroups);
  pixArray.applyTo(leds);
  showAndClear(); delay(5000);

  //spin while quickening
  for (int i = 500; i > 100; i -= 20 ) {
    pixArray.addToIndex(1);
    pixArray.applyTo(leds);
    showAndClear(); delay(i);
  }

  //spin while quickening
  for (int i = 100; i > 20; i-- ) {
    pixArray.addToIndex(1);
    pixArray.applyTo(leds);
    showAndClear(); delay(i);
  }

  //divide numgroups till single
  while (numGroups > 0) {


    pixArray.applyTo(leds);
    showAndClear(); delay(20);

    //20*128 = 2.5 sec
    for (int i = 0; i < NUM_LEDS; i++) {
      pixArray.addToIndex(1);
      pixArray.applyTo(leds);
      showAndClear(); delay(20);
    }

    numGroups = numGroups / 2;
    if (numGroups > 0)pixArray.spreadEvenlyInGroupsOf(numGroups);
  }

  //spin while quickening
  for (int i = 20; i > 1; ) {
    static int loopC = 0;
    pixArray.addToIndex(1);
    pixArray.applyTo(leds);
    showAndClear(); delay(i);
    if (loopC++ % 50 == 0 ) i--;
  }


  //spin while slowing
  for (int i = 1; i < 80; ) {
    static int loopC = 0;
    pixArray.addToIndex(1);
    pixArray.applyTo(leds);
    showAndClear(); delay(i);
    if (i < 20 && loopC++ % 50 == 0 ) i++;
    else if (i >= 20 && i < 50 && loopC++ % 15 == 0 )i++;
    else if (i >= 50)i++;
  }

//spin while quickening
for (int i = 80; i > 20; i--) {
    pixArray.addToIndex(1);
    pixArray.applyTo(leds);
    showAndClear(); delay(i);
  }



  //squish to 0
  while (pixArray.squishIndexTowords(NUM_LEDS - 1) > 0) {
    pixArray.applyTo(leds);
    showAndClear(); delay(20);
  }


  //squish to Spread
  while (pixArray.squishIndexTowordsSpreadEvenly() > 0) {
    pixArray.applyTo(leds);
    showAndClear(); delay(20);
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



void spinEvenlySlowing(int spinRate, int activeLeds) {
  if (activeLeds > 0 ) pixArray.setActivePIX(activeLeds);
  else pixArray.setAtLeastActivePIX();//Random number of pixels

  pixArray.spreadEvenly();
  showAndClear(); delay(20);
  //20*128 = 2.5 sec

  for (int VARdelay = 20; VARdelay < 80; VARdelay++) {
    pixArray.addToIndex(spinRate);
    pixArray.applyTo(leds);
    showAndClear(); delay(VARdelay);
  }
}

void spinEvenlyQuickening(int spinRate, int activeLeds) {
  if (activeLeds > 0 ) pixArray.setActivePIX(activeLeds);
  else pixArray.setAtLeastActivePIX();//Random number of pixels

  pixArray.spreadEvenly();
  showAndClear(); delay(20);
  //20*128 = 2.5 sec

  for (int VARdelay = 80; VARdelay > 20; VARdelay++) {
    pixArray.addToIndex(spinRate);
    pixArray.applyTo(leds);
    showAndClear(); delay(VARdelay);
  }
}




void doubleSpinSaturated() {

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

  int dimBy = 10 + random(10);
  //30*80= 2.4sec
  for (int i = 0; i < 160; i++) {
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





void doubleSpin() {

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

  int dimBy = 10 + random(10);
  //30*80= 2.4sec
  for (int i = 0; i < 160; i++) {
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




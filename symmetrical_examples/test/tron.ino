
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
  for (int i = 200; i > 100; i -= 20 ) {
    pixArray.addToIndex(1);
    pixArray.applyTo(leds);
    showAndClear(); delay(i);
  }

  //spin while quickening
  for (int i = 100; i > 20; i-=5 ) {
    pixArray.addToIndex(1);
    pixArray.applyTo(leds);
    showAndClear(); delay(i);
  }

    //spin while quickening
  for (int i = 100; i > 5; i-- ) {
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
      showAndClear(); delay(5);
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




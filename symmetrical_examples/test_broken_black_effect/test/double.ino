

void doubleSpinSaturated(int dimBy,int del,int num_leds) {

  //purple array
  pixArray.setActivePIX(num_leds +random(10));
  pixArray.setValue(CRGB::Blue);
  pixArray.spreadEvenly();

  //green pix
  pixArray2.setActivePIX(num_leds+5 +random(10));
  pixArray2.setValue(CRGB::Green);
  pixArray2.spreadEvenly();



  dimBy +=  random(10);
  long long startT=millis();
  

  while (millis()<startT+10000) {    
    pixArray.addToIndex(1);//spin array +
    pixArray2.addToIndex(-1);    //spin pix -

    pixArray.applyTo(leds);
    pixArray2.applyTo(leds);
    show(); 
    dimAll(dimBy);
    delay(del);
  }
}





void doubleSpin(int dimBy,int del) {

  //purple array
  pixArray.setActivePIX(7);//was 5
  pixArray.setValue(CRGB::Red);
  pixArray.spreadEvenly();

  //green pix
  pixArray2.setActivePIX(7);
  pixArray2.setValue(CRGB::Blue);
  pixArray2.spreadEvenly();

  //dimBy +=  random(10);
  long long startT=millis();  

  while (millis()<startT+10000) {
    pixArray.addToIndex(1);
    pixArray2.addToIndex(-1);

    pixArray.applyToAdditive(leds);
    pixArray2.applyToAdditive(leds);
    show(); dimAll(dimBy);
    delay(del);
  }

  //reRand();

}

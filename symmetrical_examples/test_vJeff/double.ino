

void doubleSpinSaturated() {
int dimBy=10;
int del=20;
int num_leds=80;

  //purple array
  pixArray.setActivePIX(num_leds +random(10));
  pixArray.setValue(CRGB::Purple);
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

    pixArray.applyToAdditive(leds);
    pixArray2.applyToAdditive(leds);
    show(); 
    dimAll(dimBy);
    delay(del);
  }
}





void doubleSpin() {
int dimBy =3; int del=15;
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

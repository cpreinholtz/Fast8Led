





/////////////////////////////////////
//SPIN ARRAY IN A SINGLE BLOCK
void interpolate(CRGB from,  CRGB to ) {
  
  pixArray.setActivePIX(140);//Random number of pixels
  pixArray.spreadEvenly();

  pixArray.interpolateValue(from,to);

  long long startT=millis();
  for (int i = 0; millis()<startT+10000; i++) {
    pixArray.addToIndex(1);
    pixArray.applyTo(leds);
    showAndClear(); delay(20);
  }
}


void interpolateRedToCyan(){
  interpolate(CRGB::Red, CRGB::Cyan); 
}

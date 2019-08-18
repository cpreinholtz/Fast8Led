


/////////////////////////////////////
//SPIN ARRAY IN A SINGLE BLOCK
void moveUp(int del, long long loopMillis) {
    if (pixArray.isBlack()) pixArray.interpolateRand();

  long long statT=millis();
  while(millis()<loopMillis+statT) {
    pixArray.addToIndex(1);
    pixArray.applyTo(leds);
    showAndClear(); delay(del);
  }
}

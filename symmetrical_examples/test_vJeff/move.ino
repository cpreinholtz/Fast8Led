


/////////////////////////////////////
//SPIN ARRAY IN A SINGLE BLOCK
void moveUp(int del, long long loopMillis) {

  long long statT=millis();
  while(millis()<loopMillis+statT) {
    pixArray.addToIndex(1);
    pixArray.applyTo(leds);
    showAndClear(); delay(del);
  }
}

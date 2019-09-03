
void octodemo() {
  long long startT=millis();
  while(millis()<startT+10000){
    static uint8_t hue = 0;
    for(int i = 0; i < NUM_STRIPS; i++) {
      for(int j = 0; j < NUM_LEDS_PER_STRIP; j++) {
        leds[(i*NUM_LEDS_PER_STRIP) + j] = CHSV((32*i) + hue+j,192,255);
      }
    }
  
    // Set the first n leds on each strip to show which strip it is
    for(int i = 0; i < NUM_STRIPS; i++) {
      for(int j = 0; j <= i; j++) {
        leds[(i*NUM_LEDS_PER_STRIP) + j] = CRGB::Red;
      }
    }
  
    hue++;
  
    LEDS.show();
    LEDS.delay(10);
  }
}

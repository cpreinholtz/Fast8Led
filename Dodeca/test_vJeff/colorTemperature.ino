


#define TEMPERATURE_1 Tungsten100W
#define TEMPERATURE_2 OvercastSky

// How many seconds to show each temperature before switching
#define DISPLAYTIME 20
// How many seconds to show black between switches





void colortemperature(){

  long long startT=millis();
  long long onT=40000;
  while(millis()<startT+onT){
    
    
    // draw a generic, no-name rainbow
    static uint8_t starthue = 0;
    fill_rainbow( leds + 5, NUM_LEDS - 5, --starthue, 20);
  
    // Choose which 'color temperature' profile to enable.
    uint8_t secs = (millis() / 1000) % (DISPLAYTIME * 2);
    if( secs < DISPLAYTIME) {
      FastLED.setTemperature( TEMPERATURE_1 ); // first temperature
      leds[0] = TEMPERATURE_1; // show indicator pixel
    } else {
      FastLED.setTemperature( TEMPERATURE_2 ); // second temperature
      leds[0] = TEMPERATURE_2; // show indicator pixel
    }
  

    FastLED.show();
    FastLED.delay(8);
  }

}

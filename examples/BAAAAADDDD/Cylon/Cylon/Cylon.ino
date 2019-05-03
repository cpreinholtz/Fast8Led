#define USE_OCTOWS2811
#include <OctoWS2811.h>
#include <FastLED.h>
#define NUM_LEDS_PER_STRIP 16
#define NUM_STRIPS 8
// How many leds in your strip?




// Define the array of leds
CRGB leds[NUM_LEDS_PER_STRIP*NUM_STRIPS];

void setup() { 
	Serial.begin(57600);
	Serial.println("resetting");
	LEDS.addLeds<OCTOWS2811>(leds,NUM_LEDS_PER_STRIP);
  LEDS.addLeds<OCTOWS2811>(leds,NUM_LEDS_PER_STRIP);
	LEDS.setBrightness(84);
}

void fadeall() { 
  for(int i = 0; i < NUM_STRIPS; i++) {
      for(int j = 0; j < NUM_LEDS_PER_STRIP; j++) {
    leds[(i*NUM_LEDS_PER_STRIP) + j].nscale8(250); 
  } }
}

void loop() { 
	static uint8_t hue = 0;
	Serial.print("x");
	// First slide the led in one direction
	for(int i = 0; i < NUM_STRIPS; i++) {
    for(int j = 0; j < NUM_LEDS_PER_STRIP; j++) {
		// Set the i'th led to red 
		leds[(i*NUM_LEDS_PER_STRIP) + j] = CHSV(hue++%256, 255, 255);
    
		// Show the leds
		LEDS.show(); 
		// now that we've shown the leds, reset the i'th led to black
		// leds[i] = CRGB::Black;
		fadeall();
		// Wait a little bit before we loop around and do it again
		delay(10);
	}}
	Serial.print("x");

	// Now go in the other direction.  
	for(int i = 0; i < NUM_STRIPS; i++) {
	  for(int j = (NUM_LEDS_PER_STRIP)-1; j >= 0; j--) {
	
	
		// Set the i'th led to red 
		leds[(i*NUM_LEDS_PER_STRIP) + j] = CHSV(hue++%256, 255, 255);
    
		// Show the leds
		LEDS.show();
		// now that we've shown the leds, reset the i'th led to black
		// leds[i] = CRGB::Black;
		fadeall();
		// Wait a little bit before we loop around and do it again
		delay(10);
	}}
}

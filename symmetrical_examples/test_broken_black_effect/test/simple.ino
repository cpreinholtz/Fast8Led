
void showSimple(){
  for ( int i=0; i<NUM_LEDS;i++){
    //if (i%2==0) 
    leds[i]=CRGB::White;

  }
  LEDS.show();

}



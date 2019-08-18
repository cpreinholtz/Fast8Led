void testFixBlack(){
  pixArray.setAtLeastActivePIX();//Random number of pixels
  pixArray.spreadEvenly();
  pixArray.setValue(CRGB::Black);
  spinEvenly();
}

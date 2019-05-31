
void flashAsIs(int numFlashes, int timeOn, int timeOff){

  for (int flash=0; flash<numFlashes; flash++){
    pixArray.applyTo(leds); 
    showAndClear();   
    delay(timeOn);
    
    show();//off
    delay(timeOff);
  }
  
}




void flashAllVal(int numFlashes, int timeOn, int timeOff, CRGB val){
  pixArray.setAllActivePIX();
  pixArray.setIndexToIndex();
  pixArray.setValue(val);
  flashAsIs(numFlashes, timeOn, timeOff);
}


void flashWarning(){
  flashAllVal(10,50,50,CRGB::Red);//flashes, timeon timeoff, val
  delay(1000);
  flashAsIs(3,1000,300);//flashes, timeon timeoff  
}


void flashRedFast(){
  flashAllVal(40,50,50,CRGB::Red);//flashes, timeon timeoff, val
}

void flashRedSuperFast(){
  flashAllVal(50,25,25,CRGB::Red);//flashes, timeon timeoff, val
}

void flashRandWithRedFast(){
  flashRand();
  flashRedFast();
}

void flashRand(){
  long long startT=millis();
  for(;millis()<startT+10000;){
    CRGB temp;
    temp.r=random8();
    temp.b=random8();
    temp.g=random8();
  
    //120 BPM
    flashAllVal(1,200,200,temp);//flashes, timeon timeoff, val
  }

}


/*


void flashWhite(int numFlashes){
  delay(1);
}


void flashAllRand(int numFlashes){
  delay(1);
}

void flashRand(int numFlashes){
  delay(1);
} 
*/



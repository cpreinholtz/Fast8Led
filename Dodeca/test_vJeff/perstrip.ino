

void perStrip(){


  pixArray.setActivePIX(194);
  pixArray.setValue(CRGB::MidnightBlue); 
  pixArray.useSingleStripIndexing();
  pixArray.setIndexToIndex(); 

 
  pixArray2.setActivePIX(16);
  pixArray2.setValue(CRGB::White); 
  pixArray2.useSingleStripIndexing(); 
  pixArray2.spreadEvenlyInGroupsOf(2); 
  

  
  pixArray.applyTo(leds); 
  pixArray2.applyTo(leds);
  showAndClear(); delay(80);
 

  //for max=arraylen*2^i
  //8*2^4=8*16=128

  int dimBy=10+random(10);
  //30*80= 2.4sec
  for(int i=0; i<160; i++){

    pixArray2.divergeIndex();
    
    pixArray.applyToAllStrips(leds); 
    pixArray2.applyToAllStrips(leds);
    show(); dimAll(dimBy);
    delay(50);
  }

  //reRand();
  pixArray.useAbsoluteIndexing();
  pixArray2.useAbsoluteIndexing();
  
}




//has a wierd purple flash every 16
void perStripAdditive(){



  pixArray.setActivePIX(194);
  pixArray.setValue(CRGB::MidnightBlue); 
  pixArray.useSingleStripIndexing();
  pixArray.setIndexToIndex(); 

 
  pixArray2.setActivePIX(16);
  pixArray2.setValue(CRGB::Teal); 
  pixArray2.useSingleStripIndexing(); 
  pixArray2.spreadEvenlyInGroupsOf(2); 
  


  showAndClear(); delay(80);
 

  //for max=arraylen*2^i
  //8*2^4=8*16=128
  pixArray.applyToAllStrips(leds); 
  int dimBy=10+random(10);
  //30*80= 2.4sec
  for(int i=0; i<160; i++){
    

    pixArray2.divergeIndex();
    

    pixArray2.applyToAllStripsAdditive(leds);
    show(); dimAll(dimBy);
    delay(50);
    if (i%32==31){
      
      pixArray2.dimAllRed(-30);
      pixArray2.dimAllBlue(30);      
    }
    if (i%16==15) pixArray.applyToAllStrips(leds);
    
  }

  //reRand();
  pixArray.useAbsoluteIndexing();
  pixArray2.useAbsoluteIndexing();
}


void perStripPersistentAdditive(){



  pixArray.setActivePIX(194);
  pixArray.setValue(CRGB::MidnightBlue); 
  pixArray.useSingleStripIndexing();
  pixArray.setIndexToIndex(); 

 
  pixArray2.setActivePIX(16);
  pixArray2.setValue(CRGB::Teal); 
  pixArray2.useSingleStripIndexing(); 
  pixArray2.spreadEvenlyInGroupsOf(2); 
  



  //for max=arraylen*2^i
  //8*2^4=8*16=128
  pixArray.applyToAllStrips(leds); 
  int dimBy=5;
  //30*80= 2.4sec

  long long startT=millis();  

  while (millis()<startT+10000){
    static int i=0;
  
    

    pixArray2.divergeIndex();
    

    pixArray2.applyToAllStripsAdditive(leds);
    show(); dimAll(dimBy);
    delay(50);
    if (i%32==31){      
      pixArray2.dimAllRed(-30);
      pixArray2.dimAllBlue(30); 
      pixArray.applyToAllStrips(leds);
    }


    i++;
  }

  //reRand();
  pixArray.useAbsoluteIndexing();
  pixArray2.useAbsoluteIndexing();
}






void perStripPersistent(){



  pixArray.setActivePIX(194);
  pixArray.setValue(CRGB::MidnightBlue); 
  pixArray.useSingleStripIndexing();
  pixArray.setIndexToIndex(); 

 
  pixArray2.setActivePIX(16);
  pixArray2.setValue(CRGB::Teal); 
  pixArray2.useSingleStripIndexing(); 
  pixArray2.spreadEvenlyInGroupsOf(2); 
  



  //for max=arraylen*2^i
  //8*2^4=8*16=128
  pixArray.applyToAllStrips(leds); 
  int dimBy=3+random(3);
  //30*80= 2.4sec

  long long startT=millis();  

  while (millis()<startT+10000){
    static int i=0;
  
    

    pixArray2.divergeIndex();
    

    pixArray2.applyToAllStrips(leds);
    show(); dimAll(dimBy);
    delay(50);
    if (i%32==31){      
      pixArray2.dimAllRed(-30);
      pixArray2.dimAllBlue(30);
      pixArray2.dimAllGreen(10); 
      pixArray.applyToAllStrips(leds);
    }


    i++;
  }

  //reRand();
  pixArray.useAbsoluteIndexing();
  pixArray2.useAbsoluteIndexing();
}

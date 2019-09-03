
//nice pink and orange
void chase(){

  pixArray.useSingleStripIndexing();
  pixArray.setActivePIX(18);//  
   
  
  pixArray.spreadEvenlyInGroupsOf(3); 

  //for max=arraylen*2^i
  //8*2^4=8*16=128

  int dimBy=10+random(10);
  int del=20;
  //30*80= 2.4sec
  long long startT=millis();
  while(startT+5000>millis()){
  
    for(int i=0; i<8; i++){

      switch(i){
        //purp, yel, orange, yell, pink
        case 0:
          pixArray.setValue(CRGB::Purple);
          break;        
        case 1:
          pixArray.setValue(CRGB::Purple);
          break;
        //purp, yel, orange, yell, pink
        case 2:
          pixArray.setValue(CRGB::Orange);
          break;        
        case 3:
          pixArray.setValue(CRGB::Pink);
          break;
        case 4:
          pixArray.setValue(CRGB::Pink);
          break;
        case 5:
          pixArray.setValue(CRGB::Orange);
          break;
        case 7:
          pixArray.setValue(CRGB::Purple);
          break;
        case 6:
          pixArray.setValue(CRGB::Orange);
          break;
      }      
      pixArray.applyToStrip(leds,i);   
          
    }
    
    show(); dimAll(dimBy);
    delay(del);
    pixArray.addToIndex(1);
        
  }


  //reRand();
  pixArray.useAbsoluteIndexing();
  pixArray2.useAbsoluteIndexing();
  
}







void chase2(){

  pixArray.useSingleStripIndexing();
  pixArray.setActivePIX(18);
  pixArray.setValue(CRGB::MidnightBlue);
   
  
  pixArray.spreadEvenlyInGroupsOf(3); 

  //for max=arraylen*2^i
  //8*2^4=8*16=128

  int dimBy=10+random(5);
  int del=20;
  //30*80= 2.4sec
  long long startT=millis();
  while(startT+5000>millis()){
  
    for(int strip=0; strip<8; strip++){
      int i=random(8);

      switch(i){
      //purp, yel, orange, yell, pink
      case 0:
        pixArray.setValue(CRGB::Purple);
        break;        
      case 1:
        pixArray.setValue(CRGB::Purple);
        break;
      //purp, yel, orange, yell, pink
      case 2:
        pixArray.setValue(CRGB::Orange);
        break;        
      case 3:
        pixArray.setValue(CRGB::Pink);
        break;
      case 4:
        pixArray.setValue(CRGB::Pink);
        break;
      case 5:
        pixArray.setValue(CRGB::Orange);
        break;
      case 7:
        pixArray.setValue(CRGB::Purple);
        break;
      case 6:
        pixArray.setValue(CRGB::Orange);
        break;
      }  //switch  
    
      pixArray.applyToStrip(leds,strip); 

    }   //for loop strips      
      
      showAndDimBy(dimBy);
      delay(del);
      pixArray.addToIndex(1);     
  }

  //reRand();
  pixArray.useAbsoluteIndexing();
  pixArray2.useAbsoluteIndexing();
  
}

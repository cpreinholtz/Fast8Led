void allEffects(int e) { 
  for (int i=0;i<100;i++)
    showEffect(random(i));
}

void randEffect(int e) { 
  showEffect(random(100));
}

void showEffect(int e) { 

  e=e%30;//?  set to max effects

  switch (e){

    ///////////////////
    //White dims
    case 0:
      whiteDim();
      break;
    case 1:
      whiteRandDim();
      break;
    case 2:
      whiteRandDimToGlow();
      break;

      
    case 3:
      spinArray(8);//Active LEDS?  make prop to NUM _LEDS//speed up
      break;
    case 4:
      spinEvenly(-1);
      break;
    case 5:
      spinEvenlySlowing(1,-1);
      break;

  

      
    case 6:
      spinEvenlyInGroupsOf(128,32);
      break;
      
    case 7:
      perStripAdditive();//?????
      break;

      
    case 8:
      fireworks(NUM_LEDS/2);
      break;
    case 9:
      fireworks(NUM_LEDS);
      break;
      case 10:
      fireworksClear(NUM_LEDS);
      break;

      
    case 11:
      strobeStrip();
      break;
    case 12:
      strobeColor();
      break;
    case 13:
      strobeColorQuickening();
      break;   
         
    case 14:
      chase();//purple and orange
      break;

    case 15:      
      doubleSpin();
      break;
    case 16:      
      doubleSpinSaturated();
      break;



    case 17:
      pulse();
      break;

     case 18:
      loopPalette();//rand pallete
      break;

     case 19:
      perStrip();
      break;
     case 20:
      perStripAdditive();
      break;




     case 0:
 
      break;

     case 0:
 
      break;

     case 0:
 
      break;
      

  }
   
}

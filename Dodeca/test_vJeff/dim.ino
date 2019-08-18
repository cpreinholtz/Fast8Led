
///////////////////////////////////////////////
//Single Color Single index
void dimRed(int i,  int dimBy){
    if (dimBy<1) dimBy=1;
    if (leds[i].r>= dimBy)  leds[i].r= leds[i].r-dimBy;
    else leds[i].r=0;
}
void dimGreen(int i,  int dimBy){
    if (dimBy<1) dimBy=1;
    if (leds[i].g>= dimBy)  leds[i].g= leds[i].g-dimBy;
    else leds[i].g=0;
}
void dimBlue(int i,  int dimBy){
    if (dimBy<1) dimBy=1;
    if (leds[i].b>= dimBy)  leds[i].b= leds[i].b-dimBy;
    else leds[i].b=0;
}

////////////////////////////////////////////
//All colors single index
void dim(int i,  int dimBy){
  dimRed(i,  dimBy);dimGreen(i,  dimBy);dimBlue(i,  dimBy);
}

////////////////////////////////////////////
//All indecies all colors
void dimAll( int dimBy){
  for(int i = 0; i < NUM_LEDS; i++) {
    dim(i,  dimBy);
  }
}



/////////////////////////////////////////////
//Single index Random color
void dimRandColor(int i, int dimBy){
  int col = random(3);  
  switch(col){
    case 0:
      dimRed(i,  dimBy);break;
    case 1:
      dimGreen(i,  dimBy);break;
    case 2:
      dimBlue(i,  dimBy);break;      
  }  
}

/////////////////////////////////////////////
//All indecies Random colors
void dimAllRandColor( int dimBy){
  for(int i = 0; i < NUM_LEDS; i++) {
    dimRandColor(i,dimBy);
  }
}

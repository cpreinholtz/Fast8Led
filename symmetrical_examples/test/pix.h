#ifndef pix_h
#define pix_h
#include <FastLED.h>
#include <Arduino.h>
#define NUM_LEDS 10




class Pix{
public:
  Pix(int num_leds){

    _NUM_LEDS=num_leds;
    _ACTIVE_INDEX=_NUM_LEDS;
    index=0;
    value=CRGB::Black;// CHSV(0,0,0);      
  };
  
  Pix(){
    _NUM_LEDS=NUM_LEDS;
    _ACTIVE_INDEX=_NUM_LEDS;
    index=0;
    value=CRGB::Black;// CHSV(0,0,0);      
  };


  void applyTo(CRGB *led_array){
    if (led_array[index].r==0)led_array[index].r=value.r;
    else led_array[index].r= led_array[index].r/2+ value.r/2;

    if (led_array[index].g==0)led_array[index].g=value.g;
    else led_array[index].g= led_array[index].g/2+ value.g/2;
    
     if (led_array[index].b==0)led_array[index].b=value.b;
    else led_array[index].b= led_array[index].b/2+ value.b/2;
  };

  void applyToStrip(CRGB *led_array,int strip){
    strip=strip%8;
    int i=normalize(strip*_ACTIVE_INDEX + index);
    
    if (led_array[i].r==0)led_array[i].r=value.r;
    else led_array[i].r= led_array[i].r/2+ value.r/2;

    if (led_array[i].g==0)led_array[i].g=value.g;
    else led_array[i].g= led_array[i].g/2+ value.g/2;
    
     if (led_array[i].b==0)led_array[i].b=value.b;
    else led_array[i].b= led_array[i].b/2+ value.b/2;
  };

  void applyToStripAdditive(CRGB *led_array,int strip){
    strip=strip%8;
    int i=normalize(strip*_ACTIVE_INDEX + index);
    
    if (led_array[i].r==0)led_array[i].r=value.r;
    else if ( (int)led_array[i].r+ (int)value.r <=255 ) led_array[i].r+= value.r;
    else led_array[i].r = 255;

    if (led_array[i].g==0)led_array[i].g=value.g;
    else if ( (int)led_array[i].g+ (int)value.g <=255 ) led_array[i].g+= value.g;
    else led_array[i].g = 255;
    
    if (led_array[i].b==0)led_array[i].b=value.b;
    else if ( (int)led_array[i].b+ (int)value.b <=255 ) led_array[i].b+= value.b;
    else led_array[i].b = 255;
  };
  
  void applyToAdditive(CRGB *led_array){
    if (led_array[index].r==0)led_array[index].r=value.r;
    else if ( (int)led_array[index].r+ (int)value.r <=255 ) led_array[index].r+= value.r;
    else led_array[index].r = 255;

    if (led_array[index].g==0)led_array[index].g=value.g;
    else if ( (int)led_array[index].g+ (int)value.g <=255 ) led_array[index].g+= value.g;
    else led_array[index].g = 255;
    
    if (led_array[index].b==0)led_array[index].b=value.b;
    else if ( (int)led_array[index].b+ (int)value.b <=255 ) led_array[index].b+= value.b;
    else led_array[index].b = 255;
  };

  void applyToword(CRGB *led_array, int decBy){
    if (led_array[index].r==0)led_array[index].r=value.r;
    else if (led_array[index].r>value.r)  led_array[index].r-=decBy;
    else if (led_array[index].r<value.r)  led_array[index].r+=decBy;

    if (led_array[index].g==0)led_array[index].g=value.g;
    else if (led_array[index].g>value.g)  led_array[index].g-=decBy;
    else if (led_array[index].g<value.g)  led_array[index].g+=decBy;
    
    if (led_array[index].b==0)led_array[index].b=value.b;
    else if (led_array[index].b>value.b)  led_array[index].b-=decBy;
    else if (led_array[index].b<value.b)  led_array[index].b+=decBy;
  };

  

  /////////////////////////////////////////
  //IDX 


  void setIndex(int idx){ index=idx; normalizeIndex(); };

  void useSingleStripIndexing(){
    _ACTIVE_INDEX=_NUM_LEDS/8;
    normalizeIndex(); 
  };  
  void useAbsoluteIndexing(){ 
    _ACTIVE_INDEX=_NUM_LEDS; 
    normalizeIndex(); 
  };
  
  int getIndex(){return index;};
  
  void randomIndex(){
    index = random(_NUM_LEDS);      
  };
  
  void subFromIndex(int idx){
    setIndex(index-idx);  
  };

  void addToIndex(int idx){
    setIndex(index+idx);
  };
  
  int squishIndexTowords(int ind){
      if (index> ind){
        setIndex(index-1); 
        return index-ind;        
      } 
      else if (index<ind){
        setIndex(index+1);
        return ind-index;
      }
  };
  
  /////////////////////////////////////////
  //Value
  void setValue(CRGB val){value=val;};
  CRGB getValue(){return value;};
  
  void randomValue(){
    value = CHSV(random(256),random(256),random(256));      
  };


  ///////////////////////////////
  //DIM Single Color Single index
  void dimRed(int dimBy){
      //if (dimBy<1) dimBy=1;
      if (value.r>= dimBy)  value.r= value.r-dimBy;
      else value.r=0;
  }
  void dimGreen(int dimBy){
      //if (dimBy<1) dimBy=1;
      if (value.g>= dimBy)  value.g= value.g-dimBy;
      else value.g=0;
  }
  void dimBlue(int dimBy){
      //if (dimBy<1) dimBy=1;
      if (value.b>= dimBy)  value.b= value.b-dimBy;
      else value.b=0;
  }      
  //////////////////////////
  //All colors single index
  void dim(int dimBy){
    Pix::dimRed(dimBy);
    Pix::dimGreen(dimBy);
    Pix::dimBlue(dimBy);
  }

  //////////////////////////
  //All colors single index
  void dimBrightest(int dimBy){
    if (value.r>value.g && value.r>value.b) Pix::dimRed(dimBy);
    else if (value.g>value.b && value.g>value.r) Pix::dimGreen(dimBy);
    else if (value.b>value.g && value.b>value.r) Pix::dimBlue(dimBy);
    else Pix::dimRandColor(dimBy);
  }

  ////////////////////////////
  //Single index Random Single color
  void dimRandColor( int dimBy){
    int col = random(3);  
    switch(col){
      case 0:
        Pix::dimRed(dimBy);break;
      case 1:
        Pix::dimGreen(dimBy);break;
      case 2:
        Pix::dimBlue(dimBy);break;      
    }  
  }

  
  /////////////////////////////////////////
  //Other
  
  void set_NUM_LEDS(int num){_NUM_LEDS=num;};
  int get_NUM_LEDS(void){ return _NUM_LEDS;};
  

private:
  int _NUM_LEDS;//used in indexing bounds
  int _ACTIVE_INDEX;//used in indexing bounds
  CRGB value;
  int index;
  
  //wraps around if exceeds leds in use (often all leds)
  void normalizeIndex(){
    while (index>=_ACTIVE_INDEX)index=index-_ACTIVE_INDEX;
    while (index<0)index=index+_ACTIVE_INDEX;
  };

    //wraps around if exceeds all leds
  int normalize(int num){
    while (num>=_NUM_LEDS)num=num-_NUM_LEDS;
    while (num<0)num=num+_NUM_LEDS;
    return num;
  };
  
};















template < int ARRAY_LEN >
class PixArray{
public:
  PixArray(int num_leds){
    //_NUM_PIX=ARRAY_LEN;
    _NUM_LEDS=num_leds;
    _ACTIVE_LEDS=_NUM_LEDS;
    _NUM_ACTIVE_PIX=_NUM_PIX;
    for( int i=0; i<_NUM_PIX; i++){      
      arry[i].set_NUM_LEDS(num_leds);
    }
  };

  void applyTo(CRGB *led_array){
    for( int i=0; i<_NUM_ACTIVE_PIX; i++) arry[i].applyTo(led_array);
  };

  void applyToAllStrips(CRGB *led_array){
    for(int strip=0;strip<8;strip++){
      for( int i=0; i<_NUM_ACTIVE_PIX; i++) {
        arry[i].applyToStrip(led_array,strip);
      }
    }
  };
  
  void applyToAllStripsAdditive(CRGB *led_array){
    for(int strip=0;strip<8;strip++){
      for( int i=0; i<_NUM_ACTIVE_PIX; i++) {
        arry[i].applyToStripAdditive(led_array,strip);
      }
    }
  };
  
  void applyToStrip(CRGB *led_array,int strip){
    for( int i=0; i<_NUM_ACTIVE_PIX; i++) {
      arry[i].applyToStrip(led_array,strip%8);
    }
  };
  
  void applyToAdditive(CRGB *led_array){
    for( int i=0; i<_NUM_ACTIVE_PIX; i++) arry[i].applyToAdditive(led_array);
  };
  void applyToword(CRGB *led_array, int decBy=1){
    for( int i=0; i<_NUM_ACTIVE_PIX; i++) arry[i].applyToword(led_array,decBy);
  };

  /////////////////////////////////////////
  //Value  
  CRGB getValue(int ind){
    if (ind<_NUM_LEDS)
      return arry[ind].getValue(); 
    else 
      return CRGB::Black;   
  };  
  
  void setValue(CRGB val){
    for( int i=0; i<_NUM_PIX; i++)  arry[i].setValue(val);
    //clearInactive();
  };

  void setSingleValue(CRGB val, int i){
    arry[i].setValue(val);
    //clearInactive();
  };
  void randomValue(){
    for( int i=0; i<_NUM_PIX; i++)  arry[i].randomValue(); 
    //clearInactive();     
  };


  void clearInactive(){
    for( int i=_NUM_ACTIVE_PIX; i<_NUM_PIX; i++)arry[i].setValue(CRGB::Black);
  };


  ////////////////////////////////////////////
  //DIM All indecies all colors

  void dimAllRed( int dimBy=1){
    for(int i = 0; i < _NUM_ACTIVE_PIX; i++) {
      arry[i].dimRed(dimBy);
    }
  }
  
  void dimAllBlue( int dimBy=1){
    for(int i = 0; i < _NUM_ACTIVE_PIX; i++) {
      arry[i].dimBlue(dimBy);
    }
  }
  
  void dimAllGreen( int dimBy=1){
    for(int i = 0; i < _NUM_ACTIVE_PIX; i++) {
      arry[i].dimGreen(dimBy);
    }
  }

  
  void dimAll( int dimBy=1){
    for(int i = 0; i < _NUM_ACTIVE_PIX; i++) {
      arry[i].dim(dimBy);
    }
  }
  
  /////////////////////////////////////////////
  //DIM All indecies Random colors
  void dimAllRandColor( int dimBy){
    for(int i = 0; i < _NUM_ACTIVE_PIX; i++) {
      arry[i].dimRandColor(dimBy);
    }
  }
    

  void dimAllBrightest(int dimBy=1){
    for(int i = 0; i < _NUM_ACTIVE_PIX; i++)
      arry[i].dimBrightest(dimBy);
  }

  void dimSingleBrightest(int ind, int dimBy=1){
      arry[ind].dimBrightest(dimBy);
  }

  
  //////////////////////////////
  //Index
  
  void randomIndex(){
    for( int i=0; i<_NUM_ACTIVE_PIX; i++)  arry[i].randomIndex();      
  };

  void subFromIndex(int idx){
    for( int i=0; i<_NUM_ACTIVE_PIX; i++)  arry[i].subFromIndex(idx);
  };

  void addToIndex(int idx){
    for( int i=0; i<_NUM_ACTIVE_PIX; i++)  arry[i].addToIndex(idx);   
  };
  
  void squareIndex(){
    for( int i=0; i<_NUM_ACTIVE_PIX; i++)  arry[i].addToIndex(i);   
  };
  
  void divergeIndex(){
    for( int i=0; i<_NUM_ACTIVE_PIX; i++)  
      if (i%2==0) arry[i].addToIndex(1); 
      else   arry[i].addToIndex(-1);
  };
  
  void setAllIndex(int idx){
    for( int i=0; i<_NUM_ACTIVE_PIX; i++)  arry[i].setIndex(idx);   
  };

  void setIndexToIndex(){
    for( int i=0; i<_NUM_ACTIVE_PIX; i++)  arry[i].setIndex(i);   
  };
  
  void spreadEvenly(){
    for( int i=0; i<_NUM_ACTIVE_PIX; i++)  
      arry[i].setIndex(_ACTIVE_LEDS*i/(_NUM_ACTIVE_PIX));   
  };

  int squishIndexTowords(int ind){
    int greatestDiff=0;
    for( int i=0; i<_NUM_ACTIVE_PIX; i++)  {
      int temp=arry[i].squishIndexTowords(ind-_NUM_ACTIVE_PIX+i);
      if (temp>  greatestDiff)greatestDiff=temp;
    }
    return greatestDiff;
  };

  int squishIndexTowordsSpreadEvenly(){
    int greatestDiff=0;
    for( int i=0; i<_NUM_ACTIVE_PIX; i++)  {
      int temp=arry[i].squishIndexTowords(_ACTIVE_LEDS*i/(_NUM_ACTIVE_PIX));
      if (temp>  greatestDiff)greatestDiff=temp;
    }
    return greatestDiff;
  };


  

  void spreadEvenlyInGroupsOf(int ledsPerGroup){

    //_NUM_ACTIVE_PIX=ledsPerGroup*numGroups
    int numGroups=_NUM_ACTIVE_PIX/ledsPerGroup;

    //_NUM_LEDS=groupSpacing*numGroups
    int groupSpacing=   _ACTIVE_LEDS/numGroups;
    
    for( int led=0; led<_NUM_ACTIVE_PIX; led++)  { 

      
      int subLed= led%ledsPerGroup;    //which led in the group am I?
      int group=led/ledsPerGroup;//which group am I in
      arry[led].setIndex(subLed+group*groupSpacing); 
      
      //if (led%ledsPerGroup==  ledsPerGroup-1) group++;
    }
  };
  
  
  void clearIndexInactive(){
    for( int i=_NUM_ACTIVE_PIX; i<_NUM_PIX; i++) arry[i].setIndex(0);
  }

  ///////////////////////////////////////
  //setup
  void set_NUM_LEDS(int num){
    for( int i=0; i<_NUM_PIX; i++)  arry[i].set_NUM_LEDS(num);
    _NUM_LEDS=num;
  };

  void useSingleStripIndexing(){
    _ACTIVE_LEDS=_NUM_LEDS/8;
    for( int i=0; i<_NUM_PIX; i++)  
      arry[i].useSingleStripIndexing(); 
  };  
  void useAbsoluteIndexing(){ 
    _ACTIVE_LEDS=_NUM_LEDS; 
    for( int i=0; i<_NUM_PIX; i++) 
      arry[i].useAbsoluteIndexing();
  };  

  void setActivePIX(int num){
    if (num <=_NUM_PIX)_NUM_ACTIVE_PIX=num;
    else _NUM_ACTIVE_PIX=_NUM_PIX;
  };
  
  void setAtLeastActivePIX(int atLeast=(NUM_LEDS/3)){
    _NUM_ACTIVE_PIX=atLeast+random(_NUM_PIX-atLeast);
  };
  void setAllActivePIX(){
    _NUM_ACTIVE_PIX=_NUM_PIX;
  };
  
  int get_NUM_PIX(){return _NUM_PIX;};
  int get_NUM_ACTIVE_PIX(){return _NUM_ACTIVE_PIX;};
  int get_NUM_LEDS(){return _NUM_LEDS;};
  
  Pix arry[ARRAY_LEN];//_PIX_LEN
  
private:

  //number of pixel objects in the array
  const int _NUM_PIX= ARRAY_LEN;
  
  //number of "active" pixel objects in the array
  int _NUM_ACTIVE_PIX; 
  
  //used in indexing bounds, number of total LEDs
  int _NUM_LEDS;

  int _ACTIVE_LEDS;
  
};

#endif

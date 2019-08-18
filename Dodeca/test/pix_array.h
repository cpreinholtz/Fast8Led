#ifndef pix_array_h
#define pix_array_h
#include <FastLED.h>
#include <Arduino.h>
#include "pix.h"
#define NUM_LEDS 10  //Included as default only, should be overwritten in main






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


  /////////////////////////////////////////////////////////////////////////////////
  //
  void sparkleSingleWhite(CRGB *led_array, int ind){
    arry[ind].tempSparkleWhite(led_array);
  };
  
  void sparkleSingleBlack(CRGB *led_array, int ind){
    arry[ind].tempSparkleBlack(led_array);
  };

  /////////////////////////////////////////////////////////////////////////////////////
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

  void setSingleRValue(int val, int i){
    arry[i].setRValue(val);
  };  
  void setSingleGValue(int val, int i){
    arry[i].setGValue(val);
  };  
  void setSingleBValue(int val, int i){
    arry[i].setBValue(val);
  };
  
  void randomValue(){
    for( int i=0; i<_NUM_PIX; i++)  arry[i].randomValue(); 
    //clearInactive();     
  };


  void clearInactive(){
    for( int i=_NUM_ACTIVE_PIX; i<_NUM_PIX; i++)arry[i].setValue(CRGB::Black);
  };


  void interpolateValue(CRGB from, CRGB to){

      int rdif = (to.r-from.r)/_NUM_ACTIVE_PIX;
      if (rdif==0 && to.r-from.r>0) rdif=1;
      else if (rdif==0 && to.r-from.r<0) rdif=-1;
      int rstart=from.r;
      for( int i=0; i<_NUM_ACTIVE_PIX; i++)  arry[i].setRValue(rstart+rdif*i);

      
      int gdif = (to.g-from.g)/_NUM_ACTIVE_PIX;      
      if (gdif==0 && to.g-from.g>0) gdif=1;
      else if (gdif==0 && to.g-from.g<0) gdif=-1;
      int gstart=from.g;
      for( int i=0; i<_NUM_ACTIVE_PIX; i++)  arry[i].setGValue(gstart+gdif*i);


      int bdif = (to.b-from.b)/_NUM_ACTIVE_PIX; 
      if (bdif==0 && to.b-from.b>0) bdif=1;
      else if (bdif==0 && to.b-from.b<0) bdif=-1;
      int bstart=from.b;
      for( int i=0; i<_NUM_ACTIVE_PIX; i++)  arry[i].setBValue(bstart+bdif*i);
  };
  void interpolateRand(){
    CRGB from;
    CRGB to;
    from.r=random(256);
    from.g=random(256);
    from.b=random(256);
    to.r=random(256);
    to.g=random(256);
    to.b=random(256);
    
      int rdif = (to.r-from.r)/_NUM_ACTIVE_PIX;
      if (rdif==0 && to.r-from.r>0) rdif=1;
      else if (rdif==0 && to.r-from.r<0) rdif=-1;
      int rstart=from.r;
      for( int i=0; i<_NUM_ACTIVE_PIX; i++)  arry[i].setRValue(rstart+rdif*i);

      
      int gdif = (to.g-from.g)/_NUM_ACTIVE_PIX;      
      if (gdif==0 && to.g-from.g>0) gdif=1;
      else if (gdif==0 && to.g-from.g<0) gdif=-1;
      int gstart=from.g;
      for( int i=0; i<_NUM_ACTIVE_PIX; i++)  arry[i].setGValue(gstart+gdif*i);


      int bdif = (to.b-from.b)/_NUM_ACTIVE_PIX; 
      if (bdif==0 && to.b-from.b>0) bdif=1;
      else if (bdif==0 && to.b-from.b<0) bdif=-1;
      int bstart=from.b;
      for( int i=0; i<_NUM_ACTIVE_PIX; i++)  arry[i].setBValue(bstart+bdif*i);
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
  
  //////
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

  void dimSingle(int ind,int dimBy=1){
    ind%=_NUM_ACTIVE_PIX;
      arry[ind].dim(dimBy);
  }

  
  ////////////////////////////////////////////////////////////////////////////////////////
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

  //////////////////////////////////////////////////////////////////////////////////////
  //setup


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

  void setAtLeastActivePIX(int atLeast=(NUM_LEDS/3)){
    _NUM_ACTIVE_PIX=atLeast+random(_NUM_PIX-atLeast);
  };
  void setAllActivePIX(){
    _NUM_ACTIVE_PIX=_NUM_PIX;
  };

  void setActivePIX(int num){
    if (num <=_NUM_PIX)_NUM_ACTIVE_PIX=num;
    else _NUM_ACTIVE_PIX=_NUM_PIX;
  };

  void set_NUM_LEDS(int num){
    for( int i=0; i<_NUM_PIX; i++)  arry[i].set_NUM_LEDS(num);
    _NUM_LEDS=num;
  };

   bool isBlack(){    
    int thresh=_NUM_ACTIVE_PIX/2;
    int lthresh=125;
    int off=0;
    for( int i=0; i<_NUM_ACTIVE_PIX; i++)  {
      CRGB  temp=arry[i].getValue();
      if (temp.r<lthresh &&temp.b<lthresh &&temp.g<lthresh) off++;
      if (off>=thresh) return true;
      
    }
    return false;
    
  };
  
  int get_NUM_PIX(){return _NUM_PIX;};//number of pixel object in array
  int get_NUM_ACTIVE_PIX(){return _NUM_ACTIVE_PIX;};//number of "active" pixel object in array
  int getActivePIX(){return get_NUM_ACTIVE_PIX();};//number of "active" pixel object in array
  int get_NUM_LEDS(){return _NUM_LEDS;};//number of LEDS that can be indexed to by the pixel objs  (should not exceed NUM_LEDS which determines the leds[] array size
  
  Pix arry[ARRAY_LEN];//_PIX_LEN
  
private:

  //number of pixel objects in the array
  const int _NUM_PIX= ARRAY_LEN;
  
  //number of "active" pixel objects in the array
  int _NUM_ACTIVE_PIX; 
  
  //used in indexing bounds, number of total LEDs (this effects what leds[] values can be written to
  int _NUM_LEDS;
  
  //used in indexing bounds, number of total LEDs (this effects what leds[] values can be written to
  int _ACTIVE_LEDS;
  
};

#endif

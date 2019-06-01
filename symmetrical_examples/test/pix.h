#ifndef pix_h
#define pix_h
#include <FastLED.h>
#include <Arduino.h>
#define NUM_LEDS 10 //Included as default only, should be overwritten in main




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
    
    led_array[i]+=value;
    /*
    if (led_array[i].r==0)led_array[i].r=value.r;
    else if ( (int)led_array[i].r+ (int)value.r <=255 ) led_array[i].r+= value.r;
    else led_array[i].r = 255;

    if (led_array[i].g==0)led_array[i].g=value.g;
    else if ( (int)led_array[i].g+ (int)value.g <=255 ) led_array[i].g+= value.g;
    else led_array[i].g = 255;
    
    if (led_array[i].b==0)led_array[i].b=value.b;
    else if ( (int)led_array[i].b+ (int)value.b <=255 ) led_array[i].b+= value.b;
    else led_array[i].b = 255;
    */
    
  };
  
  void applyToAdditive(CRGB *led_array){
    led_array[index]+=value;
    /*
    if (led_array[index].r==0)led_array[index].r=value.r;
    else if ( (int)led_array[index].r+ (int)value.r <=255 ) led_array[index].r+= value.r;
    else led_array[index].r = 255;

    if (led_array[index].g==0)led_array[index].g=value.g;
    else if ( (int)led_array[index].g+ (int)value.g <=255 ) led_array[index].g+= value.g;
    else led_array[index].g = 255;
    
    if (led_array[index].b==0)led_array[index].b=value.b;
    else if ( (int)led_array[index].b+ (int)value.b <=255 ) led_array[index].b+= value.b;
    else led_array[index].b = 255;
    */
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



  //////////////////////////////////////////////////////////////////////////
  void tempSparkleWhite(CRGB *led_array){
    led_array[index]=CRGB::White;
  };
  
  void tempSparkleBlack(CRGB *led_array){
    led_array[index]=CRGB::Black;
  };
  
  void tempSparkleColor(CRGB *led_array, CRGB col){
    led_array[index]=col;
  };

  
  /////////////////////////////////////////////////////////////////////////////////////////
  //Value
  void setValue(CRGB val){value=val;};
  void setRValue(int val){value.r=val;};
  void setGValue(int val){value.g=val;};
  void setBValue(int val){value.b=val;};
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


  ///////////////////////////////////////////////////////////////////////////////
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





#endif

#ifndef pix_h
#define pix_h
#include <FastLED.h>
#include <Arduino.h>
#define NUM_LEDS 10




class Pix{
public:
  Pix(int num_leds){

    _NUM_LEDS=num_leds;
    index=0;
    value=CRGB::Black;// CHSV(0,0,0);      
  };
  
  Pix(){
    _NUM_LEDS=NUM_LEDS;
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

  void subFromIndex(int idx){
    setIndex(index-idx);  
  };

  void addToIndex(int idx){
    setIndex(index+idx);
  };
  
  void randomIndex(){
    index = random(_NUM_LEDS);      
  };
  void setIndex(int idx){ index=idx; normalizeIndex(); };
  
  int getIndex(){return index;};
  
  
  
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
  CRGB value;
  int index;
  
  //wraps around if exceeds strip
  void normalizeIndex(){
    while (index>=_NUM_LEDS)index=index-_NUM_LEDS;
    while (index<0)index=index+_NUM_LEDS;
  };
  
};















template < int ARRAY_LEN >
class PixArray{
public:
  PixArray(int num_leds){
    //_NUM_PIX=ARRAY_LEN;
    _NUM_LEDS=num_leds;
    _NUM_ACTIVE_PIX=_NUM_PIX;
    for( int i=0; i<_NUM_PIX; i++){      
      arry[i].set_NUM_LEDS(num_leds);
    }
  };

  void applyTo(CRGB *led_array){
    for( int i=0; i<_NUM_ACTIVE_PIX; i++) arry[i].applyTo(led_array);
  };
  void applyToAdditive(CRGB *led_array){
    for( int i=0; i<_NUM_ACTIVE_PIX; i++) arry[i].applyToAdditive(led_array);
  };
  void applyToword(CRGB *led_array, int decBy=1){
    for( int i=0; i<_NUM_ACTIVE_PIX; i++) arry[i].applyToword(led_array,decBy);
  };

  /////////////////////////////////////////
  //Value
  void randomValue(){
    for( int i=0; i<_NUM_PIX; i++)  arry[i].randomValue(); 
    //clearInactive();     
  };
  void setValue(CRGB val){
    for( int i=0; i<_NUM_PIX; i++)  arry[i].setValue(val);
    //clearInactive();
  };
  void clearInactive(){
    for( int i=_NUM_ACTIVE_PIX; i<_NUM_PIX; i++)arry[i].setValue(CRGB::Black);
  };


  ////////////////////////////////////////////
  //DIM All indecies all colors
  void dimAll( int dimBy){
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
  
  void seAllIndex(int idx){
    for( int i=0; i<_NUM_ACTIVE_PIX; i++)  arry[i].setIndex(idx);   
  };

  void setIndexToIndex(){
    for( int i=0; i<_NUM_ACTIVE_PIX; i++)  arry[i].setIndex(i);   
  };
  
  void spreadEvenly(){
    for( int i=0; i<_NUM_ACTIVE_PIX; i++)  arry[i].setIndex(_NUM_LEDS*i/(_NUM_ACTIVE_PIX));   
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
  
};

#endif

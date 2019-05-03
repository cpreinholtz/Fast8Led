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
    led_array[index]=value;
  };

  void randomValue(){
    value = CHSV(random(256),random(256),random(256));      
  };
  void randomIndex(){
    index = random(_NUM_LEDS);      
  };

  void subFromIndex(int idx){
    setIndex(index-idx);  
  };

  void addToIndex(int idx){
    setIndex(index+idx);
  };
  
  void set_NUM_LEDS(int num){_NUM_LEDS=num;};
  void setValue(CRGB val){value=val;};
  void setIndex(int idx){ index=idx; normalizeIndex(); };
  
  int get_NUM_LEDS(void){ return _NUM_LEDS;};
  CRGB getValue(CRGB val){return value;};
  int getIndex(int idx){return index;};
  
  void run();
  void setup();
  void dbg();

private:
  int _NUM_LEDS;//used in indexing bounds
  CRGB value;
  int index;
  

  void normalizeIndex(){
    while (index>=_NUM_LEDS)index=index-_NUM_LEDS;
    while (index<0)index=index+_NUM_LEDS;
  };
  
};



template < int ARRAY_LEN >
class PixArray{
public:
  PixArray(){
    _NUM_PIX=ARRAY_LEN;
    for( int i=0; i<_NUM_PIX; i++){      
      arry[i].set_NUM_LEDS(ARRAY_LEN);
    }
  };

  void applyTo(CRGB *led_array){
    for( int i=0; i<_NUM_PIX; i++) arry[i].applyTo(led_array);
  };

  void randomValue(){
    for( int i=0; i<_NUM_PIX; i++)  arry[i].randomValue();      
  };

  void randomIndex(){
    for( int i=0; i<_NUM_PIX; i++)  arry[i].randomIndex();      
  };

  void subFromIndex(int idx){
    for( int i=0; i<_NUM_PIX; i++)  arry[i].subFromIndex(idx);
  };

  void addToIndex(int idx){
    for( int i=0; i<_NUM_PIX; i++)  arry[i].addToIndex(idx);   
  };

  Pix arry[ARRAY_LEN];
  
private:
  
  int _NUM_PIX;//used in indexing bounds

  
};

#endif

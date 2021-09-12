#include <Adafruit_NeoPixel.h>
#define PIN 3
#define SIZEARR 16
#define SIZEALLMATRIX 16*16
#define PINBUTTON 13

int MOD = 0;
const unsigned char arrColor = 16;
const unsigned char arrColorRGB = 3; 

Adafruit_NeoPixel led (SIZEALLMATRIX, PIN, NEO_GRB + NEO_KHZ800);


class colorBox{
  public:
  int red;
  int green;
  int blue;
  colorBox(){
    red = 0;
    green = 0;
    blue = 0;
    }

    colorBox(int r, int g, int b){
    red = r;
    green = g;
    blue = b;
    }
};


class Star{
  public:
  int ld,rd,cl,cc,cC,cr,lu,ru;

  Star(int i){
    ld = i;
    rd=i+1;
    cl = 32-rd*2+i+2;
    cc = 32-rd*2+i+1;
    cC = 32-rd*2+i;
    cr = 32-rd*2+i-1;
    ru = i+32;
    lu = i+33; 
  }

  void setStar(int i){
    ld = i;
    rd = i+1;
    cl = 32-rd*2+i+2;
    cc = 32-rd*2+i+1;
    cC = 32-rd*2+i;
    cr = 32-rd*2+i-1;
    ru = i+32;
    lu = i+33;
  }


};


Star st(rand()%13+1);
colorBox cb;


void setup() {
 pinMode(PINBUTTON,INPUT_PULLUP);
 led.begin();
 led.show();
}


void loop() {
modes:
 if(cb.red != 0 || cb.green != 0 || cb.blue != 0){
  MOD=MOD%3;
  switch(MOD){
    case 0:
    led.clear();
    svetCustom();
    goto modes;

    case 1:
    led.clear();
    colorGame(cb.red,cb.green,cb.blue);
    goto modes;

    case 2:
    led.clear();
    colorBright();
    goto modes;
  }}else{
  switch(MOD){
  
 
    case 0:
    led.clear();
    svetRed();
    goto modes;

    case 1:
    led.clear();
    svetBlue();
    goto modes;  
  

    case 2:
    led.clear();
    svetGreen();
    goto modes;  
  
    case 3:
    led.clear();
    svetBackround();
    goto modes;
    
    case 4:
    led.clear();
    svetBuble();
    goto modes;  
  
    case 5:
    led.clear();
    colorGame(255,0,0);
    led.clear();
    colorGame(0,255,0);
    led.clear();
    colorGame(0,0,255);
    goto modes;  
  }
 }
}

void colorBright(){
  for(int i = 0 ; i<256; i++){
    led.setPixelColor(i,cb.red,cb.green,cb.blue);
    if(!digitalRead(PINBUTTON) ){        
          unsigned long tm = millis();
          while(millis() - tm < 1500){
            if(!digitalRead(PINBUTTON)){
              svetoCor();
              return;
            }
          }
          MOD++;
          MOD = MOD%6;
          return;
    }          
  } 
  led.show();
}

void colorGame(int r, int g, int b){
  for(int i = 0; i< SIZEALLMATRIX; i++){
    led.setPixelColor(i,led.Color(r,g,b));
     if(!digitalRead(PINBUTTON) ){
        
        unsigned long tm = millis();
        while(millis() - tm < 1500){
          if(!digitalRead(PINBUTTON)){
             svetoCor();
             return;
          }
        }
        MOD++;
        MOD = MOD%6;           
        return;
      }        
    led.show();
   
  }
}


void svetCustom(){
  
   int color[arrColor][arrColorRGB];
   for(int i = 0 ; i < 16; i++){
      color[i][0]= cb.red;
      color[i][1]= cb.green;
      color[i][2]= cb.blue;
   }
   svetRGB(color);
}


void svetRed(){

  int color[arrColor][arrColorRGB]= {
    { 255, 0, 0},
    { 255, 16, 0},
    { 255, 32, 0},
    { 255, 48, 0},
    { 255, 64, 0},
    { 255, 80, 0},
    { 255, 96, 0},
    { 255, 112, 0},
    { 255, 128, 0},
    { 255, 144, 0},
    { 255, 160, 0},
    { 255, 176, 0},
    { 255, 192, 0},
    { 255, 208, 0},
    { 255, 224, 0},
    { 255 ,240, 0}
    };

    svetRGB(color);
}

  
void svetGreen(){
  
   int color[arrColor][arrColorRGB]= {
   {15,255,0},
   {31,255,0},
   {47,255,0},
   {63,255,0},
   {79,255,0},
   {95,255,0},
   {111,255,0},
   {127,255,0},
   {143,255,0},
   {159,255,0},
   {175,255,0},
   {191,255,0},
   {207,255,0},
   {223,255,0},
   {239,255,0},
   {255,255,0}
   };
   svetRGB(color);
}

  
void svetBlue(){
  
  int color[arrColor][arrColorRGB]= {
  {15,0,255},
  {31,0,255},
  {47,0,255},
  {63,0,255},
  {79,0,255},
  {95,0,255},
  {111,0,255},
  {127,0,255},
  {143,0,255},
  {159,0,255},
  {175,0,255},
  {191,0,255},
  {207,0, 255},
  {223,0,255},
  {239,0,255},
  {255,0,255}
  };
  svetRGB(color);
}


void svetRGB(int (&color)[arrColor][arrColorRGB]){
  int k =0;
  int rast = 0;
  
  while(k<16){
    int r =0;
    int g =0;
    int b = 0;
    
  
    for(int j = 0; j < 256; j++){
    if(color[k%16][0] >r){
      r=j;
    }
    if(color[k%16][1] >g){
      g=j;
    }
    if(color[k%16][2] >b){
      b=j;
    }
      for(int i = 0; i<16; i++){ 
      led.setPixelColor(i+rast,led.Color(r,g,b));
      if(!digitalRead(PINBUTTON) ){
        
        unsigned long tm = millis();
        while(millis() - tm < 1500){
          if(!digitalRead(PINBUTTON)){
            svetoCor();
            return;
          }
        }
        MOD++;
        MOD = MOD%6; 
        return;
      }     
      }
      led.show();
    }
    
    if(rast<240){
      rast+=16;
    }else{ 
      svetDown(color, rast);
    }
    k++;
  } 
}


void svetDown(int (&color)[arrColor][arrColorRGB], int &rast){
    int k =15;
    int kr = 0;
  
  while(k>=0){
    int r =color[k][0];
    int g =color[k][1];
    int b = color[k][2];
    
  
    for(int j = 255; j >= 0; j--){
    if(color[kr%16][0] <r ){
      r=j;
    }
    if(color[kr%16][1] <g ){
      g=j;
    }
    if(color[kr%16][2] <b ){
      b=j;
    }
      for(int i = 0; i<16; i++){
       
      led.setPixelColor(i+rast,led.Color(r,g,b));
      if(!digitalRead(PINBUTTON) ){     
          
          unsigned long tm = millis();
          while(millis() - tm < 1500){
            if(!digitalRead(PINBUTTON)){
              svetoCor();
              return;
            }
          }
          MOD++;
          MOD = MOD%6;           
          return;
        }         
      }
      led.show(); 
    }
   
    if(rast>=0){
      rast-=16;
    }else{
      return;
    }
    kr++;
    k--;
  }
}
 

  
void svetBackround(){
  int k =0;
  int rast = 0;
  
  int color[8][3]= {
    { 256, 256, 256},
    { 256, 0, 0},
    { 0, 256, 0},
    { 0, 0, 256},
    { 256, 0, 256},
    { 0, 256, 256},
    { 256, 256, 0},
    { 256 ,127 , 127}
    };
  while(k<256){
    int r =0;
    int g =0;
    int b = 0;
    int laps  = rand()%8;
  
    for(int j = 0; j < 256; j++){
    if(color[laps][0] >r){
      r=j;
    }
    if(color[laps][1] >g){
      g=j;
    }
    if(color[laps][2] >b){
      b=j;
    }
      for(int i = 0; i<64; i++){       
        led.setPixelColor(i+rast,led.Color(r,g,b));
        if(!digitalRead(PINBUTTON) ){
          
        
          unsigned long tm = millis();
          while(millis() - tm < 1500){
            if(!digitalRead(PINBUTTON)){
              svetoCor();
              return;
            }
          }
          MOD++;
          MOD = MOD%6;          
          return;
          }        
        }
      led.show();
    }
    
    if(rast<256){
      rast+=64;
    }else{
      rast=0;
    }
    k++;
  }
}


void svetBuble(){
  
  for( int i = 0; i < 256; i += 32 ){
     
     backround( i );

     for(int j = 20; j <= 250; j += 10) { 
       led.setPixelColor(st.ld+i,led.Color(j,0,0));
       led.setPixelColor(st.rd+i,led.Color(j,0,0));
       led.setPixelColor(st.cr+i,led.Color(j,0,0));
       led.setPixelColor(st.cc+i,led.Color(j,0,0));
       led.setPixelColor(st.cC+i,led.Color(j,0,0)); 
       led.setPixelColor(st.cl+i,led.Color(j,0,0));
       led.setPixelColor(st.lu+i,led.Color(j,0,0));
       led.setPixelColor(st.ru+i,led.Color(j,0,0));
       if(!digitalRead(PINBUTTON) ){
          
          unsigned long tm = millis();
          while(millis() - tm < 1500){
            if(!digitalRead(PINBUTTON)){
              svetoCor();
              return;
            }
          }
          MOD++;
          MOD = MOD%6;         
          return;
        }      
      
       led.show();
     }

     for(int j =250; j>=0; j-=10) { 
        led.setPixelColor(st.ld+i,led.Color(j,0,0));
       led.setPixelColor(st.rd+i,led.Color(j,0,0));
       led.setPixelColor(st.cr+i,led.Color(j,0,0));
       led.setPixelColor(st.cc+i,led.Color(j,0,0));
       led.setPixelColor(st.cC+i,led.Color(j,0,0)); 
       led.setPixelColor(st.cl+i,led.Color(j,0,0));
       led.setPixelColor(st.lu+i,led.Color(j,0,0));
       led.setPixelColor(st.ru+i,led.Color(j,0,0));
        if(!digitalRead(PINBUTTON) ){
        
          unsigned long tm = millis();
          while(millis() - tm < 1500){
            if(!digitalRead(PINBUTTON)){
              svetoCor();
              return;
            }
          }
          MOD++;
          MOD = MOD % 6;         
          return;
        }       
      
       led.show();
     }
    
   
  }
  st.setStar( rand() % 12 + 2 );
}

int backround( int k ){
  int r = 50;
  int g = 20;
  int b = 20;
  for(int i = 0; i < SIZEALLMATRIX; i++){
       if(!digitalRead( PINBUTTON ) ){
         
          unsigned long tm = millis();
          while( millis() - tm < 1500 ){
            if( !digitalRead( PINBUTTON ) ){
              svetoCor();
              return;
            }
          }
          MOD++;
          MOD = MOD % 6;        
          return;
        }      
    if (i != st.ld+k && i != st.rd+k && i != st.cc+k && i != st.cC+k && i != st.cr+k && i != st.cl+k && i != st.ru+k && i != st.lu+k){
    led.setPixelColor(i, led.Color((int)(r*1.05)%256,(int)(g*1.05)%256,(int)(b*1.05)%256));
    if(i%11==10){
      r+=rand() % 17;
      g+=rand() % 17;
      b+=rand() % 17;
    }
    }
  }
}


void svetoCor(){
 
  int red = 5;
  int green = 5;
  int blue = 5;
  unsigned long times;
  bool rgb;

colorCheng:

 //------------------red------------------//    
 
  rgb =1;
  times  = millis();
  
  while( rgb ){
    if( !digitalRead( PINBUTTON ) ){
      red++;
      red %= 255;
       times = millis();
       if (red == 0){ 
      while(millis() - times < 200){
        red == 0;
      }
    }
    for(int i = 0; i < 256; i++){ led.setPixelColor(i ,red ,0 ,0 ); }
    led.show();
    if(millis() - times >= 2000){ rgb = 0; }
   
  }
  }
 //------------------green------------------//  
 
  rgb = 1;
  times  = millis();

  while( rgb ){
    if( !digitalRead( PINBUTTON ) ){
    green++; 
    green %= 255;
    times = millis();
    if (green == 0){ 
      while(millis() - times < 200){
        green == 0;
      }
    }
    times = millis();
    }
    for(int i = 0; i < 256; i++){ led.setPixelColor(i ,0 ,green ,0 ); }
    led.show();
    if(millis() - times >= 2000){ rgb = 0; }
    }

//------------------blue------------------//    

  times  = millis();
  rgb = 1;
  
  while( rgb ){
   if( !digitalRead( PINBUTTON ) ){
    blue++;
    blue %= 255;
    if (blue == 0){
 
      while(millis() - times < 200){
        blue == 0;
      }
    
    }
    times = millis();}
   for(int i = 0; i < 256; i++){ led.setPixelColor(i ,0 ,0 , blue);}
   led.show();
   if(millis() - times >= 2000){rgb = 0; }
   }

//------------------RGB------------------// 
  times  = millis();
  while(1){
   if( !digitalRead( PINBUTTON ) ){goto colorCheng;}
   for(int i = 0; i < 256; i++){ led.setPixelColor(i ,red ,green ,blue );  }
   led.show();
   if(millis() - times >= 3000){
    cb.red = red;
    cb.green = green;
    cb.blue = blue;
    return;
   }
  }
}

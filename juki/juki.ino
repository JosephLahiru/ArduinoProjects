#include "LedControl.h"
LedControl lc=LedControl(12,11,10,2); // Pins: DIN,CLK,CS, 
unsigned long delayTime=200; 
byte invader1A[] ={
   B00000000,    
   B01111110,   
   B01000010,   
   B01000010,   
   B01111110,   
   B01000010,   
   B01000010,   
   B00000000
   };
byte invader1B[] ={
  B00000000,    
  B01111110,   
  B01000010,   
  B01111100,   
  B01000010,   
  B01000010,   
  B01111110,   
  B00000000
  };
byte invader1C[] ={
  B00000000,    
  B00111110,   
  B00100010,   
  B00100000,   
  B00100000,   
  B00100010,   
  B00111110,   
  B00000000
  };
byte invader1D[] ={
  B00000000, 
  B01111100, 
  B01000010,  
  B01000010,  
  B01000010,  
  B01000010,  
  B01111100, 
  B00000000
  };
byte invader1E[] ={
   B00000000,    
   B01111110,   
   B01000000,   
   B01111100,   
   B01000000,   
   B01000000,   
   B01111110,   
   B00000000
   };
byte invader1F[] ={
   B00000000,    
   B01111110,   
   B01000000,   
   B01111100,   
   B01000000,   
   B01000000,   
   B01000000,   
   B00000000
  };
byte invader1G[] ={
  B00000000,    
  B00111100,   
  B01000010,   
  B01000000,   
  B01001110,   
  B01000110,   
  B01111010,   
  B00000000
  };
byte invader1H[] ={
  B00000000, 
  B01000010, 
  B01000010,  
  B01111110,  
  B01000010,  
  B01000010,  
  B01000010, 
  B00000000
  };
byte invader1I[] ={
  B00000000, 
  B01111110, 
  B00011000,  
  B00011000,  
  B00011000,  
  B00011000,  
  B01111110, 
  B00000000
  };
byte invader1J[] ={
  B00000000,    
  B01111110,   
  B00001000,   
  B00001000,   
  B01001000,   
  B01001000,   
  B00110000,   
  B00000000
  };
byte invader1K[] ={
  B00000000,    
  B00100100,   
  B00101000,   
  B00110000,   
  B00110000,   
  B00101000,   
  B00100100,   
  B00000000
  };
byte invader1L[] ={
  B00000000, 
  B01000000, 
  B01000000,  
  B01000000,  
  B01000000,  
  B01000000,  
  B01111110, 
  B00000000
  };
byte invader1M[] ={
   B00000000,    
   B10000010,   
   B11000110,   
   B10101010,   
   B10010010,   
   B10000010,   
   B10000010,   
   B00000000
   };
byte invader1N[] ={
  B00000000,    
  B01000010,   
  B01100010,   
  B01010010,   
  B01001010,   
  B01000110,   
  B01000010,   
  B00000000
  };
byte invader1O[] ={
  B00000000,    
  B00111100,   
  B00100100,   
  B01000010,   
  B01000010,   
  B00100100,   
  B00111100,   
  B00000000
  };
byte invader1P[] ={
  B00000000, 
  B01111100, 
  B01000010,  
  B01000010,  
  B01111100,  
  B01000000,  
  B01000000, 
  B00000000
  };
byte invader1Q[] ={
   B00000000,    
   B00111100,   
   B01000010,   
   B01000010,   
   B01001010,   
   B01000110,   
   B01000010,   
   B00111101
   };
byte invader1R[] ={
   B00000000,    
   B01111100,   
   B01000010,   
   B01111100,   
   B01100000,   
   B01010000,   
   B01001100,   
   B00000000
  };
byte invader1S[] ={
  B00000000,    
  B00111100,   
  B01000010,   
  B00100000,   
  B00011100,   
  B01000010,   
  B00111100,   
  B00000000
  };
byte invader1T[] ={
  B00000000, 
  B11111110, 
  B00010000,  
  B00010000,  
  B00010000,  
  B00010000,  
  B00010000, 
  B00000000
  };
byte invader1U[] ={
  B00000000,    
  B01000010,   
  B01000010,   
  B01000010,   
  B01000010,   
  B01000010,   
  B00111100,   
  B00000000
  };
byte invader1V[] ={
  B00000000,    
  B00000000,   
  B10000010,   
  B10000010,   
  B01000100,   
  B00101000,   
  B00010000,   
  B00000000
  };
byte invader1W[] ={
  B00000000,    
  B10000010,   
  B10000010,   
  B10000010,   
  B10010010,   
  B10101010,   
  B11000110,   
  B00000000
  };
byte invader1X[] ={
  B00000000,    
  B01000100,   
  B00101000,   
  B00010000,   
  B00101000,   
  B01000100,   
  B10000010,   
  B00000000
  };
byte invader1Y[] ={
  B00000000,    
  B01000100,   
  B00101000,   
  B00010000,   
  B00010000,   
  B00010000,   
  B00010000,   
  B00000000
  };
byte invader1Z[] ={
  B00000000,    
  B01111111,   
  B00000110,   
  B00001000,   
  B00010000,   
  B01100000,   
  B11111110,   
  B00000000
  };
byte invader1FLASH[] ={
  B11111111,    
  B11111111,   
  B11111111,   
  B11111111,   
  B11111111,   
  B11111111,   
  B11111111,   
  B11111111
  };
byte invader1DIS_FLASH[] ={
  B00000000,    
  B00000000,   
  B00000000,   
  B00000000,   
  B00000000,   
  B00000000,   
  B00000000,   
  B00000000
  };

  
void setup(){
  lc.shutdown(0,false);  // Wake up displays
  lc.shutdown(1,false);  
  lc.setIntensity(0,5);  // Set intensity levels
  lc.setIntensity(1,5); 
  lc.clearDisplay(0);  // Clear Displays 
  lc.clearDisplay(1);}//  Take values in Arrays and Displaythem
void sinvader1A(){
  for (int i = 0; i < 8; i++)    {
    lc.setRow(0,i,invader1A[i]);  
    }}
void sinvader1B(){
  for (int i = 0;i < 8; i++)  {
    lc.setRow(0,i,invader1B[i]);  
    }}
void sinvader1C(){
  for (int i = 0; i < 8; i++)    {
    lc.setRow(0,i,invader1C[i]);  
    }}
void sinvader1D(){
  for (int i = 0;i < 8; i++)  {
    lc.setRow(0,i,invader1D[i]);  
    }}
void sinvader1E(){
  for (int i = 0; i < 8; i++)    {
    lc.setRow(0,i,invader1E[i]);  
    }}
void sinvader1F(){
  for (int i = 0;i < 8; i++)  {
    lc.setRow(0,i,invader1F[i]);  
    }}
void sinvader1G(){
  for (int i = 0; i < 8; i++)    {
    lc.setRow(0,i,invader1G[i]);  
    }}
void sinvader1H(){
  for (int i = 0;i < 8; i++)  {
    lc.setRow(0,i,invader1H[i]);  
    }}
void sinvader1I(){
  for (int i = 0; i < 8; i++)    {
    lc.setRow(0,i,invader1I[i]);  
    }}
void sinvader1J(){
  for (int i = 0;i < 8; i++)  {
    lc.setRow(0,i,invader1J[i]);  
    }}
void sinvader1K(){
  for (int i = 0; i < 8; i++)    {
    lc.setRow(0,i,invader1K[i]);  
    }}
void sinvader1L(){
  for (int i = 0;i < 8; i++)  {
    lc.setRow(0,i,invader1L[i]);  
    }}
void sinvader1M(){
  for (int i = 0; i < 8; i++)    {
    lc.setRow(0,i,invader1M[i]);  
    }}
void sinvader1N(){
  for (int i = 0;i < 8; i++)  {
    lc.setRow(0,i,invader1N[i]);  
    }}
void sinvader1O(){
  for (int i = 0; i < 8; i++)    {
    lc.setRow(0,i,invader1O[i]);  
    }}
void sinvader1P(){
  for (int i = 0;i < 8; i++)  {
    lc.setRow(0,i,invader1P[i]);  
    }}
void sinvader1Q(){
  for (int i = 0; i < 8; i++)    {
    lc.setRow(0,i,invader1Q[i]);  
    }}
void sinvader1R(){
  for (int i = 0;i < 8; i++)  {
    lc.setRow(0,i,invader1R[i]);  
    }}
void sinvader1S(){
  for (int i = 0; i < 8; i++)    {
    lc.setRow(0,i,invader1S[i]);  
    }}
void sinvader1T(){
  for (int i = 0;i < 8; i++)  {
    lc.setRow(0,i,invader1T[i]);  
    }}
void sinvader1U(){
  for (int i = 0; i < 8; i++)    {
    lc.setRow(0,i,invader1U[i]);  
    }}
void sinvader1V(){
  for (int i = 0;i < 8; i++)  {
    lc.setRow(0,i,invader1V[i]);  
    }}
void sinvader1W(){
  for (int i = 0; i < 8; i++)    {
    lc.setRow(0,i,invader1W[i]);  
    }}
void sinvader1X(){
  for (int i = 0;i < 8; i++)  {
    lc.setRow(0,i,invader1X[i]);  
    }}
void sinvader1Y(){
  for (int i = 0; i < 8; i++)    {
    lc.setRow(0,i,invader1Y[i]);  
    }}
void sinvader1Z(){
  for (int i = 0;i < 8; i++)  {
    lc.setRow(0,i,invader1Z[i]);  
    }}
void sinvader1FLASH(){
  for (int i = 0;i < 8; i++)  {
    lc.setRow(0,i,invader1FLASH[i]);  
    }}
void sinvader1DIS_FLASH(){
  for (int i = 0;i < 8; i++)  {
    lc.setRow(0,i,invader1DIS_FLASH[i]);  
    }}

    void loop(){
// Put #1frameonbothDisplay
sinvader1A();    
delay(delayTime);    

sinvader1B();    
delay(delayTime); 

sinvader1C();    
delay(delayTime);    

sinvader1D();    
delay(delayTime); 

sinvader1E();    
delay(delayTime);    

sinvader1F();    
delay(delayTime); 

sinvader1G();    
delay(delayTime);    

sinvader1H();    
delay(delayTime); 

sinvader1I();    
delay(delayTime);    

sinvader1J();    
delay(delayTime); 

sinvader1K();    
delay(delayTime);    

sinvader1L();    
delay(delayTime); 

sinvader1M();    
delay(delayTime);    

sinvader1N();    
delay(delayTime); 

sinvader1O();    
delay(delayTime);    

sinvader1P();    
delay(delayTime); 

sinvader1Q();    
delay(delayTime);    

sinvader1R();    
delay(delayTime); 

sinvader1S();    
delay(delayTime);    

sinvader1T();    
delay(delayTime); 

sinvader1U();    
delay(delayTime);    

sinvader1V();    
delay(delayTime); 

sinvader1W();    
delay(delayTime);    

sinvader1X();    
delay(delayTime); 

sinvader1Y();    
delay(delayTime);    

sinvader1Z();    
delay(delayTime); 

    }


//PROTO-prosjekt med RGB-Guesser
// 4 ledRinger, 1 ledStripe, 4 ledlys, 4 rotaryEncoder, 1 RF-antenne-modul

//*********LEDRING**********
#include <Adafruit_NeoPixel.h>
const int ledRingPin = 7;                               //definér pin 7 som digital for ledRing
Adafruit_NeoPixel ledRing = Adafruit_NeoPixel(8, ledRingPin, NEO_GRB); // en ring = 8 led  
uint32_t B = ledRing.Color(0,0,255);   //blue
uint32_t G = ledRing.Color(0,255,0);    //green 
uint32_t R = ledRing.Color(255,0,0);    //red

//********* ROTARY ENCODER****************
const int encoderPinA = 2;                     //definér pin 2 som digital for encoder
const int encoderPinB = 4;                     //----||----
int angle=0;                              //startpos.
int encoderPos=0;                         //startpos.
int encoderStepsPerRevolution= 15;        //360/24 (15 grader per step i rotary encoder)
boolean encoderALast= LOW;                //for å huske forrige tilstand til encoderPinA


//********FUNKSJONER SOM BRUKES***********
int readRot();                            //leser av rotary encoder og returnerer angle
void changeColor(int angle);              //leser inn angle og bruker setColor til å endre farge 
void setColor(uint32_t color);            //leser inn farge og skriver farge til LedRing(kan også brueks til ledStripe)

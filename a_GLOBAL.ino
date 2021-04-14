//PROTO-prosjekt med RGB-Guesser
// 4 ledRinger, 1 ledStripe, 4 ledlys, 4 rotaryEncoder, 1 RF-antenne-modul

const String red = "red";         //fint å bruke fargene som globale strenger for myColors og correctColors
const String green = "green";     //|
const String blue = "blue";       //|

String correctColors[4] = {"red", "red", "red", "red"};    //fargene til motstanders boks
static uint32_t myColors[4];                                      //fargene til min boks, skal være av størrelse 4 til en hver tid
String myColorsString[4];                                  //array for å bruke logikk, dvs. guessColors

//************PINS I BRUK******************
//ledRing =  7
//Rotary EncoderNo1 = 2 og 4
//RotaryEncoderNo2 = 5 og 6
//RotaryEncoderNo3 = 9 og 10
//RotaryEncoderNo4 = 11 og 12
//Set Color button = 3
//ShowMyPattern strip = 8






//*********LEDRING**********
#include <Adafruit_NeoPixel.h>

//***********ledRing************
const int ledRingPin = 7;                               //definér pin 7 som digital for ledRing
Adafruit_NeoPixel ledRing = Adafruit_NeoPixel(32, ledRingPin, NEO_GRB); // en ring = 8 led  -> 4 ring = 32 led
uint32_t R = ledRing.Color(255,0,0);    //red
uint32_t G = ledRing.Color(0,255,0);    //green
uint32_t B = ledRing.Color(0,0,255);   //blue



//**********ShowMyPattern Ledstripe********
const int setButton = 3;                              //definér pin 3 som setButton
const int myPatternStripPin = 8;                      //definerer pin 8 for showMyPattern ledstripe
const int countStrip = 4;                              //showMyPattern ledstripe vil bestå av 4 ledlys 
Adafruit_NeoPixel myPatternStrip = Adafruit_NeoPixel(4, myPatternStripPin, NEO_GRB);
uint32_t R_showMyP = myPatternStrip.Color(255,0,0);    //red
uint32_t G_showMyP = myPatternStrip.Color(0,255,0);    //green
uint32_t B_showMyP = myPatternStrip.Color(0,0,255);   //blue






//********* ROTARY ENCODER****************
const int encoderPinA = 2;                      //definér pin 2 som digital for encoder
const int encoderPinB = 4;                      //----||----
int angle=0;                                    //startpos.
int encoderPos=0;                               //startpos.
const int encoderStepsPerRevolution= 15;        //360/24 (15 grader per step i rotary encoder)
boolean encoderALast= LOW;                      //for å huske forrige tilstand til encoderPinA

//********* ROTARY ENCODER2****************
const int encoder2PinA = 5;
const int encoder2PinB = 6;
int angle2 = 0;
int encoderPos2=0;
boolean encoder2ALast = LOW; 

//********* ROTARY ENCODER3****************
const int encoder3PinA = 9;
const int encoder3PinB = 10;
int angle3 = 0;
int encoderPos3=0;
boolean encoder3ALast = LOW; 

//********* ROTARY ENCODER4****************
const int encoder4PinA = 11;
const int encoder4PinB = 12;
int angle4 = 0;
int encoderPos4=0;
boolean encoder4ALast = LOW; 



//********FUNKSJONER SOM BRUKES***********
int readRot();                            //leser av rotary encoder og returnerer angle
int readRot2();
int readRot3();
int readRot4();

uint32_t changeColor(int angle);          //leser inn angle og bruker setColor til å endre farge
uint32_t changeColor2(int angle2);
uint32_t changeColor3(int angle3);
uint32_t changeColor4(int angle4); 

void setColor(uint32_t color);            //leser inn farge og skriver farge til LedRing(kan også brueks til ledStripe)
void setColor2(uint32_t color);
void setColor3(uint32_t color);
void setColor4(uint32_t color);

//*********Hjelpe funksjoner*************
uint32_t makeMyColorArr();                // lager array med farger ved å lese av alle 4 readRot
String makeStringArr(uint32_t& myColors);

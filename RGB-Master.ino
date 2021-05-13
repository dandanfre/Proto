/*

  Navn: RGB-Master/Arduino Meaga
  Bruk: Sentralenheten som styrer hele RGB-Master foruten 7seg-displayene

  @forfatter: gruppe 6
  @versjon  13/05/21
*/



#include <Adafruit_NeoPixel.h>                    //for ledring og ledstripene




//********************************1. GLOBALE VERDIER**************************
const int encoderStepsPerRevolution =20;
const int setButton = 8;                                    
const int buttonGuess = 39;                                    
const int led1 = 50;                                            //statusDiode1
const int led2 = 51;                                            //statusDiode2
const int led3 = 52;                                            //statusDiode3
const int led4 = 53;                                            //statusDiode4
const int ledStrip = 9;                                       //myPatternStrip
const int ledRingPin1 = 22;                                        //ledring 1
const int ledRingPin2 = 23;                                        //ledring 2
const int ledRingPin3 = 24;                                        //ledring 3
const int ledRingPin4 = 25;                                        //ledring 4

uint32_t myColors[4];                                              //fargene til min boksen
uint32_t correctColor[4] = {65280, 255, 255, 65280};       //hardkodet riktige farger til den motstanders boks
uint32_t guessColors[4];                                   //farger som gjettes på motstanders boks


//*******************************2. DEF. AV KOMPONENTER*************************

//2.1 myPatternstrip - fargene som settes til min boks når setButton trykkes ned
Adafruit_NeoPixel myPatternStrip = Adafruit_NeoPixel(8, ledStrip, NEO_GRB);
uint32_t R_showMyP = myPatternStrip.Color(255,0,0);    //red
uint32_t G_showMyP = myPatternStrip.Color(0,255,0);    //green
uint32_t B_showMyP = myPatternStrip.Color(0,0,255);    //blue

//2.2 ledring1-4
//definerer ledrings m/ tilhørende farge
                            
Adafruit_NeoPixel ledRing1 = Adafruit_NeoPixel(24, ledRingPin1, NEO_GRB); 
uint32_t R = ledRing1.Color(255,0,0);    //red
uint32_t G = ledRing1.Color(0,255,0);    //green
uint32_t B = ledRing1.Color(0,0,255);    //blue
                            
Adafruit_NeoPixel ledRing2 = Adafruit_NeoPixel(24, ledRingPin2, NEO_GRB); 
uint32_t RR = ledRing2.Color(255,0,0);    
uint32_t GG = ledRing2.Color(0,255,0);    
uint32_t BB = ledRing2.Color(0,0,255);    

                       
Adafruit_NeoPixel ledRing3 = Adafruit_NeoPixel(24, ledRingPin3, NEO_GRB); 
uint32_t RRR = ledRing3.Color(255,0,0);    
uint32_t GGG = ledRing3.Color(0,255,0);    
uint32_t BBB = ledRing3.Color(0,0,255);    
                          
Adafruit_NeoPixel ledRing4 = Adafruit_NeoPixel(24, ledRingPin4, NEO_GRB); 
uint32_t RRRR = ledRing4.Color(255,0,0);    
uint32_t GGGG = ledRing4.Color(0,255,0);    
uint32_t BBBB = ledRing4.Color(0,0,255);    

//2.3 rotaryencoder struct for generalisering av de fire rot
struct rotaryEncoder {
  byte pin1;                                //bryter A, bryter A og B brukes til å holde styre på rotasjonsertning
  byte pin2;                                //bryter B
  int pos;                                  //posisjon til å bestemme sektorer
  bool lastState[2];
};

//2.4 definisjon av rot1-4 + interruptfunksjon for hver rot
rotaryEncoder encoder1;                       
void ISR1(){rotaryEncoderPulse(encoder1);};   //interruptfunksjon for å sikre at rotary prioriteres i prog ved vridning
rotaryEncoder encoder2;                       
void ISR2(){rotaryEncoderPulse(encoder2);};
rotaryEncoder encoder3;                       
void ISR3(){rotaryEncoderPulse(encoder3);};
rotaryEncoder encoder4;                       
void ISR4(){rotaryEncoderPulse(encoder4);};


//**********************************************3. FUNKSJONER***********************************************************

//****************************3.1 fromPosAngle*****************************************
//@param pos posisjon til rotaryencoder
//@return angle 

int fromPosAngle(const int& pos){
  int angle = abs((pos % encoderStepsPerRevolution) * 360/encoderStepsPerRevolution);  
  return angle;
  }

//****************************3.2 ledring1****************************************************

//@param farge til definerte ledring
void setColor1(uint32_t color){            
  for(int i=0; i<24; i++) {                
    ledRing1.setPixelColor(i, color);      
    ledRing1.show();                       
  }
}

//@param angle
//@return farge som er definert for den respektive ledringen
uint32_t changeColor1(int angle){
  if(angle <= 120 && angle >= 0){          //red_sector 0-120
  setColor1(R);                                          
  return(R);                               
  }
  else if(angle > 121 && angle <= 240){    //green_sector 121-240
  setColor1(G);                            
  return(G);                               
  }
  else if(angle > 240){                    //blue_sector 241-360
  setColor1(B);                            
  return(B);                               
  }
}


//****************************3.3 ledring2****************************************************
void setColor2(uint32_t color){         
  for(int i=0; i<24; i++) {             
    ledRing2.setPixelColor(i, color);   
    ledRing2.show();                    
  }
}

uint32_t changeColor2(int angle){
  if(angle <= 120 && angle >= 0){            
  setColor2(RR);                            
  return(RR);                              
  }
  else if(angle > 121 && angle <= 240){      
  setColor2(GG);                            
  return(GG);                              
  }
  else if(angle > 240){                     
  setColor2(BB);                            
  return(BB);                              
  }
}


//****************************3.4 ledring3****************************************************
void setColor3(uint32_t color){         
  for(int i=0; i<24; i++) {             
    ledRing3.setPixelColor(i, color);   
    ledRing3.show();                    
  }
}

uint32_t changeColor3(int angle){
  if(angle <= 120 && angle >= 0){             
  setColor3(RRR);                            
  return(RRR);                              
  }
  else if(angle > 121 && angle <= 240){       
  setColor3(GGG);                            
  return(GGG);                              
  }
  else if(angle > 240){                      
  setColor3(BBB);                            
  return(BBB);                              
  }
}

//****************************3.5 ledring4****************************************************
void setColor4(uint32_t color){        
  for(int i=0; i<24; i++) {             
    ledRing4.setPixelColor(i, color);   
    ledRing4.show();                    
  }
}

uint32_t changeColor4(int angle){
  if(angle <= 120 && angle >= 0){              
  setColor4(RRRR);                            
  return(RRRR);                              
  }
  else if(angle > 121 && angle <= 240){        
  setColor4(GGGG);                            
  return(GGGG);                              
  }
  else if(angle > 240){                        
  setColor4(BBBB);                            
  return(BBBB);                              
  }
}


//****************************3.6 rotaryEncoderPulse****************************************************
//@param rotary encoder struct

void rotaryEncoderPulse(rotaryEncoder &encoder){
  bool currentState[] = {digitalRead(encoder.pin1), digitalRead(encoder.pin2)};  
  //Serial.println((String)currentState[0] + (String)currentState[1]);           
  if(encoder.lastState[0] == LOW && encoder.lastState[1] == HIGH && currentState[0] == HIGH && currentState[1] == LOW){
    encoder.pos ++;
  }
  else if(encoder.lastState[0] == LOW && encoder.lastState[1] == LOW && currentState[0] == HIGH && currentState[1] == HIGH){
    encoder.pos --;
  }
  encoder.lastState[0] = currentState[0];
  encoder.lastState[1] = currentState[1];
}




//****************************3.7 makeMyColorArr****************************************************
//@param peker til uint32_t-array

void makeMyColorArr(uint32_t *myColors){
  myColors[0] = changeColor1(fromPosAngle(encoder1.pos));   
  myColors[1] = changeColor2(fromPosAngle(encoder2.pos));
  myColors[2] = changeColor3(fromPosAngle(encoder3.pos));
  myColors[3] = changeColor4(fromPosAngle(encoder4.pos));
  }


//****************************3.8 makeGuessColorArr****************************************************
//@param peker til arr

 void makeGuessColorArr(uint32_t *guessColors){
    guessColors[0] = changeColor1(fromPosAngle(encoder1.pos));   
    guessColors[1] = changeColor2(fromPosAngle(encoder2.pos));
    guessColors[2] = changeColor3(fromPosAngle(encoder3.pos));
    guessColors[3] = changeColor4(fromPosAngle(encoder4.pos));
     }
     

//*****************************3.9 showMyPattern******************************************************
//@param peker til myColors-array

void showMyPattern(uint32_t *myColors) {    
    for (int i=0; i<4; i++){                  
      if((int)myColors[i]==(int)R_showMyP){
        myPatternStrip.setPixelColor(2*i,  R_showMyP);     //skriver farge til annenhver led 
        myPatternStrip.show();
        //Serial.println(i);               problemsøking
        }
      else if((int)myColors[i]==(int)G_showMyP){
        myPatternStrip.setPixelColor(2*i,  G_showMyP);
        myPatternStrip.show();
        }
      else if((int)myColors[i]==(int)B_showMyP){
        myPatternStrip.setPixelColor(2*i, B_showMyP);
        myPatternStrip.show();
      }    
   }
}


//*****************************3.10 guessColor****************************************************
//@return sum som bestemmer antall korrekte farger som var gjettet uavghengig av plassering

int guessColor() {
  int sum=0;
  for( int i=0;i<4;i++){
    if(correctColor[i]==guessColors[i]){
       sum++;
    }
  }
  return sum;
}


//*****************************3.11 statusDioder***************************************************
//for antall riktige fra guessColor lyser diodene
void statusDioder(int numCorrect) {
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  
  if(numCorrect==1){        
    digitalWrite(led1, HIGH);                           
  }
  else if(numCorrect==2){   
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);                         
  }
  else if(numCorrect==3){                   
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);                         
  } 
  else if(numCorrect==4){                   
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH); 
    digitalWrite(led4, HIGH);                        
  }
}

//**************************************4. SETUP*****************************************************


void setup() {
 
//rot1
  encoder1.pin1 = 2;
  encoder1.pin2 = 3;
  pinMode(encoder1.pin1, INPUT_PULLUP);
  pinMode(encoder1.pin2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(encoder1.pin1), ISR1, CHANGE);

//rot2
  encoder2.pin1 = 18;
  encoder2.pin2 = 4;
  pinMode(encoder2.pin1, INPUT_PULLUP);
  pinMode(encoder2.pin2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(encoder2.pin1), ISR2, CHANGE);

//rot3
  encoder3.pin1 = 19;
  encoder3.pin2 = 5;
  pinMode(encoder3.pin1, INPUT_PULLUP);
  pinMode(encoder3.pin2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(encoder3.pin1), ISR3, CHANGE);

//rot4
  encoder4.pin1 = 20;
  encoder4.pin2 = 6;
  pinMode(encoder4.pin1, INPUT_PULLUP);
  pinMode(encoder4.pin2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(encoder4.pin1), ISR4, CHANGE);


  ledRing1.begin();
  ledRing1.show();            
  ledRing1.setBrightness(40); 

  ledRing2.begin();
  ledRing2.show();            
  ledRing2.setBrightness(40); 

  ledRing3.begin();
  ledRing3.show();            
  ledRing3.setBrightness(40); 

  ledRing4.begin();
  ledRing4.show();            
  ledRing4.setBrightness(40); 


  myPatternStrip.begin();
  myPatternStrip.show();
  myPatternStrip.setBrightness(40);

//setButton
  pinMode(setButton, INPUT_PULLUP);

//buttonGuess
  pinMode(buttonGuess, INPUT_PULLUP);

//statusLed1-4  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT); 
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  Serial.begin(9600);
}




//**************************************5. LOOP*****************************************************


void loop() {
   
  int pos1 = encoder1.pos;
  int pos2 = encoder2.pos;
  int pos3 = encoder3.pos;
  int pos4 = encoder4.pos;
  
  changeColor1(fromPosAngle(pos1));
  changeColor2(fromPosAngle(pos2));
  changeColor3(fromPosAngle(pos3));
  changeColor4(fromPosAngle(pos4));
  
  if(digitalRead(setButton) == LOW){
   makeMyColorArr(myColors); 
   showMyPattern(myColors);
  }
    
  if (digitalRead (buttonGuess) == LOW){
   makeGuessColorArr(guessColors);  
   int numCorrect = guessColor();
   statusDioder(numCorrect);
  }
}

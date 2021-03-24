//****************************SETUP FUNKSJON*****************

void setup(){

  Serial.begin(9600); //åpner seriell monitor for problemsøking

  //initialiserer ledRing**************************
  ledRing.begin();
  ledRing.show();            // initialiserer alle led som 'AV'
  ledRing.setBrightness(100); // 40/255 intensitet(ca.15%)

  //definér  I/O for ROTARY ENCODER****************
  pinMode(encoderPinA, INPUT);      //setter encoderPinA til digitalINPUT
  pinMode(encoderPinB, INPUT);      //----||----
  digitalWrite(encoderPinA, HIGH);  //skriver encoderPinA til HØY 
  digitalWrite(encoderPinB, HIGH);  //----||----
  }



  

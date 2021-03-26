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

  //definér I/O for ROTARY ENCODER2******************
  pinMode(encoder2PinA, INPUT);
  pinMode(encoder2PinB, INPUT);
  digitalWrite(encoder2PinA,HIGH);
  digitalWrite(encoder2PinB,HIGH);
  }



 /* pinMode(setButton, INPUT_PULLUP); #Bruker intern motstand -> low og high blir motsatt grei standard å bruke
  digitalWrite(setButton, HIGH)*/
  

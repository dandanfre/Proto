//****************************SETUP FUNKSJON*****************

void setup(){

  Serial.begin(9600); //åpner seriell monitor for problemsøking

  //initialiserer ledRing**************************
  ledRing.begin();
  ledRing.show();            // initialiserer alle led som 'AV'
  ledRing.setBrightness(100); // 40/255 intensitet(ca.15%)

  //initialiserer ledStrip for showMyPattern
  pinMode(setButton, INPUT_PULLUP); //Bruker intern motstand -> low og high blir motsatt(dvs. 1 ->(knapp holdes inne) 0)
  //digitalWrite(setButton, HIGH); unødvendig??
  myPatternStrip.begin();
  myPatternStrip.show();
  ledRing.setBrightness(100);
  

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

  //definér I/O for ROTARY ENCODER3******************
  pinMode(encoder3PinA, INPUT);
  pinMode(encoder3PinB, INPUT);
  digitalWrite(encoder3PinA,HIGH);
  digitalWrite(encoder3PinB,HIGH);

  //definér I/O for ROTARY ENCODER2******************
  pinMode(encoder4PinA, INPUT);
  pinMode(encoder4PinB, INPUT);
  digitalWrite(encoder4PinA,HIGH);
  digitalWrite(encoder4PinB,HIGH);

  //definér pins for Seven Segments 0-10
  pinMode(0,OUTPUT);
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(guessButton,INPUT_PULLUP);     //Bruker intern motstand, 1 og 0 invertes. Dvs. kanpp trykkes ned er det samme som 0, men ellers 1

  
  //Definér pins for statusDioder
  pinMode(led1, OUTPUT);  //14
  pinMode(led2, OUTPUT);  //15
  pinMode(led3, OUTPUT);  //16
  pinMode(led4, OUTPUT);  //17
  }



 /* pinMode(setButton, INPUT_PULLUP); #Bruker intern motstand -> low og high blir motsatt grei standard å bruke
  digitalWrite(setButton, HIGH)*/
  

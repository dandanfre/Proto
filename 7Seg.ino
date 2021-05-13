/**

  Navn: RGB-Master/Arduino Uno m/ to 7Segment-display
  Bruk: Telller antall forsøk spiller har brukt på å gjette/antall ganger spiller har trykket på Guess-knappen

  @forfatter: gruppe 6
  @versjon  13/05/21
*/

//Seven segment display = 7seg

//**************************GLOBALE VARIABLER**************************

int t = 0;                                    // tierplassen 
int e = 0;                                    // enerplassen
int i =0;                                     // variabel for å telle # trykk 00,01,02,...,99
const int buttonGuess = 13;                  

// boolske-tilstands variabler gir buttonGuess stabilitet 
int buttonNow=1;
int buttonBefore=1;

//dmplementasjon muligjør multiplexing av to 7seg
byte numbers[10]={B1000000, B1111001, B0100100, B0110000, B0011001, B0010010,B0000010, B1111000, B00000000, B0010000};






//***********************SETUP*****************************************

void setup() {
//pins til 7seg, pin 0-6 er av typen PORTD
// kingbrigth - a   pin = 0
// kingbrigth - b   pin = 1
// kingbrigth - c   pin = 2
// kingbrigth - d   pin = 3
// kingbrigth - e   pin = 4
// kingbrigth - f   pin = 5
// kingbrigth - g   pin = 6

// pins for multiplexing første og andre 7seg
// første 7seg - tierplass    pin = 8
// andre 7seg  - enerplass    pin  = 9

  for(int i = 0; i < 10; i++) pinMode(i,OUTPUT);    // initialiserer + definerer pins 0-10

  digitalWrite(buttonGuess, INPUT_PULLUP);          
  
}



//***********************LOOP***************************************

void loop() {
    
    buttonNow = digitalRead (buttonGuess);               
    if((buttonNow==HIGH) && (buttonBefore==0))
    {
        if (i<99)                                        //99 er øvre grense for #tries
            i++;                                         
    }
    buttonBefore=buttonNow;                              
  
  
    // display håndtering: konverterer til desimal 0-99
    t=i/10;                                              //#tiere
    e=i-(t*10);                                          //#enere
    
    // første 7seg, tierplass
    digitalWrite(8,HIGH);
    digitalWrite(9,LOW);
    PORTD = numbers[t];                                  //PORTD, registrerer state på pins 0-6
    delay(5);                                            
   
    // andre 7seg, enerplass
    digitalWrite(9,HIGH);
    digitalWrite(8,LOW);
    PORTD = numbers[e];                                 
    delay(5);
}

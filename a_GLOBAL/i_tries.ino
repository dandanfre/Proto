//*************Teller antall forsøk og viser #forsøk på seven segment display. Forsøk itereres for hver gang knappen guessButton trykkes ned




void tries(int& i, int& t, int& e) {
    
        if (i<99)
            i++;
  
  
    // display management: encoding fra desimal 0-99 
    // til 2 siffer for 7 segment displays
    t=i/10;
    e=i-(t*10);
    
    // display tierplassen
    digitalWrite(9,HIGH);
    digitalWrite(8,LOW);
    PORTD = numbers[t];     //PORTD, registrerer state
    delay(10);              //av OUTPUT (fra pin 0-7)
    // display enerplassen
    digitalWrite(8,HIGH);
    digitalWrite(9,LOW);
    PORTD = numbers[e];
    delay(15);
}

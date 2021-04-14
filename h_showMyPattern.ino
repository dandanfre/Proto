//******showMyPattern skriver til ledlysene som velges set-knappen holdes ned******
//Dette vil vise ledlys mønsteret på min boks


void showMyPattern(uint32_t myColors[]) {     //tar inn myColors som parameter, denen brukes til å skrive farge til ledlysene i 
  if (digitalRead(setButton) == LOW){
    for (int i=0; i<countStrip; i++){        //vil lese igjennom lysene til neopixel strip
      myPatternStrip.setPixelColor(i, myColors[i]);
    }
  }
  myPatternStrip.show();
}

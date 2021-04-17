//**************LESER INN FARGE OG SKRIVER DET TIL LEDRING**********

/*ledRing1 0-7 ledlys   
  ledRing2 8-15 ledlys
  ledRing3 16-23 ledlys
  ledRing4 24-32 ledlys
*/


//***********ledRing1******
void setColor(uint32_t color){         // funksjonene itererer gjennom alle led-lys fra 1-8
  for(int i=0; i<8; i++) {             //  led i hver ledRing
    ledRing.setPixelColor(i, color);   // setter farge på repsektive ledlys
    ledRing.show();                    // viser farge
    //delay(40);
  }
}


//**************ledRing2*****       //fortsatt en del av samme ledring
void setColor2(uint32_t color){
  for (int j = 8; j < 16; j++){
    ledRing.setPixelColor(j,color);
    ledRing.show();
  }
}


//**************ledRing3*****
void setColor3(uint32_t color){
  for (int k = 16; k < 24; k++){
    ledRing.setPixelColor(k,color);
    ledRing.show();
  }
}


//**************ledRing4*****       
void setColor4(uint32_t color){
  for (int l = 24; l < 32; l++){
    ledRing.setPixelColor(l,color);
    ledRing.show();
  }
}

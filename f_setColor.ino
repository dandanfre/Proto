//**************LESER INN FARGE OG SKRIVER DET TIL LEDRING**********


//***********ledRing1******
void setColor(uint32_t color){         // funksjonene itererer gjennom alle led-lys fra 1-8
  for(int i=0; i<8; i++) {             //  led i hver ledRing
    ledRing.setPixelColor(i, color);   // setter farge på repsektive ledlys
    ledRing.show();                    // viser farge
    //delay(40);
  }
}


//**************ledRing2*****
void setColor2(uint32_t color){
  for (int j = 8; j < 16; j++){
    ledRing.setPixelColor(j,color);
    ledRing.show();
  }
}

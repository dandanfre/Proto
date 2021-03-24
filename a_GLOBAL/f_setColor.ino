//**************LESER INN FARGE OG SKRIVER DET TIL LEDRING**********



void setColor(uint32_t color){
  for(int i=0; i<8; i++) {            //8 led i hver ledRing
    ledRing.setPixelColor(i, color);   // endre farge
    ledRing.show();
    //delay(40);
  }
}

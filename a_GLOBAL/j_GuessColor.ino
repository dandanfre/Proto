///***********************Returnerer et heltall som representerer antall korrekte farger som har blitt gjettet i et forsøk

int guessColor() {
  int sum=0;
  for( int i=0;i<4;i++){
    if(correctColor[i]==myGuessColor[i]){
       sum++;
    }
  }
  return sum;
}

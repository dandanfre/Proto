//*************************kaller på funksjonen GUESSCOLOR og skriver antall riktige gjetninger til led-lysene

void statusDioder(int numCorrect) {
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  if(numCorrect== 1){
    digitalWrite(led1, HIGH);
  }
  else if(numCorrect==2){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
  }
  else if(numCorrect==3){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
  }
  else if(numCorrect==4){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
  }
}

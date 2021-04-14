//***********HER KJØRES HELE PROGRAMMET***********

void loop(){  
  changeColor(readRot());   //returnerer en streng for første lys: "red", "green" eller "blue"
  changeColor2(readRot2()); //returnerer en streng for første lys: "red", "green" eller "blue"
  changeColor3(readRot3());   //returnerer en streng for første lys: "red", "green" eller "blue"
  changeColor4(readRot4()); //returnerer en streng for første lys: "red", "green" eller "blue"
  uint32_t myPattern = makeMyColorArr();   //lager en array av typen uint32_t som brukes til å skrive lysene til showMyPattern

}

//******************Samler alle lysene fra de fire lysene i et array************************


uint32_t makeMyColorArr(){
  memset(myColors, 0, sizeof(myColors));   //deallocates copies of the array
  uint32_t newColorArr[4];
  myColors[0] = changeColor(readRot());   
  myColors[1] = changeColor2(readRot2());
  myColors[2] = changeColor3(readRot3());
  myColors[3] = changeColor4(readRot4());
  return newColorArr[4];
  }
  

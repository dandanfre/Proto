//*************LESER AV ANGLE I READROT() OG BRUKER SETCOLOR() TIL Å ENDRE FARGE************

//**********ledRing**********
String changeColor(int angle){
  if(angle <= 120 && angle >= 0){         //red_sector 0-120
  setColor(R);                            //setter hele ledRing til rød
  return(red);                            //returnerer strengen "red"
  }
  else if(angle > 121 && angle <= 240){   //green_sector 121-240
  setColor(G);                            //setter hele ledRing til grønn
  return(green);                          // returnerer strengen "green"
  }
  else if(angle > 240){                   //blue_sector 241-360
  setColor(B);                            //setter hele ledRing til blå
  return(blue);                           //returnerer strengen "blue"
  }
}


//**********ledRing2**********
String changeColor2(int angle){
  if(angle <= 120 && angle >= 0){         //red_sector 0-120
  setColor2(R);
  return(red);
  }
  else if(angle > 121 && angle <= 240){   //green_sector 121-240
  setColor2(G);
  return(green);
  }
  else if(angle > 240){                   //blue_sector 241-360
  setColor2(B);  
  return(blue);
  }
}

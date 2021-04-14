//*************LESER AV ANGLE I READROT() OG BRUKER SETCOLOR() TIL Å ENDRE FARGE************

//**********ledRing**********
uint32_t changeColor(int angle){
  if(angle <= 120 && angle >= 0){         //red_sector 0-120
  setColor(R);                            //setter hele ledRing til rød
  myColorsString[0] = "red";              //setter første element i myColorString til rød
  return(R);                              //returnerer strengen "red"
  }
  else if(angle > 121 && angle <= 240){   //green_sector 121-240
  setColor(G);                            //setter hele ledRing til grønn
  myColorsString[0] = "green";             //setter første element i myColorString til grønn
  return(G);                              // returnerer strengen "green"
  }
  else if(angle > 240){                   //blue_sector 241-360
  setColor(B);                            //setter hele ledRing til blå
  myColorsString[0] = "blue";              //setter første element i myColorString til blå
  return(B);                              //returnerer strengen "blue"
  }
}


//**********ledRing2**********
uint32_t changeColor2(int angle2){
  if(angle2 <= 120 && angle2 >= 0){         //red_sector 0-120
  setColor2(R);
  myColorsString[1] = "red";                //setter andre element i myColorString til rød
  return(R);
  }
  else if(angle2 > 121 && angle2 <= 240){   //green_sector 121-240
  setColor2(G);
  myColorsString[1] = "green";              //setter andre element i myColorString til grønn
  return(G);
  }
  else if(angle2 > 240){                    //blue_sector 241-360
  setColor2(B);  
  myColorsString[1] = "blue";               //setter andre element i myColorString til blå
  return(B);
  }
}


//**********ledRing3**********
uint32_t changeColor3(int angle3){
  if(angle3 <= 120 && angle3 >= 0){         //red_sector 0-120
  setColor3(R);
  myColorsString[2] = "red";                //setter tredje element i myColorString til rød
  return(R);
  }
  else if(angle3 > 121 && angle3 <= 240){   //green_sector 121-240
  setColor3(G);
  myColorsString[2] = "green";              //setter tredje element i myColorString til grønn
  return(G);
  }
  else if(angle3 > 240){                    //blue_sector 241-360
  setColor3(B);  
  myColorsString[2] = "blue";               //setter tredje element i myColorString til blå
  return(B); 
  }
}

//**********ledRing4**********
uint32_t changeColor4(int angle4){
  if(angle4 <= 120 && angle4 >= 0){           //red_sector 0-120
  setColor4(R);
  myColorsString[3] = "red";                  //setter siste element i myColorString til rød
  return(R);
  }
  else if(angle4 > 121 && angle4 <= 240){     //green_sector 121-240
  setColor4(G);
  myColorsString[3] = "green";                //setter siste element i myColorString til grønn
  return(G);
  }
  else if(angle4 > 240){                      //blue_sector 241-360
  setColor4(B);  
  myColorsString[3] = "blue";                 //setter siste element i myColorString til rød
  return(B);
  }
}

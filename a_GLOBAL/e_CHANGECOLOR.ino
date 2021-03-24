//*************LESER AV ANGLE I READROT() OG BRUKER SETCOLOR() TIL Å ENDRE FARGE************


void changeColor(int angle){
  if(angle <= 120 && angle >= 0){         //red_sector 0-120
  setColor(R);
  }
  else if(angle > 121 && angle <= 240){   //green_sector 121-240
  setColor(G);
  }
  else if(angle > 240){                   //blue_sector 241-360
  setColor(B);  
  }
}

//**************FUNKSJON LESER AV ROTARYENCODERS POS.**************

//******readRot1*********
int readRot(){
  boolean encoderA= digitalRead(encoderPinA);   //leser av ROTARY ENCODER på på encoderPinA 
  if ((encoderALast == HIGH) && (encoderA == LOW))
  {
    if (digitalRead(encoderPinB) == LOW)
  {
    encoderPos--;
    }
    else
    {
      encoderPos++;
      }
      angle= abs((encoderPos % encoderStepsPerRevolution) * 360/encoderStepsPerRevolution); //grader, brukes i chooseColor. med abs() vil angle alltid være større enn 0 -> angle element i [0,360]
      /*Serial.print(encoderPos);
      Serial.print(" ");          for problemsøking
      Serial.println(angle);*/
   }
      encoderALast= encoderA;
      return angle;
}


//******readRot2*********
int readRot2(){
  boolean encoder2A= digitalRead(encoder2PinA); 
  if ((encoder2ALast == HIGH) && (encoder2A == LOW))
  {
    if (digitalRead(encoder2PinB) == LOW)
  {
    encoderPos2--;
    }
    else
    {
      encoderPos2++;
      }
      angle2 = abs((encoderPos2 % encoderStepsPerRevolution) * 360/encoderStepsPerRevolution); //grader, brukes i chooseColor
      /*Serial.print(encoderPos2);
      Serial.print(" ");          for problemsøking
      Serial.println(angle2);*/
   }
      encoder2ALast= encoder2A;
      return angle2;
}


//******readRot3*********
int readRot3(){
  boolean encoder3A= digitalRead(encoder3PinA); 
  if ((encoder3ALast == HIGH) && (encoder3A == LOW))
  {
    if (digitalRead(encoder3PinB) == LOW)
  {
    encoderPos3--;
    }
    else
    {
      encoderPos3++;
      }
      angle3 = abs((encoderPos3 % encoderStepsPerRevolution) * 360/encoderStepsPerRevolution); //grader, brukes i chooseColor
      /*Serial.print(encoderPos3);
      Serial.print(" ");          for problemsøking
      Serial.println(angle3);*/
   }
      encoder3ALast= encoder3A;
      return angle3;
}


//******readRot4*********
int readRot4(){
  boolean encoder4A= digitalRead(encoder4PinA); 
  if ((encoder4ALast == HIGH) && (encoder4A == LOW))
  {
    if (digitalRead(encoder4PinB) == LOW)
  {
    encoderPos4--;
    }
    else
    {
      encoderPos4++;
      }
      angle4 = abs((encoderPos4 % encoderStepsPerRevolution) * 360/encoderStepsPerRevolution); //grader, brukes i chooseColor
      /*Serial.print(encoderPos4);
      Serial.print(" ");          for problemsøking
      Serial.println(angle4);*/
   }
      encoder4ALast= encoder4A;
      return angle4;
}

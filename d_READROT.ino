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
      /*Serial.print(encoderPos);
      Serial.print(" ");          for problemsøking
      Serial.println(angle);*/
   }
      encoder2ALast= encoder2A;
      return angle2;
}

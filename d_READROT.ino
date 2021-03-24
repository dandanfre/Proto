//**************FUNKSJON LESER AV ROTARYENCODERS POS.**************


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
      angle= abs((encoderPos % encoderStepsPerRevolution) * 360/encoderStepsPerRevolution); //grader, brukes i chooseColor
      /*Serial.print(encoderPos);
      Serial.print(" ");          for problemsøking
      Serial.println(angle);*/
   }
      encoderALast= encoderA;
      return angle;
}

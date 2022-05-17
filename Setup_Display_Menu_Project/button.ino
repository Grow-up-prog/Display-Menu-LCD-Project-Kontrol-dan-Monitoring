
void buttonA(){
  currentState1=digitalRead(button1);
  if(lastState1==HIGH&&currentState1==LOW){
    Serial.println("lampuA_ON");
    nav=1;
    lcd.clear();
  } else if(lastState1==LOW&&currentState1==HIGH){
    Serial.println("LampuA_OFF");
  }
  lastState1=currentState1;
}
void buttonB(){
  currentState2=digitalRead(button2);
  if(lastState2==HIGH&&currentState2==LOW){
    Serial.println("LampuB_ON");
    nav=2;
    aritmatika1=HIGH;
    lcd.clear();
  } else if(lastState2==LOW&&currentState2==HIGH){
    Serial.println("LampuB_OFF");
    aritmatika1=LOW;
  }
  lastState2=currentState2;
}
void buttonC(){
  currentState3=digitalRead(button3);
  if(lastState3==HIGH&&currentState3==LOW){
    Serial.println("LampuC_ON");
    nav=3;
    aritmatika2=HIGH;
    lcd.clear();
  } else if(lastState3==LOW&&currentState3==HIGH){
    Serial.println("LampuC_OFF");
    aritmatika2=LOW;
  }
  lastState3=currentState3;
}
void buttonD(){
  currentState4=digitalRead(button4);
  if(lastState4==HIGH&&currentState4==LOW){
    Serial.println("LampuD_ON");
    nav=4; 
    lcd.clear();
  } else if(lastState4==LOW&&currentState4==HIGH){
    Serial.println("LampuD_OFF");
  }
  lastState4=currentState4;
}

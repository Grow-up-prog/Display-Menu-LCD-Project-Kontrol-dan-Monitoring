#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2); //menggunakan LCD 16x2
//variabel state
int state=0;
int nav=0;
int freq=0;
int aritmatika1=0;
int aritmatika2=0;
//setting nomor pin button
const int button1=8;
const int button2=9;
const int button3=10;
const int button4=11;
//variabel kondisi perubahan
int lastState1=LOW; //variabel penyimpan pembacaan state sebelumnya dari pin button
int lastState2=LOW;
int lastState3=LOW;
int lastState4=LOW;
int currentState1;int currentState2;int currentState3;int currentState4; //variabel penyimpanan nilai yang sedang berlangsung
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //PULLUP pada button pin
  pinMode(button1,INPUT_PULLUP);
  pinMode(button2,INPUT_PULLUP);
  pinMode(button3,INPUT_PULLUP);
  pinMode(button4,INPUT_PULLUP);
  //pull up inpun pin akan HIGH apabila switch terbuka dan LOW ketika switch ter-tutup 
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("PROTOTIPE V1.0");
  delay(300);
  lcd.clear();
}
void loop() {
  switch(state){
    case 0:
    lcd.setCursor(3,0);
    lcd.print("MENU UTAMA");
    lcd.setCursor(1,1);
    lcd.print("KONTROL MOTOR");
    buttonA();
    buttonB();
    buttonC();
    buttonD();
    if(nav==3){
      state=1;
    }else if(nav==1){
      state=2;
      lcd.clear();
    }
    break;      
    case 1:
    lcd.setCursor(3,0);
    lcd.print("MENU UTAMA");
    lcd.setCursor(0,1);
    lcd.print("MONITORING MOTOR");
    buttonA();
    buttonB();
    buttonC();
    buttonD();
    if(nav==2){
      state=0;
    }else if(nav==1){
      state=8;
      lcd.clear();
    }
    break;
    case 2:
    lcd.setCursor(4,0);
    lcd.print("SETTING");
    lcd.setCursor(6,1);
    lcd.print("MENU");
    buttonA();
    buttonB();
    buttonC();
    buttonD();
    if(nav==3){
      state=3;
    }else if(nav==2){
      state=3;
    }else if(nav==4){
      state=1;
    }   
    break;
    
    case 3:
    lcd.setCursor(4,0);
    lcd.print("SETTING");
    lcd.setCursor(3,1);
    lcd.print("ARAH MOTOR");
    buttonA();
    buttonB();
    buttonC();
    buttonD();
    if(nav==2){
      state=4;
    }else if(nav==4){
      state=1;
    }else if(nav==1){
      state=5;
      lcd.clear();
    }
    break;

    case 4:
    lcd.setCursor(4,0);
    lcd.print("SETTING");
    lcd.setCursor(3,1);
    lcd.print("FREQ MOTOR");
    buttonA();
    buttonB();
    buttonC();
    buttonD();
    if(nav==3){
      state=3;
    }else if(nav==4){
      state=1;
    }else if(nav==1){
      state=7;
    }
    break;
//  ================SET FREQ=================================
    case 7:
    lcd.setCursor(1,0);
    lcd.print("SET FREQ=");
    if(aritmatika1==HIGH&&aritmatika2==LOW){
      freq--;
      delay(100);
      lcd.clear();
    }else if(aritmatika1==LOW&&aritmatika2==HIGH){
      freq++;
      delay(100);
      lcd.clear();
    }
    lcd.setCursor(10,0);
    lcd.print(freq);
    lcd.setCursor(0,1);
    lcd.print("Save");
    lcd.setCursor(8,1);
    lcd.print("Back");
    buttonA();
    buttonB();
    buttonC();
    buttonD();
    if(nav==1){
      int nilai_freq=freq;//save nilai
      analogWrite(5,freq);
    }else if(nav==4){
      state=0;
      analogWrite(5,0);
    }
    break;
//  ================SET ARAH PUTAR CW=========================
    case 5:
    lcd.setCursor(0,0);
    lcd.print("ARAH PUTAR=");
    lcd.setCursor(12,0);
    lcd.print("<--");
    lcd.setCursor(0,1);
    lcd.print("Save");
    lcd.setCursor(10,1);
    lcd.print("Back");
    buttonA();
    buttonB();
    buttonC();
    buttonD();
    if(nav==1){
      int arah=50;
      analogWrite(6,arah);
    }else if(nav==4){
      lcd.clear();
      state=0;
    }else if(nav==2){
      state=6;
      lcd.clear();
    }
    break;  
//==============ARAH PUTAR CCW===================
    case 6:
    lcd.setCursor(0,0);
    lcd.print("ARAH PUTAR=");
    lcd.setCursor(12,0);
    lcd.print("-->");
    lcd.setCursor(0,1);
    lcd.print("Save");
    lcd.setCursor(10,1);
    lcd.print("Back");
    buttonA();
    buttonB();
    buttonC();
    buttonD();
    if(nav==4){
      state=0   ;
      lcd.clear();
    }else if(nav==3){
      state=5;
      lcd.clear();
    }else if(nav==1){
      int arah=150;
      analogWrite(6,arah);
    }
     break;
//===========END OF KONTROL MENU================

//=========START PROGRAM MONITORING MENU=============
 case 8:
    lcd.setCursor(3,0);
    lcd.print("MONITORING");
    lcd.setCursor(6,1);
    lcd.print("MENU");
    buttonA();
    buttonB();
    buttonC();
    buttonD();
    if(nav==3){
      state=9;
    }else if(nav==2){
      state=9;
    }else if(nav==4){
      state=1;
    }
  break;
  case 9:
    lcd.setCursor(3,0);
    lcd.print("MONITORING");
    lcd.setCursor(6,1);
    lcd.print("ARUS");
    buttonA();
    buttonB();
    buttonC();
    buttonD();
    if(nav==3){
      state=10;
    }else if(nav==4){
      state=8;
    }else if(nav==1){
      state=11;   
      lcd.clear();
    }
  break; 
  case 10:
    lcd.setCursor(3,0);
    lcd.print("MONITORING");
    lcd.setCursor(4,1);
    lcd.print("VOLTASE");
    buttonA();
    buttonB();
    buttonC();
    buttonD();
    if(nav==2){
      state=9;
    }else if(nav==4){
      state=8;
    }else if(nav==1){
      state=12;   
    }
  break; 
    case 11:
    lcd.setCursor(3,0);
    lcd.print("MONITORING");
    lcd.setCursor(0,1);
    lcd.print("ARUS=");
    lcd.setCursor(15,1);
    lcd.print("A");
    buttonA();
    buttonB();
    buttonC();
    buttonD();
    if(nav==4){
      state=8;
    }   
    break;
    case 12:
    lcd.setCursor(3,0);
    lcd.print("MONITORING");
    lcd.setCursor(0,1);
    lcd.print("VOLTASE=");
    lcd.setCursor(15,1);
    lcd.print("V");
    buttonA();
    buttonB();
    buttonC();
    buttonD();
    if(nav==4){
      state=8;
    }   
    break; 
  }
}

  
  

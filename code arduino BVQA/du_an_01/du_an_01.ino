#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int button1 = 3;
int button2 = 4;

double x = 250;
int led = 5;
void setup() {
   pinMode(led, OUTPUT);
   digitalWrite(led, LOW);
  Serial.begin(9600);   //Mở cổng Serial ở baudrate 9600 để giao tiếp với máy tính
  pinMode(button1, INPUT);  //Cài đặt chân D2 ở trạng thái đọc dữ liệu
 pinMode(button2, INPUT);
 
   lcd.begin();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("www.knastec.com");
  lcd.setCursor(2,1);
  lcd.print(" ");
  delay(3000);
  lcd.clear();
  //lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("AC: ");
  lcd.setCursor(0,1);
  lcd.print("ST: ");
  lcd.setCursor(11,0);
  lcd.print("V ");
  lcd.setCursor(11,1);
  lcd.print("V");
}

void loop() {
  int volt = analogRead(A0);
  double vol = map(volt,0,1023,0,500);
  double voltage  = (vol+9.56)/100.0 * 5.0;
  double AC = (((voltage/sqrt(2.0))/0.9)*20)+10.0;
  
  lcd.setCursor(4,0);
  lcd.print(AC);
  /*lcd.setCursor(9,0);
  lcd.print(voltage);*/
 
  
  int b1 = digitalRead(button1);    //Đọc trạng thái button
  int b2 = digitalRead(button2);    //Đọc trạng thái button
 
if (b1==1) {
  lcd.setCursor(4,0);
  lcd.print("      ");
  x = x+1;
}
else if (b2==1) {
   lcd.setCursor(4,0);
  lcd.print("      ");
  x = x-1;
}

else if (AC>=x){
  digitalWrite(led,HIGH);
  lcd.setCursor(11,1);
  lcd.print("X");
}
else if (AC<x){
  digitalWrite(led,LOW );
  lcd.setCursor(11,1);
  lcd.print("V");
}

  lcd.setCursor(4,1);
  lcd.print(x);

  delay(500);


}

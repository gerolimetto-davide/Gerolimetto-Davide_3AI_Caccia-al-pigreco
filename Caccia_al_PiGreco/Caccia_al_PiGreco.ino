int button1=6;
int button2=5;
int button3=4;
int button4=3;
int button5=2;

int migliorePunteggio=0; 
int vite=3;
int tempo;
//LCD
#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11,10, 9, 8);

byte Cuore[8] = {
        B00000,
        B01010,
        B11111,
        B11111,
        B11111,
        B01110,
        B00100,
        B00000
};

byte ghostChar[8] = {
        B00000,
        B01110,
        B10101,
        B11111,
        B11111,
        B11111,
        B10101,
        B00000
};



void CacciaAlPigreco()
{
  lcd.clear();
  lcd.print("punteggi:");
  lcd.print(migliorePunteggio);
  lcd.print(" ");
    if(vite==3){
  lcd.print(0);
  lcd.print(0);
  lcd.print(0);
  }
   if(vite==2){
  lcd.print(0);
  lcd.print(0);
   }
    if(vite==1){
  lcd.print(0);
   }
   
  lcd.setCursor(0,1); //la parte del LCD
  
  if(tempo==1)
  {
   lcd.write(1);
   int i=0;
   while(digitalRead(button1)==LOW && digitalRead(button2)==LOW && digitalRead(button3)==LOW && digitalRead(button4)==LOW && digitalRead(button5)==LOW){
    delay(1);
    i++;
   }
    if (digitalRead(button1)==HIGH)
    {
     if(i<3000)
     {
      migliorePunteggio++;
      delay(200);
      i=0;
      }
      else
      {
        delay(200);
       vite--;
      }
   }
   else{
        delay(200);
        vite--;
   }
  }
  if(tempo==2)
  {
   lcd.print(" ");
   lcd.write(1);
   int i=0;
   while(digitalRead(button1)==LOW && digitalRead(button2)==LOW && digitalRead(button3)==LOW && digitalRead(button4)==LOW && digitalRead(button5)==LOW){
    delay(1);
    i++;
   }
    if (digitalRead(button2)==HIGH)
    {
     if(i<3000)
     {
      migliorePunteggio++;
      delay(200);
      i=0;
      }
      else
      {
        delay(200);
        vite--;
      }
   }
   else{
        delay(200);
        vite--;
   }
  }

  if(tempo==3)
  {
    lcd.print(" ");
    lcd.print(" ");
    lcd.write(1);
   int i=0;
   while(digitalRead(button1)==LOW && digitalRead(button2)==LOW && digitalRead(button3)==LOW && digitalRead(button4)==LOW && digitalRead(button5)==LOW){
    delay(1);
    i++;
   }
    if (digitalRead(button3)==HIGH)
    {
     if(i<3000)
     {
      migliorePunteggio++;
      delay(200);
      i=0;
      }
      else
      {
        delay(200);
        vite--;
      }
   }
   else{
        delay(200);
        vite--;
   }
  }
  if(tempo==4)
  {
    lcd.print(" ");
    lcd.print(" ");
    lcd.print(" ");
   lcd.write(1);
   int i=0;
   while(digitalRead(button1)==LOW && digitalRead(button2)==LOW && digitalRead(button3)==LOW && digitalRead(button4)==LOW && digitalRead(button5)==LOW){
    delay(1);
    i++;
   }
    if (digitalRead(button4)==HIGH)
    {
     if(i<3000)
     {
      migliorePunteggio++;
      delay(200);
      i=0;
      }
      else
      {
        delay(200);
        vite--;
      }
   }
   else{
        delay(200);
        vite--;
   }
  }
  if(tempo==5)
  {
    lcd.print(" ");
    lcd.print(" ");
    lcd.print(" ");
    lcd.print(" ");
   lcd.write(1);
   int i=0;
   while(digitalRead(button1)==LOW && digitalRead(button2)==LOW && digitalRead(button3)==LOW && digitalRead(button4)==LOW && digitalRead(button5)==LOW){
    delay(1);
    i++;
   }
    if (digitalRead(button5)==HIGH)
    {
     if(i<3000)
     {
     migliorePunteggio++;
      delay(200);
      i=0;
      }
      else
      {
        delay(200);
        vite--;
      }
   }
   else{
        delay(200);
        vite--;
   }
  }
  if (vite == 0){
    lcd.clear();
    lcd.print("hai perso");
    delay(5000);
  }
 }

void loop() {
  // put your main code here, to run repeatedly: 
  //random
while(vite!=0){
randomSeed(analogRead(0));
tempo=random(1,6);//random da 1 a 5
CacciaAlPigreco();
}

}
void setup() {
  // put your setup code here, to run once:
pinMode(button1,INPUT);
pinMode(button2,INPUT);
pinMode(button3,INPUT);
pinMode(button4,INPUT);
pinMode(button5,INPUT);

lcd.begin(16, 2);
lcd.createChar(0, Cuore);
lcd.write(byte(0));
lcd.createChar(1,ghostChar);
lcd.write(byte(1));  
}

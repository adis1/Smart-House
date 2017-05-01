#include <Wire.h>
//#include <LCD.h>
#include <LiquidCrystal_I2C.h>

//-----LCD -------
#define I2C_ADDR 0x3F // <<- Adrsa pentru comunicare pe port I2C.
#define Rs_pin  0
#define Rw_pin  1
#define En_pin  2
#define BACKLIGHT_PIN 3
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7


LiquidCrystal_I2C lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);

int releu_1= 11;
int releu_2= 12;
int led_rosu=7;
int led_verde=6;
int inchis=1;
char comanda;

void setup()

{
  lcd.begin (20,4);
  
  pinMode(releu_1,OUTPUT);
  pinMode(releu_2,OUTPUT);
  
  pinMode(led_rosu,OUTPUT);
  pinMode(led_verde,OUTPUT);

  digitalWrite(led_verde, HIGH);
  digitalWrite(led_rosu, LOW);
  
  digitalWrite(releu_1, HIGH);
  digitalWrite(releu_2, HIGH);
  
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.home (); 
  lcd.print(" CAR WASH WITH SMS  ");  
  lcd.setCursor (0,2);
  lcd.print("  Bine ati venit!   ");

  Serial.begin(9600);  
  
 }

void loop()
{
 //if(comanda=='a'){digitalWrite(releu_1, HIGH);lcd.setCursor (0,3);lcd.print("--Apa deja oprita --"); }
 
if(comanda=='1'){digitalWrite(releu_1, LOW); 
                               lcd.setCursor(0,3);  lcd.print("-- Pornire apa 1E --"); 
                  delay(4000); lcd.setCursor (0,3); lcd.print("--   Oprire apa   --"); 
                  digitalWrite(releu_1, HIGH); 
                  }
if(comanda=='2'){digitalWrite(releu_1, LOW); 
                               lcd.setCursor(0,3);  lcd.print("-- Pornire apa 2E --"); 
                  delay(8000); lcd.setCursor (0,3); lcd.print("--   Oprire apa   --"); 
                  digitalWrite(releu_1, HIGH); 
                  }     

if(comanda=='c'){ digitalWrite(led_rosu, HIGH); digitalWrite(releu_2, LOW); 
                               lcd.setCursor(0,3);  lcd.print(" Se prepara cafeaua "); 
                  delay(8000);  digitalWrite(led_rosu, LOW);
                  lcd.setCursor (0,3); lcd.print(" Sunteti servit!    "); 
                  digitalWrite(releu_2, HIGH); 
                  }
            

 comanda = Serial.read();
 delay(2);
 
 
} 

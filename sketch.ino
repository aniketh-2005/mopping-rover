/*
 * Connections of Arduino and Bluetooth Module HC-05 for this Code:
 *       Arduino |  Bluetooth Module (HC-05)
 *            3  |  RX
 *            2  |  TX
 *           5V  |  5V
 *          GND  |  GND
 */


/* Code starts from here */

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#include <SoftwareSerial.h>   //including library for Software Serial communication
#include <Servo.h>
SoftwareSerial mySerial (2, 3);    //(RX, TX)

Servo tap_servo1;
//defining all the pins of Arduino
#define m1 4
#define m2 5
#define m3 6
#define m4 7
#define light1 8
#define sound 9 // Water






void setup()
{
  
    lcd.init();
  lcd.backlight(); // backlight ON 
  lcd.setCursor(0,0); 
  lcd.print("Mopping");  
  lcd.setCursor(2,1);  
  lcd.print("Robot"); 
  delay(3000);
  lcd.clear();
  //setting all the pins 
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);
  pinMode(sound, OUTPUT);
  pinMode(light1, OUTPUT);
  

  //defining baudrate
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop()
{

  
  
  if(mySerial.available() == 1)   //if communication is going on
  {
    char val = mySerial.read();   //Read the data recieved
    Serial.println("Recieved data is " + (String) val);
    if(val == 'F')    
    {
      //forward
      digitalWrite(m1, HIGH);
      digitalWrite(m2, LOW);
      digitalWrite(m3, HIGH);
      digitalWrite(m4, LOW);
      Serial.println("Going forward!");
      lcd.clear();
      lcd.setCursor(0,0); 
      lcd.print("Robot Moving");  
      lcd.setCursor(2,1);  
      lcd.print("Forward"); 
      
      
    }
    if(val == 'B')
    {
      //backward
      digitalWrite(m1, LOW);
      digitalWrite(m2, HIGH);
      digitalWrite(m3, LOW);
      digitalWrite(m4, HIGH);
      Serial.println("Going backward!");
      lcd.clear();
      lcd.setCursor(0,0); 
      lcd.print("Robot Moving");  
      lcd.setCursor(2,1);  
      lcd.print("Backward"); 
      
    }
    if(val == 'L')
    {
      //left
      digitalWrite(m1, LOW);
      digitalWrite(m2, HIGH);
      digitalWrite(m3, HIGH);
      digitalWrite(m4, LOW);
      Serial.println("Going left!");
      lcd.clear();
      lcd.setCursor(0,0); 
      lcd.print("Robot Moving");  
      lcd.setCursor(2,1);  
      lcd.print("Left"); 
      
    }
    if(val == 'R')
    {
      //right
      digitalWrite(m1, HIGH);
      digitalWrite(m2, LOW);
      digitalWrite(m3, LOW);
      digitalWrite(m4, HIGH);
      Serial.println("Going right!");
      lcd.clear();
      lcd.setCursor(0,0); 
      lcd.print("Robot Moving");  
      lcd.setCursor(2,1);  
      lcd.print("Right"); 
      
    }
    if(val == 'l')
    {
      //forward left
      digitalWrite(m1, LOW);
      digitalWrite(m2, LOW);
      digitalWrite(m3, HIGH);
      digitalWrite(m4, LOW);
      Serial.println("Going forward left!");
    }
    if(val == 'r')
    {
      //forward right
      digitalWrite(m1, HIGH);
      digitalWrite(m2, LOW);
      digitalWrite(m3, LOW);
      digitalWrite(m4, LOW);
      Serial.println("Going forward right!");
    }
    if(val == 'm')
    {
      //backward left
      digitalWrite(m1, LOW);
      digitalWrite(m2, LOW);
      digitalWrite(m3, LOW);
      digitalWrite(m4, HIGH);
    }
    if(val == 'n')
    {
      //backward right
      digitalWrite(m1, LOW);
      digitalWrite(m2, HIGH);
      digitalWrite(m3, LOW);
      digitalWrite(m4, LOW);
    }
    if(val == 'Z')
    {
      //sound on
      digitalWrite(sound, HIGH);
    }
    if(val == 'Y')
    {
      //light on
      digitalWrite(light1, HIGH);
      lcd.clear();
      lcd.setCursor(0,0); 
      lcd.print("Robot");  
      lcd.setCursor(2,1);  
      lcd.print("Cleaning"); 
      

  Serial.println("OPEN");
    }
    if(val == 'y')
    {
      //light on
      digitalWrite(light1, LOW);
            lcd.clear();
      lcd.setCursor(0,0); 
      lcd.print("Robot Stopped");  
      lcd.setCursor(2,1);  
      lcd.print("Cleaning");
 
  Serial.println("CLOSE");
    }
    if(val == 'S')
    {
      //all off
      digitalWrite(m1, LOW);
      digitalWrite(m2, LOW);
      digitalWrite(m3, LOW);
      digitalWrite(m4, LOW);
      digitalWrite(sound, LOW);
      lcd.clear();
      lcd.setCursor(0,0); 
      lcd.print("Robot");  
      lcd.setCursor(2,1);  
      lcd.print("Stopped"); 
      
    }
  }
}
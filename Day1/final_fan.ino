#define sw 5
#define debouncetime 50
int flickstate = LOW;
int flicksteadystate = LOW;
unsigned long lastDebouncetime = 0;
int currstate;
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
const int in1Pin = 18;  //ประกาศตัวแปร in1Pin ชนิด Integer ที่เป็นค่าคงที่ให้มีค่าเท่ากับ 18
const int in2Pin = 19;  //ประกาศตัวแปร in2Pin ชนิด Integer ที่เป็นค่าคงที่ให้มีค่าเท่ากับ 19
const int enA = 23;  //ประกาศตัวแปร enA ชนิด Integer ที่เป็นค่าคงที่ให้มีค่าเท่ากับ 23
int lv = 0;
#define OLED_RESET 4
#include <analogWrite.h>
Adafruit_SSD1306 display(OLED_RESET);

void setup() {
  Serial.begin(9600);
  pinMode(sw,INPUT_PULLUP);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3c); //initialize I2C addr 0x3c
  display.clearDisplay(); // clears the screen and buffer
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("0");
  display.setTextSize(2);
  display.display();
  pinMode(in1Pin, OUTPUT); //กำหนดให้ in1Pin เป็น OUTPUT
  pinMode(in2Pin, OUTPUT); //กำหนดให้ in2Pin เป็น OUTPUT
  pinMode(enA, OUTPUT); //กำหนดให้ enA เป็น OUTPUT

}


void loop() {
  currstate = digitalRead(sw);
  if(currstate != flickstate){
    lastDebouncetime = millis();
    flickstate = currstate;
  }
  if((millis()-lastDebouncetime)>debouncetime){
    if(flicksteadystate == HIGH && currstate == LOW){
      Serial.println("Button not pressed");
      lv++;
      lv=lv%4;
    }
    flicksteadystate = currstate;
    
  }
  if (lv == 0) //ถ้าค่าที่รับเข้ามาเป็น '+'
    {
      Serial.println("0"); //แสดงข้อความ "CW" ผ่าน Serial
      display.clearDisplay();
      display.setTextColor(WHITE);
      display.setCursor(0,0);
      display.println("0");
      display.setTextSize(2);
      display.display();
      analogWrite(enA, 0); //ใช้ analogWrite() เพื่อนตั้งค่า enA เป็น 200
      digitalWrite(in1Pin,LOW); //ใช้ digitalWrite() เพื่อตั้งค่า in1Pin เป็น LOW
      digitalWrite(in2Pin,HIGH); //ใช้ digitalWrite() เพื่อตั้งค่า in2Pin เป็น HIGH
    } else if (lv == 1) //ถ้าค่าที่รับเข้ามาเป็น '+'
    {
      Serial.println("1"); //แสดงข้อความ "CW" ผ่าน Serial
       display.clearDisplay();
      display.setTextColor(WHITE);
      display.setCursor(0,0);
      display.println("1");
      display.setTextSize(2);
      display.display();
      analogWrite(enA, 180); //ใช้ analogWrite() เพื่อนตั้งค่า enA เป็น 200
      digitalWrite(in1Pin,LOW); //ใช้ digitalWrite() เพื่อตั้งค่า in1Pin เป็น LOW
      digitalWrite(in2Pin,HIGH); //ใช้ digitalWrite() เพื่อตั้งค่า in2Pin เป็น HIGH
    }else if (lv == 2) //ถ้าค่าที่รับเข้ามาเป็น '+'
    {
      Serial.println("2"); //แสดงข้อความ "CW" ผ่าน Serial
       display.clearDisplay();
      display.setTextColor(WHITE);
      display.setCursor(0,0);
      display.println("2");
      display.setTextSize(2);
      display.display();
      analogWrite(enA, 200); //ใช้ analogWrite() เพื่อนตั้งค่า enA เป็น 200
      digitalWrite(in1Pin,LOW); //ใช้ digitalWrite() เพื่อตั้งค่า in1Pin เป็น LOW
      digitalWrite(in2Pin,HIGH); //ใช้ digitalWrite() เพื่อตั้งค่า in2Pin เป็น HIGH
    }else if (lv == 3) //ถ้าค่าที่รับเข้ามาเป็น '+'
    {
      Serial.println("3"); //แสดงข้อความ "CW" ผ่าน Serial
       display.clearDisplay();
      display.setTextColor(WHITE);
      display.setCursor(0,0);
      display.println("3");
      display.setTextSize(2);
      display.display();
      analogWrite(enA, 230); //ใช้ analogWrite() เพื่อนตั้งค่า enA เป็น 200
      digitalWrite(in1Pin,LOW); //ใช้ digitalWrite() เพื่อตั้งค่า in1Pin เป็น LOW
      digitalWrite(in2Pin,HIGH); //ใช้ digitalWrite() เพื่อตั้งค่า in2Pin เป็น HIGH
    }
 
}



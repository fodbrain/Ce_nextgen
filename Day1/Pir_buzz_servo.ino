int inp;  // ประกาศตัวแปรชื่อ inp แบบ integer สำหรับเก็บค่าที่อ่านจากขาดิจิตอล
#define bus 23
#include <ESP32Servo.h>
Servo myservo; //ประกาศตัวแปรแทน Servo

void setup() {
  Serial.begin(9600);  // เริ่มใช้งาน Serial Communication ที่ความเร็ว 9600 bps (บิตต่อวินาที)
  pinMode(18, INPUT);  // กำหนดขาดิจิตอลที่ขา 18 เป็นขาแสดงผล (INPUT) เพื่ออ่านค่าจากขาดิจิตอลนี้
  pinMode(bus, OUTPUT);  // กำหนดขาดิจิตอลที่ขา 18 เป็นขาแสดงผล (INPUT) เพื่ออ่านค่าจากขาดิจิตอลนี้
  myservo.attach(13);
}

void loop() {
  inp = digitalRead(18);  // อ่านค่าจากขาดิจิตอลที่ขา 18 และเก็บค่านั้นไว้ในตัวแปร inp
      // ส่งค่าที่อ่านจากขาดิจิตอล (ที่เก็บในตัวแปร inp) ไปยัง Serial Monitor
  if(inp == 1){
    Serial.println("found");
    digitalWrite(bus,HIGH);
    myservo.write(80);
    delay(1000);
  }else{
    digitalWrite(bus,LOW);
    myservo.write(10);
    delay(1000);
  }
}

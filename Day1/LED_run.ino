#define led1 12
#define led2 13
#define led3 14
#define sw 4
int a = 0;
int cnt=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(sw,INPUT);
}

void loop() {
  a = digitalRead(sw);
  digitalWrite(led1,HIGH);
  delay(500);
  digitalWrite(led2,HIGH);
  delay(500);
  digitalWrite(led3,HIGH);
  delay(500);
  digitalWrite(led3,LOW);
  delay(500);
  digitalWrite(led2,LOW);
  delay(500);
  digitalWrite(led1,LOW);
  delay(500);
  
}


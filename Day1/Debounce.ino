#define sw 4
#define debouncetime 50
int flickstate = LOW;
int flicksteadystate = LOW;
unsigned long lastDebouncetime = 0;
int currstate;
void setup() {
  Serial.begin(9600);
  pinMode(sw,INPUT_PULLUP);

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
    }else if(flicksteadystate == LOW && currstate == HIGH){
      Serial.println("Button pressed");
    }
    flicksteadystate = currstate;
  }

}

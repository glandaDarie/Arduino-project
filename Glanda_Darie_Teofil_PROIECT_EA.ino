#define pin1 9
#define pin2 10
#define pin3 11
#define pin4 12
int step_number = 0;
int potentiometru = A0;
int pwm = 0;
int valoare;


void setup() {
Serial.begin(9600);
pinMode(potentiometru, INPUT);
pinMode(pin1, OUTPUT);
pinMode(pin2, OUTPUT);
pinMode(pin3, OUTPUT);
pinMode(pin4, OUTPUT);
}

void loop() {
  valoare = analogRead(potentiometru);
  pwm = map(valoare, 1023, 0, 0, 255);
  OneStep(false);
  Serial.print("SENZORUL: "); Serial.println(valoare); Serial.print("\n");
  Serial.print("PWM: "); Serial.println(pwm); Serial.print("\n");
  delay(pwm);
}


void OneStep(bool direction_){
  if(direction_){
  switch(step_number){
  case 0:
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, LOW);
  break;
  case 1:
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, HIGH);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, LOW);
  break;
  case 2:
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, HIGH);
  digitalWrite(pin4, LOW);
  break;
  case 3:
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, HIGH);
  break;
    } 
  }else{
  switch(step_number){
  case 0:
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, HIGH);
  break;
  case 1:
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, HIGH);
  digitalWrite(pin4, LOW);
  break;
  case 2:
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, HIGH);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, LOW);
  break;
  case 3:
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, LOW);
} 
  }
  step_number++;
  if(step_number > 3){
    step_number = 0;
  }
}

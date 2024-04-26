int pwm = 12;
byte pwmValue=0;
int updown=0;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(pwm, pwmValue);
  if (pwmValue >=255) {
    updown=1;
    Serial.println("Top");
  }else if(pwmValue<=0){
    updown=0;
    Serial.println("Bottom");
  }
  if (updown==0){
    pwmValue=pwmValue+1;
  } else {
    pwmValue=pwmValue-1;
  }
  //Serial.println(pwmValue);
  //Serial.println(updown);
  delay(50);
}

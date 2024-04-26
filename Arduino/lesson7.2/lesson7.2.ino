int num = 0;
int val;
float v;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(num);
  Serial.print (val);
  v = val * 5.0 / 1023;
  Serial.print(", ");
  Serial.println(v);
  if (v <= 1.67) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
  }else if (v > 1.67 && v <= 3.33){
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(5, LOW);
  }else if (v > 3.33){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(5, HIGH);
  }
  delay(100);
}

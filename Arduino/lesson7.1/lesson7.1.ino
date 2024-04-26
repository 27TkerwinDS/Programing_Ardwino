void say_hi(void){
	Serial.print("yoooo");
}
int num (int n){
  return n * n;
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  say_hi();
}

void loop() {
  // put your main code here, to run repeatedly:
  say_hi();
  Serial.print(num(2));
  delay(1000);
}

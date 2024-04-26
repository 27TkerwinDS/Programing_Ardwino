int num = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (num < 100)
  {
    num = num + 1;
    Serial.println("Wait for it...");
    Serial.println(num);
    delay(1000);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("your feet smell.");
  delay(999999999999999999999999999999999999);
}

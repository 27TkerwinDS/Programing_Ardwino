void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  char Name []="Thomas";
  int age=70;
  Serial.print("There was a man named ");
  Serial.println(Name);
  Serial.print("he was ");
  Serial.println(age);
  Serial.print("he liked the name ");
  Serial.println(Name);
  Serial.print("he didn't like the age ");
  Serial.println(age);
}

void loop() {
  // put your main code here, to run repeatedly:
}

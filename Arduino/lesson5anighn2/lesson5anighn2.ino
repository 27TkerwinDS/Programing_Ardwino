int ledPin = 2; 
int potPin = A1;
int potIn; // variable to store the value coming from the potentiometer
int brightness; // variable to hold the pwm value

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  //reading from potentiometer
  potIn = analogRead(potPin);
  //mapping the Values between 0 to 255
  brightness = map(potIn, 0, 1023, 0, 255);
  analogWrite(ledPin, brightness);
  delay(1);
}

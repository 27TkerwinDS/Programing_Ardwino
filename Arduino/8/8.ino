int BUTTON = 50;
int LED = 8;
int BUZZER_PIN = 2;
bool test = false;
int PIN_BUZZER = 3;
int PIN_BUTTON = 48;
bool bEngine = false;
bool bBtnPrev = false;
int FREQ = 800;
int FREQ2 = 750;
bool check() {
  if (digitalRead(BUTTON) == LOW){
    return true;
  }else{
    return false;
  }
}
#include "pitches.h" 
#define BUZZER_PIN 2 
int melody[] = { 
	NOTE_A2, NOTE_G4, NOTE_G5, NOTE_G3, NOTE_A2
}; 
int durations[] = { 
	 // Notes duration goes here
  3, 3, 1.5, 2, .5,
}; 

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(BUZZER_PIN, OUTPUT); 
  Serial.begin(9600);
 
  Serial.println("started");

  // set our button to pullup mode.
  pinMode(PIN_BUTTON, INPUT_PULLUP);

  // set our buzzer pin to output
  pinMode(PIN_BUZZER, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  test = check();
  if (test == true) {
    digitalWrite(LED, HIGH);
    int size = sizeof(durations) / sizeof(int); 
	 for (int note = 0; note < size; note++) { 
	   //to calculate the note duration, take one second divided by the note type. 
	   //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc. 
	   int duration = 1000 / durations[note]; 
	   tone(BUZZER_PIN, melody[note], duration); 
	   //to distinguish the notes, set a minimum time between them. 
	   //the note's duration + 30% seems to work well: 
	   int pauseBetweenNotes = duration * .1; 
	   delay(pauseBetweenNotes); 
	   //stop the tone playing: 
	   noTone(BUZZER_PIN); 
	 } 
    digitalWrite(LED, LOW);
  }else{
    digitalWrite(LED, LOW);
    noTone(BUZZER_PIN);
  }
  // put your main code here, to run repeatedly:

  // was the button just pressed?
  if (digitalRead(PIN_BUTTON) == LOW && bBtnPrev == false) {
    // button was just pressed.
    Serial.println("enginee button was just pressed!");
    // toggle the engine.
    bEngine = !bEngine;

    // update the engine.
    if (bEngine) {
      // turn on engine.
      tone(PIN_BUZZER, FREQ);
      delay(25);
      tone(PIN_BUZZER, FREQ2);
      delay(25);
      tone(PIN_BUZZER, FREQ);
    } else {
      // turn of engine.
      noTone(PIN_BUZZER);
    }

    // update previous state.
    bBtnPrev = true;
  } 
  if (digitalRead(PIN_BUTTON) == HIGH && bBtnPrev == true) {
    // button was just released.
     Serial.println("button was just released!");

    // update previous state;
    bBtnPrev = false;
  }  
  delay(200);
}

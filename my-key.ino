#include <Keyboard.h>

const int pinButton1 = 2;
const int pinButton2 = 9;

int button1 = 0;
int button2 = 0;

void setup() {
  pinMode(pinButton1, INPUT);
  pinMode(pinButton2, INPUT);
  Keyboard.begin();
  delay(500);
}

void loop() {
  button1 = digitalRead(pinButton1);
  button2 = digitalRead(pinButton2);

  if(button1 == HIGH){
    Serial.println("BUTTON1");
    
    Keyboard.print("YOUR TEXT GOES HERE");
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
  }

  if(button2 == HIGH){
    Serial.println("BUTTON2");

    Keyboard.print("YOUR TEXT GOES HERE");
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
  }

  delay(250);
}

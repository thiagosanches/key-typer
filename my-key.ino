#include <Keyboard.h>
bool done = false;
void setup() {
  Keyboard.begin();
  delay(500);
}

void loop() {
  delay(500);
  if (!done) {
    done = true;
    Keyboard.print("MY-LONG-PASSWORD-GOES-HERE");
    Keyboard.press(KEY_RETURN);
    //THIS IS SO IMPORTANT, IF YOU FORGET IT, YOU ARE BRICKED.
    Keyboard.releaseAll();
  }
}

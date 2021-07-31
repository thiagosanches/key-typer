//References:
//https://github.com/TheCodingPlace/TheCodingPlace/blob/main/Characters.h
//https://www.youtube.com/watch?v=tvqA-JcTQNg
//https://www.youtube.com/watch?v=j05vj8zRP1o

//Based on the source code from:
//https://github.com/Lacerda53/duckduino/blob/0f9c1fd9a8233a288a7624a9abc08913aeab3926/ArduinoUNO_HID/Duckduino/Duckduino.ino

#define TOTAL_BUFFER 8

#define KEY_LEFT_CTRL   0x01
#define KEY_LEFT_SHIFT  0x02
#define KEY_LEFT_ALT    0x04
#define KEY_LEFT_GUI    0x08
#define KEY_RIGHT_CTRL  0x10
#define KEY_RIGHT_SHIFT 0x20
#define KEY_RIGHT_ALT   0x40
#define KEY_RIGHT_GUI   0x80
#define KEY_RIGHT_ARROW 0x4F
#define KEY_LEFT_ARROW  0x50
#define KEY_DOWN_ARROW  0x51
#define KEY_UP_ARROW    0x52
#define KEY_ESC         0x29T
#define KEY_F1          0x3A
#define KEY_F2          0x3B
#define KEY_F3          0x3C
#define KEY_F4          0x3D
#define KEY_F5          0x3E
#define KEY_F6          0x3F
#define KEY_F7          0x40
#define KEY_F8          0x41
#define KEY_F9          0x42
#define KEY_F10         0x43
#define KEY_F11         0x44
#define KEY_F12         0x45
#define KEY_PRTSCR      0x46
#define KEY_SCRLK       0x47
#define KEY_PAUSE       0x48
#define KEY_DEL         0x4C
#define KEY_INS         0x49
#define KEY_END         0x4D
#define KEY_HOME        0x4A
#define KEY_PGDN        0x4E
#define KEY_PGUP        0x4B
#define KEY_BACKSPC     0x2A
#define KEY_TAB         0x2B
#define KEY_ENTER       0x28
#define KEY_SPC         0x2C
#define KEY_MUTE        0x7F
#define KEY_VOL_UP      0x80
#define KEY_VOL_DOWN    0x81
#define KEY_UNDERLINE   0x2D
#define KEY_PLUS        0x2E
#define KEY_NONE 0x37

uint8_t buf[TOTAL_BUFFER ] = { 0 };
bool done = false;
void type(char *);
void enter();

void setup() {
  Serial.begin(9600);
  delay(200);
}

void loop() {

  if (!done) {
    type("YOUR BIG PASSWORD GOES HERE");
    enter();
    done = true;
  }
  delay(5000);
}

void type(char *txt) {
  while (*txt) {
    if (*txt >= 'a' && *txt <= 'z') {
      buf[2] = *txt - 'a' + 4;
    }
    else if (*txt >= 'A' && *txt <= 'Z') {
      buf[0] = KEY_LEFT_SHIFT;

      buf[2] = *txt - 'A' + 4;
    }
    else if (*txt >= '0' && *txt <= '9') {
      if (*txt == '0') {
        buf[2] = *txt - 9;
      }
      else {
        buf[2] = *txt - 19;
      }
    }
    else if (*txt == ' ') {
      buf[2] = KEY_SPC;
    }
    else if (*txt == '&') {
      buf[0] = KEY_LEFT_SHIFT;
      buf[2] = 0x24;
    }
    else if (*txt == '>') {
      buf[0] = KEY_LEFT_SHIFT;
      buf[2] = KEY_NONE;
    }
    else if (*txt == '<') {
      buf[0] = KEY_LEFT_SHIFT;
      buf[2] = 0x36;
    }
    else if (*txt == '|') {
      buf[0] = KEY_LEFT_SHIFT;
      buf[2] = 0x64;
    }
    else if (*txt == '/') {
      buf[0] = KEY_RIGHT_ALT;
      buf[2] = 0x14;
    }
    else if (*txt == '\\') {
      buf[2] = 0x34;
    }
    else if (*txt == ';') {
      buf[2] = 0x38;
    }
    else if (*txt == '(') {
      buf[0] = KEY_LEFT_SHIFT;
      buf[2] = 0x26;
    }
    else if (*txt == ')') {
      buf[0] = KEY_LEFT_SHIFT;
      buf[2] = 0x27;
    }
    else if (*txt == '{') {
      buf[0] = KEY_RIGHT_ALT;
      buf[2] = 0x24;
    }
    else if (*txt == '}') {
      buf[0] = KEY_RIGHT_ALT;
      buf[2] = 0x27;
    }
    else if (*txt == '[') {
      buf[0] = KEY_RIGHT_ALT;
      buf[2] = 0x25;
    }
    else if (*txt == ']') {
      buf[0] = KEY_RIGHT_ALT;
      buf[2] = 0x26;
    }
    else if (*txt == '-') {
      buf[2] = 0x2D;
    }
    else if (*txt == '=') {
      buf[2] = 0x2E;
    }
    else if (*txt == '.') {
      buf[2] = 0x37;
    }
    else if (*txt == ',') {
      buf[2] = 0x36;
    }
    else if (*txt == '_') {
      buf[0] = KEY_LEFT_SHIFT;
      buf[2] = KEY_UNDERLINE;
    }
    else if (*txt == '+') {
      buf[0] = KEY_LEFT_SHIFT;
      buf[2] = KEY_PLUS;
    }
    else {
      buf[2] = KEY_NONE;
    }

    Serial.write(buf, 8);   // Send keypress
    buf[0] = 0;
    buf[2] = 0;
    Serial.write(buf, 8);   // Release key
    txt++;
  }
}

void enter() {
  buf[2] = KEY_ENTER;

  Serial.write(buf, 8);       // Send keypress
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf, 8);
}

#include <string.h>

const int LED = 10
const int RESET_LED = 4;

const char* MORSE_CODE[] = {
        ".- ",    // A
        "-... ",  // B
        "-.-. ",  // C
        "-.. ",   // D
        ". ",     // E
        "..-. ",  // F
        "--. ",   // G
        ".... ",  // H
        ".. ",    // I
        ".--- ",  // J
        "-.- ",   // K
        ".-.. ",  // L
        "-- ",    // M
        "-. ",    // N
        "--- ",   // O
        ".--. ",  // P
        "--.- ",  // Q
        ".-. ",   // R
        "... ",   // S
        "- ",     // T
        "..- ",   // U
        "...- ",  // V
        ".-- ",   // W
        "-..- ",  // X
        "-.-- ",  // Y
        "--.. "   // Z
};

char* getMorseCode(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return MORSE_CODE[ch - 'A'];
    }
    else if (ch == ' ') {
        return "/ ";
    }
    else {
        return "";
    }
}

void dot() {
  digitalWrite(LED, HIGH);
  delay(200);
  digitalWrite(LED, LOW);
  delay(200);
}

void dash() {
  digitalWrite(LED, HIGH);
  delay(600);
  digitalWrite(LED, LOW);
  delay(200);
}

void displayMorseCode(const char* morseCode) {
  while(*morseCode) {
    if(*morseCode == '.') {
      dot();
    }
    else if(*morseCode == '-') {
      dash();
    }
    else if (*morseCode == '/') {
      delay(400);
    }
    morseCode++;
  }
  delay(800);
}

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(RESET_LED, OUTPUT);
}

void loop() {
  String message = "Hello World";
  message.toUpperCase();
  for(int i = 0; i < message.length(); i++) {
    char ch = message[i];
    const char* morseCode = getMorseCode(ch);
    displayMorseCode(morseCode);
  }

  digitalWrite(RESET_LED, HIGH);
  delay(10000);
  digitalWrite(RESET_LED, LOW);
}

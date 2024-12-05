#include <Keypad.h>

const byte ROWS = 4;  // 4 rows
const byte COLS = 3;  // 3 columns
char keys[ROWS][COLS] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'*', '0', '#'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};     // Connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3};        // Connect to the column pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

String inputBuffer = "";
const int maxLength = 5;  // Maximum length of ID number

void setup() {
    Serial.begin(9600);
}

void loop() {
    char key = keypad.getKey();

    if (key) {
        if (key == '#') {
            // Send the complete number when # is pressed
            if (inputBuffer.length() > 0) {
                Serial.println("ID:" + inputBuffer);
                inputBuffer = ""; // Clear buffer
            }
        }
        else if (key == '*') {
            // Clear the current input
            inputBuffer = "";
            Serial.println("CLEAR");
        }
        else if (key >= '0' && key <= '9' && inputBuffer.length() < maxLength) {
            inputBuffer += key;
            Serial.println("KEY:" + String(key));
        }
    }
}

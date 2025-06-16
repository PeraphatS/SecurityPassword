#include <Wire.h>
#include <Keypad.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define BUZZER_PIN 14
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_SDA 21
#define OLED_SCL 22
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire);

// ---- Keypad setup ----
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {19, 18, 5, 17};   // ESP32 GPIOs
byte colPins[COLS] = {16, 4, 2, 15};    // ESP32 GPIOs
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

String inputPassword = "";
const String correctPassword = "0000"; //password set
int attempts = 0;
const int maxAttempts = 3;

void setup() {
  Serial.begin(115200);
  delay(1000);

  // OLED
  Wire.begin(OLED_SDA, OLED_SCL);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED not found");
    while (true);
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Password Security");
  display.display();
  delay(1000);
}

void loop() {
  char key = keypad.getKey();
  if(key){
    if (key == '#'){
      if(inputPassword == correctPassword){
        display.clearDisplay();
        display.setCursor(0, 0);
        display.println("Access Granted");
        display.display();
        tone(BUZZER_PIN, 1000);
        delay(200);
        noTone(BUZZER_PIN);
        inputPassword = "";
        attempts = 0;
      }
      else{
        attempts++;
        display.clearDisplay();
        display.setCursor(0, 0);
        display.println("Access Denied");
        display.print("Attempts: ");
        display.println(attempts);
        display.display();
        tone(BUZZER_PIN, 2000);
        delay(300);
        noTone(BUZZER_PIN);
        inputPassword = "";
        if(attempts >= maxAttempts){
          display.clearDisplay();
          display.setCursor(0, 0);
          display.println("Locked out");
          display.display();
        }

      }
  }else if(key == '*'){ //clear input password
      inputPassword ="";
      display.clearDisplay();
      display.setCursor(0, 0);
      display.print("Cleared");
      display.display();
  }else{
    inputPassword += key;
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Enter Code:");
    display.print(inputPassword);
    display.display();
  }
}
  delay(100); // this speeds up the simulation
}

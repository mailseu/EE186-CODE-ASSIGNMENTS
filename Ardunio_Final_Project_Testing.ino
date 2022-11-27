#include <Servo.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#define continueSwitch 10

LiquidCrystal_I2C lcd(0x27, 16, 2);

const char resetSwitch = 11;
int joyX = 0;
int joyY = 1;
long timer;

Servo servoX;
Servo servoY;

void setup(){
  lcd.begin();
  lcd.backlight();
  
  servoX.attach(9);
  servoY.attach(8);
  pinMode(resetSwitch, INPUT_PULLUP);
  pinMode(continueSwitch, INPUT);

  programIntroduction();

  Serial.begin(9600);
}

int resetToggle() {
  bool resetState = digitalRead(resetSwitch);
  bool outputState, pressed = false;

  if(resetState == pressed){
    outputState = true;
  } else {
    outputState = false;
  }
  return outputState;
}

int programIntroduction() {
  lcd.setCursor(1,0);
  lcd.print("Welcome to the");
  lcd.setCursor(0,1);
  lcd.print("Marble Maze Game!");
  delay(4000);

  lcd.clear();

  lcd.setCursor(2.8,0);
  lcd.print("Project By:");
  delay(2000);
  lcd.setCursor(2,1);
  lcd.print("Henry Samala");
  delay(3000);
 
  lcd.clear();
}
int programResetMSG(){
  lcd.print("Resetting Maze...");
  delay(3000);
     
   lcd.clear();
     
   lcd.setCursor(1,0);
   lcd.print("Press Continue");
   lcd.setCursor(0,1);
   lcd.print("To Continue Game");
} 
int gameCountdown(){
  lcd.setCursor(0,0);
  lcd.print("Game Starts In...");

  delay(500);
    for(int i = 3; i > 0; i--){
      lcd.setCursor(0,1);
      lcd.print(i);
      delay(1000);
    }
}

void loop () {
  int displayMessage = 0, programStart = 0;

while(programStart == 0) {

  servoX.write(130);
  servoY.write(130);
  delay(100);
  
  while(digitalRead(continueSwitch) == LOW) {
    
    if(displayMessage == 0){
      lcd.print("Press Continue");
      lcd.setCursor(0,1);
      lcd.print("To Start...");
   
      displayMessage++;
    }
    
    if(digitalRead(continueSwitch) == HIGH){
      lcd.clear();

      gameCountdown();
      
      programStart++;
      displayMessage = 0;
      break;
     } 
  }
}

lcd.clear();

while(programStart == 1) {
  int valX = analogRead(joyX), valY = analogRead(joyY);
  int valueX, valueY;
  bool resetStatus = resetToggle();
  long timeElapsed;

  if(displayMessage == 0){
    lcd.print("Game Time:");
    timer = millis();
    delay(400);
    displayMessage++;
  }

  lcd.setCursor(0,1);
  lcd.print((millis() - timer) / 1000.0); 
  
  valX = map(valX, 0, 1023, 10, 170);
  valY = map(valY, 0, 1023, 10, 170);
  
  servoX.write(valX); 
  servoY.write(valY);
  
  delay(5);
  
  Serial.println(valX); //91 resting postion
  Serial.println(valY); //90 resting position

  if(resetStatus == true){
   displayMessage = 0;
   while(resetStatus == true) {  

    if(displayMessage == 0) {
     servoX.write(130);
     servoY.write(130);

     lcd.clear();
     lcd.print("Elapsed Time:");
     delay(1000);
     lcd.setCursor(1,1);
     lcd.print(((millis() - timer) / 1000.0) - 1);
     delay(4000);

     lcd.clear();
     
     programResetMSG();
     displayMessage++;
    }
   
    if(digitalRead(continueSwitch) == HIGH) {
     lcd.clear();
     resetStatus = false;
     programStart = 0;
    } 
    else {
      resetStatus = true;
      delay(10);
    }
   
   delay(100);
   }
  }
 }
}

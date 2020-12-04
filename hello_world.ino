// include the library code:
#include <LiquidCrystal.h>
#include <Keypad.h>

//pinMode ();

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {7, 6, 13, 0}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {10, 9, 8}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  //lcd.begin(16, 2);
  lcd.begin(16, 2);
  // Print a message to the LCD.
  //lcd.print("hello, world!");

  //void setup keypad
  Serial.begin(9600);
  
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  //lcd.print(millis() / 1000);
  
  //void loop keypad
  char key = keypad.getKey();
  
  char cont;
  if (key){
      lcd.println(key);
      delay(300);
      lcd.clear();
      
      while(key > '0'){
        key--;
        lcd.println(key);
        delay(200);
        lcd.clear();
        
        if(key == '0'){
          break;
        }
      }
       
    }
}

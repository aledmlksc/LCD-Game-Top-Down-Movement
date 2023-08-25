// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int player_pos_row=0;
int player_pos_col=0;
int button_pin=13;
int button_state=0;

int button_pin1=10;
int button_state1=0;

int button_pin2=9;
int button_state2=0;
// make some custom characters:
byte empty[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};
//beast0f1
byte image0_0_0[8] = {B00000, B00111, B10000, B10100, B10010, B10001, B10011, B10011};
byte image0_0_1[8] = {B00000, B11100, B00001, B00101, B01001, B10001, B11001, B11001};
byte image0_0_2[8] = {B10000, B10001, B10001, B10011, B10100, B10000, B11100, B00011};
byte image0_0_3[8] = {B00001, B10001, B10001, B11001, B00101, B00001, B00111, B11000};
//beast0f2
byte image0_1_0[8] = {B00000, B00111, B10000, B10100, B10010, B10001, B10011, B10011};
byte image0_1_1[8] = {B00000, B11100, B00001, B00101, B01001, B10001, B11001, B11001};
byte image0_1_2[8] = {B10000, B10000, B10001, B10010, B10010, B10001, B11100, B00011};
byte image0_1_3[8] = {B00001, B00001, B10001, B01001, B01001, B10001, B00111, B11000};

byte armsDown[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b00100,
  0b01110,
  0b10101,
  0b00100,
  0b01010
};

byte armsUp[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b10101,
  0b01110,
  0b00100,
  0b00100,
  0b01010
};

void setup() {
  // initialize LCD and set up the number of columns and rows:
  lcd.begin(16, 2);

  // create a new character
  lcd.createChar(0, empty);
  lcd.createChar(1, armsDown);
  lcd.createChar(2, armsUp);
  
//  lcd.createChar(3, image0_0_0);
//  lcd.createChar(4, image0_0_1);
//  lcd.createChar(5, image0_0_2);
//  lcd.createChar(6, image0_0_3);
//  
//  lcd.createChar(7, image0_1_0);
//  lcd.createChar(8, image0_1_1);
//  lcd.createChar(9, image0_1_2);
//  lcd.createChar(10, image0_1_3);
  // set the cursor to the top left
   lcd.setCursor(player_pos_col, player_pos_row);


lcd.home();
}

void loop() {
  // read the potentiometer on A0:
  int sensorReading = analogRead(A0);
  // map the result to 200 - 1000:
  int delayTime = map(sensorReading, 0, 1023, 200, 1000);
  // draw the little man, arms down:
 
  lcd.write(1);
  delay(delayTime/4);
  lcd.setCursor(player_pos_col, player_pos_row);
  lcd.write(2);
  lcd.setCursor(player_pos_col, player_pos_row);
  
  

  
  button_state=digitalRead(button_pin);
  button_state1=digitalRead(button_pin1);
  button_state2=digitalRead(button_pin2);
  
  if (button_state == HIGH and player_pos_col<15) {
    lcd.write(byte(0));
    player_pos_col+=1;
    lcd.setCursor(player_pos_col, player_pos_row);
    
  }
  if (button_state1 == HIGH and player_pos_col>0) {
    lcd.write(byte(0));
    player_pos_col-=1;
    lcd.setCursor(player_pos_col, player_pos_row);
  }
  if (button_state2 == HIGH) {
    if (player_pos_row==0){
      
      lcd.write(byte(0));
      player_pos_row=1;
      lcd.setCursor(player_pos_col, player_pos_row);
    }
    else if (player_pos_row==1){
      lcd.write(byte(0));
      player_pos_row=0;
      lcd.setCursor(player_pos_col, player_pos_row);
    }
    
  }
}


void beast0f1() {

lcd.setCursor(14, 0);
lcd.write(3);
lcd.setCursor(15, 0);
lcd.write(4);
lcd.setCursor(14, 1);
lcd.write(5);
lcd.setCursor(15, 1);
lcd.write(6);
}
void beast0f2() {

lcd.setCursor(14, 0);
lcd.write(7);
lcd.setCursor(15, 0);
lcd.write(8);
lcd.setCursor(14, 1);
lcd.write(9);
lcd.setCursor(15, 1);
lcd.write(10);
}

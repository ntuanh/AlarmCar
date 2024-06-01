// https://wokwi.com/projects/399424216918261761

// setup music
#include "pitches.h"

// Define pin 10 for buzzer, you can use any other digital pins (Pin 0-13)
 int buzzer = 10;

// Change to 0.5 for a slower version of the song, 1.25 for a faster version
const float songSpeed = 1.0;

// Defining frequency of each music note
#define NOTE_C4 262
#define NOTE_D4 294
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_G4 392
#define NOTE_A4 440
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_D5 587
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_G5 784
#define NOTE_A5 880
#define NOTE_B5 988

// Music notes of the song, 0 is a rest/pulse
int notes[] = {
    NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
    NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
    NOTE_A4, NOTE_G4, NOTE_A4, 0,

    NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
    NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
    NOTE_A4, NOTE_G4, NOTE_A4, 0,

    NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
    NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, 0,
    NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, 0,
    NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, 0,

    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
    NOTE_D5, NOTE_E5, NOTE_A4, 0,
    NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, 0,
    NOTE_C5, NOTE_A4, NOTE_B4, 0,

    NOTE_A4, NOTE_A4,
    //Repeat of first part
    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
    NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
    NOTE_A4, NOTE_G4, NOTE_A4, 0,

    NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
    NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
    NOTE_A4, NOTE_G4, NOTE_A4, 0,

    NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
    NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, 0,
    NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, 0,
    NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, 0,

    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
    NOTE_D5, NOTE_E5, NOTE_A4, 0,
    NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, 0,
    NOTE_C5, NOTE_A4, NOTE_B4, 0,
    //End of Repeat

    NOTE_E5, 0, 0, NOTE_F5, 0, 0,
    NOTE_E5, NOTE_E5, 0, NOTE_G5, 0, NOTE_E5, NOTE_D5, 0, 0,
    NOTE_D5, 0, 0, NOTE_C5, 0, 0,
    NOTE_B4, NOTE_C5, 0, NOTE_B4, 0, NOTE_A4,

    NOTE_E5, 0, 0, NOTE_F5, 0, 0,
    NOTE_E5, NOTE_E5, 0, NOTE_G5, 0, NOTE_E5, NOTE_D5, 0, 0,
    NOTE_D5, 0, 0, NOTE_C5, 0, 0,
    NOTE_B4, NOTE_C5, 0, NOTE_B4, 0, NOTE_A4};

// Durations (in ms) of each music note of the song
// Quarter Note is 250 ms when songSpeed = 1.0
int durations[] = {
    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 375, 125,

    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 375, 125,

    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 125, 250, 125,

    125, 125, 250, 125, 125,
    250, 125, 250, 125,
    125, 125, 250, 125, 125,
    125, 125, 375, 375,

    250, 125,
    //Rpeat of First Part
    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 375, 125,

    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 375, 125,

    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 125, 250, 125,

    125, 125, 250, 125, 125,
    250, 125, 250, 125,
    125, 125, 250, 125, 125,
    125, 125, 375, 375,
    //End of Repeat

    250, 125, 375, 250, 125, 375,
    125, 125, 125, 125, 125, 125, 125, 125, 375,
    250, 125, 375, 250, 125, 375,
    125, 125, 125, 125, 125, 500,

    250, 125, 375, 250, 125, 375,
    125, 125, 125, 125, 125, 125, 125, 125, 375,
    250, 125, 375, 250, 125, 375,
    125, 125, 125, 125, 125, 500};
#include<Wire.h>
#include <LiquidCrystal_I2C.h>

//#include "sound.h"

LiquidCrystal_I2C lcd(0x27, 16, 2); // Địa chỉ I2C là 0x27, 16 cột và 2 hàng

/* Địa chỉ của DS1307 */
const byte DS1307 = 0x68;
/* Số byte dữ liệu sẽ đọc từ DS1307 */
const byte NumberOfFields = 7;
 
/* khai báo các biến thời gian */
int second, minute, hour, day, wday, month, year;
 
const int right_forward = 6 ;
const int right_backward = 5 ;
const int left_forward = 7 ;
const int left_backward = 8 ;
const int led_blue = 11  ;
const int led_red = 12 ;


int hour_main = 10 ;
int minute_main =27 ;

const int button_1 = 4  ;
const int button_2 = 3 ;
const int button_3 = 2 ;


int check ;


void setup(){
  Wire.begin();
  /* cài đặt thời gian cho module */
  setTime(10, 26 , 55, 7, 1, 6, 24); // 12:30:45 CN 08-02-2015
  Serial.begin(9600);

  pinMode(right_forward , OUTPUT);
  pinMode(left_forward , OUTPUT);
  pinMode(right_backward , OUTPUT);
  pinMode(left_backward , OUTPUT);
  pinMode(led_blue , OUTPUT);
  pinMode(led_red, OUTPUT);
  pinMode(buzzer, OUTPUT);

  lcd.init(); 

  pinMode(button_3, INPUT_PULLUP);
  pinMode(button_2, INPUT_PULLUP);
  pinMode(button_1 , INPUT_PULLUP);

  pinMode(led_blue, OUTPUT);
  check = 0 ;
  
}
// layout 

class Status {
  //setup();
  public:
  void normal();
  void getup_status1();
  void getup_status2();
  void Alarm(int x, int y);
  void mode();
};


void Status::normal(){
  lcd.noBacklight();
  XY(0, 0);  // Di chuyển con trỏ đến vị trí (0, 0)
  if ( hour < 10 ){
    lcd.print(0);
    XY(1,0);
  }
  lcd.print(hour);
  XY(2,0);
  lcd.print(":");
  XY(3,0);
  if(minute < 10 ){
    lcd.print(0);
    XY(4, 0);}
  lcd.print(minute);
  XY(5,0);
  lcd.print(":");
  XY(6, 0);
  if(second < 10 ){
    lcd.print(0);
    XY(7, 0);}
  lcd.print(second);

  int location = 11;
  XY(location,0);
  if(day < 10 ){
    lcd.print(0);
    XY(location+1, 0);}
  lcd.print(day);
  XY(location+2,0);
  lcd.print("/");
  XY(location+3,0);
  if(month < 10 ){
    lcd.print(0);
    XY(location+4, 0);}
  lcd.print(month);
  XY(location+5,0);



}


void Status::getup_status1(){
  sound();
  lcd.backlight();
  XY(0, 1);
  lcd.print("                ");
  XY(4, 1);
  lcd.print("GET UP !!!");
  digitalWrite(buzzer, 1);
    GO(0);
    stop();
    GO(1);
    stop();
    GO(-1);
    stop();
}

void Status::getup_status2(){
  //sound();
  lcd.print("                ");
  XY(0, 1);
  lcd.print("Have a good day! ");
  delay(2000);
  XY(0, 1);
  lcd.print("                ");

}

void Status::Alarm(int x, int y){
  XY(x,y);
  lcd.print("                           ");
  lcd.print("Alarm  ");

  int location = 7  ;
  XY( location, 1);
  if ( hour_main < 10){
    lcd.print(0);
    XY(location + 1, 1);
  }
  lcd.print(hour_main);
  XY(location+ 2, 1);
  lcd.print(":");
  XY(location + 3, 1);
  if ( minute_main < 10){
    lcd.print(0);
    XY(location+4, 1);
    
  }
  lcd.print(minute_main);
}

void Status::mode(){
  XY(0,0);
  lcd.print("                ");
  XY(0,1);
  lcd.print("                ");
  int time =  300 ;
  XY(0,0);
  lcd.print("set alarm -.-");
  XY(1,1);
  int hour= hour_main; int minute= minute_main;
  int hour_location = 9 ; int minute_location = 12 ;
    XY(hour_location-1, 1 );
    lcd.print("[");
    XY(hour_location+2, 1);
    lcd.print("]");
  while(true){
    delay(time);
    if ( hour < 10 ){
      XY(hour_location , 1);
      lcd.print(" ");
      XY(hour_location+1, 1);
    }else XY(hour_location , 1);;
    lcd.print(hour);
    if(digitalRead(button_1) == 0){
      hour++;
      delay(time);
      }
    if(digitalRead(button_2) == 0)break ;
    hour = hour % 24 ;
  }
  XY(hour_location-1, 1 );
  lcd.print(" ");
  XY(hour_location+2, 1);
  lcd.print(" ");
  XY(minute_location-1, 1 );
  lcd.print("[");
  XY(minute_location+2, 1);
  lcd.print("]");
  while(true){
    delay(time);
    if ( minute < 10 ){
      XY(minute_location , 1);
      lcd.print(0);
      XY(minute_location+1, 1);
    }else XY(minute_location , 1);;
    lcd.print(minute);
    if(digitalRead(button_1) == 0){
      minute++;
      delay(time);
    }
    if(digitalRead(button_2) == 0){
      break;
    }
    minute = minute % 60 ;
  }
  
  hour_main = hour ;
  minute_main = minute;
  XY(0,0);
  lcd.print("                ");
  XY(0,1);
  lcd.print("                ");
  delay(time);
}

void loop(){
  Status status ;
  if ( digitalRead(button_2) == 1){digitalWrite(led_blue,1);}

  if( digitalRead(button_2) == 0)status.mode();
  if (minute!= minute_main && check == 2){
    check =0 ;
    XY(0, 1);
  }

    /* Đọc dữ liệu của DS1307 */
  readDS1307();

  status.normal();

  XY(13 , 1 );
  lcd.print("^.^");
  if ( hour == hour_main && minute == minute_main  && check == 0){
    check = 1;
    while( check == 1){
      status.getup_status1();
    
    if ( digitalRead(button_3) == 0 ){
      status.getup_status2();
      check = 2;
    }
    }
  }

}





void XY( int x , int y){
  lcd.setCursor(x, y);
}

// *** motor driver 

void stop(){
  digitalWrite(right_backward,0);
  digitalWrite(right_forward, 0);
  digitalWrite(left_backward,0);
  digitalWrite(left_forward, 0);
}

void GO( int x ){
  digitalWrite(buzzer,1);
  int time = 500 ;
  if ( x == 0 ){
    digitalWrite(right_forward,1);
    digitalWrite(right_backward, 0);
    digitalWrite(left_forward,1);
    digitalWrite(left_backward, 0);
    delay(time);
    stop();
  }else {
    if ( x == 1 ) {
      digitalWrite(right_forward,1);
      digitalWrite(right_backward, 0);
      digitalWrite(left_forward,0);
      digitalWrite(left_backward, 0);
      delay(time);
      stop();
    }else {
      digitalWrite(right_forward,0);
      digitalWrite(right_backward, 0);
      digitalWrite(left_forward,1);
      digitalWrite(left_backward, 0);
      delay(time);
      stop();
    }
  }
  digitalWrite(buzzer,0);
}

// set time 
void readDS1307()
{
        Wire.beginTransmission(DS1307);
        Wire.write((byte)0x00);
        Wire.endTransmission();
        Wire.requestFrom(DS1307, NumberOfFields);
        
        second = bcd2dec(Wire.read() & 0x7f);
        minute = bcd2dec(Wire.read() );
        hour   = bcd2dec(Wire.read() & 0x3f); // chế độ 24h.
        wday   = bcd2dec(Wire.read() );
        day    = bcd2dec(Wire.read() );
        month  = bcd2dec(Wire.read() );
        year   = bcd2dec(Wire.read() );
        year += 2000;    
}
/* Chuyển từ format BCD (Binary-Coded Decimal) sang Decimal */
int bcd2dec(byte num)
{
        return ((num/16 * 10) + (num % 16));
}
/* Chuyển từ Decimal sang BCD */
int dec2bcd(byte num)
{
        return ((num/10 * 16) + (num % 10));
}
/* cài đặt thời gian cho DS1307 */
void setTime(byte hr, byte min, byte sec, byte wd, byte d, byte mth, byte yr)
{
        Wire.beginTransmission(DS1307);
        Wire.write(byte(0x00)); // đặt lại pointer
        Wire.write(dec2bcd(sec));
        Wire.write(dec2bcd(min));
        Wire.write(dec2bcd(hr));
        Wire.write(dec2bcd(wd)); // day of week: Sunday = 1, Saturday = 7
        Wire.write(dec2bcd(d)); 
        Wire.write(dec2bcd(mth));
        Wire.write(dec2bcd(yr));
        Wire.endTransmission();
}

// sound
void sound()
{  const int totalNotes = sizeof(notes) / sizeof(int);
  // Loop through each note
  for (int i = 0; i < totalNotes; i++)
  {
    const int currentNote = notes[i];
    float wait = durations[i] / songSpeed;
    // Play tone if currentNote is not 0 frequency, otherwise pause (noTone)
    if (currentNote != 0)
    {
      tone(buzzer, notes[i], wait); // tone(pin, frequency, duration)
    }
    else
    {
      noTone(buzzer);
    }
    // delay is used to wait for tone to finish playing before moving to next loop
    delay(wait);

    if(digitalRead(button_3) == 0)break;
  }
}
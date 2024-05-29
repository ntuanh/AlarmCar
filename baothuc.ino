#include<Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Địa chỉ I2C là 0x27, 16 cột và 2 hàng

/* Địa chỉ của DS1307 */
const byte DS1307 = 0x68;
/* Số byte dữ liệu sẽ đọc từ DS1307 */
const byte NumberOfFields = 7;
 
/* khai báo các biến thời gian */
int second, minute, hour, day, wday, month, year;
 
const int right_forward = 5 ;
const int right_backward = 6 ;
const int left_forward = 7 ;
const int left_backward = 8 ;
const int led_blue = 11  ;
const int led_red = 12 ;
const int buzzer = 10 ;

int hour_main = 4 ;
int minute_main = 6 ;

const int button_1 = 4  ;
const int button_2 = 3 ;
const int button_3 = 2 ;


int check ;


void setup(){
  Wire.begin();
  /* cài đặt thời gian cho module */
  setTime(6, 05, 55, 7, 27, 5, 24); // 12:30:45 CN 08-02-2015
  Serial.begin(9600);

  pinMode(right_forward , OUTPUT);
  pinMode(left_forward , OUTPUT);
  pinMode(right_backward , OUTPUT);
  pinMode(left_backward , OUTPUT);
  pinMode(led_blue , OUTPUT);
  pinMode(led_red, OUTPUT);
  pinMode(buzzer, OUTPUT);

  lcd.init();  // Khởi tạo lcd
  lcd.backlight();  // Bật đèn nền

  pinMode(button_3, INPUT_PULLUP);
  pinMode(button_2, INPUT_PULLUP);
  pinMode(button_1 , INPUT_PULLUP);
  check = 0 ;
}

void loop(){
  if( digitalRead(button_2) == 0)mode();
  if (minute!= minute_main && check == 2){
    check =0 ;
    lcd.setCursor(0, 1);
  }

    /* Đọc dữ liệu của DS1307 */
  readDS1307();
  /* Hiển thị thời gian ra Serial monitor */
  digitalClockDisplay();
  //delay(1000);
  lcd.setCursor(0, 0);  // Di chuyển con trỏ đến vị trí (0, 0)
  if ( hour < 10 ){
    lcd.print(0);
    lcd.setCursor(1,0);
  }
  lcd.print(hour);
  lcd.setCursor(2,0);
  lcd.print(":");
  lcd.setCursor(3,0);
  if(minute < 10 ){
    lcd.print(0);
    lcd.setCursor(4, 0);}
  lcd.print(minute);
  lcd.setCursor(5,0);
  lcd.print(":");
  lcd.setCursor(6, 0);
  if(second < 10 ){
    lcd.print(0);
    lcd.setCursor(7, 0);}
  lcd.print(second);


  int location = 11;
  lcd.setCursor(location,0);
  if(day < 10 ){
    lcd.print(0);
    lcd.setCursor(location+1, 0);}
  lcd.print(day);
  lcd.setCursor(location+2,0);
  lcd.print("/");
  lcd.setCursor(location+3,0);
  if(month < 10 ){
    lcd.print(0);
    lcd.setCursor(location+4, 0);}
  lcd.print(month);
  lcd.setCursor(location+5,0);
  // lcd.print("/");
  // lcd.setCursor(location+6,0);
  // lcd.print(year);

  lcd.setCursor(1,1);
  lcd.print("Alarm  ");

  location = 7  ;
  lcd.setCursor( location, 1);
  if ( hour_main < 10){
    lcd.print(0);
    lcd.setCursor(location + 1, 1);
  }
  lcd.print(hour_main);
  lcd.setCursor(location+ 2, 1);
  lcd.print(":");
  lcd.setCursor(location + 3, 1);
  if ( minute_main < 10){
    lcd.print(0);
    lcd.setCursor(location+4, 1);
    
  }
  lcd.print(minute_main);

  lcd.setCursor(13 , 1 );
  lcd.print("^.^");
  if ( hour == hour_main && minute == minute_main  && check == 0){
    check = 1;
    while( check == 1){
      lcd.setCursor(0, 1);
      lcd.print("                ");
      lcd.setCursor(4, 1);
      lcd.print("GET UP !!!");
      digitalWrite(buzzer, 1);
      GO(0);
      stop();
      GO(1);
      stop();
      GO(-1);
      stop();
    
    if ( digitalRead(button_3) == 0 ){
      digitalWrite(buzzer, 0);
      lcd.print("                ");
      lcd.setCursor(0, 1);
      lcd.print("Have a good day! ");
      delay(2000);
      lcd.setCursor(0, 1);
      lcd.print("                ");
      check = 2;
    }
    }
  }
  

}


void mode(){
  lcd.setCursor(0,0);
  lcd.print("                ");
  lcd.setCursor(0,1);
  lcd.print("                ");
  int time =  500 ;
  lcd.setCursor(0,0);
  lcd.print("set alarm -.-");
  lcd.setCursor(1,1);
  int hour= hour_main; int minute= minute_main;
  int hour_location = 9 ; int minute_location = 12 ;
    lcd.setCursor(hour_location-1, 1 );
    lcd.print("[");
    lcd.setCursor(hour_location+2, 1);
    lcd.print("]");
  while(true){
    delay(time);
    if ( hour < 10 ){
      lcd.setCursor(hour_location , 1);
      lcd.print(" ");
      lcd.setCursor(hour_location+1, 1);
    }else lcd.setCursor(hour_location , 1);;
    lcd.print(hour);
    if(digitalRead(button_1) == 0){
      hour++;
      delay(time);
      }
    if(digitalRead(button_2) == 0)break ;
    hour = hour % 24 ;
  }
  lcd.setCursor(hour_location-1, 1 );
  lcd.print(" ");
  lcd.setCursor(hour_location+2, 1);
  lcd.print(" ");
  lcd.setCursor(minute_location-1, 1 );
  lcd.print("[");
  lcd.setCursor(minute_location+2, 1);
  lcd.print("]");
  while(true){
    delay(time);
    if ( minute < 10 ){
      lcd.setCursor(minute_location , 1);
      lcd.print(0);
      lcd.setCursor(minute_location+1, 1);
    }else lcd.setCursor(minute_location , 1);;
    lcd.print(minute);
    if(digitalRead(button_1) == 0){
      minute++;
      delay(time);
    }
    if(digitalRead(button_2) == 0){
      //delay(1000);
      break;
    }
    minute = minute % 60 ;
  }
  
  hour_main = hour ;
  minute_main = minute;
  lcd.setCursor(0,0);
  lcd.print("                ");
  lcd.setCursor(0,1);
  lcd.print("                ");
  delay(time);
}

void led(){
  int time = 300 ;
  digitalWrite(led_blue , 1);
  digitalWrite(led_red, 0);
  delay(time);
  digitalWrite(led_blue, 0);
  digitalWrite(led_red , 1);
  delay(time);
}

void right(int n ){
  digitalWrite(right_forward , n);
  digitalWrite(right_forward , abs(n-1));
}

void left(int n ){
  digitalWrite(left_forward , n);
  digitalWrite(left_backward , abs(n-1));
}

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
    right(1);
    left(1);
    delay(time);
    stop();
  }else {
    if ( x == 1 ) {
      left(1);
      delay(time);
      stop();
    }else {
      right(1);
      delay(time);
      stop();
    }
  }
  digitalWrite(buzzer,0);
}
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
 
void digitalClockDisplay(){
    // digital clock display of the time
    Serial.print(hour);
    printDigits(minute);
    printDigits(second);
    Serial.print(" ");
    Serial.print(day);
    Serial.print(" ");
    Serial.print(month);
    Serial.print(" ");
    Serial.print(year); 
    Serial.println(); 
}
 
void printDigits(int digits){
    // các thành phần thời gian được ngăn chách bằng dấu :
    Serial.print(":");
        
    if(digits < 10)
        Serial.print('0');
    Serial.print(digits);
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
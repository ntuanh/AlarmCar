const int right_forward = 5 ;
const int right_backward = 6 ;
const int left_forward = 7 ;
const int left_backward = 8 ;
const int buzzer = 9 ;

void setup(){
  pinMode(right_forward , OUTPUT);
  pinMode(left_forward , OUTPUT);
  pinMode(right_backward , OUTPUT);
  pinMode(left_backward , OUTPUT);
}

void loop(){
  digitalWrite(right_forward,1);
  digitalWrite(right_backward, 0);
  digitalWrite(left_forward,1);
  digitalWrite(left_backward, 0);
  delay(1000);
  stop();
  GO(0);

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
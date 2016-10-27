int motorPin1 = 36; // Blue / Синий - 28BYJ48 pin 1
int motorPin2 = 38; // Pink / Розовый - 28BYJ48 pin 2
int motorPin3 = 40; // Yellow / Желтый - 28BYJ48 pin 3
int motorPin4 = 42; // Orange / Оранжевый - 28BYJ48 pin 4

int motorPin5 = 46; // Blue / Синий - 28BYJ48 pin 1
int motorPin6 = 48; // Pink / Розовый - 28BYJ48 pin 2
int motorPin7 = 50; // Yellow / Желтый - 28BYJ48 pin 3
int motorPin8 = 52; // Orange / Оранжевый - 28BYJ48 pin 4

int buttonPin1 = 22; // кнопку подключаем к Pin 22.
int buttonPin2 = 24; // кнопку подключаем к Pin 24.
int buttonPin3 = 26; // кнопку подключаем к Pin 26.
int buttonPin4 = 28; // кнопку подключаем к Pin 28.
int buttonPin5 = 30; // кнопку подключаем к Pin 30.

int motorSpeed = 1800;

int steps = 0;

int led0 = 13;

boolean pressed = 0;

//
int lookup[8] = {
B01000, B01100, B00100, B00110, B00010, B00011, B00001, B01001};
/////////////////////////////////////////////////////////////////

void setup() {
  pinMode(led0, OUTPUT); 

  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  
  pinMode(motorPin5, OUTPUT);
  pinMode(motorPin6, OUTPUT);
  pinMode(motorPin7, OUTPUT);
  pinMode(motorPin8, OUTPUT);

  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  pinMode(buttonPin5, INPUT);
  digitalWrite(buttonPin1, HIGH);
  digitalWrite(buttonPin2, HIGH);
  digitalWrite(buttonPin3, HIGH);
  digitalWrite(buttonPin4, HIGH);
  digitalWrite(buttonPin5, HIGH);
}

void loop(){
  digitalWrite(led0, LOW);

  if (digitalRead(buttonPin1) == LOW){
    anticlockwise();
  }
  if (digitalRead(buttonPin2) == LOW){
    clockwise();
  }
  if (digitalRead(buttonPin3) == LOW){
    anticlockwise1();
  }
  if (digitalRead(buttonPin4) == LOW){
    clockwise1();
  }
  
  if (digitalRead(buttonPin5) == LOW){
    digitalWrite(led0, HIGH);
    for(int repley=0; repley<=1000; repley++){
      delay(random(5000, 70000));
      shuffle();
      delay(random(2000, 40000));
      klacKlac(1);
      delay(random(5000, 70000));
      rightLeft();
      delay(random(2000, 40000));
      klacKlac(2);
      delay(random(5000, 70000));
      for(int i =0; i<=45; i++){
        clockwise1();
      }
      klacKlac(2);
      delay(random(2000, 70000));
      for(int i =0; i<=45; i++){
        anticlockwise1();
      }
    }
  }
}

//--------------------------------------
//buttons for move
void anticlockwise() {
  for(int i = 0; i < 8; i++) {
    setOutput(i);
    delayMicroseconds(motorSpeed);
  }
}

void anticlockwise1() {
  for(int i = 0; i < 8; i++) {
    setOutput1(i);
    delayMicroseconds(motorSpeed);
  }
}

void clockwise() {
  for(int i = 7; i >= 0; i--)  {
      setOutput(i);
      delayMicroseconds(motorSpeed);
  }
}

void clockwise1() {
  for(int i = 7; i >= 0; i--)  {
      setOutput1(i);
      delayMicroseconds(motorSpeed);
  }
}
//--------------------------------------
//for 5 button
void rightLeft(){
    for(int i =0; i<=45; i++){
      clockwise1();
    }
    for(int i =0; i<=90; i++){
      anticlockwise1();
    }
    for(int i =0; i<=45; i++){
      clockwise1();
    }
}

void klacKlac(int klac){
  for(int j=0; j<= klac; j++){
    for(int i =0; i<=45; i++){
        clockwise();
    }
    for(int i =0; i<=45; i++){
        anticlockwise();  
    }
  }
}

void shuffle(){
  //left
  for(int i =0; i<=50; i++){
    clockwise1();
  }
  //klack
  for(int j=0; j<2; j++){
    for(int i =0; i<=45; i++){
      clockwise();
    }
    for(int i =0; i<=45; i++){
      anticlockwise();  
    }
  }
  //right
  for(int i =0; i<=100; i++){
    anticlockwise1();  
  }
  //klac
  for(int j=0; j<1; j++){
    for(int i =0; i<=45; i++){
      clockwise();
    }
    for(int i =0; i<=45; i++){
      anticlockwise();  
    }
  }
  //left
  for(int i =0; i<=50; i++){
    clockwise1();
  }  
  
}
void setOutput(int out) {
  digitalWrite(motorPin1, bitRead(lookup[out], 0));
  digitalWrite(motorPin2, bitRead(lookup[out], 1));
  digitalWrite(motorPin3, bitRead(lookup[out], 2));
  digitalWrite(motorPin4, bitRead(lookup[out], 3));
}

void setOutput1(int out) {
  digitalWrite(motorPin5, bitRead(lookup[out], 0));
  digitalWrite(motorPin6, bitRead(lookup[out], 1));
  digitalWrite(motorPin7, bitRead(lookup[out], 2));
  digitalWrite(motorPin8, bitRead(lookup[out], 3));
}

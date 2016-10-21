// declare variables for the motor pins
//tests for changes in code
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

// установить скорость шагового двигателя.
//variable to set stepper speed.
int motorSpeed = 1200;

//кол-во шагов
int steps = 0;

//
int lookup[8] = {
B01000, B01100, B00100, B00110, B00010, B00011, B00001, B01001};
/////////////////////////////////////////////////////////////////

void setup() {
// declare the motor pins as outputs.
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  
  pinMode(motorPin5, OUTPUT);
  pinMode(motorPin6, OUTPUT);
  pinMode(motorPin7, OUTPUT);
  pinMode(motorPin8, OUTPUT);

// Одна нога кнопки подключается к GND, другая к Pin №
// (никаких внешних резисторов не нужно).
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  digitalWrite(buttonPin1, HIGH);
  digitalWrite(buttonPin2, HIGH);
  digitalWrite(buttonPin3, HIGH);
// Serial.begin(9600); //WHY comented?!
}

void loop(){
  
  //если кнопка1 и                   && steps < НУЖНОГО тогда поворачиваем
  if (digitalRead(buttonPin1) == LOW && steps <=120){
    anticlockwise(); // крутим влево если нажата кнопка 1. и увеличиваем кол-во шагов вращая(когда кнопка нажата это 1 сигнал или много? проверить)  
    steps++;
  }
  if (digitalRead(buttonPin2) == LOW && steps >=-120){
    //if(steps>0)steps=0;
    clockwise(); // крутим влево если нажата кнопка 2.
    steps--;
  }//шаг вперед-назад
  if (digitalRead(buttonPin3) == LOW){
    for(int i =0; i<=120; i++){
      anticlockwise();
    }
    for(int i =0; i<=120; i++){
      clockwise();
    }
  }
}

// —------------------------------

//set pins to ULN2003 high in sequence from 1 to 4
//delay "motorSpeed" between each pin setting (to determine speed)
// функция поворачивает мотор против часовой стрелки.
void anticlockwise() {
  for(int i = 0; i < 8; i++) {
    Serial.println('1buttonPresed'); 
    setOutput(i);
    setOutput1(i);
    delayMicroseconds(motorSpeed);
    steps = steps++;
  }
}
// функция поворачивает мотор по часовой стрелке.
void clockwise() {
  for(int i = 7; i >= 0; i--)  {
      Serial.println('2buttonPresed');
      setOutput(i);
      setOutput1(i);
      delayMicroseconds(motorSpeed);
      steps = steps++;  
  }
}
// посылает куски массива на пины тем самым подавая ток? с 0 до... и с ... до 0? и подходящее битовое значение заставляет вращатся? о_О магия бладж
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

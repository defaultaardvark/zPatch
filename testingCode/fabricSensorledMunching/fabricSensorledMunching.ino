
//value for storing resistive readings
int resValues;
int red = 20;
int yel = 21;
int gre = 22;
int blu = 23;
int brightness = 0;
int resLow;
int resHigh;

const int numReadings = 10;

int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average

void setup()
{
  Serial.begin(9600); // open the arduino serial port
  pinMode(red, OUTPUT);
  pinMode(yel, OUTPUT);
  pinMode(gre, OUTPUT);
  pinMode(blu, OUTPUT);
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
  delay(50);
}


void loop()
{
  resValues = fourAnalogRead(A0, A1, A3, A4, A5, 6); //sample resistance

  // subtract the last reading:
  total = total - readings[readIndex];
  // read from the sensor:
  readings[readIndex] = resValues;
  // add the reading to the total:
  total = total + readings[readIndex];
  // advance to the next position in the array:
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }

  // calculate the average:
  average = total / numReadings;
  // send it to the computer as ASCII digits
  //Serial.println(average);

  //Serial.print(resValues); 
  //Serial.println(); 
  int resVal;
  resVal = -average;
  Serial.println(resVal);
  Serial.println();
  /*Serial.println(0);
  Serial.println();
  Serial.println(-1500);
  Serial.println();*/
  //Defines upper and lower bounds of signal
  if (resVal >= resHigh){
    resHigh = resVal;
  }
  else if (resVal <= resLow){
    resLow = resVal;
  }
  int resRange = resHigh-resLow;

  int Q1 = resRange/4;
  int Q2 = resRange/2;
  int Q3 = resRange*(3/4);
  
  float k = (255/Q1);
  
  if (resVal <= Q1){
    brightness = resVal*k;
    analogWrite(red, brightness);
  }
  else if (resVal > Q1 && resVal <= Q2){
    brightness = (resValues - Q1)*k;
    analogWrite(yel, brightness);
  }
  else if (resVal > Q2 && resVal <= Q3){
    brightness = (resValues - Q2)*k;
    analogWrite(gre, brightness);
  }
  else if (resVal > Q3){
    brightness = (resHigh - Q3)*k;
    analogWrite(blu, brightness);
  }

  delay(5); // (so as not to completely flood the serial port)

}

// ---------------- Here there be Dragons ---------- 
/*
int capacitiveRead(int pinA, int pinB, int number) {
  int capacitanceA = 0;
  int capacitanceB = 0;
  int capacitance = 0;

  for (int i = 0; i < number; i++) {
    pinMode(pinA, INPUT);
    pinMode(pinB, INPUT_PULLUP);
    ADMUX |=   0b11111;
    ADCSRA |= (1 << ADSC); //start conversion
    while (!(ADCSRA & (1 << ADIF))); //wait for conversion to finish
    ADCSRA |= (1 << ADIF); //reset the flag
    pinMode(pinB, INPUT);
    capacitanceB = analogRead(pinB);

    pinMode(pinB, INPUT);
    pinMode(pinA, INPUT_PULLUP);
    ADMUX |=   0b11111;
    ADCSRA |= (1 << ADSC); //start conversion
    while (!(ADCSRA & (1 << ADIF))); //wait for conversion to finish
    ADCSRA |= (1 << ADIF); //reset the flag
    pinMode(pinA, INPUT);
    capacitanceA = analogRead(pinA);

    capacitance = capacitance + capacitanceA + capacitanceB;

  }
  return capacitance;
}
*/

int fourAnalogRead(int pinA, int pinB, int pinC, int pinD, int pinE, int number) {
  int resistanceA = 0;
  int resistanceB = 0;
  int resistanceC = 0;
  int resistanceD = 0;
  int resistanceE = 0;
  int resistance = 0;

  for (int i = 0; i < number; i++) {
    pinMode(pinA, OUTPUT);
    digitalWrite(pinA, LOW);
    pinMode(pinB, INPUT_PULLUP);
    resistanceB = analogRead(pinB);

    pinMode(pinB, OUTPUT);
    digitalWrite(pinB, LOW);
    pinMode(pinA, INPUT_PULLUP);
    resistanceA = analogRead(pinA);

    pinMode(pinC, OUTPUT);
    digitalWrite(pinC, LOW);
    pinMode(pinC, INPUT_PULLUP);
    resistanceC = analogRead(pinC);

    pinMode(pinD, OUTPUT);
    digitalWrite(pinD, LOW);
    pinMode(pinD, INPUT_PULLUP);
    resistanceD = analogRead(pinD);

    pinMode(pinE, OUTPUT);
    digitalWrite(pinE, LOW);
    pinMode(pinE, INPUT_PULLUP);
    resistanceE = analogRead(pinE);

    resistance = (resistanceA + resistanceB + resistanceC + resistanceD + resistanceE);

  }
  return resistance / number;
}

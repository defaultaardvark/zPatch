///////////////////////////
// zPatch Sensor Code /////
///////////////////////////

// paul.strohmeier@gmail.com
// zPatch.github.io

// This Sketch is for testing zPatch, presented at TEI 2018

// The key things to know are the function 
// dualAnalogRead(pinA, pinB, samples) and capacitiveRead(pinA, pinB, samples)
// Both functions take two analog pins as parameters (where your sensors is connected)
// The third parameter is the number of times you want to sample. 
// capacitiveRead needs more samples, dualAnalogRead is quite stable.

// Based on the adcTouch library --> https://github.com/martin2250/ADCTouch

//Values for filtering and storing capacitive readings
/*int baseline;
int capValues;
int prevCapValues;
int rawCapacitance;
float k = 0.2; // this adjusts the low-pass filter: 
               // 0 == no signal
               // 0.001 == very aggressive (slow but steady) 
               // 0.999 == not aggressive at all (fast but noisy)
               // 1 == no filter
*/
//value for storing resistive readings
int resValues;
int red = 20;
int yel = 21;
int gre = 22;
int blu = 23;
int brightness = 0;
int resLow;
int resHigh;

void setup()
{
  Serial.begin(9600); // open the arduino serial port
  pinMode(red, OUTPUT);
  pinMode(yel, OUTPUT);
  pinMode(gre, OUTPUT);
  pinMode(blu, OUTPUT);
  delay(50); //wait a bit before establishing baseline
  resValues = dualAnalogRead(A0, A1, 3); //this line should not be needed, but might stabalize readings
  //baseline = capacitiveRead(A0, A1, 10); //set the baseline for capacitive readings
  //Serial.println(baseline);
  delay(50);
}


void loop()
{
  /*rawCapacitance = capacitiveRead(A0, A1, 10); //sample capacitance
  rawCapacitance = (rawCapacitance - baseline); //baseline capacitance value 
  capValues = prevCapValues + (k * (rawCapacitance - prevCapValues)); //filter capacitive value
  prevCapValues = capValues; //for filtering*/

  resValues = dualAnalogRead(A0, A1, 3); //sample resistance

//print to serial port
  //Serial.print(capValues); 
  //Serial.print(", ");
  Serial.print(resValues); 
  Serial.println(); 

  resValues = -resValues;
  //Defines upper and lower bounds of signal
  if (resValues >= resHigh){
    resHigh = resValues;
  }
  else if (resValues <= resLow){
    resLow = resValues;
  }
  int resRange = resHigh-resLow;

  int Q1 = resRange/4;
  int Q2 = resRange/2;
  int Q3 = resRange*(3/4);
  
  float k = (255/Q1);  
  
  if (resValues <= Q1){
    brightness = resValues*k;
    analogWrite(red, brightness);
  }
  else if (resValues > Q1 && resValues <= Q2){
    brightness = (resValues - Q1)*k;
    analogWrite(yel, brightness);
  }
  else if (resValues > Q2 && resValues <= Q3){
    brightness = (resValues - Q2)*k;
    analogWrite(gre, brightness);
  }
  else if (resValues > Q3){
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

int dualAnalogRead(int pinA, int pinB, int number) {
  int resistanceA = 0;
  int resistanceB = 0;
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

    resistance = resistance + (resistanceA + resistanceB) / 2;

  }
  return resistance / number;

  
}

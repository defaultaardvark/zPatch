int push = 14;
int resVal;
int red = 20;

int resLow;
int resHigh;

void setup() {
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  resVal = analogRead(A0);
  resLow = resHigh = resVal;
}

void loop() {
  resVal = analogRead(A0);
  
  if (resVal >= resHigh){
    resHigh = resVal;
  }
  int tip = (resHigh - resLow)/2;
  if (resVal >= tip){
    analogWrite(red, 255);
  }
  else{
    analogWrite(red, 0);
  }
}

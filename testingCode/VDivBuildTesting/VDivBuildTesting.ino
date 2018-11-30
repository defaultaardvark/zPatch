int red = 20;
int yel = 21;
int gre = 22;
int blu = 23;

int index;
int middle;
int ring;
int pinky;

int resLow;
int resHigh;

void setup() {
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(yel, OUTPUT);
  pinMode(gre, OUTPUT);
  pinMode(blu, OUTPUT);
  index = analogRead(A0);
  middle = analogRead(A1);
  ring = analogRead(A2);
  pinky = analogRead(A3);
  
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

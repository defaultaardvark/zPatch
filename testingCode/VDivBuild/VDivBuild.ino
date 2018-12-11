int push = 14;
int iniIndex;
int iniMid;
int iniRing;
int iniPink;
int Index;
int Mid:
int Ring;
int Pink;

int red = 20;
int yellow = 21;
int green = 22
int blue = 23;

int resLow;
int resHigh;
  
void setup() {
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  iniIndex = analogRead(A0);
  iniMid = analogRead(A1);
  iniRing = analogRead(A2);
  iniPink = analogRead(A3);
}

void loop() {
  Index = analogRead(A0);
  Mid = analogRead(A1);
  Ring = analogRead(A2);
  Pink = analogRead(A3);
  if (Index >= (iniIndex*1.1)){
    analogWrite(, 255);
  }
  else{
    analogWrite(red, 0);
  }
  if (Mid >= (iniMid*1.1)){
    analogWrite(red, 255);
  }
  else{
    analogWrite(red, 0);
  }
  if (Ring >= (iniRing*1.1)){
    analogWrite(red, 255);
  }
  else{
    analogWrite(red, 0);
  }
  if (Pink >= (iniPink*1.1)){
    analogWrite(red, 255);
  }
  else{
    analogWrite(red, 0);
  }
  Serial.println(resHigh);
 }

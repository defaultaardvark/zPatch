int red = 20;
int yellow = 21;
int green = 22;
int blue = 23;

int Index;
int Mid;
int Ring;
int Pink;
int iniIndex;
int iniMid;
int iniRing;
int iniPink;

void setup() {
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
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
  
  if (Index <= (iniIndex)){
    analogWrite(red, 255);
  }
  else{
    analogWrite(red, 0);
  }
  if (Mid <= (iniMid)){
    analogWrite(yellow,255);
  }
  else{
    analogWrite(yellow,0 );
  }
  if (Ring <= (iniRing)){
    analogWrite(green, 255);
  }
  else{
    analogWrite(green, 0);
  }
  if (Pink <= (iniPink)){
    analogWrite(blue, 255);
  }
  else{
    analogWrite(blue, 0);
  }
  Serial.println(Ring);
 }

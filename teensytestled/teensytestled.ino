int red = 20;
int yel = 21;
int gre = 22;
int blu = 23;
int brightness = 0;

void setup() {
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(yel, OUTPUT);
  pinMode(gre, OUTPUT);
  pinMode(blu, OUTPUT);
}

void loop() {
  int fabvar = analogRead(A0);
  if (fabvar <= 250){
    brightness = fabvar;
    analogWrite(red, brightness);
  }
  else if (fabvar > 250 && fabvar <= 500){
    brightness = fabvar - 250;
    analogWrite(yel, brightness);
  }
  else if (fabvar > 500 && fabvar <= 750){
    brightness = fabvar - 500;
    analogWrite(gre, brightness);
  }
  else if (fabvar > 750){
    brightness = fabvar - 750;
    analogWrite(blu, brightness);
  }
  Serial.println(fabvar);
}

int red = 20;

void setup() {
  Serial.begin(9600);
  pinMode(red, OUTPUT);
}

void loop() {
  delay(1000);
  analogWrite(red, 255);
  delay(1000);
  analogWrite(red, 0);
}

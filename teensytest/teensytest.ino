void setup() {
  Serial.begin(9600);
}

void loop() {
  int fabvar = analogRead(A0);
  Serial.println(fabvar);
  delay(1);

}

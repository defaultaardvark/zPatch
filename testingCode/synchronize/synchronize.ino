int red = 20;
int up = 0;
float v_in;
char serIn;
long currentTime;
long startTime;

void setup(){
  Serial.begin(9600);
  serIn = Serial.read();
  pinMode(red, OUTPUT);
}

void loop(){
  currentTime = millis();
  if (Serial.available() > 0) {
    serIn = Serial.read();
    startTime = millis();
  }
  if (serIn == 'e') { 
    up = 255;
    analogWrite(red, up);
    v_in = analogRead(A4);
  }
  else if (serIn == 'r'){
    up = 0;
    analogWrite(red, up);
    v_in = analogRead(A4);
  }
  Serial.println(v_in);
}

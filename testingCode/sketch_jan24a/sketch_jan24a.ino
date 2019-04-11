int Index;
int Mid;
int Ring;
int Pink;
int Thumb;

float Index_avg = 0; //Reading average
float Mid_avg = 0;
float Ring_avg = 0;
float Pink_avg = 0;
float Thumb_avg = 0;
int avg_count = 32; //# of measurements to average

long startTime;
long time1;
long time2;
long elapsedTime1;
long elapsedTime2;
long avgElapsedTime;

void setup() {  
  Serial.begin(9600);
  startTime = millis();
  time1 = startTime;
}

void loop() {  
  Index = analogRead(A0);
  Mid = analogRead(A1);
  Ring = analogRead(A2);
  Pink = analogRead(A3);
  Thumb = analogRead(A4);

  for (int n = 0; n < avg_count; ++n)
  {
    Index_avg += Index;
    Mid_avg += Mid;
    Ring_avg += Ring;
    Pink_avg += Pink;
    Thumb_avg += Thumb;
    delay(1);
  }
  Index_avg /= Index;
  Mid_avg /= Mid;
  Ring_avg /= Ring;
  Pink_avg /= Pink;
  Thumb_avg /= Thumb;

  time2 = millis();
  elapsedTime1 = elapsedTime2;
  elapsedTime2 = time2 - time1;
  time1 = millis();
  avgElapsedTime = (elapsedTime1 + elapsedTime2)/2;
  
  Serial.print(Index_avg);
  Serial.print(",");
  Serial.print(Mid_avg);
  Serial.print(",");
  Serial.print(Ring_avg);
  Serial.print(",");
  Serial.print(Pink_avg);
  Serial.print(",");
  Serial.println(Thumb_avg);
  /*Serial.print(",");
  Serial.println(avgElapsedTime);*/
  delay(5);  
}

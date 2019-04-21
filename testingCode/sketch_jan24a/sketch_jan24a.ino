int Index; //Running totals of each finger
int Mid;
int Ring;
int Pink;
int Thumb;

const int avg_count = 16; //# of measurements to average

int Index_read[avg_count]; //Array of readings from analog
int Mid_read[avg_count];
int Ring_read[avg_count];
int Pink_read[avg_count];
int Thumb_read[avg_count];

int readIndex = 0; //Index of current reading

int Index_avg = 0;
int Mid_avg = 0;
int Ring_avg = 0;
int Pink_avg = 0;
int Thumb_avg = 0;

void setup() {
  Serial.begin(115200);
  for (int n = 0; n < avg_count; n++){
    Index_read[n] = 0;
    Mid_read[n] = 0;
    Ring_read[n] = 0;
    Pink_read[n] = 0;
    Thumb_read[n] = 0;
  }
}

void loop() {
  Index = Index - Index_read[readIndex];
  Mid = Mid - Mid_read[readIndex];
  Ring = Ring - Ring_read[readIndex];
  Pink = Pink - Pink_read[readIndex];
  Thumb = Thumb - Thumb_read[readIndex];
  
  Index_read[readIndex] = analogRead(A0);
  Mid_read[readIndex] = analogRead(A1);
  Ring_read[readIndex] = analogRead(A2);
  Pink_read[readIndex] = analogRead(A3);
  Thumb_read[readIndex] = analogRead(A4);

  Index = Index + Index_read[readIndex];
  Mid = Mid + Mid_read[readIndex];
  Ring = Ring + Ring_read[readIndex];
  Pink = Pink + Pink_read[readIndex];
  Thumb = Thumb + Thumb_read[readIndex];

  readIndex = readIndex + 1;

  if (readIndex >= avg_count){
    readIndex = 0;
  }

  Index_avg = Index/avg_count;
  Mid_avg = Mid/avg_count;
  Ring_avg = Ring/avg_count;
  Pink_avg = Pink/avg_count;
  Thumb_avg = Thumb/avg_count;

  Serial.print(Index_avg);
  Serial.print(",");
  Serial.print(Mid_avg);
  Serial.print(",");
  Serial.print(Ring_avg);
  Serial.print(",");
  Serial.print(Pink_avg);
  Serial.print(",");
  Serial.println(Thumb_avg);
  delay(10);
}

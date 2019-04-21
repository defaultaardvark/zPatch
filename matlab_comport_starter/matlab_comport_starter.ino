#include <ADC.h>

int out1 = 0;
int j =0;

ADC *adc = new ADC();
void setup(){
adc->setConversionSpeed(ADC_CONVERSION_SPEED::VERY_HIG H_SPEED); 
adc->setSamplingSpeed(ADC_SAMPLING_SPEED::VERY_HIGH_SP EED);
adc->setResolution(8);

Serial.begin(115200);
pinMode(2,OUTPUT) ; //Logic pins are also set as output
pinMode(3,OUTPUT) ;
pinMode(32, INPUT_DISABLE);
}

void loop()
{
j = Serial.read() ;
if(j==1){ 
digitalWrite(2,LOW) ;
digitalWrite(3,HIGH) ; //Turns Motor On
out1 = adc->analogRead(32);
Serial.print(out1);
Serial.print('\n');
}
if(j==2){
digitalWrite(2,LOW); //Turns Motor Off
digitalWrite(3,LOW);
}
}

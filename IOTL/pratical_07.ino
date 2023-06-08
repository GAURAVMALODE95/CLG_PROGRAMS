const int piezopin=A1;
const int Idrpin=A0;

void setup() {
serial.begin(9600);
PinMode(A0,INPUT);
PinMode(A1,OUTPUT);

}

void loop() {
int melody[]={262,294,330,349,392,440,494,523};
int value=analogRead(A0);
Serial.print(value);
Serial.println();

if(value<200){

  for(int i=0;i<7;i++){
    Tone(A1,melody[i]);
    delay(1000);

  }
}
else{
  noTone(A1);
}
delay(1000);
}

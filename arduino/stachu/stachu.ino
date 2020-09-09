void setup() {
  pinMode(2,OUTPUT);
  pinMode(7,INPUT);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(7))
  {
    digitalWrite(2,HIGH);
    Serial.write("play\n");
    while(digitalRead(7));
  }
  else
    digitalWrite(2,LOW);
}

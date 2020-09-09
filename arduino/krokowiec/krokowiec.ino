int motorOutputs[4] = {8,9,10,11};


void setup() {
  Serial.begin(9600);
  for(int i=0; i<4; i++)
    pinMode(motorOutputs[i], OUTPUT);
}

void loop() {
  for(int i = 0; i<4; i++){
    delay(500);
    Serial.println(motorOutputs[i]);
  }
}

char incomingByte;  // incoming data
int  LED = 12;      // LED pin

void setup() {
  Serial.begin(38400); // initialization
  pinMode(LED, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  Serial.println("Press 1 to Switch module1 ON or 0 to switch off");
  Serial.println("PRESS 2 TO SWITCH ON MODULE 2 AND 3 TO SWITCH OF MODULE 2");
  Serial.println("Press 5 switch on all together and 6 switch off together");
}

void loop() {
  
  if (Serial.available() > 0) {  // if the data came
    incomingByte = Serial.read(); // read byte
    Serial.println(incomingByte);
    if(incomingByte == '1') 
    {
       digitalWrite(LED, LOW);  // if 1, switch LED Off
       Serial.println("LED OFF. Press 1 to LED ON!");  // print message
       digitalWrite(9, LOW);
    }
    if(incomingByte == '0') 
    {
       digitalWrite(LED, HIGH); // if 0, switch LED on
       Serial.println("LED ON. Press 0 to LED OFF!");
       digitalWrite(9, HIGH);
    }
    if(incomingByte == '3') 
    {
       digitalWrite(8, HIGH); // if 0, switch LED on
       Serial.println("MODULE 2 switched on");
    }
    if(incomingByte == '2') 
    {
       digitalWrite(8, LOW); // if 0, switch LED on
       Serial.println("MODULE 2 switched off");
    }
    if(incomingByte == '6') 
    {
       digitalWrite(8, HIGH); // if 0, switch LED on
       digitalWrite(9, HIGH);
       Serial.println("Both modules switched on together");     
    }
    if(incomingByte == '5') 
    {
      digitalWrite(8, LOW); // if 0, switch LED on
       digitalWrite(9, LOW);
    }
  }
}

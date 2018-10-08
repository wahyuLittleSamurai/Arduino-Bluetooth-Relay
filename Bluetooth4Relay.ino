#include <SoftwareSerial.h>

SoftwareSerial mySerial(3, 2); // RX, TX

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  mySerial.begin(9600);
  Serial.println("BT Ready...!!!");
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  digitalWrite(A1, HIGH);
  digitalWrite(A2, HIGH);
  digitalWrite(A3, HIGH);
  digitalWrite(A4, HIGH);
}

void loop() { // run over and over
  if (mySerial.available()) {
    char valBluetooth = mySerial.read();
    Serial.print("Nilai Bluetooth: ");
    Serial.print(valBluetooth);
    switch(valBluetooth)
    {
      case 'A': digitalWrite(A1, LOW); Serial.println(" Relay 1 ON"); break;
      case 'a': digitalWrite(A1, HIGH); Serial.println(" Relay 1 OFF"); break;
      case 'B': digitalWrite(A2, LOW); Serial.println(" Relay 2 ON"); break;
      case 'b': digitalWrite(A2, HIGH); Serial.println(" Relay 2 OFF"); break;
      case 'C': digitalWrite(A3, LOW); Serial.println(" Relay 3 ON"); break;
      case 'c': digitalWrite(A3, HIGH); Serial.println(" Relay 3 OFF"); break;
      case 'D': digitalWrite(A4, LOW); Serial.println(" Relay 4 ON");break;
      case 'd': digitalWrite(A4, HIGH); Serial.println(" Relay 4 OFF");break;
    }
  }
  
}


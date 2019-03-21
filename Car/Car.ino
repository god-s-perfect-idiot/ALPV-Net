#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#define led 12
RF24 radio(7, 8); // CE, CSN
const byte addresses[][6] = {"00001", "00002"};
boolean buttonState = 0;
void setup() {
  pinMode(12, OUTPUT);
  radio.begin();
  Serial.begin(9600);
  radio.openWritingPipe(addresses[1]); // 00001
  radio.openReadingPipe(1, addresses[0]); // 00002
  radio.setPALevel(RF24_PA_MIN);
}
void loop() {
  delay(5);
  radio.stopListening();
  int packet=1;
  radio.write(&packet, sizeof(packet));
  Serial.println("Data sent to AP");
 delay(5);
  radio.startListening();
  
  if (radio.available()){
  
    Serial.println("Direction received from AP");
  }
}

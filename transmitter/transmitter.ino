#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); // CE, CSN
const byte raddress[6] = "00002";
const byte waddress[6] = "00004";

int n=0;
void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.setRetries(15,15);
  radio.setPALevel(RF24_PA_MIN);
  radio.openReadingPipe(0,raddress);
    radio.openWritingPipe(waddress);

}
void loop() {
  
  radio.stopListening();
  
  const char text[] = "Data Packet";
  radio.write(&text,sizeof(text));
    Serial.println("This is Car, Sending Packet to server");
  
  //Serial.println(text);
}

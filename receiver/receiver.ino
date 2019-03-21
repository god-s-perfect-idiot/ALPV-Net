#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN
const byte waddress[6] = "00002";
const byte raddress[6] = "00004";

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.setPALevel(RF24_PA_MIN);
  radio.openReadingPipe(0, raddress);  
  radio.openWritingPipe(waddress);
}
void loop() {
  radio.startListening();
  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.println("Packet from Car Recieved by an access point, transmitting to server");
   
    radio.stopListening();
  }
  const char text[] = "Data Packet";
  radio.write(&text,sizeof(text));
  Serial.println("Packet response recieved from Server, sending to Car");
}

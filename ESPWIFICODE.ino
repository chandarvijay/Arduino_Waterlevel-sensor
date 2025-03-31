#include <ESP8266WiFi.h>
#include "ESP8266WebServer.h"

const char* ssid ="Uma chandar_5G";
const char* password = "9980337734";

float distance ;
float duration;

float distanceUS1;
float durationus1;



ESP8266WebServer server (80);

String header;
void setup(){

Serial.begin(9600);

//Relay pin 
 pinMode(D8,OUTPUT);

 // Wifi status light 
 pinMode(D5, OUTPUT);
//Ultrasonic Pins 
//EcoPin is input 
 pinMode(D2, INPUT);
//Trigger Pin 
 pinMode(D1, OUTPUT);

//Ecopin 2 in INPUT
 pinMode(D3, INPUT);
//Trigger pin 2 
 pinMode(D4, OUTPUT);

 WiFi.begin(ssid, password);

while(WiFi.status() != WL_CONNECTED ){
  delay(100);
  Serial.print("....");
}

digitalWrite(D5,HIGH);
Serial.println("Connected and the lights are On");
Serial.println("The IP address that is connected to the Network");
Serial.println(WiFi.localIP());

server.on("/",[](){server.send(200 ,"text/html");});

server.on("/",test);

server.begin();



}




void loop()
{

digitalWrite(D1, LOW);
delayMicroseconds(2);

digitalWrite( D1,HIGH);
delayMicroseconds(20);

digitalWrite(D1, LOW);


duration = pulseIn(D2,HIGH);

durationus1 = pulseIn(D3,HIGH);

distanceUS1 = (durationus1/2) * 0.343;

distance = (duration/2) * 0.343;

Serial.print("The time taken is \n");
Serial.print(duration);

Serial.print("The distance is \n");
Serial.print(distance);

Serial.print("The distance of second ultrasonic sensor \n");
Serial.print(distanceUS1);
Serial.print("THe duratioon of the second Ultrasonic sensor \n");
Serial.print(durationus1);


  digitalWrite(D6,HIGH);
  server.handleClient();


if(distance <=  70 ){
  digitalWrite(D8, HIGH);
  }
  else {
    digitalWrite(D8, LOW);
  delay(1000);
  }




if (distance <= 70){

  digitalWrite(D8,HIGH);
  
}else {
  digitalWrite(D8,LOW);
  delay(1000);
}

}

void test(){

server.send(200,"/test","The new code is working");

}

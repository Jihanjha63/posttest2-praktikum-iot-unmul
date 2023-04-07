/*
    Program Alarm PIR dengan Telegram
    dibuat oleh Indobot
*/
#include "CTBot.h"  //Pendeklarasian Library
CTBot myBot;

String ssid = "Universitas Mulawarman";    //nama ssid wifi kalian
String pass = "";  //password wifi kalian
String token = "6115141412:AAFNjoX6lor_O8cd_FwNQ9GwOKQvDdcVLRc";    //token bot baru kalian
const int id = 1013940006;      //id telegram kalian

#define buzzerPin D7  // Pemilihan Pin dan pendeklarasian variabel
#define pirPin D1 
int pirValue; 

void setup(){  //Pengaturan Pin dan Variabel
  Serial.begin(9600);
  Serial.println("Starting TelegramBot...");
  myBot.wifiConnect(ssid, pass);
  myBot.setTelegramToken(token);
  if (myBot.testConnection()) {
    Serial.println("Koneksi Bagus");
  } else {
    Serial.println("Koneksi Jelek");
  }
  pinMode(buzzerPin, OUTPUT);
  pinMode(pirPin, INPUT);
  digitalWrite(buzzerPin, LOW);
}

void loop(){ //Perulangan Program
  pirValue = digitalRead(pirPin);
  digitalWrite(buzzerPin, pirValue);
  if (pirValue == HIGH)  //Apabila Terdeteksi Gerakan
  { 
    Serial.println("Gerakan terdeteksi");
    myBot.sendMessage(id, "Gerakan terdeteksi");
  }
  delay(100);
}

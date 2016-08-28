/*Brazo Robot controlado por Bluetooth
 * Este programa facilita la comunicación de Arduino por Bluetooth 
 * con un dispositivo Android para el control de un brazo robot
 * (base giratoria, dos brazos articulados y una pinza) mediante
 * dispositivos táctiles.
 * Creado por Antonio Gómez García
 * IES Eduardo Valencia
 * Calzada de Calatrava, Ciudad Real
 * Spain
 * 28 Aug 2016
 */
#include<Servo.h>
Servo base,brazo1,brazo2,pinza;
int led=13;
int posBase=0;
int posBrazo1=0;
int posBrazo2=0;
int posPinza=0;
boolean encendido=false;
void setup() {
  // You should know and modify, in case, the value
  //in Serial.begin according to the Bluetooth module
  // you are using. I.E., Zum Card from BQ Electronics
  //uses 19200, whereas JY-MCU module is usually 9600
Serial.begin(19200);
base.attach(9);
brazo1.attach(10);
brazo2.attach(11);
pinza.attach(12);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
posBase=Serial.parseInt();
posBrazo1=Serial.parseInt();
posBrazo2=Serial.parseInt();
posPinza=Serial.parseInt();
if (!encendido){
digitalWrite(led,HIGH);
  }else{digitalWrite(led,LOW);}
  if (Serial.read()=='\n'){
  base.write(posBase);
  brazo1.write(posBrazo1);
  brazo2.write(posBrazo2);
  pinza.write(posPinza);
  }

}
}

/*
Realizar un programa de seguridad domótica que permita 
encender las luces de un domicilio de 5 habitaciones de 
forma aleatoria solo en horario nocturno. 
El sistema se activa al ingresar una contraseña 
por comunicación serial.
*/
//Horario nocturno se lo toma como si fuera después de 1 min.
#include <MsTimer2.h>
#include <TimerOne.h>

int horero, minutero, segundero;
int act = 0;
String pswd;
boolean val;
int alm = 0;
int h1 = 9;
int h2 = 10;
int h3 = 11;
int h4 = 12;
int h5 = 13;
int ale;

void setup() {
  MsTimer2::set(300, reloj);
  MsTimer2::start();
  Serial.begin(9600);
  attachInterrupt(0, activacion, LOW);
  Serial.println("SISTEMA DOMOTICO");
  pinMode(h1, OUTPUT);
  pinMode(h2, OUTPUT);
  pinMode(h3, OUTPUT);
  pinMode(h4, OUTPUT);
  pinMode(h5, OUTPUT);
}

void loop() {
  if (act == 1) {
    if (Serial.available() > 0) {
      pswd = Serial.readString();
      val = pswd.equals("1234");
      if (val == true) {
        Serial.println("CLAVE VALIDA");
        alm = 1;
      }
      else {
        Serial.println("CLAVE INCORRECTA");
        alm = 0;
      }
    }
  }
}
void activacion() {
  switch (act) {
    case 0:
      Serial.println("INGRESE EL PASSWORD");
      act++;
      break;
    case 1:
      act = 0;
      break;
  }
}
void reloj() {
  if (segundero < 60) {
    Serial.print(horero);
    Serial.print(":");
    Serial.print(minutero);
    Serial.print(":");
    Serial.println(segundero);
    segundero++;
  }
  else {
    segundero = 0;
    if (minutero < 60) {
      Serial.print(horero);
      Serial.print(":");
      Serial.print(minutero);
      Serial.print(":");
      Serial.println(segundero);
      minutero++;
      if (alm == 1) {
        if (minutero > 0) {
          ale = random(0, 2);
          digitalWrite(h1, ale);
          ale = random(0, 2);
          digitalWrite(h2, ale);
          ale = random(0, 2);
          digitalWrite(h3, ale);
          ale = random(0, 2);
          digitalWrite(h4, ale);
          ale = random(0, 2);
          digitalWrite(h5, ale);
          Serial.println("Luces encendidas");
        }
      }
    }
    else {
      minutero = 0;
      if (horero < 12) {
        Serial.print(horero);
        Serial.print(":");
        Serial.print(minutero);
        Serial.print(":");
        Serial.println(segundero);
        horero++;
      }
      else {
        horero = 0;
      }
    }
  }
}

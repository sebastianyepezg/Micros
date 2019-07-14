#include <TimerOne.h>
#include <MsTimer2.h>
#include <LiquidCrystal.h>
#include <EEPROM.h>
/*Realizar un sistema reloj con alarma almacenada en la EEPROM */
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);
int ih, im, hora = 0, minuto = 0, segundo = 0, opc = 0, subopc = 0, act = 0, ex = 0, apagar = 0, m1, m2;
String sh, sm, ss, alm;
void setup() {
  /*EEPROM.write(0, 0); //Reseteo de la EEPROM
    EEPROM.write(1, 0);
    EEPROM.write(2, 0);*/
  pinMode(7, OUTPUT); //Led de aviso
  Serial.begin(9600); 
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("RELOJ DESP");
  lcd.setCursor(13, 0);
  lcd.print("OFF"); //Aviso de la alarma
  attachInterrupt(0, menu, LOW); //Interrupcion en el pin 2
  attachInterrupt(1, submenu, LOW); //Interrupcion en el pin 3
  MsTimer2::set(1000, reloj); //Seteo del reloj
  MsTimer2::start(); //Inicio del reloj
  lcd.setCursor(1, 1); //Formato del reloj
  lcd.print("00");
  lcd.setCursor(3, 1);
  lcd.print(":");
  lcd.setCursor(4, 1);
  lcd.print("00");
  lcd.setCursor(6, 1);
  lcd.print(":");
  lcd.setCursor(7, 1);
  lcd.print("00");
  im = EEPROM.read(0); //Inicio del valor de minutos de la alarma guardado en memoria
  ih = EEPROM.read(1); //Inicio del valor de horas de la alarma guardado en memoria
}
void loop() {
  if (act == 1) { //Si la alarma está activa hará los siguientes pasos

    if (Serial.available() > 0) { //Si no se escribe no pasa nada
      alm = Serial.readString(); //Se guarda lo escrito en el serial
      if (alm.length() == 5) { //La dimension de la alarma "HH:MM"
        if (alm.substring(2, 3) == ":") { //Comparar si lo escrito en el tercer espacio es igual dos puntos
          ih = alm.substring(0, 2).toInt(); //Recoge lo escrito en las dos primeras posiciones (horas)
          im = alm.substring(3, 5).toInt(); //Recoge lo escrito en las dos ultimas posiciones (minutos)
          Serial.println(""); 
          Serial.println("ALARMA ACTIVADA");
          lcd.setCursor(13, 0);
          lcd.print("ON ");
          ex = 1; //Aviso de que todo está correcto
          alm = ""; //Vaciar la variable alm donde se escribio la hora y los minutos de la alarma
        }
      }
      else {
        Serial.println("MAL"); //En caso de haber escrito mal
      }
    }
  }
}

void reloj() { //Variable del MsTimer2
  //Desde aquí empieza el código del reloj
  if (segundo < 59) {
    segundo++;
    ss = String(segundo); //Transformar en variable string el numero
    if (ss.length() == 1) { //Para ver si el numero ingresado es de un digito
      lcd.setCursor(7, 1);
      lcd.print("0");
      lcd.setCursor(8, 1);
      lcd.print(segundo);
    }
    else { //Cuando el numero ingresado es de 2 digitos
      lcd.setCursor(7, 1);
      lcd.print(segundo);
    }
  }
  else {
    if (minuto < 59) {
      lcd.setCursor(7, 1);
      lcd.print("00");
      segundo = 0;
      minuto++;
      sm = String(minuto);
      if (sm.length() == 1) {
        lcd.setCursor(4, 1);
        lcd.print("0");
        lcd.setCursor(5, 1);
        lcd.print(minuto);
      }
      else {
        lcd.setCursor(4, 1);
        lcd.print(minuto);
      }
    }
    else {
      if (hora < 23) {
        lcd.setCursor(4, 1);
        lcd.print("00");
        minuto = 0;
        segundo = 0;
        hora++;
        sh = String(hora);
        if (sh.length() == 1) {
          lcd.setCursor(1, 1);
          lcd.print("0");
          lcd.setCursor(2, 1);
          lcd.print(hora);
        }
        else {
          lcd.setCursor(1, 1);
          lcd.print(hora);
        }
      }
    }
  }
  if (ex == 1) { //Cuando esta correctamente ingresada la alarma
    if (hora == ih && minuto == im) { //Comparar la hora actual del reloj con la establecida de la alarma para la activación
      digitalWrite(7, HIGH); //Juego de luces cuando se encienda la alarma
      delay(2000);
      digitalWrite(7, LOW);
      delay(2000);
    }
    else {
      digitalWrite(7, LOW); 
    }
  }
}
void menu() { //Interrupcion 0
  switch (opc) { //Se activa cuando se presiona la interrupción
    case 0: //Caso inicial
      opc++; //Cuando se presione de nuevo la interrrupcion 0, se dirija al case 1
      Serial.println("ACTIVAR ALARMA");
      break;
    case 1:
      if (subopc == 1) {
        Serial.println("INGRESE ALARMA");
        Serial.println("FORMATO HH:MM");
        act = 1; //Se activaran las lineas de codigo que empiezan en la linea 37
        apagar = 1; //Con esto se podrá apagar la alarma con la segunda interrupcion
      }
      else {
        Serial.println("FIN");
        opc = 0; //Reinicializa la interrupcion 0
      }
      break;
  }
}
void submenu() {
  if (opc == 1) { //Submenu de ACTIVAR ALARMA
    if (subopc < 2) { //Para recorrer el submenu
      if (subopc == 0) { //1er submenu
        subopc++; //Contador que ayuda a recorrer el submenu
        Serial.println("SI"); //Submenu 1
      }
      else {
        Serial.println("NO"); //Submenu 2
        subopc = 0; //Reiniciar submenu
      }
    }
  }
  if (apagar == 1) { //Cuando esté encendida la alarma el submenu servirá para apagarla
    ex = 0; //Desactivar el aviso de la linea 50
    lcd.setCursor(13, 0);
    lcd.print("OFF");
    digitalWrite(7, LOW);
  }
}
void bckp() { //Guardar los datos de la alarma
  if (ex == 1) {
    EEPROM.write(0, im);
    EEPROM.write(1, ih);
  }
}

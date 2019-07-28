#include <EEPROM.h>
#include <TimerOne.h>
#include <MsTimer2.h>
#include <LiquidCrystal.h>
#include <EEPROM.h>
#include <avr/wdt.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
int hora, minuto  , segundo, i = 0, seg = 10, mint = 11;
String sh, sm, ss;
void setup() {

  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("RELOJ");

  //EEPROM.write(0, 0);
  //EEPROM.write(1, 0);
  //EEPROM.write(2, 0);
  if (EEPROM.read(2) == 0) {
    //---Codigo Reloj 1----------
    MsTimer2::set(100, reloj);
    MsTimer2::start();
    lcd.setCursor(1, 1);
    lcd.print("00"); //Hora
    lcd.setCursor(3, 1);
    lcd.print(":");
    lcd.setCursor(4, 1);
    lcd.print("00"); //Minuto
    lcd.setCursor(6, 1);
    lcd.print(":");
    lcd.setCursor(7, 1);
    lcd.print("00"); //Segundo
    //--------------------------
  }
  if (EEPROM.read(2) == 1) {
    //---Codigo Reloj 2----------
    MsTimer2::set(100, reloj);
    MsTimer2::start();
    lcd.setCursor(1, 1);
    lcd.print("00");
    lcd.setCursor(3, 1);
    lcd.print(":");
    lcd.setCursor(4, 1);
    lcd.print("11");
    lcd.setCursor(6, 1);
    lcd.print(":");
    lcd.setCursor(7, 1);
    lcd.print("10");
    //--------------------------
  }
  //  Serial.println("++++++++++++");
  //  Serial.println(EEPROM.read(0));
  //  Serial.println(EEPROM.read(1));
  //  Serial.println(EEPROM.read(2));
  //  Serial.println("++++++++++++");
}
void loop() {

}
void reloj() {
  //Reloj 1
  if (EEPROM.read(2) == 0) {
    if (segundo < 59) {
      segundo++;
      ss = String(segundo);
      if (ss.length() == 1) {
        lcd.setCursor(7, 1);
        lcd.print("0");
        lcd.setCursor(8, 1);
        lcd.print(segundo);
      }
      else {
        lcd.setCursor(7, 1);
        lcd.print(segundo);
      }
      if (EEPROM.read(1) == 10) {
        if (segundo == 50) {
          EEPROM.update(2, 1); //Requisito para la activacion del WDT
          wdt_enable(WDTO_500MS);
        }
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
        if (minuto == 10) {
          EEPROM.update(1, 1);
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
  }
  //Reloj 2
  if (EEPROM.read(2) == 1) {
    if (seg < 59) {
      seg++;
      ss = String(seg);
      if (ss.length() == 1) {
        lcd.setCursor(7, 1);
        lcd.print("0");
        lcd.setCursor(8, 1);
        lcd.print(seg);
      }
      else {
        lcd.setCursor(7, 1);
        lcd.print(seg);
      }
    }
    else {
      if (mint < 59) {
        lcd.setCursor(7, 1);
        lcd.print("00");
        seg = 0;
        mint++;
        sm = String(mint);
        if (sm.length() == 1) {
          lcd.setCursor(4, 1);
          lcd.print("0");
          lcd.setCursor(5, 1);
          lcd.print(mint);
        }
        else {
          lcd.setCursor(4, 1);
          lcd.print(mint);
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
  }
}

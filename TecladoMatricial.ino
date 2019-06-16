/*
  VALIDAR UNA CLAVE DE 5 DIGITOS
  Clave: 12345
  ON/C sirve para borrar un dato
  = sirve para comprobar la clave
  + sirve para reiniciar el programa
*/
#include <LiquidCrystal.h>              //Libreria LCD
#include <Keypad.h>                     //Libreria Teclado
LiquidCrystal lcd(5, 4, 13, 12, 11, 10);//Pines del LCD: RS, E, D4, D5, D6, D7
String clave = "12345";                 //Clave predeterminada
String claveTemp = "";                  //Variable donde se guardan los datos del LCD
int m = 0;                              //Posición inicial de las filas
int n = 1;                              //Posición inicial de las columnas
char tecla;                             //Variable que se asigna cuando se presionan los pulsadores del teclado
const byte fil = 4;                     //# de filas que se usan del teclado
const byte col = 4;                     //# de columnas que se usan del teclado
char matriz[fil][col] = {               //Matriz que hace relación al teclado real
  {'7', '8', '9', 'A'},
  {'4', '5', '6', 'B'},
  {'1', '2', '3', 'C'},
  {'*', '0', '#', 'D'}
};
byte filPin[fil] = {A0, A1, A2, A3};    //Conexion de los pines de las filas del teclado al arduino
byte colPin[col] = {9, 8, 7, 6};        //Conexion de los pines de las columnas del teclado al arduino
Keypad teclado = Keypad(makeKeymap(matriz), filPin, colPin, fil, col); //Asignación de los pines con las filas y columnas
void setup() {
  lcd.begin(16, 2);                     //Inicio LCD
  lcd.setCursor(0, 0);
  lcd.print("INGRESE CLAVE");           //Presentación del programa
  for (int pos = 0; pos < 16; pos++) {
    lcd.scrollDisplayRight();
    delay(40);
  }
  for (int pos = 0; pos < 16; pos++) {
    lcd.scrollDisplayLeft();
    delay(40);
  }
  lcd.clear();
  lcd.print("INGRESE CLAVE");
  lcd.setCursor(0, 1);
  lcd.blink();                          //Parpadeo del cursor
}
void loop() {

  tecla = teclado.getKey();             //Obtener los datos del teclado
  if (tecla != NO_KEY) {
    if (tecla == '1' || tecla == '2' || tecla == '3' || tecla == '4' || tecla == '5' || tecla == '6' || tecla == '7' || tecla == '8' || tecla == '9' || tecla == '0') {
      claveTemp += tecla;               //Guardar los datos de las teclas presionadas
      lcd.setCursor(m, n);              //Sirve para cambiar la posicion del cursor del LCD
      lcd.print(tecla);                 //Imprime lo que se pulsa en el teclado
      m++;                              //Mover la poscición de las filas
    }
    if (tecla == '*') {
      lcd.setCursor(m - 1, n);          //Regresar el cursor un espacio
      lcd.print(' ');                   //Borra el número
      m = m - 1;
      claveTemp = claveTemp.substring(0, m);//Quita los datos que han sido borrados de la variable
    }
    if (tecla == '#') {
      if (clave == claveTemp) {
        lcd.clear();
        lcd.print("BIENVENIDO");
        claveTemp = "";
        lcd.noBlink();                  //Quitar el parpadeo del cursor
      }
      else {
        lcd.setCursor(0, 1);
        lcd.print("ERROR");
        delay(400);
        claveTemp = "";
        reinicio();
      }
    }
    if (tecla == 'D') {
      reinicio();
    }
  }
}
void reinicio() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("INGRESE CLAVE");
  lcd.setCursor(0, 1);
  m = 0;
  lcd.blink();
}

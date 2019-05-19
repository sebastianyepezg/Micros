String placa = "";
String pl;
void setup() {
  Serial.begin(9600);
  Serial.println("VALIDADOR DE PLACAS");
  Serial.println("Ingrese su placa");
  Serial.println("Debe contener 3 letras, 1 guion y 4 numeros");
  Serial.println("-------------------------------------------");
  delay(100);

}

void loop() {
  if (Serial.available() > 0)
  {
    placa = Serial.readString();
    placa.toUpperCase(); //Todas las letras ingresadas estarán en mayúsculas
    Serial.println(placa);
    Serial.println("-----------------------------");
    if (placa.length() == 8) {
      pl = placa.substring(placa.indexOf("-") + 1, placa.length());
      if (pl.length() == 4) {
        if (placa.substring(3, 4) == "-") {
          if (placa.substring(0, 1) != "0" && placa.substring(0, 1) != "1" && placa.substring(0, 1) != "2" && placa.substring(0, 1) != "3" && placa.substring(0, 1) != "4" && placa.substring(0, 1) != "5" && placa.substring(0, 1) != "6" && placa.substring(0, 1) != "7" && placa.substring(0, 1) != "8" && placa.substring(0, 1) != "9") {
            if (placa.substring(1, 2) != "0" && placa.substring(1, 2) != "1" && placa.substring(1, 2) != "2" && placa.substring(1, 2) != "3" && placa.substring(1, 2) != "4" && placa.substring(1, 2) != "5" && placa.substring(1, 2) != "6" && placa.substring(1, 2) != "7" && placa.substring(1, 2) != "8" && placa.substring(1, 2) != "9") {
              if (placa.substring(2, 3) != "0" && placa.substring(2, 3) != "1" && placa.substring(2, 3) != "2" && placa.substring(2, 3) != "3" && placa.substring(2, 3) != "4" && placa.substring(2, 3) != "5" && placa.substring(2, 3) != "6" && placa.substring(2, 3) != "7" && placa.substring(2, 3) != "8" && placa.substring(2, 3) != "9") {
                //Serial.println(placa);
                if (placa.substring(0, 1) == "A")
                  Serial.println("Su placa pertenece a Azuay");
                if (placa.substring(0, 1) == "B")
                  Serial.println("Su placa pertenece a Bolivar");
                if (placa.substring(0, 1) == "C")
                  Serial.println("Su placa pertenece a Carchi");
                if (placa.substring(0, 1) == "X")
                  Serial.println("Su placa pertenece a Cotopaxi");
                if (placa.substring(0, 1) == "H")
                  Serial.println("Su placa pertenece a Chimborazo");
                if (placa.substring(0, 1) == "O")
                  Serial.println("Su placa pertenece a El Oro");
                if (placa.substring(0, 1) == "E")
                  Serial.println("Su placa pertenece a Esmeraldas");
                if (placa.substring(0, 1) == "W")
                  Serial.println("Su placa pertenece a Galapagos");
                if (placa.substring(0, 1) == "G")
                  Serial.println("Su placa pertenece a Guayaquil");
                if (placa.substring(0, 1) == "I")
                  Serial.println("Su placa pertenece a Imbabura");
                if (placa.substring(0, 1) == "L")
                  Serial.println("Su placa pertenece a Loja");
                if (placa.substring(0, 1) == "R")
                  Serial.println("Su placa pertenece a Los Rios");
                if (placa.substring(0, 1) == "M")
                  Serial.println("Su placa pertenece a Manabi");
                if (placa.substring(0, 1) == "V")
                  Serial.println("Su placa pertenece a Morona Santiago");
                if (placa.substring(0, 1) == "N")
                  Serial.println("Su placa pertenece a Napo");
                if (placa.substring(0, 1) == "S")
                  Serial.println("Su placa pertenece a Pastaza");
                if (placa.substring(0, 1) == "P")
                  Serial.println("Su placa pertenece a Pichincha");
                if (placa.substring(0, 1) == "Q")
                  Serial.println("Su placa pertenece a Orellana");
                if (placa.substring(0, 1) == "K")
                  Serial.println("Su placa pertenece a Sucumbios");
                if (placa.substring(0, 1) == "T")
                  Serial.println("Su placa pertenece a Tungurahua");
                if (placa.substring(0, 1) == "Z")
                  Serial.println("Su placa pertenece a Zamora Chinchipe");
                if (placa.substring(0, 1) == "Y")
                  Serial.println("Su placa pertenece a Santa Elena");
                if (placa.substring(0, 1) == "J")
                  Serial.println("Su placa pertenece a Santo Domingo de los Tsachilas");
              }
              else {
                Serial.println("Los 3 primeros digitos deben ser letras");
              }
            }
            else {
              Serial.println("Los 3 primeros digitos deben ser letras");
            }
          }
          else {
            Serial.println("Los 3 primeros digitos deben ser letras");
          }
        }
        else {
          Serial.println("Debe colocar guion despues de las letras");
        }
      }
      else {
        Serial.println("Deben ser 4 numeros");
      }
    }
    else {
      Serial.println("La placa debe tener 3 letras, 1 guion y 4 numeros");
    }
  }

}

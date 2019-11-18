/***********************
  Validador de Cédulas
***********************/
String cedula = "";
String verif;
int num;
int vec [10] = {2, 1, 2, 1, 2, 1, 2, 1, 2};
String ced;
int i = 0;
int sum = 0;;
int mul;
//int aprox;
int resul;
void setup() {
  Serial.begin(9600);
  Serial.println("VALIDADOR DE CEDULA");
  Serial.println("Ingrese su numero de cedula");
  Serial.println("-------------------------------------------");
  delay(100);
}

void loop() {
  if (Serial.available() > 0) //Condición para escribir en virtual comand
  {
    cedula = Serial.readStringUntil('\n'); //Capturar la cédula sin el Enter
    Serial.println("");
    Serial.println("-------------------------------------------");
    if (cedula.length() == 11) //Restricción de la dimensión de la cédula
    {
      if (cedula.substring(9, 10) == "-") //Verificador del guión
      {
        Serial.println("Se han ingresado 11 digitos incluido el guion");
        Serial.println("-------------------------------------------");
        delay(500);
        ced = cedula.substring(0, cedula.indexOf("-")) + cedula.substring(10, 11); //Quitar el guión para facilitar la verificación
        if (cedula.substring(2, 3).toInt() < 6) //Restricción del 3er dígito menor a 6
        {
          verif = cedula.substring(10, 11); //Extraer el último dígito de la cédula
          num = verif.toInt();
          //Serial.println(ced);
          for (i = 0; i < ced.length() ; i++) { //Multiplicar por el vector verificador con los 9 primeros dígitos
            mul = vec[i] * ced.substring(i, i + 1).toInt();
            if (mul > 9) {
              mul = mul - 9; //suma la decena y unidad de un número
            }
            sum = sum + mul;
          }
          //Serial.println(sum);
          if (sum % 10 == 0) {
            if (sum / 10 == ced.substring(9, 10).toInt())
            {
              Serial.println("La cedula es correcta");
              Serial.println("-------------------------------------------");
            }
          } else {
            resul = (((sum / 10) + 1) * 10) - sum;
            //Serial.println(resul);
            //Serial.println(ced.substring(9, 10).toInt());
            if (resul == ced.substring(9, 10).toInt()) {
              Serial.println("La cedula es correcta");
              sum = 0;
              Serial.println("-------------------------------------------");
            }
          }
        }
        else
        {
          Serial.println("Error al ingresar su cedula");
          Serial.println("-------------------------------------------");
        }
      }
      else
      {
        Serial.println("Error al ingresar su cedula");
        Serial.println("-------------------------------------------");
      }
    }
    else
    {
      Serial.println("Error al ingresar su cedula");
      Serial.println("-------------------------------------------");
    }
    cedula = "";
  }
}

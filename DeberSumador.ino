//Puertos con entrada de datos digitales
int b1 = 7;
int b2 = 6;
int b3 = 5;
int cont1 = 0;
int cont2 = 0;
int A = 11;
int B = 10;
int C = 9;
int D = 8;
int decenas1;
int unidades1;
int s1 = 0;
int s2 = 0;
int sum = 0;
int dec1 = A1;
int uni1 = A0;
void setup() {
  pinMode(b1, INPUT);
  pinMode(b2, INPUT);
  pinMode(b3, INPUT);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(dec1, OUTPUT);
  pinMode(uni1, OUTPUT);
}
void loop() {
  //Funcionamiento de un botón sumando 1
  if (digitalRead(b1) == LOW) //El momento en que pulsamos el botón tenemos 0v.
  {
    delay(300); //Delay anti-rebote (200 - 500)Soft; (15 - 30)hard
    if (cont1 < 25)
    {
      cont1++;
    }
    else
    {
      cont1 = 0;
    }
    s1 = cont1;
    cont2 = 0;
    sum = 0;
  }
  decenas1 = cont1 / 10;
  unidades1 = cont1 % 10;
  digitalWrite(dec1, HIGH);
  digitalWrite(uni1, LOW);
  contador(decenas1);
  delay(50);
  digitalWrite(dec1, LOW);
  digitalWrite(uni1, HIGH);
  contador(unidades1);
  delay(50);
  //Funcionamiento de un botón sumando 2
  if (digitalRead(b2) == LOW)
  {
    delay(300); //Delay anti-rebote (200 - 500)Soft; (15 - 30)hard
    if (cont2 < 25)
    {
      cont2++;
    }
    else
    {
      cont2 = 0;
    }
    s2 = cont2;
    cont1 = 0;
    sum = 0;
  }
  decenas1 = cont2 / 10;
  unidades1 = cont2 % 10;
  digitalWrite(dec1, HIGH);
  digitalWrite(uni1, LOW);
  contador(decenas1);
  delay(50);
  digitalWrite(dec1, LOW);
  digitalWrite(uni1, HIGH);
  contador(unidades1);
  delay(50);
  //Funcionamiento del botón Sumador
  if (digitalRead(b3) == LOW)
  {
    delay(300); //Delay anti-rebote (200 - 500)Soft; (15 - 30)hard
    cont1 = 0;
    cont2 = 0;
    sum = s1 + s2;
  }
  decenas1 = (sum) / 10;
  unidades1 = (sum) % 10;
  digitalWrite(dec1, HIGH);
  digitalWrite(uni1, LOW);
  contador(decenas1);
  delay(50);
  digitalWrite(dec1, LOW);
  digitalWrite(uni1, HIGH);
  contador(unidades1);
  delay(50);
}
void contador (int dato) {
  switch (dato) {
    case 0:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      break;
    case 1:
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      break;
    case 2:
      digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      break;
    case 3:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      break;
    case 4:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      break;
    case 5:
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      break;
    case 6:
      digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      break;
    case 7:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      break;
    case 8:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
      break;
    case 9:
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
      break;
  }
}

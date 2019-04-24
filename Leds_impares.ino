int i;
int juego[8]={0, 1, 2, 3, 4, 5, 6, 7};
void setup() {
 for(i=0;i<8;i++)
  {
    pinMode(juego[i], OUTPUT);  
  }
}
void loop() {
////----------------------------1)Leds impares
 for(i=0;i<8;i++)
  {
    digitalWrite(juego[i],HIGH);
    delay(500);
    digitalWrite(juego[i],LOW);
    i++;
  }
//----------------------------2)Leds pares
 for(i=1;i<8;i++)
  {
    digitalWrite(juego[i],HIGH);
    delay(500);
    digitalWrite(juego[i],LOW);
    i++;
  }
//----------------------------3)Leds ascendentes/descendentes
 for(i=0;i<8;i++)
  {
    digitalWrite(juego[i],HIGH);
    delay(500);
  }
  for(i=7;i>=0;i--)
  {
    digitalWrite(juego[i],LOW);
    delay(500);
  }
//----------------------------4)Leds extremos
 for(i=0;i<4;i++)
  {
    digitalWrite(juego[i],HIGH);
    delay(500);
    digitalWrite(juego[i],LOW);
    delay(500);
    digitalWrite(juego[7-i],HIGH);
    delay(500);
    digitalWrite(juego[7-i],LOW);
  }
  //----------------------------5)Pares de Leds extremos
 for(i=0;i<8;i++)
  {
    digitalWrite(juego[i],HIGH);
    digitalWrite(juego[7-i],HIGH);
    delay(500);
    digitalWrite(juego[i],LOW);
    digitalWrite(juego[7-i],LOW);
  }  
}

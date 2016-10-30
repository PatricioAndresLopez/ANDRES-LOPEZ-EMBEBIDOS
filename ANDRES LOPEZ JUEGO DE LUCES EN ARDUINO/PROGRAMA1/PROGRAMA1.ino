// VARIABLES PARA LAS ENTRADAS 
int sw1=3;
int sw2=2;
int sw3=1;
// DECLARACION DE VARIABLES
int n=4; 
int leds[10]={13,12,11,10,9,8,7,6,5,4}; //Vector que hace referencia a los pines a ser utilizados 
int cont;
int cont1;
int a;
int b;
int i=0;
long randNumber; // inicialización de la función Random
void setup()  
{
Serial.begin(9600);  // Inicializacion comunicación serial
 while(n<=13)       // Ciclo para habilitar como salidas los puertos
 {
  pinMode(n,OUTPUT);
  n=n+1;
 }
 // HABILITACION DE PUERTOS COMO ENTRADAS
 pinMode(1,INPUT); 
 pinMode(2,INPUT);
 pinMode(3,INPUT);
}

void loop()
{ 
  if(digitalRead(sw1)==LOW && digitalRead(sw2)==LOW && digitalRead(sw3)==LOW) // Método para PRIMER juego no hace nada 
  {
    for(cont=0;cont<=9;cont++) // ciclo para recorrer los pines 
    { 
       digitalWrite(leds[cont],LOW);  // apago los leds 
    }
  i=0;    // pongo un valor de cero a la variable i para utilizarla en el último metodo 
  }

   if(digitalRead(sw1)==LOW && digitalRead(sw2)==HIGH && digitalRead(sw3)==LOW)  // Método para SEGUNDO juego ENCIENDO LOS PARES
  {
    for(cont=1;cont<=9;cont++)  // ciclo para recorrer los pines
    {
       digitalWrite(leds[cont],HIGH);  // enciendo cada uno de los leds
       delay(200);                     // tiempo de espera 
       digitalWrite(leds[cont],LOW);   // apago los leds
       delay(200);                     // tiempo de espera 
       cont=cont+1;                    // para enceder los leds en numeros pares  
    }
    i=0; // pongo un valor de cero a la variable i para utilizarla en el último metodo 
  }

  if(digitalRead(sw1)==LOW && digitalRead(sw2)==HIGH && digitalRead(sw3)==HIGH)  // Método para TERCER juego ENCIENDO LOS IMPARES
  {
    for(cont=0;cont<=9;cont++)   // enciendo cada uno de los leds
    {
       digitalWrite(leds[cont],HIGH);  // enciendo los leds 
       delay(200);                     // tiempo de espera 
       digitalWrite(leds[cont],LOW);   // apago los leds
       delay(200);                     // tiempo de espera 
       cont=cont+1;                    // para enceder los leds en numeros impares
    }
    i=0; // pongo un valor de cero a la variable i para utilizarla en el último metodo
  }
  if(digitalRead(sw1)==HIGH && digitalRead(sw2)==LOW && digitalRead(sw3)==HIGH)   // Método para CUARTO juego ENCIENDO MEDIANTE LA FUNCION RANDOM
  {
  for(cont=0;cont<=9;cont++)     // ciclo para recorrer los pines 
    {
       randNumber = random(0, 9);   // Funcion Random de 0 a 9 
       a=randNumber;                // A la variable a le asigno el valor de la funcion RANDOM
       digitalWrite(leds[a],HIGH);  // enciendo los leds 
       delay(200);                  // tiempo de espera 
       digitalWrite(leds[a],LOW);   // apago los leds
       delay(200);                  // tiempo de espera 
    }
    i=0; // pongo un valor de cero a la variable i para utilizarla en el último metodo
  }

   if(digitalRead(sw1)==HIGH && digitalRead(sw2)==HIGH && digitalRead(sw3)==LOW)   // Método para QUINTO juego ENCIENDO MEDIANTE LA FUNCION RANDOM
  {
    b=9;                                    // ASIGNO A LA VARIABLE b UN VALOR DE 9 
    for(cont=0;cont<=4;cont++)              // ciclo para recorrer los pines 
    {
       digitalWrite(leds[cont],HIGH);       // enciendo los leds de arriba hacia abajo 
       digitalWrite(leds[b],HIGH);          // enciendo los leds de abajo hacia arriba 
       delay(100);                          // tiempo de espera 
       digitalWrite(leds[cont],LOW);        // apago los leds   
       digitalWrite(leds[b],LOW);           // apago los leds  
       delay(100);                          // tiempo de espera 
       b=b-1;                               // Decremento de la variables b
    } 
    i=0; // pongo un valor de cero a la variable i para utilizarla en el último metodo
  }
  
   if(digitalRead(sw1)==HIGH && digitalRead(sw2)==HIGH && digitalRead(sw3)==HIGH) // Método para SEXTO juego OPCIONAL
  {
    if(i<5) // condicion para que solo se repita 5 veces este juego 
  {
    b=0;    // asignacion de valor 0 a la variable b
    cont1=9;  // asignacion de valor 9 a la variable cont1
    for(cont=0;cont<=4;cont++)  // metodo para recorrer los pines 
    { 
       if(cont1==9)     // condicion si la variable cont1=9
       {
       for(;cont1>=5;cont1--)  // metodo para recorrer los pines 
       {
          digitalWrite(leds[cont1],HIGH);  // enciendo los leds de arriba hacia abajo 
          digitalWrite(leds[b],HIGH);      // enciendo los leds de abajo hacia arriba 
          delay(200);                      // tiempo de espera 
          b=b+1;                           // incremento b en uno cada iteracción 
       }
       b=4;                                // Vuelvo a un dar un valor de 4 a la variable b 
       }
       cont1=cont1+1;                      // Incremento la varible cont 
       digitalWrite(leds[cont1],LOW);      // apago los leds encendidos 
       digitalWrite(leds[b],LOW);          // apago los leds encendidos 
       delay(100);                         // tiempo de espera
       b=b-1;                              
    }
    delay(100);                            // Tiempo de espera 
    i=i+1;                                 // CONTADOR PARA REALIZAR 5 REPETICIONES DE ESTE JUEGO  
  }
  }
}

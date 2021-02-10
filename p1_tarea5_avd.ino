/* Contador electronico con dos digitos que se actualiza
 *  dependiendo del pulsador que se pulse. Pup aumenta una
 *  unidad, pdown decrementa una unidad, pcenter inicializa a 0,
 *  si esta en 00 y se pulsa pdown el contador se pone en 99,
 *  y en este caso si se le da a pdown debe volver a 0
 */
byte Uno     = 0x06;
byte Dos     = 0x5B;
byte Tres    = 0x4F;
byte Cuatro  = 0x66;
byte Cinco   = 0x6D;
byte Seis    = 0x7D;
byte Siete   = 0x07;
byte Ocho    = 0x7F;
byte Nueve   = 0x67;
byte Cero    = 0x3F;
byte Unidades = 0;
byte Decenas = 0;

void setup() {
  DDRA = B11111111;
  PORTC = 0xFF;
  DDRL = 0x0F;
  DDRC = 0xFE;
}

void digit(byte digito) {
  switch (digito) {
    case 0: {
        PORTA = Cero;
        break;
      }
    case 1: {
        PORTA = Uno;
        break;
      }
    case 2: {
        PORTA = Dos;
        break;
      }
    case 3: {
        PORTA = Tres;
        break;
      }
    case 4: {
        PORTA = Cuatro;
        break;
      }
    case 5: {
        PORTA = Cinco;
        break;
      }
    case 6: {
        PORTA = Seis;
        break;
      }
    case 7: {
        PORTA = Siete;
        break;
      }
    case 8: {
        PORTA = Ocho;
        break;
      }
    case 9: {
        PORTA = Nueve;
        break;
      }
  }
}

// Inicializamos a 0 con la funcion pcenter
int pcenter() {
  Unidades = 0;
  Decenas = 0;
}

// Aumentamos en una unidad con la funcion pup
int pup() {
  if(Unidades == 9){
    Unidades = 0;
    if(Decenas == 9){
      Decenas = 0;
    } else {
      Decenas++;  
    }
  } else {
    Unidades++;
  }
}

// Decrementamos una unidad con la funcion pdown
int pdown() {
    if (Unidades == 0) {
      Unidades = 9;
      if(Decenas == 0){
        Decenas = 9; 
      } else {
        Decenas--;    
      }
    } else {
      Unidades--;
    }
}

void loop() {
  if (digitalRead(34) == 0) {
    pup();
    delay(200);
    tone(200,200,200);
  }
  if (digitalRead(31) == 0) {
    pdown();
    delay(200);
    tone(200,200,200);
  }
  if (digitalRead(33) == 0) {
    pcenter();
    delay(200);
    tone(200,200,200);
  }
  // Barrido continuo
  DDRL = 0b1;
  digit(Unidades);
  delay(5);
  DDRL = 0b10;
  digit(Decenas);
  delay(5);
}

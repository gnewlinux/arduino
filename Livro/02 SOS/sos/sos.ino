// Projeto 2 - SOS

// LED conectado ao pino 10
int ledPin = 10;

// executa uma vez, quando o sketch inicia
void setup() {
  // define o pino como saida
  pinMode(ledPin, OUTPUT);
}

// executa repetidas vezes
void loop() {

  // 3 pontos
  for (int x=0; x<3; x++){
    digitalWrite(ledPin, HIGH); // acende o LED
    delay(150); // espera 150ms
    digitalWrite(ledPin, LOW); // apaga o LED
    delay(150); // espera 150ms
  }

  // espera 100ms para marcar o intervalo entre as letras
  delay(200);

  // 3 traços
  for (int x=0; x<3; x++){
    digitalWrite(ledPin, HIGH); // acende o LED
    delay(400); // espera 400ms
    digitalWrite(ledPin, LOW); // apaga o LED
    delay(100); // espera 100ms
  }

  delay(200);
  // espera 100ms para marcar o intervalo enre as letras
  // 3 pontos
  for (int x=0; x<3; x++){
    digitalWrite(ledPin, HIGH); // acende o LED
    delay(150); // espera 150ms
    digitalWrite(ledPin, LOW); // apaga o LED
    delay(150); // espera 150ms
  }
  // espero 5 segundos antes de repetir o sinal de SOS
  delay(5000);
}


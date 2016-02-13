// Projeto 4 - Semáforo Interativo

// estabelece o semaforo para carros
int carRed = 12; 
int carYellow = 11;
int carGreen = 10;

// estabelece o semaforo para pedestres
int pedRed = 9; 
int pedGreen = 8;

// pino do botão
int button = 2;

int crossTime = 5000; // tempo para que os pedestres atravessem

int randomNumber;

unsigned long changeTime; // tempo desde que o botão foi pressionado

void setup() {
  pinMode(carRed, OUTPUT);
  pinMode(carYellow, OUTPUT);
  pinMode(carGreen, OUTPUT);
  pinMode(pedRed, OUTPUT);
  pinMode(pedGreen, OUTPUT);
  pinMode(button, INPUT); // botão pino 2

  // acende a luz verde
  digitalWrite(carGreen, HIGH);
  digitalWrite(pedRed, HIGH);

}

void loop() {
  int state = digitalRead(button);

  /* Verifica se o botão foi pressionado e se
  transcorreram 5 segundos desde a ultima vez que isso occoreu */
  if (state == HIGH && (millis() - changeTime) > 5000){
    // Chama a função para alterar as luzes
    changeLights();
  }
  
}

void changeLights() {

  randomNumber = random(1000, 5000);
  delay(randomNumber);
  
  digitalWrite(carGreen, LOW);  // apaga o verde
  digitalWrite(carYellow, HIGH);  // acende o amarelo
  delay(2000); // espera 2 segundos

  digitalWrite(carYellow, LOW); //  apaga o amarelo
  digitalWrite(carRed, HIGH); //  acende o vermelho
  delay(1000);  //  espera 1 segundos, por segurança

  digitalWrite(pedRed, LOW);  //  apaga o vermelho dos pedestres
  digitalWrite(pedGreen, HIGH);  // acende o verde dos pedestres
  delay(crossTime); //  espera por intervalo de tempo predefinido

  // pisca verde dos pedestres
  for (int x=0; x<10; x++){
    digitalWrite(pedGreen, HIGH);
    delay(250);
    digitalWrite(pedGreen, LOW);
    delay(250);
  }

  // acende o vermelho dos pedestres
  digitalWrite(pedRed, HIGH);
  delay(500);

  digitalWrite(carYellow,HIGH); //  acende o amarelo
  digitalWrite(carRed, LOW);  //  apaga o vermelho
  delay(1000);

  digitalWrite(carGreen, HIGH); // acende o verde
  digitalWrite(carYellow, LOW); //  apaga o amarelo

  // registra o tempo desde a ultima alteração no semaforo
  changeTime = millis();
  // depois retorna para o loop pincipal do programa
}

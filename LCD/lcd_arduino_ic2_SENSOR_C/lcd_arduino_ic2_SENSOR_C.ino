  
// Programa : Display LCD 16x2 e modulo I2C
// Autor : Arduino e Cia
#include "DHT.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN A1 // pino que estamos conectado
#define DHTTYPE DHT11 // DHT 11

DHT dht(DHTPIN, DHTTYPE);

// Inicializa o display no endereco 0x27
LiquidCrystal_I2C lcd(0x3F,2,1,0,4,5,6,7,3, POSITIVE);
 
void setup()
{
 Serial.begin(9600);
 dht.begin();
 lcd.begin (4,20); 
}
 
void loop()
{
  lcd.setBacklight(HIGH);
 /* lcd.setCursor(0,0);
  lcd.print(" CAMPUS PARTY 2016 ");*/
  // A leitura da temperatura e umidade pode levar 250ms!
  // O atraso do sensor pode chegar a 2 segundos.
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  // testa se retorno é valido, caso contrário algo está errado.
  if (isnan(t) || isnan(h)) 
  {
    Serial.println("Failed to read from DHT");
  } 
  else
  {
    lcd.setCursor(0,0);
    lcd.print(" CAMPUS PARTY 2016 ");
    lcd.setCursor(0,2);
    lcd.print("Temperatura: ");
    lcd.print(t);
    lcd.print(" C");
    lcd.setCursor(0,3);
    lcd.print("Umidade: ");
    lcd.print(h);
    lcd.print(" %");

    delay(2000);
 }
}

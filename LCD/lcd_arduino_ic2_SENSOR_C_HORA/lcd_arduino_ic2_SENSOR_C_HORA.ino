  
// Programa : Display LCD 16x2 e modulo I2C
// Autor : Arduino e Cia
#include "DHT.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN A1 // pino que estamos conectado
#define DHTTYPE DHT11 // DHT 11

DHT dht(DHTPIN, DHTTYPE);

int segundo, minuto, hora; 
unsigned long UtlTime; 

//LEDS

int verdePin = 8;
int amareloPin = 9;
int vermelhoPin = 10;

// Inicializa o display no endereco 0x27
LiquidCrystal_I2C lcd(0x3F,2,1,0,4,5,6,7,3, POSITIVE);
 
void setup()
{
  // LEDS

 pinMode(verdePin, OUTPUT);
 pinMode(amareloPin, OUTPUT);
 pinMode(vermelhoPin, OUTPUT);
 
 UtlTime=0;   
 minuto=0;   
 hora=0;   
 segundo=0;
 
 Serial.begin(9600);
 Serial.println("DHTxx test!");
 dht.begin();
 lcd.begin (4,20);

 Serial.print("\nEntre Minuto:");  
  while(minuto==0)   {     
  if (Serial.available() > 0)     
  {       
  minuto= Serial.parseInt();     
  }   
  }   
  lcd.print(minuto);   
  delay(1000); 
  
  //Configura a hora   
  lcd.clear();   
  lcd.setCursor(0,0);   
  lcd.print("Hora: ");   
  Serial.print("\nEntre Hora:"); 
  while(hora==0)   
  {     
  if (Serial.available() > 0)     
  {       
  hora= Serial.parseInt();     
  }   
  }   
  lcd.print(hora);   
  delay(1000);  
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
  if (t <= 24){
  digitalWrite(verdePin, HIGH);
  } else if (t <= 26 && t > 24){
    digitalWrite(amareloPin, HIGH);
  } else if (t > 26 ){
    digitalWrite(vermelhoPin, HIGH);
  }
  if (isnan(t) || isnan(h)) 
  {
    Serial.println("Failed to read from DHT");
  } 
  else
  {
    lcd.setCursor(0,2);
    lcd.print("Temperatura: ");
    lcd.print(t);
    lcd.print(" C");
    lcd.setCursor(0,3);
    lcd.print("Umidade: ");
    lcd.print(h);
    lcd.print(" %");

    if(millis()-UtlTime<0) {
      UtlTime=millis();
    }
      else
    {
      segundo=int((millis()-UtlTime)/1000);
    }
      if(segundo>59)
    {
      lcd.clear();
      segundo=0;
      minuto++;     
      UtlTime=millis();     
      if(minuto>59)     
    {       
      hora++;       
      minuto=0;       
      if(hora>23)       
    {         
      hora=0;
    }
    }
    }

    lcd.setCursor(0,0);   
    lcd.print("Hora ");   
    lcd.print(hora);   
    lcd.print(":");   
    lcd.print(minuto);   
    lcd.print(":");   
    lcd.print(segundo); 

 }
}

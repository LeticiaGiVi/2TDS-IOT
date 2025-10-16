#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#define POT1 34
#define POT2 35

LiquidCrystal_l2C lcd(0x27, 20, 4);//endereço I2C do LCD, 20 colunas, 4 linhas

// variaveis

int valorPOT1_V; // armazena valor de 0 a 4.095(analogRead)
int valorPOT2_I;

float tensao;// no projeto usaremos 0 a 240 V
float corrente;// no projeto, usaremos 0 a 20A
float potencia;// calcular ----> P= V * I ----> unidade W
float tempo;// medir o tempo que o dispositivo está ligado
float energia_consumida;// calcular ---> energia_consumida = P * t 

float calcular_potencia(){
potencia = tensao * corrente;
return potencia
}

void setup() {
  Serial.begin(115200);//baudrate para ESP32
  lcd.init();
  
  lcd.backlight();//ativa luz de fundo do display
  lcd.serCursor(0, 0)// coluna, linha 
  lcd.print(" Medidior de energia ")
  lcd.serCursor(0, 1)// coluna, linha 
  lcd.print("  1CCR - S.E.R.S  ")
  lcd.serCursor(0, 2)// coluna, linha 
  lcd.print("   09/10/2025   ")
  lcd.serCursor(0, 3)// coluna, linha 
  lcd.print("   FIAP - CC   ")
  delay(3000);
  lcd.clear();


  lcd.serCursor(0, 1)// coluna, linha 
  lcd.print("  Sistema  ")
  lcd.serCursor(0, 2)// coluna, linha 
  lcd.print("   Inicializado   ")
  delay(3000);
  lcd.clear();
}

void loop() {
// Ler pinos analogicos
valorPOT1_V = analogRead(POT1);
valorPOT2_I = analogRead(POT2);

//converter de valores de 0 a 4095 para as faixas de medição de V e I
tensao= map(valorPOT1_V, 0, 4095, 0 , 2400) / 10.0;
corrente = map(valorPOT2_I, 0, 4095, 0 , 200) / 10.0;

lcd.setCursor(0,0);
lcd.print("Tensao: ");
lcd.print(tensao);
lcd.print(" V");

lcd.setCursor(0,1);
lcd.print("Corrente: ");
lcd.print(corrente);
lcd.print(" A");

calcular_potencia();
lcd.setCursor(0,2);
lcd.print("potencia: ");
lcd.print(potencia);
lcd.print(" W");
}



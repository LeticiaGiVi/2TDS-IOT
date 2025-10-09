#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#define POT1 34
#define POT2 35

LiquidCrystal_l2C lcd(0x27, 20, 4);//endereço I2C do LCD, 20 colunas, 4 linhas

// variaveis

int valorPOT1_V; // armazena valor de 0 a 4.095(analogRead)
int valorPOT2_I;
float tensao;// no projeto usaremos 0 a 240 V
float corrente;// no projeto, usaremos 0 a 10A

void setup() {
  Serial.begin(115200);//baudrate para ESP32
  lcd.init();
  
  lcd.backlight();//ativa luz de fundo do display
  lcd.serCursor(0, 0)// coluna, linha 
  lcd.print("Projeto - Medidor")
    lcd.serCursor(0, 1)// coluna, linha 
  lcd.print("de energia")
    lcd.serCursor(0, 2)// coluna, linha 
  lcd.print("SERS - 1CCR")
    lcd.serCursor(0, 3)// coluna, linha 
  lcd.print("09/10/2025")


}

void loop() {
// nada a fazer...
}

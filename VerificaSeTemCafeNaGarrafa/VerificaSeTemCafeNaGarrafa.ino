/*
###################################################################
Verificador de quantidade de caf� na garrafa
-------------------------------------------------------------------
Vers�o: 0.1 Alpha
Desenvolvedor:  Dyego Mass / Alexandre Alvaro
-------------------------------------------------------------------
HARDWARE
Controlador:		ATMega 328p
C�lula de carga:    Balan�a de precis�o SF-400 (at� 10kg)
Conversor de sinal: Amplificador HX711
-------------------------------------------------------------------
DESCRI��O
Atrav�s do peso da garrafa de caf� � detectado e sinalizado quando
a quantidade de l�quido fica abaixo de um valor pr�-definido.
###################################################################
*/

#include "Balanca.h"
Balanca balanca;

void setup() {
	Serial.begin(115200);
	balanca.parametros(2, 3, 35600.f, 1000);
	balanca.inicializar();
}

void loop() {
	float peso = balanca.lerValorDoPeso();
	Serial.print("Peso: ");
	Serial.print(peso);
	Serial.println("kg");
}


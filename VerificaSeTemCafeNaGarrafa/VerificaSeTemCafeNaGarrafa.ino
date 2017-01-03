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

#include <HX711.h>
HX711 celulaDeCarga(2, 3);
const float fatorDeCalibracao = 35600.f;
const int velocidadeDaComunicacaoSerial = 115200;
const int atrasoNoLoopDeAquisicaoDeDados = 3000;

void setup() {
	Serial.begin(velocidadeDaComunicacaoSerial);
	celulaDeCarga.set_scale(fatorDeCalibracao);
	celulaDeCarga.tare();
}

void loop() {
	float peso = lerValorDoPeso();
	Serial.print("Peso: ");
	Serial.print(peso);
	Serial.println("kg");
}

float lerValorDoPeso() {
	celulaDeCarga.power_down();
	delay(atrasoNoLoopDeAquisicaoDeDados);
	celulaDeCarga.power_up();
	float peso = celulaDeCarga.get_units() * 0.1;
	peso = (peso < 0.01 && peso > -0.01) ? 0.0 : peso;
	return peso;
}
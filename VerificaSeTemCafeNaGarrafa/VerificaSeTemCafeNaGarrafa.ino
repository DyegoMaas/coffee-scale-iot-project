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

#include "GarrafaCafe.h"

void setup() {
	Serial.begin(115200);
}

void loop() {
	Serial.print("Peso da garrafa vazia: ");
	Serial.print(GarrafaCafe.getPesoGarrafaVazia());
	Serial.println("kg");

	Serial.print("Peso da garrafa cheia: ");
	Serial.print(GarrafaCafe.getPesoGarrafaCheia());
	Serial.println("kg");

	Serial.print("Peso atual na balanca: ");
	Serial.print(Balanca.lerValorDoPeso());
	Serial.println("kg");

	Serial.print("Quantidade de cafe na garrafa: ");
	Serial.print(GarrafaCafe.QuantidadeCafeEmMl() * 100);
	Serial.println("%");
	Serial.println();

	Serial.print("Situacao da garrafa: ");
	Serial.println(GarrafaCafe.stringSituacaoGarrafa[GarrafaCafe.VerificaSituacaoCafe()]);
	Serial.println("---------------------------------------");

}
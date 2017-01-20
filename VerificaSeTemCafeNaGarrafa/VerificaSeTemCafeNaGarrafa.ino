/*
###################################################################
Verificador de quantidade de cafe na garrafa
-------------------------------------------------------------------
Versao: 0.1 Alpha
Desenvolvedor:  Dyego Mass / Alexandre Alvaro
-------------------------------------------------------------------
HARDWARE
Controlador:		ATMega 328p
Celula de carga:    Balanca de precisao SF-400 (ate 10kg)
Conversor de sinal: Amplificador HX711
-------------------------------------------------------------------
DESCRICAO
Atraves do peso da garrafa de cafe e detectado e sinalizado quando
a quantidade de liquido fica abaixo de um valor pre-definido.
###################################################################
*/

//#include "InterfaceUsuario.h"
#include "GarrafaCafe.h"

void setup()
{
	auto velocidadeComunicacaoSerial = 115200;
	Serial.begin(velocidadeComunicacaoSerial);
	while (!Serial){}
	Serial.println("Serial OK!");
	//InterfaceUsuario.Iniciar();
}

void loop()
{
	Serial.print("Quantidade cafe: ");
	Serial.println(GarrafaCafe.QuantidadeCafeEmMl());

	Serial.print("Situacao da garrafa: ");
	Serial.println(GarrafaCafe.stringSituacaoGarrafa[GarrafaCafe.VerificarSituacaoCafe()]);
	Serial.println("---------------------------------------");
}

#ifndef _GARRAFACAFE_h
#define _GARRAFACAFE_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
#include "Balanca.h"
#include "MensagemStatusGarrafa.h"
#include "InterfaceUsuario.h"


class GarrafaCafeClass
{
	float _peso_garrafa_cheia;
	float _maximo_cafe;

	bool _modo_calibracao = false;
	const int PINO_IO_CALIBRACAO_BALANCA = 6;
	const int PINO_IO_CALIBRACAO_GARRAFA_VAZIA = 10;
	const int PINO_IO_CALIBRACAO_GARRAFA_CHEIA = 9;
	const float PORCENTAGEM_NIVEL_CRITICO_CAFE = 0.1f;
	const float PORCENTAGEM_POUCO_CAFE = 0.3f;
	const float FATOR_CONVERSAO_PORCENTAGEM_PARA_ML_CAFE = 1.0f;
	const float FATOR_TOLERANCIA_PORCENTAGEM_CAFE = 0.1f;
	const bool BOTAO_PRESSIONADO = LOW;
	static void FiltrarRuidoSinalBalanca(float& quantidade_cafe_em_litros);

public:
	float _porcentagem_cafe;
	float _peso_cafe;
	float _peso_garrafa_vazia;

	explicit GarrafaCafeClass();

	MensagemStatusGarrafaClass::SituacaoGarrafa VerificarSituacaoCafe();

	void ChecarBotoesCalibrarPesoGarrafa();

	float RecalcularPorcentagemCafeNagarrafa();
	float QuantidadeCafeEmMl();

	void atualizarPesoGarrafaVazia();

	float getPesoGarrafaVazia() const
	{
		return _peso_garrafa_vazia;
	}

	void atualizarPesoGarrafaCheia();

	float getPesoGarrafaCheia() const
	{
		return _peso_garrafa_cheia;
	}
};

extern GarrafaCafeClass GarrafaCafe;

#endif

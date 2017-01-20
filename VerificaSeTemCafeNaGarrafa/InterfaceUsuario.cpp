#include "InterfaceUsuario.h"
#include <LiquidCrystal.h>

LiquidCrystal lcd = LiquidCrystal(12, 11, 5, 4, 3, 2);
byte blocoBarra1[8] = { 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10 };
byte blocoBarra2[8] = { 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18 };
byte blocoBarra3[8] = { 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C };
byte blocoBarra4[8] = { 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E };
byte blocoBarra5[8] = { 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F };

void InterfaceUsuarioClass::Iniciar()
{
	lcd.begin(16, 4);
	lcd.setCursor(0, 1);
	lcd.write("Hello World!");
	Serial.println("Hello World!");
}

void InterfaceUsuarioClass::criarCaracteresBarraProgresso()
{
	lcd.createChar(1, blocoBarra1);
	lcd.createChar(2, blocoBarra2);
	lcd.createChar(3, blocoBarra3);
	lcd.createChar(4, blocoBarra4);
	lcd.createChar(5, blocoBarra5);
}

void InterfaceUsuarioClass::ImprimirBlocosCheios(int linha_lcd, int blocos)
{
	if (blocos > 0) {
		for (auto bloco = 0; bloco < blocos; bloco++)
		{
			lcd.setCursor(bloco, linha_lcd);
			lcd.write(5);
		}
	}
}

void InterfaceUsuarioClass::ImprimirUltimoBloco(int linha_lcd, int blocos, int colunasUltimoBloco)
{
	auto ultimoBloco = blocos;
	lcd.setCursor(ultimoBloco, linha_lcd);
	if(colunasUltimoBloco > 0)
	{
		lcd.write(colunasUltimoBloco);
	}
}

void InterfaceUsuarioClass::ImprimirBarraProgresso(int linha_lcd, float porcentagem)
{
	criarCaracteresBarraProgresso();
	int porcentagemSemVirgula = porcentagem * 100;
	int blocos = map(porcentagemSemVirgula, 0, 100, 0, 16);
	int linha = map(porcentagemSemVirgula, 0, 100, 0, 80);
	auto colunasUltimoBloco = (linha - (blocos * 5));

	ImprimirBlocosCheios(linha_lcd, blocos);
	ImprimirUltimoBloco(linha_lcd, blocos, colunasUltimoBloco);
	Serial.println(porcentagem);
}

void InterfaceUsuarioClass::ImprimirBarraProgresso(int linha_lcd, int valor, int valor_minimo, int valor_maximo)
{
	criarCaracteresBarraProgresso();
	int blocos = map(valor, valor_minimo, valor_maximo, 0, 16);
	int linha = map(valor, valor_minimo, valor_maximo, 0, 80);
	auto colunasUltimoBloco = (linha - (blocos * 5));

	ImprimirBlocosCheios(linha_lcd, blocos);
	ImprimirUltimoBloco(linha_lcd, blocos, colunasUltimoBloco);
}


InterfaceUsuarioClass InterfaceUsuario;

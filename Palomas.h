#pragma once
#include"Aves.h"
class Paloma :public Aves
{
private:

public:
	Paloma();
	~Paloma();
	void mostrar();


};

Paloma::Paloma(): Aves(3,1,2)
{
}

Paloma::~Paloma()
{
}

void Paloma::mostrar() {
	Console::ForegroundColor=ConsoleColor::Gray;
	Console::SetCursorPosition(x, y); cout << "<=>";
}
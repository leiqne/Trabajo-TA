#pragma once
#include"Aves.h"
class Paloma :public Aves
{
private:

public:
	Paloma();
	~Paloma();
	void mostrar();

	void mostrarMuert()
	{
		Console::ForegroundColor = ConsoleColor::Red;
		Console::SetCursorPosition(x, y); cout << "*~*";
	}
};

Paloma::Paloma() : Aves(4, 1, 2)
{
}

Paloma::~Paloma()
{
}

void Paloma::mostrar() {
	Console::ForegroundColor = ConsoleColor::Gray;
	Console::SetCursorPosition(x, y); cout << "<=>";
}
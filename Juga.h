#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include "Bala.h"
#include <vector>
#define ALTO 40
#define ANCHO 70

using namespace std;
using namespace System;
class Jugador
{
public:
	Jugador(int x, int y)
	{
		this->x = x;
		this->y = y;
		this->dx = 1;
		this->alto = 1;
		this->ancho = 1;


	}
	~Jugador();

	void SetX(int x)
	{
		this->x = x;
	}

	int getX()
	{
		return this->x;
	}


	void Sety(int y)
	{
		this->y = y;
	}

	int gety()
	{
		return this->y;
	}

	int getDy()
	{
		return this->dx;
	}

	void setDY(int dx)
	{
		this->dx = dx;
	}

	int getAncho()
	{
		return this->ancho = ancho;
	}

	int getAlto()
	{
		return this->ancho = ancho;
	}




	void mover(char tecla)
	{


		// borrar

		for (int i = 0; i < ancho; i++)
		{
			Console::SetCursorPosition(x + i, y);
			cout << "     ";
		}
		// movimiento

		if (tecla == char(ConsoleSpecialKey(75)))
		{
			if (x > 0)
			{
				x--;
			}
		}
		else if (tecla == char(ConsoleSpecialKey(77)))
		{
			if (x < ANCHO - 1)
			{
				x++;
			}
		}
		//CON ESTO DE ACA ARRIBA YA TIENES TODO PARA MOVIMIENTO WASD!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! OE NO TE OLVIDES ESTO VALE MILLONES :V


		//mostrar

		Console::SetCursorPosition(x, y); cout << char(219);
	}

private:
	int x, y, dx, alto, ancho;
	char tecla;
	vector<Bala*>* arrB;
};



Jugador::~Jugador()
{
}
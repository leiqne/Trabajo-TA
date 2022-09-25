#pragma once
#include "Aves.h"
#include "Gaviotas.h"
#include "Palomas.h"
#include "Juga.h"
#include "ArrBalas.h"

class Controlador
{
public:
	Controlador();
	~Controlador();
	void agregarJugador()
	{
		p1 = new Jugador((ANCHO / 2), ALTO - 5);//Se crea Jugador
	}

	void agregarEn()
	{
		char tec;
		while (tec != char(32))			//Parametro de tecla para que inicie el juego
		{
			Console::SetCursorPosition(20, ALTO / 2);
			cout << "PRESIONE ESPACIO PARA INICIAR JUEGO...";
			tec = _getch();
			int avG = rand() % 10 + 1;			//Se crea numero de Aves random (10)
			int agP = 10 - avG;					//Se resta la cantidad con 10 para las sobrantes. Ej. 10 - 8 = 2 AGP = 2
			Console::SetCursorPosition(20, ALTO / 2);

			system("cls");
			if (tec == char(32)) {
				for (int i = 0; i < avG; i++)
				{
					AV->agregar(new Gaviotas());//se crea gaviota AVG veces

				}
				for (int i = 0; i < agP; i++)
				{
					AV->agregar(new Paloma());//se crea paloma AGP veces
				}
			}
		}

	}

	void moverJug(char tecla)
	{
		p1->mover(tecla);
	}

	void moverEn()
	{
		if (AV->getSize() > 0)
		{
			AV->mover();
		}
	}

	void agregarBala(char tecla)
	{
		if (tecla == 'D' || tecla == 'd')
		{
			cout << "PUM!";
			AB->agregar(new Bala(p1->getX(), (ALTO - 6)));
		}
	}
	void moverBala()
	{
		AB->mover();
	}

	void Stats()
	{

	}


	void StatM()
	{

		AV->StatM();

	}

	bool Colision()
	{

		for (int i = 0; i < AB->getSize(); i++)
		{
			for (int j = 0; j < AV->getSize(); j++)
			{
				if (AB->getX(i) + 1 + 0 >= AV->getX(j) && AB->getX(i) <= AV->getX(j) + AV->getAncho(j) + AV->getDX(j)
					&&
					AB->getY(i) + 1 + AB->getDY(i) >= AV->getY(j) && AB->getY(i) <= AV->getY(j) + 1 + 0)
				{

					AV->mostrarmuerto(j);
					AV->StatMuert(j);

					AB->borrarCON(i);
					AV->borrarCON(j);

					AB->EliminarCON(i);

					AV->EliminarCON(j);

					return true;



				}



			}
		}
		return false;





	}


private:
	ArregloAves* AV = new ArregloAves();
	ArregloBala* AB = new ArregloBala();
	Jugador* p1;
	bool Col;

};

Controlador::Controlador()
{
}

Controlador::~Controlador()
{
}
#pragma once
#include "Bala.h"
#include "ArregloAV.h"
#include<vector>
#include<conio.h>
class ArregloBala
{
private:
	vector<Bala*> arrA;// se cra un vector vala

public:
	ArregloBala();
	~ArregloBala();
	void agregar(Bala* objB);
	void eliminar(Bala* objA)
	{
		for (int i = 0; i < arrA.size(); i++)
		{
			if (objA->getY() - objA->getDy() < 0)
			{
				arrA.erase(arrA.begin() + i);
			}

		}
	}
	void mover();
	//se retorna la posicion de x
	int getX(int i) 
	{
		return arrA.at(i)->getX();
	}
	//se retorna la velocidad de la bala
	int getDY(int i)
	{


		return arrA.at(i)->getDy();


	}
	//se retorna la posicion de y
	int getY(int i)
	{
		return arrA.at(i)->getY();
	}

	//se devuelve el tamaño del arreglo
	int getSize()
	{
		return arrA.size();
	}
	//para borrar la forma
	void borrarCON(int i)
	{

		arrA.at(i)->borrar();
	}
	//para borrar del arreglo
	void EliminarCON(int i)
	{
		arrA.erase(arrA.begin() + i);
	}


};
//constructor
ArregloBala::ArregloBala(){}
//destructor
ArregloBala::~ArregloBala(){}

void ArregloBala::agregar(Bala* objA) {// se agrega una bala al final
	arrA.push_back(objA);
}

void ArregloBala::mover() { // se hace el borrar mover mostrar en 1 sola funcion
	for (int i = 0; i < arrA.size(); i++)
	{
		arrA.at(i)->borrar();


		arrA.at(i)->mover();


		if (arrA.at(i)->getY() != 0)
		{
			arrA.at(i)->mostrar();
		}
	}
}



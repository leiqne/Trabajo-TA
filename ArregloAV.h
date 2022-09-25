#pragma once
#include"Gaviotas.h"
#include"Palomas.h"
#include<vector>
#include<conio.h>
class ArregloAves
{
private:
	vector<Aves*> arrA;
	int ContG = 0, ContP = 0;
public:
	ArregloAves();
	~ArregloAves();
	void agregar(Aves* objA);
	void eliminar(int pos);
	void borrar();
	void mostrar();
	void mover();


	int getDX(int i)//se retorna la velocidad de la ave
	{
		return arrA.at(i)->getDX();
	}


	int getX(int i)// se retorna  la posicion en x
	{
		return arrA.at(i)->getX();

	}

	int getY(int i)// se retorna  la posicion en y
	{
		return arrA.at(i)->getY();
	}



	int getSize()//se retorna el tamaño del arreglo
	{
		return arrA.size();
	}


	//se retorna el ancho de las gaviotas
	int getAncho(int i)
	{
		switch (arrA.at(i)->getId())
		{
		case 1:
			return 3;

			break;
		case 2:
			return 4;
			break;

		default:
			break;
		}

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

	//estaticas de las palomas muertas
	void StatM()
	{
		cout << "Palomas: " << ContG << " / ";

		cout << "Gaviotas: " << ContP;

	}

	//los contadores segun la id de cada paloma
	void StatMuert(int i)
	{

		switch (arrA.at(i)->getId())
		{
		case 1:

			ContG++;

			break;
		case 2:
			ContP++;
			break;

		default:
			break;
		}
		Console::SetCursorPosition(1, ALTO - 2);
		cout << "Palomas: " << ContG;
		Console::SetCursorPosition(1, ALTO - 1);
		cout << "Gaviotas: " << ContP;

	}

	//se muestran la animacion de las palomas al colisionar con una bala
	void mostrarmuerto(int i) {

		switch (arrA.at(i)->getId())
		{
		case 1:

			((Gaviotas*)(arrA.at(i)))->mostrarMuert();
			_sleep(150);
			break;
		case 2:
			((Paloma*)(arrA.at(i)))->mostrarMuert();
			_sleep(150);
			break;

		default:
			break;
		}

	}

};

ArregloAves::ArregloAves(){}

ArregloAves::~ArregloAves(){}

void ArregloAves::agregar(Aves* objA) {
	arrA.push_back(objA);
}
void ArregloAves::eliminar(int pos) {//se borra del arreglo
	for (int i = 0; i < arrA.size(); i++)
	{
		arrA.erase(arrA.begin() + i);
	}
}
void ArregloAves::mover() {// se mueven los objetos aves
	for (int i = 0; i < arrA.size(); i++)
	{
		arrA.at(i)->borrar();

		switch (arrA.at(i)->getId())
		{
		case 1:
			((Gaviotas*)(arrA.at(i)))->mover();
			((Gaviotas*)(arrA.at(i)))->mostrar();

			break;
		case 2:((Paloma*)(arrA.at(i)))->mover();
			((Paloma*)(arrA.at(i)))->mostrar();
			break;

		default:
			break;
		}
	}

}

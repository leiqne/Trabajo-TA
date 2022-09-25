#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#define ALTO 40 //se devine el alto y el ancho de la consola
#define ANCHO 70

using namespace std;
using namespace System;
class Bala
{
private:
	int x, y, dy, ancho, alto; //se define los atributos de 
	int contmuerte = 0;

public:

	Bala(int x, int y); // se definen los metodos
	~Bala();
	void mostrar();
	void borrar();
	void mover();
	int getX();
	int getY();
	int getDy();//velocidad del objeto
	int getAncho();
	int getAlto();



};

Bala::Bala(int x, int y) //se inicializan los atributos
{
	this->alto = 1;
	this->ancho = 1;
	this->x = x;
	this->y = y;
	this->dy = 1;
}

Bala::~Bala() {}
//los getters para poder acceder a los atributos desde otra clase
int Bala::getX() {
	return this->x;
}
int Bala::getY() {
	return this->y;
}
int Bala::getDy() {
	return this->dy;
}
int Bala::getAncho() {
	return this->ancho;
}
int Bala::getAlto() {
	return this->alto;
}
//se reemplaza el caracter por un espacio en blanco
void Bala::borrar() {

	if (y - dy < 0 || y - dy <= ALTO)
	{
		Console::SetCursorPosition(x, y);

		cout << " ";
	}
	if (y - dy < 0)// se comprueba si la bala esta en el limite de la pantalla para que no de error de memoria ni que se quede pegado
		//y se reemplaza el caracter por un espacio
	{
		dy *= 0;
		cout << "  ";
	}



}
void Bala::mover() {
	y = y - dy; //se resta para que asi tenga un movieminto hacia arriba
}
void Bala::mostrar() { //se dibuja la bala y se define su color
	Console::ForegroundColor = ConsoleColor::Blue;
	Console::SetCursorPosition(x, y); cout << "*";
}
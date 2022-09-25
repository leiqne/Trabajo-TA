#pragma once
#include<iostream>
#define ALTO 40
#define ANCHO 70
using namespace System;
using namespace std;

class Aves
{
protected:
	int x;
	int y;
	int dx;
	int ancho;
	int alto;
	int id;
public:
	Aves(int ancho, int alto,int id);
	~Aves();
	int getX();
	int getY();
	int getDX();
	int getAncho();
	int getAlto();
	int getId();
	void borrar();
	void mover();
	virtual void mostrar() {}


};

Aves::Aves(int ancho, int alto,int id)
{
	this->alto = alto;
	this->ancho = ancho;
	this->id = id;
	x = rand() % (ANCHO - ancho);
	y = rand() % (ALTO - alto);
	dx = rand() % 10 + 1;

}

Aves::~Aves()
{
}

int Aves::getX() {
	return this->x;
}
int Aves::getY() {
	return this->y;
}
int Aves::getDX() {
	return this->dx;
}
int Aves::getAncho() {
	return this->ancho;
}
int Aves::getAlto() {
	return this->alto;
}
int Aves::getId() {
	return this->id;
}

void Aves::borrar() {

	for (int i = 0; i < alto; i++) {
		for (int j = 0; j < ancho; j++) {
			Console::SetCursorPosition(x + j, y + i);
			cout << " ";
		}
	}
}

void Aves::mover() {
	x = x + dx;
	if (x + dx < 0 || x + ancho + dx >= ANCHO)
	{
		dx *= -1;
	}
}
#pragma once
#include "Personaje.h"

class Enemigo : public Personaje // Realción de Herencia
{
public:
	Enemigo(double px, int py);
	~Enemigo();
	double get_x();
};

// imp
Enemigo::Enemigo(double px, int py) : Personaje(px, py) // Heredo el metodo constructor del padre
{

}

Enemigo::~Enemigo()
{}

double Enemigo::get_x()
{
	return this->x;
}
#pragma once
#include "Personaje.h"

class Aliado : public Personaje // Realción de Herencia
{
public:
	Aliado(double px, int py);
	~Aliado();
	double get_x();
};

// imp
Aliado::Aliado(double px, int py) : Personaje(px, py) // Heredo el metodo constructor del padre
{

}

Aliado::~Aliado()
{}

double Aliado::get_x()
{
	return this->x1;
}

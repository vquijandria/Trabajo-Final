#pragma once
#include "Personaje.h"
class Jugador :public Personaje // Relacion de herenica
{
public:
	Jugador(double px, int py);
	~Jugador();
	double get_x();
};

// Imp
Jugador::Jugador(double px, int py) :Personaje(px, py)
{
}

Jugador::~Jugador()
{}

double Jugador::get_x()
{
	return this->x;
}
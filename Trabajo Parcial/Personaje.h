#pragma once
#include "Librerias.h"

class Personaje
{
protected:
	double x;
	double x1;
	int y;
	int color;
	// dx
	double velocidad; // velocidad 
	double velocidadt;

public:
	Personaje(double px, int py);
	~Personaje();
	void borrar();
	void mover();
	void dibujar(short elegido);
};

//IMPLMENTACION
Personaje::Personaje(double px, int py)
{

	this->x = px;
	this->x1 = px;
	this->y = py;

	//velocidad = 0.1 + (rand() % 10) / 5.0;
	velocidad = 1;
	velocidadt = 1;
}

Personaje::~Personaje()
{}

void Personaje::borrar()
{
	Console::SetCursorPosition(x, y);	  cout << "    ";
	Console::SetCursorPosition(x, y + 1); cout << "    ";
	Console::SetCursorPosition(x, y + 2); cout << "    ";
	Console::SetCursorPosition(x, y + 3); cout << "    ";

}
void Personaje::mover()
{
	x += velocidad;
	x1 += velocidadt;
}

void Personaje::dibujar(short elegido)
{
	//Jugador
	if (elegido == 1)
	{
		Console::ForegroundColor = ConsoleColor(3);

		Console::SetCursorPosition(x, y);    cout << " O  " << endl;
		Console::SetCursorPosition(x, y + 1);cout << "/|\\" << endl;
		Console::SetCursorPosition(x, y + 2);cout << " |  " << endl;
		Console::SetCursorPosition(x, y + 3);cout << "/ \\" << endl;
	}
	//Enemigo
	if (elegido == 2)
	{
		Console::ForegroundColor = ConsoleColor(4);
		Console::SetCursorPosition(x, y);    cout << " T  " << endl;
		Console::SetCursorPosition(x, y + 1);cout << "/|\\" << endl;
		Console::SetCursorPosition(x, y + 2);cout << " |  " << endl;
		Console::SetCursorPosition(x, y + 3);cout << "/ \\" << endl;
	}
	//Aliado
	if (elegido == 3)
	{
		Console::SetCursorPosition(x, y);    cout << " B  " << endl;
		Console::SetCursorPosition(x, y + 1);cout << "/|\\" << endl;
		Console::SetCursorPosition(x, y + 2);cout << " |  " << endl;
		Console::SetCursorPosition(x, y + 3);cout << "/ \\" << endl;
	}
}
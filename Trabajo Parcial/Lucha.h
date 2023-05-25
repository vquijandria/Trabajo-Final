#pragma once
#include "M_Enemigo.h"
#include "M_Jugador.h"
#include "M_Aliado.h"

class Lucha  // Clase Controladora
{
private:
	Jugador* ObjetoJugador;
	Enemigo* ObjetoEnemigo;
	Aliado* ObjetoAliado;
	Lucha* ObjetoCalculadora;
	int num1, num2, respuesta, operacion, aciertos, desaciertos;

public:
	Lucha();
	~Lucha();
	void iniciar_Lucha();
	void iniciar_Lucha2();
	short meta;
};

// imp
Lucha::Lucha()
{
	srand(time(NULL));
	ObjetoJugador = new Jugador(3, 4);
	ObjetoEnemigo = new Enemigo(3, 10);
	ObjetoAliado = new Aliado(10, 4);
}

Lucha::~Lucha()
{
	delete ObjetoJugador;
	delete ObjetoEnemigo;
	delete ObjetoAliado;
	delete ObjetoCalculadora;
}

void Lucha::iniciar_Lucha()
{
	srand(time(0)); // Inicializa el generador de números aleatorios con la hora actual

	short jugador = 1;
	short enemigo = 2;
	short aliado = 3;
	short aciertos = 0, desaciertos = 0;
	short repuestaUsuario;
	short VidaE = 0;
	short VidaJ = 0; 

	// ( x, y )
	// x = lateral
	// y = vertical

	while (true)
	{
		Console::ForegroundColor = ConsoleColor(11);
		Console::SetCursorPosition(0, 15);
		cout << " ------------------------------------------------------------------------------ ";
		Console::SetCursorPosition(55, 4);
		cout << " | ";
		Console::SetCursorPosition(55, 5);
		cout << " | ";
		Console::SetCursorPosition(55, 6);
		cout << " | ";
		Console::SetCursorPosition(55, 7);
		cout << " | ";
		Console::SetCursorPosition(55, 8);
		cout << " | ";
		Console::SetCursorPosition(55, 9);
		cout << " | ";
		Console::SetCursorPosition(55, 10);
		cout << " | ";
		Console::SetCursorPosition(55, 11);
		cout << " | ";
		Console::SetCursorPosition(55, 12);
		cout << " | ";
		Console::SetCursorPosition(55, 13);
		cout << " | ";
		Console::SetCursorPosition(55, 14);
		cout << " | ";

		ObjetoJugador->dibujar(jugador);
		
		ObjetoEnemigo->dibujar(enemigo);

		int num1 = rand() % 30 + 30; //numero aleatorio del 0 al 20 
									 // rand() % x + y x: limitar maximo ; y: limitar minimo
		int num2 = rand() % (num1 + 1) + 1; // Generar un número aleatorio entre 0 y num1 
											// Siempre poner un +1 para evitar error

		// Genera una operación aleatoria (0 = suma, 1 = resta, 2 = multiplicación)
		operacion = rand() % 2;

		// Genera los valores de vidas
		
		
		// posicion de la pregunta matematica
		Console::ForegroundColor = ConsoleColor(2);
		Console::SetCursorPosition(38, 17);
		cout << "Cuanto es " << num1 << " ";

		if (operacion == 0) {
			cout << "+";
			respuesta = num1 + num2;
		}
		else if (operacion == 1) {
			cout << "-";
			respuesta = num1 - num2;
		}
		cout << " " << num2 << "? ";
		cin >> repuestaUsuario;
		Console::SetCursorPosition(56, 17);
		cout << "    ";

		// Verifica si la respuesta es correcta y muestra un mensaje
		if (repuestaUsuario == respuesta)
		{
			ObjetoJugador->borrar();
			ObjetoJugador->mover();
			ObjetoJugador->dibujar(jugador);

			aciertos++;
			Console::SetCursorPosition(26, 22);
			VidaJ = VidaJ + 10;
			
			if (aciertos == 3)
			{
				VidaJ = VidaJ + 10;
				ObjetoAliado->borrar();
				ObjetoAliado->dibujar(aliado);
			}

		}
		else if (repuestaUsuario != respuesta)
		{
			ObjetoEnemigo->borrar();
			ObjetoEnemigo->mover();
			ObjetoEnemigo->dibujar(enemigo);

			desaciertos++;
			Console::SetCursorPosition(15, 22);
			VidaE = VidaE + 10;
			
		}
		if (VidaJ == 40)
		{
			
			system("CLS");
			Console::SetCursorPosition(50, 13);
			cout << " !!You Win !!!" << endl;
			_sleep(500);
			Console::SetCursorPosition(45, 17);
			cout << "Presiona cualquier tecla para continuar...." << endl;
			break;
		}
		if (VidaE == 30)
		{
			system("CLS");
			Console::SetCursorPosition(50, 13);
			cout << " !!!Game Over !!!" << endl;
			_sleep(500);
			Console::SetCursorPosition(45, 17);
			cout << "Presiona cualquier tecla para continuar...." << endl;
			break;
		}

		Console::ForegroundColor = ConsoleColor(11);
		Console::SetCursorPosition(63, 19);
		cout << "Distancia del Enemigo: " << VidaE << endl;
		Console::SetCursorPosition(13, 19);
		cout << "Distancia del Jugador: " << VidaJ << endl;
		_sleep(120);
	}
}
void Lucha::iniciar_Lucha2()
{
	srand(time(0)); // Inicializa el generador de números aleatorios con la hora actual

	short jugador = 1;
	short enemigo = 2;
	short aliado = 3;
	short aciertos = 0, desaciertos = 0;
	short repuestaUsuario;
	short VidaE = 0;
	short VidaJ = 0;

	// ( x, y )
	// x = lateral
	// y = vertical

	while (true)
	{
		Console::ForegroundColor = ConsoleColor(11);
		Console::SetCursorPosition(0, 15);
		cout << " ------------------------------------------------------------------------------ ";
		Console::SetCursorPosition(55, 4);
		cout << " | ";
		Console::SetCursorPosition(55, 5);
		cout << " | ";
		Console::SetCursorPosition(55, 6);
		cout << " | ";
		Console::SetCursorPosition(55, 7);
		cout << " | ";
		Console::SetCursorPosition(55, 8);
		cout << " | ";
		Console::SetCursorPosition(55, 9);
		cout << " | ";
		Console::SetCursorPosition(55, 10);
		cout << " | ";
		Console::SetCursorPosition(55, 11);
		cout << " | ";
		Console::SetCursorPosition(55, 12);
		cout << " | ";
		Console::SetCursorPosition(55, 13);
		cout << " | ";
		Console::SetCursorPosition(55, 14);
		cout << " | ";

		ObjetoJugador->dibujar(jugador);

		ObjetoEnemigo->dibujar(enemigo);

		int num1 = rand() % 30 + 30; //numero aleatorio del 0 al 20 
									 // rand() % x + y x: limitar maximo ; y: limitar minimo
		int num2 = rand() % (num1 + 1) + 1; // Generar un número aleatorio entre 0 y num1 
											// Siempre poner un +1 para evitar error

		// Genera una operación aleatoria (0 = suma, 1 = resta, 2 = multiplicación)
		operacion = rand() % 2;

		// Genera los valores de vidas


		// posicion de la pregunta matematica
		Console::ForegroundColor = ConsoleColor(2);
		Console::SetCursorPosition(38, 17);
		cout << "Cuanto es " << num1 << " ";

		if (operacion == 0) {
			cout << "x";
			respuesta = num1 * num2;
		}
		else if (operacion == 1) {
			cout << "/";
			respuesta = num1 / num2;
		}
		cout << " " << num2 << "? ";
		cin >> repuestaUsuario;
		Console::SetCursorPosition(56, 17);
		cout << "    ";

		// Verifica si la respuesta es correcta y muestra un mensaje
		if (repuestaUsuario == respuesta)
		{
			ObjetoJugador->borrar();
			ObjetoJugador->mover();
			ObjetoJugador->dibujar(jugador);

			aciertos++;
			Console::SetCursorPosition(26, 22);
			VidaJ = VidaJ + 10;

			if (aciertos == 3)
			{
				VidaJ = VidaJ + 10;
				ObjetoAliado->borrar();
				ObjetoAliado->dibujar(aliado);
			}

		}
		else if (repuestaUsuario != respuesta)
		{
			ObjetoEnemigo->borrar();
			ObjetoEnemigo->mover();
			ObjetoEnemigo->dibujar(enemigo);

			desaciertos++;
			Console::SetCursorPosition(15, 22);
			VidaE = VidaE + 10;

		}
		if (VidaJ == 40)
		{

			system("CLS");
			Console::SetCursorPosition(50, 13);
			cout << " !!You Win !!!" << endl;
			_sleep(500);
			Console::SetCursorPosition(45, 17);
			cout << "Presiona cualquier tecla para continuar...." << endl;
			break;
			_getch();
		}
		if (VidaE == 30)
		{
			system("CLS");
			Console::SetCursorPosition(50, 13);
			cout << " !!!Game Over !!!" << endl;
			_sleep(500);
			Console::SetCursorPosition(45, 17);
			cout << "Presiona cualquier tecla para continuar...." << endl;
			break;
			_getch();
		}

		Console::ForegroundColor = ConsoleColor(11);
		Console::SetCursorPosition(63, 19);
		cout << "Distancia del Enemigo: " << VidaE << endl;
		Console::SetCursorPosition(13, 19);
		cout << "Distancia del Jugador: " << VidaJ << endl;
		_sleep(120);
	}
}
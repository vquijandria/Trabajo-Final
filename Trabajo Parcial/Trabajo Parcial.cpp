#include "pch.h"
#include "Lucha.h"
int menu() {
    int op;
    do {
        Console::ForegroundColor = ConsoleColor(11);
        cout << "================Runner by Work================" << endl;
        cout << "BIENVENIDO!" << endl;
        cout << "[1] Nuevo Juego" << endl;
        cout << "[2] Elige la dificultad" << endl;
        cout << "[3] Contexto e instrucciones del juego" << endl;
        cout << "[4] Creditos." << endl;
        cout << "[5] Salir." << endl;
        cout << "------------------------------------------------" << endl;
        cout << "Elija una opcion -> ";
        cin >> op;
    } while (op < 1 || op > 5);
    return op;
}

void Creditos() 
{
    system("CLS");

    cout << "Quijandria Araneda, Vicente (U201822697)" << endl;
    cout << "Howard Robles, Guillermo (U202222275)" << endl;
    cout << "Guevara Dueñas, Fabricio (U202114081)" << endl;
}

void Contexto()
{
    system("CLS");

    cout << "Contexto: " << endl;
    cout << "Dos economistas muy destacados pero por la situación económica que atraviesa el pais hay mucha" << endl;
    cout << "demanda de trabajo y solo hay un puesto de trabajo para uno de elllos" << endl;
    cout << "el que logre llegar primero a la oficina del jefe se queda con el puesto" << endl;
    cout << "ayudalo resolviendo problemas matematicos para poder llegar antes que tu rival." << endl;

    cout << endl;
    cout << "Instrucciones: " << endl;
    cout << "Resolviendo problemas matematicos puede avanzar su personaje a la meta para la victoria" << endl;
    cout << "al ser correctas avanzara pero al ser incorrectas su enemigo avanzara" << endl;
    cout << "Tambien cuando logre tener 3 problemas resueltos con exito un aliado llegara a darle un empujon para llegar a la meta" << endl;
    cout << "El primero que llegue se dara con la victoria de la carrera" << endl;
}


int main()
{
    Console::SetWindowSize(90, 40);
    Console::CursorVisible = false;

    Lucha* ObjetoLuchar;
    ObjetoLuchar = new Lucha();
    
    int op;
    char tecla = ' ';
    int numero;
    op = menu();
    while (1) 
    {
        if (op == 1) 
        {
            while (true)
            {
                //aqui tendria que aver un reinicio de iniciar_lucha

                system("CLS");
                ObjetoLuchar->iniciar_Lucha();
                system("pause>0"); //da paso al mensaje de finalizacion del juego

                system("CLS");
                ObjetoLuchar->iniciar_Lucha2();
                system("pause>0"); //da paso al mensaje de finalizacion del juego

                //aqui tendria que aver un reinicio de iniciar_lucha

                //manda al menu
                system("CLS");
                op = menu();
                break;
            }
        }
        if (op == 2)
        {
            cout << endl;
            cout << "Normal[1] o Dificil[2]" << endl;
            cin >> numero;

            if (numero == 1) 
            {
                while (true)
                {
                    //aqui tendria que aver un reinicio de iniciar_lucha

                    system("CLS");
                    ObjetoLuchar->iniciar_Lucha();
                    system("pause>0"); //da paso al mensaje de finalizacion del juego

                    //aqui tendria que aver un reinicio de iniciar_lucha

                    //manda al menu
                    system("CLS");
                    op = menu();
                    break;
                }
            }
            if (numero == 2) 
            {
                while (true)
                {
                    //aqui tendria que aver un reinicio de iniciar_lucha

                    system("CLS");
                    ObjetoLuchar->iniciar_Lucha2();
                    system("pause>0"); //da paso al mensaje de finalizacion del juego

                    //aqui tendria que aver un reinicio de iniciar_lucha

                    //manda al menu
                    system("CLS");
                    op = menu();
                    break;
                }
            }
        }
        if (op == 3) 
        {
            Contexto();
            cout << endl;
            cout << "Ingrese x para regresar -> ";
            cin >> tecla;
            if (tecla == 'x') {
                system("CLS");
                op = menu();
            }
        }
        if (op == 4) {
            Creditos();
            cout << endl;
            cout << "Ingrese x para regresar -> ";
            cin >> tecla;
            if (tecla == 'x') {
                system("CLS");
                op = menu();
            }
        }
        if (op == 5) {
            cout << endl;
            cout << "Cerrando el programa...";
            cout << endl;
            exit(0);
        }
        system("CLS");
    }
    _getch();
}

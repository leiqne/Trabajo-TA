#include <time.h>
#include "Controller.h"

int main()
{
	Console::SetWindowSize(ANCHO, ALTO);
	Console::CursorVisible = false;
	Controlador* C1 = new Controlador();

	srand(time(NULL));


	int AvesC = 0;
	int PC = 0;
	int PG = 0;






	//En este caso se agregan las palomas.


	C1->agregarEn();
	C1->agregarJugador();


	while (AvesC < 10)
	{





		Console::SetCursorPosition(0, ALTO - 4);
		for (int i = 0; i <= ANCHO; i++)
		{

			cout << "-";
		}

		Console::SetCursorPosition(1, ALTO - 3);
		cout << "Aves cazadas: " << AvesC;







		if (_kbhit())//espera a tecla
		{
			char tecla = _getch();

			C1->moverJug(tecla);
			C1->agregarBala(tecla);








		}
		C1->moverBala();

		C1->moverEn();

		if (C1->Colision())
		{
			AvesC++;
		}

		_sleep(25);
	}

	system("cls");

	Console::ForegroundColor = ConsoleColor::White;
	Console::SetCursorPosition(20, ALTO / 2);
	cout << "Cazaste todas las aves, termino el juego!!!!!";
	Console::SetCursorPosition(20, ALTO / 2 + 1);
	cout << "Aves cazadas: " << AvesC;
	Console::SetCursorPosition(20, ALTO / 2 + 2);
	C1->StatM();
	getch();

	getch();
	return 0;
}
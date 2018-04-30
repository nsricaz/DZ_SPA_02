#include"IGRA_ZIVOTA.h"


//int main() {
//
//	srand(time(nullptr));
//	system("color B");
//	int x, y;
//
//	cout << "         THE GAME OF life - Implementation in C++" << endl;
//	cout << endl;
//	IGRA_ZIVOTA A;
//		while (true)
//		{
//			A.iscrtaj();
//			A.sljedeca_generacija();
//			Sleep(2000);
//			system("CLS");
//		}	
//		return 0;
//}
//U PRVOM MAINU NE ZNAM DI MI JE TOCNO GRESKA ,PA BI MOLIO DA MI POJASNITE ;
//U DRUGOM MISLIM DA RADI DOBRO;
#include<iostream>
#include<ctime>
#include<Windows.h>


using namespace std;

static const unsigned int STUPACA = 40;
static const unsigned int REDAKA = 20;

void iscrtaj(bool _generacija[REDAKA + 1][STUPACA + 1]);
void sljedeca_generacija(bool _generacija[REDAKA + 1][STUPACA + 1]);
int generateRandoom(int min, int max) {
	return rand() % (max - min + 1) + min;
}
int main() {

	srand(time(nullptr));
	system("color A");
	bool _generacija[REDAKA + 1][STUPACA + 1] = {};
	bool _sljedeca_generacija[REDAKA + 1][STUPACA + 1]{};
	int x, y, n;
	char start;
	cout << "         -THE GAME OF life -" << endl;
	cout << endl;

	
	/*for (int i = 0; i<60; i++)
	{

		x = generateRandoom(1, 10);
		y = generateRandoom(1, 10);
		_generacija[x][y] = true;
		iscrtaj(_generacija);
	}*/
	for (unsigned int i = 0; i < REDAKA; i++)
	{
		for (unsigned int j = 0; j < STUPACA; j++)
		{
			_generacija[i][j] = generateRandoom(0, 3) == 0;
		}
	}
				cout << "IGRA ZIVOTA postavljena. Start the game ? (y/n)" << endl;
	iscrtaj(_generacija);
	cin >> start;

	if (start == 'y' || 'Y')
	{
		while (true)
		{
			iscrtaj(_generacija);
			sljedeca_generacija(_generacija);
			Sleep(1000);
			system("CLS");
		}
	}
	else
	{
		return 0;
	}

}

void iscrtaj(bool _generacija[REDAKA + 1][STUPACA + 1]) {
	for (int a = 1; a < REDAKA; a++)
	{
		for (int b = 1; b < STUPACA; b++)
		{
			if (_generacija[a][b] == true)
			{
				cout << " O ";
			}
			else
			{
				cout << " . ";
			}
			if (b == STUPACA - 1)
			{
				cout << endl;
			}
		}
	}
}

void compareGrid(bool _generacija[REDAKA + 1][STUPACA + 1], bool _sljedeca_generacija[REDAKA + 1][STUPACA + 1]) {
	for (int a = 0; a < REDAKA; a++)
	{
		for (int b = 0; b < STUPACA; b++)
		{
			_sljedeca_generacija[a][b] = _generacija[a][b];
		}
	}
}

void sljedeca_generacija(bool _generacija[REDAKA + 1][STUPACA + 1]) {
	bool _sljedeca_generacija[REDAKA + 1][STUPACA + 1] = {};
	compareGrid(_generacija, _sljedeca_generacija);

	for (int a = 1; a < REDAKA; a++)
	{
		for (int b = 1; b < STUPACA; b++)
		{
			int alive = 0;
			for (int c = -1; c < 2; c++)
			{
				for (int d = -1; d < 2; d++)
				{
					if (!(c == 0 && d == 0))
					{
						if (_sljedeca_generacija[a + c][b + d])
						{
							++alive;
						}
					}
				}
			}
			if (alive < 2)
			{
				_generacija[a][b] = false;
			}
			else if (alive == 3)
			{
				_generacija[a][b] = true;
			}
			else if (alive == 2)
			{
				_generacija[a][b] = true;
			}
			else if (alive > 3)
			{
				_generacija[a][b] = false;
			}
		}
	}
}
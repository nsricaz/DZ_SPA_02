//#include "IGRA_ZIVOTA.h"
//
//int generateRandoom(int min, int max) {
//	return rand() % (max - min + 1) + min;
//}
//
//
//bool IGRA_ZIVOTA::slucajna_vrijednost()
//{
//	
//	int x, y;
//	for ( unsigned int i = 0; i<REDAKA; i++)
//	{
//		for (unsigned int j = 0; j < STUPACA; j++)
//		{
//			_generacija[i][j] = generateRandoom(0, 3) == 0;
//		}
//
//	
//		
//	}
//	
//	
//	return  false;
//}
//void IGRA_ZIVOTA::celija_zauzeta(bool _generacija[REDAKA + 1][STUPACA + 1], bool _sljedeca_generacija[REDAKA + 1][STUPACA + 1])
//{
//
//	for (int a = 0; a < REDAKA; a++)
//	{
//		for (int b = 0; b < STUPACA; b++)
//		{
//			_sljedeca_generacija[a][b] = _generacija[a][b];
//		}
//	}
//
//
//	
//
//
//}
//void IGRA_ZIVOTA::sljedeca_generacija()
//{
//	bool _sljedeca_generacija[REDAKA + 1][STUPACA + 1] = {};
//	celija_zauzeta(_generacija, _sljedeca_generacija);
//
//	for (int a = 1; a < REDAKA; a++)
//	{
//		for (int b = 1; b < STUPACA; b++)
//		{
//			int alive = 0;
//			for (int c = -1; c < 2; c++)
//			{
//				for (int d = -1; d < 2; d++)
//				{
//					if (!(c == 0 && d == 0))
//					{
//						if (_sljedeca_generacija[a + c][b + d])
//						{
//							++alive;
//						}
//					}
//				}
//			}
//			if (alive < 2)
//			{
//				_generacija[a][b] = false;
//			}
//			else if (alive == 3)
//			{
//				_generacija[a][b] = true;
//			}
//			else if (alive == 2)
//			{
//				_generacija[a][b] = true;
//			}
//			else if (alive > 3)
//			{
//				_generacija[a][b] = false;
//			}
//		}
//	}
//}
//void IGRA_ZIVOTA::iscrtaj()
//{
//	
//		for (int a = 1; a <REDAKA ; a++)
//		{
//			for (int b = 1; b < STUPACA; b++)
//			{
//				if (_generacija[a][b] == true)
//				{
//					cout << " @ ";
//				}
//				else
//				{
//					cout << " . ";
//				}
//				if (b == STUPACA - 1)
//				{
//					cout << endl;
//				}
//			}
//		}
//	
//}

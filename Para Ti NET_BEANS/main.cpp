/*
 * Copyright (C) 2017 Sergio Cuellar <s.cuellar.21s@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * File:   newmain.cpp
 * Author: Sergio Cuellar <s.cuellar.21s@gmail.com>
 * Created on 17 de junio de 2017, 01:10 PM
 */

#include<cmath>
#include<iostream>
#include<stdio.h>
#include<Windows.h>
using namespace std;

#define SIZE 14 // TAMAÑO    SOLO de 5-18!!
#define CH ((char)3) // caracter ASCII de "corazón"
//Definir valores para parametros de MoveWindows
//****DEFINIR TAMAÑO DE LA VENTANA CON REGLA DE 3 EN RELACION SIZE!!!!**** 14-500 en x    14-616 en y
#define WindowWidth (SIZE * 500 / 14)
#define WindowHeight (SIZE * 616 / 14)

const string MENSAJE (" Que tengas un dia igual de bonito que tu ;)"); // "(ESPACIO+MENSAJE)"
//Dimensiones de la pantalla del usuario (px)
const int scWidth = GetSystemMetrics (SM_CXSCREEN);
const int scHeight = GetSystemMetrics (SM_CYSCREEN);
//Valores de la pocision deseada de la ventana para MoveWindows
const int posX = (scWidth - WindowWidth) / 2;
const int posY = (scHeight - WindowHeight) / 2;
int x, y;

int main ()
{
  // Ajusta la ventana de la consola y la centra
  HWND hWnd = GetConsoleWindow ();
  MoveWindow (hWnd, posX, posY, WindowWidth, WindowHeight, TRUE);
  //COORD coord;
  //coord.X = WindowWidth; // Defining our X and
  //coord.Y = WindowHeight;  // Y size for buffer.
  //SetConsoleScreenBufferSize(hWnd, coord);

  /*
  Partes superiores (parábolas)
   */
  for (y = 0; y < SIZE / 2 + 2; y++) // ALTURA  TOP-MENSAJE  // SIZE/2
  {
	for (x = 0; x <= 4 * SIZE; x++)
	{
	  if (y == SIZE / 2 + 2 - 1 && 2 * SIZE - 1 <= x && x <= 2 * SIZE + 1)// para juntar las parabolas en la ultima linea
		cout << CH;
	  else
	  {
		int dist1 = sqrt (pow (y - SIZE, 2) + pow (x - SIZE, 2));
		int dist2 = sqrt (pow (y - SIZE, 2) + pow (x - 3 * SIZE, 2));
		if (dist1 < SIZE + 0.5 || dist2 < SIZE + 0.5) // +0.5 // AJUSTAR ESTO PARA DARLE MAYOR ANCHURA A LAS PARABOLAS
		  cout << CH; // imprime el caracter de "corazón"
		  //Sleep(25); // da efecto de lluvia en la muestra de la figura
		else
		  cout << " "; // imprime espacio vacio
	  }
	}
	cout << endl; // termina la linea
  }

  // FIX: Ajustar para que el triangulo quede menos "picudo"
  /*
  Parte inferior con mensaje impreso
   */
  for (y = 1; y < 2 * SIZE; y++) //tamaño de la parte baja // 2*SIZE
  {
	for (x = 0; x < y; x++) // los espacios antes de la piramide en cada linea
	  cout << " ";

	for (x = 0; x < 4 * SIZE - 2 * y + 1; x++)
	{
	  if (2 <= y && y <= 4) // CAJA donde se muestra el mensaje  (de 1 a 3)renglon
	  {
		int idx = x - (4 * SIZE - 2 * y - MENSAJE.length ()) / 2; //ARREGLADO PARA QUEDAR CENTRADO! ;)
		if (0 <= idx && idx <= MENSAJE.length ())
		{
		  if (y == 3) // imprime el mensaje en el centro del cuadro
			cout << MENSAJE[idx];
		  else
			cout << " ";
		}else
		  cout << CH;
	  }else
		cout << CH;
	}
	cout << endl;
  }

  /*
  PARTE DE ABAJO REDONDEADA    ***!!! TERMINADO !!!****(AJUSTADA PARA TAMAÑO 14!)
   */
  //for (int y = 2 * SIZE - (SIZE / 2); y >= 0; y--) // tamaño: 4/3(SIZE)-1
  //{
  //	for (x = 0; x <= 4 * SIZE; x++)
  //	{
  //		int dist1 = sqrt(pow(y - SIZE - (SIZE - 1), 2) + pow(x - 2 * SIZE, 2));
  //		if (dist1 < 2 * SIZE) // +0.5
  //		{
  //			cout << CH; // imprime el caracter de "corazón"
  //		}
  //		else
  //			cout << " "; // imprime espacio vacio
  //	}
  //	cout << endl; // termina la linea
  //}

  printf ("Escribe 'Me encanta' + ENTER para continuar . . .\n");
  int scan;
  scanf ("%d", &scan);
  printf ("De nada preciosa\n");
  printf ("Adios =)");
  Sleep (4000);
  return 0;
}

// http://www.thecrazyprogrammer.com/2014/02/valentines-day-special-c-program-to-print-heart-shape-with-happy-valentines-day-message-inside-it.html
//int main()
//{
//    double x, y, size=10;
//    char ch=3;
//    string message(" Happy Valentine's Day ");
//    int print_line = 4;
//
//    if(message.length() % 2 != 0)
//        message += " ";
//
//    for(x=0;x<size;x++)
//    {
//        for(y=0;y<=4*size;y++)
//        {
//            double dist1 = sqrt( pow(x-size,2) + pow(y-size,2) );
//            double dist2 = sqrt( pow(x-size,2) + pow(y-3*size,2) );
//
//            if (dist1 < size + 0.5 || dist2 < size + 0.5 ) {
//                cout<< ch;
//            }
//            else
//                cout<< " ";
//        }
//
//        cout<<"\n";
//    }
//
//    for(x=1;x<2*size;x++)
//    {
//        for(y=0;y<x;y++)
//            cout << " ";
//
//        for (y=0;y<4*size + 1 - 2*x; y++)
//        {
//            if (x>= print_line - 1 && x <= print_line + 1) {
//                int idx = y - (4*size - 2*x - message.length()) / 2;
//                if(idx < message.length() && idx >= 0) {
//                    if (x == print_line)
//                        cout<<message[idx];
//                    else cout << " ";
//                }
//                else
//                    cout << ch;
//            }
//            else
//                cout<< ch;
//        }
//        cout<<endl;
//    }
//
//    return 0;
//}
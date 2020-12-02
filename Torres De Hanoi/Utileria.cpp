#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
//***********************
#include "Utileria.h"
#include "Arte.h"

using std::cout;
using std::endl;

//*************************************************************************************************************************
void gotoxy(short x, short y)
{
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos={x,y};
    SetConsoleCursorPosition(hcon,dwPos);
}
//*************************************************************************************************************************
void ImprimirMarco(int ancho, int alto, int x, int y)
{
    // Parte superior
    gotoxy(x,y);
    std::cout << (char)ESI;
    for(int i = 2 ; i < ancho ; ++i) std::cout << (char)BH;
    std::cout << (char)ESD;
    // Parte media
    for(int i = 2; i < alto; ++i){
        gotoxy(x, ++y);
        std::cout << (char)BV;
        for (int i=2; i< ancho; ++i) std::cout << " ";
        std::cout << (char)BV;
    }
    // Parte inferior
    gotoxy(x,++y);
    std::cout << (char)EII;
    for(int i = 2 ; i < ancho ; ++i) std::cout << (char)BH;
    std::cout << (char)EID;
}
//*************************************************************************************************************************
void CambiarCursor(EstadoCursor estado, ModoCursor modo /* = NORMAL*/)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info = {modo,estado};
	SetConsoleCursorInfo(consoleHandle, &info);
}
//*************************************************************************************************************************
void EstablecerTamVentana(short ancho, short alto)
{
	_COORD coord = {--ancho, --alto};
	_SMALL_RECT rect = {0,0,ancho,alto};
	HANDLE hConsola = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleScreenBufferSize(hConsola, coord);
	SetConsoleWindowInfo(hConsola, true, &rect);
}
//*************************************************************************************************************************
void FuncionBorrar(unsigned longitud)
{
    for(int i = 0; i < longitud; ++i){
        cout << " ";
    }
}
//*************************************************************************************************************************






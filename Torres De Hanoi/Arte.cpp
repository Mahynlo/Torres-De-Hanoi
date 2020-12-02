#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <cctype>
#include <conio.h>

using std::cout;
using std::endl;

#include "Arte.h"
#include "Utileria.h"
//*************************************************************************************************************************
void EstablecerColor(WORD colorEst)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorEst);
}
//*************************************************************************************************************************
void EstablecerColor(Color colorFondo, Color colorTexto)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorFondo*16 + colorTexto);
}
//*************************************************************************************************************************
WORD ObtenerColorOriginal()
{
    HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO *ConsoleInfo = new CONSOLE_SCREEN_BUFFER_INFO();
    GetConsoleScreenBufferInfo(hConsoleHandle, ConsoleInfo);
    WORD original = ConsoleInfo->wAttributes;
    delete ConsoleInfo;
    return original;
}
//*************************************************************************************************************************
void Titulo()
{
    //FUENTE MODULAR
    gotoxy(10,3);
    cout <<" _______  _______  ______    ______    _______  _______    ______   _______    __   __  _______  __    _  _______  ___" << endl;
    gotoxy(10,4);
    cout <<"|       ||       ||    _ |  |    _ |  |       ||       |  |      | |       |  |  | |  ||   _   ||  |  | ||       ||   |" << endl;
    gotoxy(10,5);
    cout <<"|_     _||   _   ||   | ||  |   | ||  |    ___||  _____|  |  _    ||    ___|  |  |_|  ||  |_|  ||   |_| ||   _   ||   |" << endl;
    gotoxy(10,6);
    cout <<"  |   |  |  | |  ||   |_||_ |   |_||_ |   |___ | |_____   | | |   ||   |___   |       ||       ||       ||  | |  ||   |" << endl;
    gotoxy(10,7);
    cout <<"  |   |  |  |_|  ||    __  ||    __  ||    ___||_____  |  | |_|   ||    ___|  |       ||       ||  _    ||  |_|  ||   |" << endl;
    gotoxy(10,8);
    cout <<"  |   |  |       ||   |  | ||   |  | ||   |___  _____| |  |       ||   |___   |   _   ||   _   || | |   ||       ||   |" << endl;
    gotoxy(10,9);
    cout <<"  |___|  |_______||___|  |_||___|  |_||_______||_______|  |______| |_______|  |__| |__||__| |__||_|  |__||_______||___|" << endl;
}

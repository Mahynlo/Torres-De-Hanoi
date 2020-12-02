#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <limits>
//********************
#include "Arte.h"
#include "Utileria.h"
#include "Motor.h"

using std::cout;
using std::endl;
using std::cin;
using std::numeric_limits;

//Imprime los botones del menu de inicio
void Botones()
{
    EstablecerColor(BLANCO,AZUL);
    ImprimirMarco(16,3,59,15);
    gotoxy(64,16);
    cout << "JUGAR";
    //***********************
    ImprimirMarco(16,3,59,20);
    gotoxy(61,21);
    cout << "INSTRUCCIONES";
    //************************
    ImprimirMarco(16,3,59,25);
    gotoxy(63,26);
    cout << "CREDITOS";
    //************************
    ImprimirMarco(16,3,59,30);
    gotoxy(64,31);
    cout << "SALIR";
    //************************
    gotoxy(59,36);
    cout << "'PRECIONE ENTER'";
}
void Instrucciones()
{
    EstablecerColor(AGUAMARINA, AZUL);
    ImprimirMarco(141,60,0,0);
    EstablecerColor(AGUAMARINA, BLANCO);
    gotoxy(1,1);
    cout << "INSTUCCIONES";
    Titulo();
    //*******************************************************************************************************
    gotoxy(5,50);
    cout << "PRESIONE [ ESC ] PARA REGRESAR A INICIO";
    gotoxy(10,14);
    cout << "Reglas:";
    gotoxy(10,15);
    cout << "1) El objetivo del juego es mover los discos de el extremo en el que se ubican al extremo opuesto.";
    gotoxy(10,16);
    cout << "2) Solo puedes mover un disco a la vez.";
    gotoxy(10,17);
    cout << "3) No puedes poner un disco sobre uno mas peque\244o. ";
    gotoxy(10,18);
    cout << "4) Intenta hacerlo en el menor numero de movimientos posible.";
    //*******************************************************************************************************
    gotoxy(10,20);
    cout <<"CONTROLES: ";
    gotoxy(10,21);
    cout <<" Movimiento a la derecha: [ -"<< char(16)<<" ] o [ D ]";
    gotoxy(10,23);
    cout <<" Movimiento a la izquierda: [ "<< char(17)<<"- ] o [ A ]";
    gotoxy(10,25);
    cout <<" Seleccionar disco: ["<< char(24)<<"] o [ W ]";
    gotoxy(10,27);
    cout <<" Soltar disco: ["<<char(25)<<"] o [ S ]";
}
//Es la selección de un boton del menu de inicio
void BotonesDeSeleccion(int eleccion)
{
    switch(eleccion){
        case 0:
            EstablecerColor(VERDE,AZUL);
            ImprimirMarco(16,3,59,15);
            gotoxy(64,16);
            cout << "JUGAR";
            break;
        case 1:
            EstablecerColor(VERDE,AZUL);
            ImprimirMarco(16,3,59,20);
            gotoxy(61,21);
            cout << "INSTRUCCIONES";
            break;
        case 2:
            EstablecerColor(VERDE,AZUL);
            ImprimirMarco(16,3,59,25);
            gotoxy(63,26);
            cout << "CREDITOS";
            break;
        case 3:
            EstablecerColor(VERDE,AZUL);
            ImprimirMarco(16,3,59,30);
            gotoxy(64,31);
            cout << "SALIR";
            break;
    }

}
//Se encarga de imprimir una sub ventana
void SubVentanas(int eleccion)
{
    //Para que no se vea de otro color en la transición
    EstablecerColor(AGUAMARINA, BLANCO);
    system("cls");
    switch(eleccion){
        case 0:
            //Función que determina la dificultad del juego
            FuncionDificultad();
            break;
        case 1:
            Instrucciones();
            break;
        case 2:
            EstablecerColor(AGUAMARINA, AZUL);
            ImprimirMarco(141,60,0,0);
            EstablecerColor(AGUAMARINA, BLANCO);
            Titulo();
            gotoxy(1,1);
            cout << "CREDITOS";
            gotoxy(10,13);
            cout << "Programa elaborado como proyecto final por el quipo \"Tucanes de Tijuana\", conformado por:";
            gotoxy(10,15);
            cout << "-Gaspar Armando D\240vila Reyes";
            gotoxy(10,17);
            cout << "-Malcom Hiram Navarro Lopez";
            gotoxy(10,19);
            cout << "Para la clase de programaci\242n de computadoras en la Universidad de Sonora.";
            //*********************************
            gotoxy(5,50);
            cout << "PRESIONE [ ESC ] PARA REGRESAR A INICIO";
            break;
        case 3:
            exit(1);
            break;
    }

}

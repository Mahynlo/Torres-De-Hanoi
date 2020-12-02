#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <conio.h>
//******************
#include "Utileria.h"
#include "Arte.h"
#include "Interfaz.h"

using namespace std;

#define FLECHA_ARRIBA 72
#define FLECHA_ABAJO 80
#define ENTER 13
#define ESCAPE 27

int main()
{
    char tecla;
    int cont = 0,cotsl=1;
    //**************************
    EstablecerTamVentana(141,60);
    WORD original = ObtenerColorOriginal();

    CambiarCursor(APAGADO);

    srand(time(NULL));
    //Imprime el inicio del programa
    EstablecerColor(AGUAMARINA, AZUL);
    ImprimirMarco(141,60,0,0);
    EstablecerColor(AGUAMARINA,ROJO);
    Titulo();
    EstablecerColor(AGUAMARINA, BLANCO);
    Botones();
    EstablecerColor(VERDE,AZUL);
    ImprimirMarco(16,3,59,15);
    gotoxy(64,16);
    cout << "JUGAR";

    while(true){
        if(kbhit()){
            tecla = getch();
            //Para regresar al menu de inicio
            if(cotsl == 2 && tecla == ESCAPE){
                EstablecerColor(AGUAMARINA,BLANCO);
                system("cls");
                cotsl= 1;
                EstablecerColor(AGUAMARINA, AZUL);
                ImprimirMarco(141,60,0,0);
                EstablecerColor(AGUAMARINA,ROJO);
                Titulo();
                EstablecerColor(AGUAMARINA,BLANCO);
                Botones();
                BotonesDeSeleccion(cont);

            }
            if(cotsl == 1 && (tecla == FLECHA_ARRIBA || tolower(tecla) == 'w'))
            {
                cont--;

                if(cont < 0){

                    cont = 3;
                }
                Botones();
                BotonesDeSeleccion(cont);
            }
            if(cotsl == 1 && (tecla == FLECHA_ABAJO  || tolower(tecla) == 's')){
                cont++;
                if(cont == 4){

                    cont = 0;
                }
                Botones();
                BotonesDeSeleccion(cont);
            }
            if(cotsl== 1 && tecla == ENTER){

                cotsl=2;
                SubVentanas(cont);
            }

        }
    }
    EstablecerColor(original);
    CambiarCursor(ENCENDIDO);

    gotoxy(1, 49);
    system("pause");
    return 0;
}

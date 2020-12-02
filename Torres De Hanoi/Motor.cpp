#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <math.h>
#include <conio.h>
#include <limits>
//*********************
#include "Arte.h"
#include "Utileria.h"
#include "Motor.h"

using std::cout;
using std::endl;
using std::cin;
using std::numeric_limits;

#define FLECHA_ARRIBA 72
#define FLECHA_IZQ 75
#define FLECHA_DER 77
#define FLECHA_ABAJO 80
#define ESCAPE 27

void FuncionDificultad()
{
    int numDiscos, diametro = 29;
    Color colorDisco[8]={ROJO, VERDE, PURPURA, AZUL, AMARILLO, VERDECLARO, AMARILLOCLARO, ROJOCLARO};
    Disco *Torre[8][3]={};
    EstablecerColor(AGUAMARINA, AZUL);
    ImprimirMarco(141,60,0,0);
    EstablecerColor(AGUAMARINA, ROJO);
    ImprimirMarco(91,10,25,20);
    EstablecerColor(AGUAMARINA, BLANCO);
    Titulo();
    gotoxy(26,22);
    cout << "Introduce la cantidad de discos con los que desa jugar entre mas discos mayor dificultad";
    gotoxy(26,23);
    cout << "Introdsca un numero entre 3 y 8";
    gotoxy(26,24);
    cout <<"\xA8""Con cuantos discos desea jugar?";
    CambiarCursor(ENCENDIDO);

    while(true)
    {
        gotoxy(26,25);
        FuncionBorrar(10);
        gotoxy(26,25);
        cin >> numDiscos;
        if(cin.good())
        {

            if(numDiscos < 3 || numDiscos > 8);
            else break;
        }
        if(cin.bad())
        {

            throw "Error irrecuperable en el flujo de entrada, el programa debe terminar...";

        }
        if(cin.fail())
        {
            gotoxy(26,27);
            cout << "Error: no es un numero. Introduzca un numero valido.";
            cin.clear();
            cin.ignore(numeric_limits<int>::max(),'\n');
            Sleep(1500);
            gotoxy(26,27);
            FuncionBorrar(52);
        }

    }
    CambiarCursor(APAGADO);
    system("cls");
    EstablecerColor(AGUAMARINA, AZUL);
    ImprimirMarco(141,60,0,0);
    EstablecerColor(AGUAMARINA, BLANCO);
    Titulo();
    gotoxy(5,50);
    cout << "PRESIONE [ ESC ] DOS VECES PARA REGRESAR AL INICIO";

    for (int i = 1 ; i <= numDiscos ; ++i){
        Torre[8-i][0]= new Disco(diametro, colorDisco[8-i]);
        Torre[8-i][1]= NULL;
        Torre[8-i][2]= NULL;

        diametro = diametro - 2;
    }
    //Mandamos llamar a la funcion para jugar
    FuncionMovimientos(Torre,numDiscos,diametro);
}
//****************************************************************************************************
void FuncionMovimientos(Disco *Torre[8][3],int numDiscos,int diametro){

    char tecladisco;
    Disco *DiscoSelec = NULL;
    int posMano = 0;
    imprimirTablero(Torre);
    int movimientos = 0;

    EstablecerColor(BLANCO,BLANCO);
    ImprimirMarco(2, 1, 35 + (32 * posMano),16);
    while(true){
        if(kbhit()){
            tecladisco = getch();
            //**************************************************************************************
            if((tecladisco == FLECHA_ARRIBA || tolower(tecladisco) == 'w') && DiscoSelec == NULL){
                for (int i = 0 ; i < 8 ; ++i){

                    if(Torre[i][posMano] != NULL){

                        EstablecerColor(Torre[i][posMano]->colorDisco,Torre[i][posMano]->colorDisco);
                        ImprimirMarco(Torre[i][posMano]->diametro,2,
                                    (21 + (14 - (Torre[i][posMano]->diametro/2) + (33*posMano))),16);
                        DiscoSelec = Torre[i][posMano];
                        Torre[i][posMano] = NULL;

                        ImprimirEstaca(posMano);
                        ImprimirBaston(Torre, posMano);
                        break;
                    }

                }
            }
            //************************************************************************************
            if(tecladisco == FLECHA_DER || tolower(tecladisco) == 'd'){
                if(DiscoSelec != NULL){
                    EstablecerColor(AGUAMARINA,AGUAMARINA);
                    ImprimirMarco(DiscoSelec->diametro,2,
                                (21 + (14 - (DiscoSelec->diametro/2) + (33*posMano))),16);
                }else{
                    EstablecerColor(AGUAMARINA,AGUAMARINA);
                    ImprimirMarco(2, 1, 35 + (32 * posMano),16);
                }


                posMano = posMano + 1;
                if(posMano > 2){
                    posMano = 0;
                }
                if(DiscoSelec != NULL){
                    EstablecerColor(DiscoSelec->colorDisco,DiscoSelec->colorDisco);
                    ImprimirMarco(DiscoSelec->diametro,2,
                                          (21 + (14 - (DiscoSelec->diametro/2) + (33*posMano))),16);
                }else{
                    EstablecerColor(BLANCO,BLANCO);
                    ImprimirMarco(2, 1, 35 + (32 * posMano),16);
                }
            }
            //*************************************************************************************
            if(tecladisco == FLECHA_IZQ || tolower(tecladisco) == 'a'){
                if(DiscoSelec != NULL){
                    EstablecerColor(AGUAMARINA,AGUAMARINA);
                    ImprimirMarco(DiscoSelec->diametro,2,
                                          (21 + (14 - (DiscoSelec->diametro/2) + (33*posMano))),16);
                }else{
                    EstablecerColor(AGUAMARINA,AGUAMARINA);
                    ImprimirMarco(2, 1, 35 + (32 * posMano),16);
                }
                posMano = posMano - 1;
                if(posMano < 0){
                    posMano = 2;
                }
                if(DiscoSelec != NULL){
                    EstablecerColor(DiscoSelec->colorDisco,DiscoSelec->colorDisco);
                    ImprimirMarco(DiscoSelec->diametro,2,
                                          (21 + (14 - (DiscoSelec->diametro/2) + (33*posMano))),16);
                }else{
                    EstablecerColor(BLANCO,BLANCO);
                    ImprimirMarco(2, 1, 35 + (32 * posMano),16);
                }
            }
            //*************************************************************************************
            if((tecladisco == FLECHA_ABAJO || tolower(tecladisco) == 's') && DiscoSelec != NULL){
                if(Torre[7][posMano] != NULL){
                    for (int i = 0 ; i < 8 ; ++i){

                        if(Torre[i][posMano] != NULL){
                            if (Torre [i][posMano] -> diametro > DiscoSelec -> diametro){
                                EstablecerColor(AGUAMARINA,AGUAMARINA);
                                ImprimirMarco(DiscoSelec->diametro,2,
                                        (21 + (14 - (DiscoSelec->diametro/2) + (33*posMano))),16);

                                ImprimirEstaca(posMano);
                                Torre [i-1][posMano] = DiscoSelec;
                                DiscoSelec = NULL;
                                ImprimirBaston(Torre, posMano);
                                EstablecerColor(BLANCO,BLANCO);
                                ImprimirMarco(2, 1, 35 + (32 * posMano),16);
                                movimientos = movimientos + 1;
                                MensajeGanaste(Torre, numDiscos, movimientos);

                            }else{
                                EstablecerColor(AGUAMARINA,BLANCO);
                                gotoxy((25 + (14 - (DiscoSelec->diametro/2) + (33*posMano))),15);
                                cout <<"Movimiento invalido";
                                Sleep(1000);
                                gotoxy((25 + (14 - (DiscoSelec->diametro/2) + (33*posMano))),15);
                                FuncionBorrar(20);
                            }
                            break;
                        }
                    }
                }else{
                    EstablecerColor(AGUAMARINA,AGUAMARINA);
                    ImprimirMarco(DiscoSelec->diametro,2,
                                          (21 + (14 - (DiscoSelec->diametro/2) + (33*posMano))),16);

                    ImprimirEstaca(posMano);

                    Torre [7][posMano] = DiscoSelec;
                    DiscoSelec = NULL;
                    ImprimirBaston(Torre, posMano);

                    EstablecerColor(BLANCO,BLANCO);
                    ImprimirMarco(2, 1, 35 + (32 * posMano),16);

                    movimientos = movimientos + 1;
                    MensajeGanaste(Torre, numDiscos, movimientos);
                }
            }
            //**********************************************************************************
             if(tecladisco == ESCAPE){
                return;
            }
        }
    }

}
//********************************************************************
void imprimirTablero(Disco*Torre[8][3]){

    EstablecerColor(NEGRO,NEGRO);
    //Estaca 1****************
    ImprimirMarco(1,25,35,19);
    //Estaca 2****************
    ImprimirMarco(1,25,67,19);
    //Estaca 3*****************
    ImprimirMarco(1,25,99,19);
    //Base
    ImprimirMarco(99,4,20,43);

    for (int j = 0 ; j < 3 ; ++j){
        ImprimirBaston(Torre, j);
    }
    EstablecerColor(AGUAMARINA,AGUAMARINA);
}
//******************************************************************************
void ImprimirBaston (Disco*Torre[8][3], int j){

    int posY = 27;

    for (int i = 0 ; i < 8 ; ++i){
        if (Torre[i][j] != NULL){
            EstablecerColor(Torre[i][j]->colorDisco,Torre[i][j]->colorDisco);
            ImprimirMarco(Torre[i][j]->diametro,2,
                          (21 + (14 - (Torre[i][j]->diametro/2) + (33*j))),posY);
        }

            posY = posY + 2;
    }
}
//**********************************************************************************
void ImprimirEstaca (int numEstaca){

    switch(numEstaca){
        case 0:
        EstablecerColor(AGUAMARINA,AGUAMARINA);
        ImprimirMarco(29, 24, 21, 19);
        EstablecerColor(NEGRO,NEGRO);
        //Estaca 1****************
        ImprimirMarco(1,25,35,19);

        break;

        case 1:
        EstablecerColor(AGUAMARINA,AGUAMARINA);
        ImprimirMarco(29, 24, 54, 19);
        EstablecerColor(NEGRO,NEGRO);
        //Estaca 2****************
        ImprimirMarco(1,25,67,19);

        break;

        case 2:
        EstablecerColor(AGUAMARINA,AGUAMARINA);
        ImprimirMarco(29, 24, 87, 19);
        EstablecerColor(NEGRO,NEGRO);
        //Estaca 3*****************
        ImprimirMarco(1,25,99,19);

        break;

    }
    EstablecerColor(AGUAMARINA,AGUAMARINA);
}
//*********************************************************************************************************************
bool Ganaste (Disco *Torre[8][3], int numDiscos){
    for(int i = 0 ; i < numDiscos ; ++i){
        if (Torre[7-i][2] == NULL){
            return false;
        }
    }
    return true;
}
//*********************************************************************************************************************
void MensajeGanaste (Disco *Torre[8][3], int numDiscos, int movimientos){
    int numMin=pow(2, numDiscos)-1;
    if (Ganaste(Torre, numDiscos) == true){
        EstablecerColor(AGUAMARINA, BLANCO);
        if (movimientos == numMin){
            gotoxy(39,13);
            cout << "Felicidades, lo hiciste en el numero minimo de movimientos :)";
            gotoxy(56,14);
            cout << "Numero de movimientos: "<< movimientos;

        }else{
            gotoxy(54,13);
            cout << "Lo lograste, pero puedes mejorar :/";
            gotoxy(59,14);
            cout << "Numero de movimientos: "<< movimientos;
            gotoxy(56,15);
            cout <<"Numero minimo de movimientos: "<< numMin;
        }
    }
}

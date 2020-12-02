#ifndef MOTOR_H_INCLUDED
#define MOTOR_H_INCLUDED

struct Disco{

    int diametro;
    Color colorDisco;
    Disco(int d,Color c){
        diametro = d;
        colorDisco = c;
    }
};

//********************************************************************************************
/** \brief Determina la dificultad del juego en base al número de discos seleccionado.
 *
 * \return void
 *
 */
void FuncionDificultad();
//********************************************************************************************

/** \brief Imprime el tablero inicial del juego.
 *
 * \param Torre[8][3] Disco* Arreglo bidimensional de los discos y estacas.
 * \return void
 *
 */
void imprimirTablero(Disco *Torre[8][3]);
//*******************************************************************************************
/** \brief Imprime los discos.
 *
 * \param Torre[8][3] Disco* Arreglo bidimensional de los discos y estacas.
 * \param j int Posición de la mano en las estacas.
 * \return void
 *
 */
void ImprimirBaston (Disco*Torre[8][3], int j);
//*******************************************************************************************
/** \brief Imprime la estaca y el fondo.
 *
 * \param numEstaca int  Número de la estaca en la que se encuentra.
 * \return void
 *
 */
void ImprimirEstaca (int numEstaca);
//*******************************************************************************************
/** \brief Determina si el juego terminó.
 *
 * \param Torre[8][3] Disco* Arreglo bidimensional de los discos y estacas.
 * \param numDiscos Número de discos.
 * \return bool
 *
 */
bool Ganaste (Disco *Torre[8][3], int numDiscos);
//*******************************************************************************************
/** \brief Imprime el mensaje cuando se termina el juego.
 *
 * \param Torre[8][3] Disco* Arreglo bidimensional de los discos y estacas.
 * \param numDiscos Número de discos.
 * \param movimientos int Número de movimientos del usuario.
 * \return void
 *
 */
void MensajeGanaste (Disco *Torre[8][3], int numDiscos, int movimientos);
//***********************************************************************************
/** \brief Determina las acciones que le corresponden a los controles.
 *
 * \param Torre[8][3] Disco* Arreglo bidimensional de los discos y estacas.
 * \param numDiscos Número de discos.
 * \param diametro int Ancho del disco.
 * \return void
 *
 */
void FuncionMovimientos(Disco *Torre[8][3],int numDiscos,int diametro);

#endif // MOTOR_H_INCLUDED

#ifndef INTERFAZ_H_INCLUDED
#define INTERFAZ_H_INCLUDED


//***************************Prototipo de funcion para Interfaz*******************************
/** \brief Imprime los botones en blanco.
 *
 * \return void
 *
 */
void Botones();
//******************************||************************************************************
/** \brief Imprime en verde el bot�n seleccionado.
 *
 * \param eleccion int N�mero que le corresponde a cada bot�n de 0 a 3.
 * \return void
 *
 */
void BotonesDeSeleccion(int eleccion);
//********************************************************************************************
/** \brief Imprime las instrucciones del juego
 *
 * \return void
 *
 */
void Instrucciones();
//********************************************************************************************
/** \brief Imprime las ventanas correspondientes a cada bot�n.
 *
 * \param eleccion int N�mero correspondiente a cada ventana.
 * \return void
 *
 */
void SubVentanas(int eleccion);


#endif // INTERFAZ_H_INCLUDED

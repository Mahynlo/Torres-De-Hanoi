#ifndef UTILERIA_H_INCLUDED
#define UTILERIA_H_INCLUDED

/** Posibles estados del cursor */
enum EstadoCursor{
	APAGADO, /**< Cursor no visible */
	ENCENDIDO  /**< Cursor visible */
};
//*******************************************************************************************************************************
/** Modos o tama&ntilde;os del cursor */
enum ModoCursor{
	MINI = 5, /**< Tama&ntilde;o de cursor peque&ntilde;o */
	NORMAL = 20, /**< Tama&ntilde;o de cursor mediano  */
	SOLIDO = 80 /**< Tama&ntilde;o de cursor grande */
};

//**************************************Prototipo de Funcion Utileria*************************************************************
//********************************************************************************************************************************

/** \brief Imprime un marco o rect&aacute;ngulo en pantalla con la dimensi&oacute;n dada y en la posici&oacute;n indicada
 *
 * \param ancho Ancho o base del rect&aacute;ngulo
 * \param alto Alto del rect&aacute;ngulo
 * \param x Posici&oacute;n en x donde se imprimir&aacute; el rect&aacute;ngulo
 * \param y Posici&oacute;n en y donde se imprimir&aacute; el rect&aacute;ngulo
 *
 * \pre El ancho y el alto deben ser por lo menos 2. Los valores para la posici&oacute;n (x,y) deben ser no negativos y corresponden
 *      a la posici&oacute;n de la esquina superior izquierda del rect&aacute;ngulo
*/
void ImprimirMarco(int ancho, int alto, int x, int y);

/** \brief Mueve el cursor a la posici&oacute;n indicada
 *
 * \param x Posici&oacute;n en x a la que se mueve el cursor
 * \param y Posici&oacute;n en y a la que se mueve el cursor
 *
 * \pre Las posiciones (x,y) deben ser no negativas. La posici&oacute;n m&iacute;nima es cero.
 */
void gotoxy(short x, short y);
//*******************************************************************************************************************************
/**
 * \brief Establece el tama&ntilde;o de la ventana de ejecuci&oacute;n.
 *
 * \param ancho Valor entero para el ancho de la ventana.
 * \param alto Valor entero para el alto de la ventana.
 **/
void EstablecerTamVentana(short ancho, short alto);
//*******************************************************************************************************************************
/**
 * \brief Modifica el estado del cursor.
 *
 * \param estado Estado del cursor a establecer. Puede ser un valor de la enumeraci&oacute;n EstadoCursor
 * \param modo Tama&ntilde;o del indicador del cursor. Puede ser un valor de la enumeraci&oacute;n ModoCursor.
 *           Si se omite, tomar&aacute; el valor NORMAL.
 **/
void CambiarCursor(EstadoCursor estado, ModoCursor modo = NORMAL);
//*******************************************************************************************************************************
/** \brief Borra caracteres.
 *
 * \param longitud unsigned Cantidad de caracteres que serán borrados.
 * \return void
 *
 */
void FuncionBorrar(unsigned longitud);

#endif // UTILERIA_H_INCLUDED

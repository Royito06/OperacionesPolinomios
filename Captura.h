#ifndef CAPTURA_H
#define CAPTURA_H
#include "Operaciones.h"


/**
 * @brief La funci�n CapturaArregloD captura entrada del usuario para crear un arreglo de coeficientes
 * y exponentes polinomiales, asegurando que la entrada est� dentro de los l�mites especificados.
 *
 * @param arreglo La funci�n CapturaArregloD se encarga de capturar datos para crear un arreglo
 * de polinomios. Solicita al usuario ingresar el grado del polinomio y luego procede a capturar
 * los coeficientes para cada t�rmino del polinomio.
 *
 * @return La funci�n CapturaArregloD retorna un valor entero n, que representa el grado
 * del polinomio ingresado por el usuario.
 */
int CapturaArregloD (Polinomio* &Arreglo);

/**
 * @brief La funci�n ImprimirArregloD imprime un arreglo polinomial de manera formateada, omitiendo t�rminos con
 * coeficiente 0 y manejando diferentes casos para coeficientes y exponentes.
 *
 * @param Arreglo La funci�n ImprimirArregloD est� dise�ada para imprimir un arreglo de t�rminos polinomiales.
 * Cada t�rmino en el arreglo est� representado por una estructura Polinomio que contiene un coeficiente y un
 * exponente.
 * @param n El par�metro n en la funci�n ImprimirArregloD representa el n�mero de elementos en
 * el arreglo de tipo Polinomio que se pasa a la funci�n. Se utiliza para determinar el tama�o del
 * arreglo y controlar el ciclo que itera sobre los elementos del mismo.
 */
void ImprimirArregloD (Polinomio* Arreglo, int n);

#endif

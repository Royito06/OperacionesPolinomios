#ifndef CAPTURA_H
#define CAPTURA_H
#include "Operaciones.h"


/**
 * @brief La función CapturaArregloD captura entrada del usuario para crear un arreglo de coeficientes
 * y exponentes polinomiales, asegurando que la entrada esté dentro de los límites especificados.
 *
 * @param arreglo La función CapturaArregloD se encarga de capturar datos para crear un arreglo
 * de polinomios. Solicita al usuario ingresar el grado del polinomio y luego procede a capturar
 * los coeficientes para cada término del polinomio.
 *
 * @return La función CapturaArregloD retorna un valor entero n, que representa el grado
 * del polinomio ingresado por el usuario.
 */
int CapturaArregloD (Polinomio* &Arreglo);

/**
 * @brief La función ImprimirArregloD imprime un arreglo polinomial de manera formateada, omitiendo términos con
 * coeficiente 0 y manejando diferentes casos para coeficientes y exponentes.
 *
 * @param Arreglo La función ImprimirArregloD está diseñada para imprimir un arreglo de términos polinomiales.
 * Cada término en el arreglo está representado por una estructura Polinomio que contiene un coeficiente y un
 * exponente.
 * @param n El parámetro n en la función ImprimirArregloD representa el número de elementos en
 * el arreglo de tipo Polinomio que se pasa a la función. Se utiliza para determinar el tamaño del
 * arreglo y controlar el ciclo que itera sobre los elementos del mismo.
 */
void ImprimirArregloD (Polinomio* Arreglo, int n);

#endif

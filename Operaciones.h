#ifndef OPERACIONES_H_INCLUDED
#define OPERACIONES_H_INCLUDED

#include <iostream>

using namespace std;

struct Polinomio
{
    int exponente;
    double coeficiente;

};

/**
 * @brief Realiza la suma de dos polinomios representados como arreglos de estructuras Polinomio.
 *
 * La función suma los coeficientes de los polinomios A y B término a término, almacena el resultado
 * en un nuevo arreglo y muestra la operación completa con formato.
 *
 * @param A Primer polinomio a sumar (arreglo de estructuras Polinomio)
 * @param B Segundo polinomio a sumar (arreglo de estructuras Polinomio)
 * @param nA Número de términos del polinomio A
 * @param nB Número de términos del polinomio B
 *
 */
void SumarPolinomio(Polinomio* &A, Polinomio* &B,int nA,int nB);

/**
 * @brief función RestarPolinomio resta dos polinomios e imprime el resultado.
 *
 * @param A La función RestarPolinomio recibe como entrada dos arreglos polinomiales A y B junto con
 * sus respectivos tamaños nA y nB. Calcula la resta del polinomio B al polinomio A y almacena
 * el resultado en un nuevo arreglo polinomial.
 * @param B La función RestarPolinomio recibe como entrada dos arreglos polinomiales A y B junto con
 * sus respectivos tamaños nA y nB. Calcula la resta del polinomio B al polinomio A y almacena
 * el resultado en un nuevo arreglo polinomial.
 * @param nA El parámetro nA en la función RestarPolinomio representa el número de elementos del
 * arreglo A de tipo Polinomio. Se utiliza para determinar el tamaño del arreglo y para iterar
 * sobre sus elementos durante la operación de resta con el arreglo B.
 * @param nB El parámetro nB en la función RestarPolinomio representa el número de elementos del
 * arreglo B que contiene un polinomio. Se utiliza para determinar el tamaño del arreglo y para
 * iterar sobre los elementos del polinomio B durante la operación de resta con el polinomio A.
 */
void RestarPolinomio(Polinomio* &A, Polinomio* &B,int nA,int nB);

/**
 * @brief Realiza la multiplicación de dos polinomios representados como arreglos de estructuras Polinomio.
 *
 * La función multiplica los polinomios A y B mediante un proceso de:
 * 1. Multiplicación término a término
 * 2. Reducción de términos semejantes
 * 3. Visualización del resultado final
 *
 * @param A Primer polinomio factor (arreglo de estructuras Polinomio)
 * @param B Segundo polinomio factor (arreglo de estructuras Polinomio)
 * @param nA Número de términos del polinomio A
 * @param nB Número de términos del polinomio B
 *
 */
void MultiplicacionPolinomio(Polinomio* &A,Polinomio* &B, int nA,int nB);

/**
 * @brief Realiza la división de dos polinomios representados como arreglos de estructuras Polinomio.
 *
 * Esta función implementa el algoritmo de división de polinomios, calculando el cociente y el residuo
 * de dividir el polinomio A (dividendo) entre el polinomio B (divisor).
 *
 * @param A Polinomio dividendo (arreglo de estructuras Polinomio)
 * @param B Polinomio divisor (arreglo de estructuras Polinomio)
 * @param nA Número de términos del polinomio A (dividendo)
 * @param nB Número de términos del polinomio B (divisor)
 *
 */
void DividirPolinomio(Polinomio* P, int nP, Polinomio* Q, int nQ);

/**
 * @brief función DerivarPolinomio calcula la derivada de un arreglo polinomial e imprime el resultado.
 *
 * @param Arreglo El fragmento de código proporcionado corresponde a una función llamada DerivarPolinomio
 * que calcula la derivada de un polinomio almacenado en un arreglo de tipo Polinomio. La función
 * crea un nuevo arreglo llamado Derivada para almacenar la derivada del polinomio.
 * @param n El parámetro n en la función DerivarPolinomio representa el número de elementos en
 * el arreglo Arreglo de tipo Polinomio. Se utiliza para determinar el tamaño del arreglo
 * dinámicamente asignado Derivada que almacenará la derivada del polinomio.
 */
void DerivarPolinomio(Polinomio* &Arreglo, int n);

/**
 * @brief función EvaluarPolinomio evalúa una expresión polinomial en un valor dado utilizando un arreglo
 * de coeficientes polinomiales.
 *
 * @param Arreglo El parámetro Arreglo es una referencia a un arreglo de tipo Polinomio. La función
 * EvaluarPolinomio toma este arreglo como entrada y evalúa una expresión polinomial utilizando los
 * coeficientes almacenados en los objetos Polinomio dentro del arreglo.
 * @param n El parámetro n en la función EvaluarPolinomio representa el número de términos del
 * polinomio que se desea evaluar. Se utiliza para determinar el número de iteraciones en el ciclo
 * que calcula el valor del polinomio para un valor de entrada valor dado.
 * @param valor El parámetro valor en la función EvaluarPolinomio representa el valor en el cual
 * se necesita evaluar el polinomio. Este valor será sustituido en la expresión polinomial para
 * calcular el resultado.
 */
void EvaluarPolinomio(Polinomio* &Arreglo,int n,float valor);
#endif // OPERACIONES_H_INCLUDED

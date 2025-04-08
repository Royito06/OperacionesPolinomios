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
 * La funci�n suma los coeficientes de los polinomios A y B t�rmino a t�rmino, almacena el resultado
 * en un nuevo arreglo y muestra la operaci�n completa con formato.
 *
 * @param A Primer polinomio a sumar (arreglo de estructuras Polinomio)
 * @param B Segundo polinomio a sumar (arreglo de estructuras Polinomio)
 * @param nA N�mero de t�rminos del polinomio A
 * @param nB N�mero de t�rminos del polinomio B
 *
 */
void SumarPolinomio(Polinomio* &A, Polinomio* &B,int nA,int nB);

/**
 * @brief funci�n RestarPolinomio resta dos polinomios e imprime el resultado.
 *
 * @param A La funci�n RestarPolinomio recibe como entrada dos arreglos polinomiales A y B junto con
 * sus respectivos tama�os nA y nB. Calcula la resta del polinomio B al polinomio A y almacena
 * el resultado en un nuevo arreglo polinomial.
 * @param B La funci�n RestarPolinomio recibe como entrada dos arreglos polinomiales A y B junto con
 * sus respectivos tama�os nA y nB. Calcula la resta del polinomio B al polinomio A y almacena
 * el resultado en un nuevo arreglo polinomial.
 * @param nA El par�metro nA en la funci�n RestarPolinomio representa el n�mero de elementos del
 * arreglo A de tipo Polinomio. Se utiliza para determinar el tama�o del arreglo y para iterar
 * sobre sus elementos durante la operaci�n de resta con el arreglo B.
 * @param nB El par�metro nB en la funci�n RestarPolinomio representa el n�mero de elementos del
 * arreglo B que contiene un polinomio. Se utiliza para determinar el tama�o del arreglo y para
 * iterar sobre los elementos del polinomio B durante la operaci�n de resta con el polinomio A.
 */
void RestarPolinomio(Polinomio* &A, Polinomio* &B,int nA,int nB);

/**
 * @brief Realiza la multiplicaci�n de dos polinomios representados como arreglos de estructuras Polinomio.
 *
 * La funci�n multiplica los polinomios A y B mediante un proceso de:
 * 1. Multiplicaci�n t�rmino a t�rmino
 * 2. Reducci�n de t�rminos semejantes
 * 3. Visualizaci�n del resultado final
 *
 * @param A Primer polinomio factor (arreglo de estructuras Polinomio)
 * @param B Segundo polinomio factor (arreglo de estructuras Polinomio)
 * @param nA N�mero de t�rminos del polinomio A
 * @param nB N�mero de t�rminos del polinomio B
 *
 */
void MultiplicacionPolinomio(Polinomio* &A,Polinomio* &B, int nA,int nB);

/**
 * @brief Realiza la divisi�n de dos polinomios representados como arreglos de estructuras Polinomio.
 *
 * Esta funci�n implementa el algoritmo de divisi�n de polinomios, calculando el cociente y el residuo
 * de dividir el polinomio A (dividendo) entre el polinomio B (divisor).
 *
 * @param A Polinomio dividendo (arreglo de estructuras Polinomio)
 * @param B Polinomio divisor (arreglo de estructuras Polinomio)
 * @param nA N�mero de t�rminos del polinomio A (dividendo)
 * @param nB N�mero de t�rminos del polinomio B (divisor)
 *
 */
void DividirPolinomio(Polinomio* P, int nP, Polinomio* Q, int nQ);

/**
 * @brief funci�n DerivarPolinomio calcula la derivada de un arreglo polinomial e imprime el resultado.
 *
 * @param Arreglo El fragmento de c�digo proporcionado corresponde a una funci�n llamada DerivarPolinomio
 * que calcula la derivada de un polinomio almacenado en un arreglo de tipo Polinomio. La funci�n
 * crea un nuevo arreglo llamado Derivada para almacenar la derivada del polinomio.
 * @param n El par�metro n en la funci�n DerivarPolinomio representa el n�mero de elementos en
 * el arreglo Arreglo de tipo Polinomio. Se utiliza para determinar el tama�o del arreglo
 * din�micamente asignado Derivada que almacenar� la derivada del polinomio.
 */
void DerivarPolinomio(Polinomio* &Arreglo, int n);

/**
 * @brief funci�n EvaluarPolinomio eval�a una expresi�n polinomial en un valor dado utilizando un arreglo
 * de coeficientes polinomiales.
 *
 * @param Arreglo El par�metro Arreglo es una referencia a un arreglo de tipo Polinomio. La funci�n
 * EvaluarPolinomio toma este arreglo como entrada y eval�a una expresi�n polinomial utilizando los
 * coeficientes almacenados en los objetos Polinomio dentro del arreglo.
 * @param n El par�metro n en la funci�n EvaluarPolinomio representa el n�mero de t�rminos del
 * polinomio que se desea evaluar. Se utiliza para determinar el n�mero de iteraciones en el ciclo
 * que calcula el valor del polinomio para un valor de entrada valor dado.
 * @param valor El par�metro valor en la funci�n EvaluarPolinomio representa el valor en el cual
 * se necesita evaluar el polinomio. Este valor ser� sustituido en la expresi�n polinomial para
 * calcular el resultado.
 */
void EvaluarPolinomio(Polinomio* &Arreglo,int n,float valor);
#endif // OPERACIONES_H_INCLUDED

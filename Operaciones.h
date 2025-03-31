#ifndef OPERACIONES_H_INCLUDED
#define OPERACIONES_H_INCLUDED

#include <iostream>

using namespace std;

void SumarPolinomio(int* &A, int* &B,int nA,int nB);
void RestarPolinomio(int* &A, int* &B,int nA,int nB);
void MultiplicacionPolinomio(int* &A,int* &B, int nA,int nB);

struct Polinomio
{
    int exponente;
    float coeficiente;

};
void DerivarPolinomio(Polinomio* &Arreglo, int n);
void EvaluarPolinomio(int* &Arreglo,int n,float valor);
#endif // OPERACIONES_H_INCLUDED

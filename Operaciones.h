#ifndef OPERACIONES_H_INCLUDED
#define OPERACIONES_H_INCLUDED

#include <iostream>

using namespace std;

struct Polinomio
{
    int exponente;
    float coeficiente;

};

void SumarPolinomio(Polinomio* &A, Polinomio* &B,int nA,int nB);
void RestarPolinomio(Polinomio* &A, Polinomio* &B,int nA,int nB);
void MultiplicacionPolinomio(Polinomio* &A,Polinomio* &B, int nA,int nB);

void DividirPolinomio(Polinomio* &A,Polinomio* &B, int nA,int nB);
void DerivarPolinomio(Polinomio* &Arreglo, int n);
void EvaluarPolinomio(Polinomio* &Arreglo,int n,float valor);
#endif // OPERACIONES_H_INCLUDED

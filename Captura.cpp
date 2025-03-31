#include <iostream>
#include <cstdlib>
#include <string>
#include "Captura.h"
#include "CapturaSegura.tpp"
#include "Operaciones.h"

#define MINIMO 0
#define MAXIMO 15

using std::cout;
using std::cin;
using std::endl;

int CapturaArreglo (int* &Arreglo)
{
    int n;

    do{
    cout<<"Introduzca el grado del polinomio A["<<MINIMO<<"-"<<MAXIMO<<"]: ";
    cin>>n;
    }while(!CapturaSegura(n)||n<MINIMO||n>MAXIMO);
    n=n+1;//aqui se le suma 1 a n para que el tamaño del arreglo sea el correcto
    delete [] Arreglo;

    Arreglo= new int [n];
    for (int i=0; i<n;i++)
    {
        cout<<"Introduzca x^"<<i<<": ";
        cin>>Arreglo[i];
    }
    ImprimirArreglo(Arreglo,n);
    cout<<endl;
    return n;
}
int CapturaArregloD (Polinomio* &Arreglo)
{
    int n;

    do{
    cout<<"Introduzca el grado del polinomio A["<<MINIMO<<"-"<<MAXIMO<<"]: ";
    cin>>n;
    }while(!CapturaSegura(n)||n<MINIMO||n>MAXIMO);
    n=n+1;//aqui se le suma 1 a n para que el tamaño del arreglo sea el correcto
    delete [] Arreglo;

    Arreglo= new Polinomio [n];

    for (int i=0; i<n;i++)
    {
        cout<<"Introduzca x^"<<i<<": ";
        cin>>Arreglo[i].coeficiente;
        Arreglo[i].exponente=i;
    }
    ImprimirArregloD(Arreglo,n);
    cout<<endl;
    return n;
}

void ImprimirArregloD (Polinomio* Arreglo, int n)
{

    for (int i=n-1; i>-1;i-- )
    {


        if(Arreglo[i].coeficiente!=0)
        {
            if(i==n-1)
            {
                cout<<Arreglo[i].coeficiente<<"x^"<<i;
            }else
            {
            cout<<(Arreglo[i].coeficiente>0? "+":"")<<Arreglo[i].coeficiente<<(Arreglo[i].exponente>0?"x":"")<<
            (Arreglo[i].exponente>1 ? "^"+ std::to_string(Arreglo[i].exponente):"");
            }
        }

    }

}

void ImprimirArreglo (int* Arreglo, int n)
{

    for (int i=n-1; i>-1;i-- )
    {


        if(Arreglo[i]!=0)
        {
            if(i==n-1)
            {
                cout<<Arreglo[i]<<"x^"<<i;
            }else
            {
            cout<<(Arreglo[i]>0? "+":"")<<Arreglo[i]<<(i>0?"x":"")<<(i>1 ? "^"+ std::to_string(i):"");
            }
        }

    }

}

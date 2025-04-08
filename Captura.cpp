#include <iostream>
#include <cstdlib>
#include <string>
#include <windows.h>
#include "Captura.h"
#include "CapturaSegura.tpp"
#include "Operaciones.h"

#define MINIMO 0
#define MAXIMO 15

using std::cout;
using std::cin;
using std::endl;


int CapturaArregloD(Polinomio* &Arreglo)
{
    int n;

    do{
    cout<<"Introduzca el grado del polinomio ["<<MINIMO<<"-"<<MAXIMO<<"]: ";
    cin>>n;
    }while(!CapturaSegura(n)||n<MINIMO||n>MAXIMO);

    n=n+1;//aqui se le suma 1 a n para que el tamaño del arreglo sea el correcto

    //Por si acaso
    delete [] Arreglo;
    Arreglo= new Polinomio [n];


    cout<<endl;
    cout<<"CADA x QUE INTRODUZCA DEBE SER DISTINTA DE 0";
    cout<<endl;
    for (int i=0; i<n;i++)
    {
        do{
            if(i!=n-1)
            {
            cout<<"Introduzca x^"<<n-1-i<<": ";
            cin>>Arreglo[i].coeficiente;
            }else
            {
                cout<<"Introduzca la constante: ";
                cin>>Arreglo[i].coeficiente;
            }
        }while(!CapturaSegura(Arreglo[i].coeficiente)||Arreglo[i].coeficiente==0);
        Arreglo[i].exponente=n-1-i;
    }

    ImprimirArregloD(Arreglo,n);
    cout<<endl;
    return n;
}

void ImprimirArregloD (Polinomio* Arreglo, int n)
{

 if(n==1&&Arreglo[0].coeficiente==0)
    {
        cout<<0;
    }else{

        if(Arreglo[0].coeficiente==1)
        {
            cout<<(Arreglo[0].coeficiente!=0?"x":"")<<
            (Arreglo[0].exponente>1 ? "^"+ to_string(Arreglo[0].exponente):"");
        }else
        {
            cout<<Arreglo[0].coeficiente<<(Arreglo[0].coeficiente!=0?"x":"")<<
            (Arreglo[0].exponente>1 ? "^"+ to_string(Arreglo[0].exponente):"");
        }

        for (int i=1; i<n-1;i++)
        {

            if(Arreglo[i].coeficiente!=1)
            {

                cout<<(Arreglo[i].coeficiente>0? "+":"")<<Arreglo[i].coeficiente
                <<(Arreglo[i].exponente>0?"x":"")<<(Arreglo[i].exponente>1 ? "^"+ to_string(Arreglo[i].exponente):"");

            }else
            {
                cout<<(Arreglo[i].coeficiente>0? "+":"")
                <<(Arreglo[i].exponente>0?"x":"")<<(Arreglo[i].exponente>1 ? "^"+ to_string(Arreglo[i].exponente):"");
            }

        }

        if(Arreglo[n-1].coeficiente!=0)
        {
            cout<<(Arreglo[n-1].coeficiente>0? "+":"")<<Arreglo[n-1].coeficiente;
        }


    }



}


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


int CapturaArregloD (Polinomio* &Arreglo)
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
    cout<<"ej. para x^7 escribir 4 si es 4x^7, igual para cualquier otro exponente";
    cout<<endl<<endl;

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
        }while(!CapturaSegura(Arreglo[i].coeficiente));
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

        for (int i=0; i<n;i++)
        {


            if(Arreglo[i].coeficiente!=0)
            {
                if(i==0)
                {
                    cout<<Arreglo[i].coeficiente<<(Arreglo[i].exponente>0?"x":"")<<
                    (Arreglo[i].exponente>1 ? "^"+ std::to_string(Arreglo[i].exponente):"");

                }else
                {
                    cout<<(Arreglo[i].coeficiente>0? "+":"")<<Arreglo[i].coeficiente<<(Arreglo[i].exponente>0?"x":"")<<
                    (Arreglo[i].exponente>1 ? "^"+ std::to_string(Arreglo[i].exponente):"");
                }
            }

        }
    }


}


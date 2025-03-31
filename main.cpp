#include <iostream>
#include<string>
#include "Captura.h"
#include "Operaciones.h"
#include "CapturaSegura.tpp"

using namespace std;

int main()
{
    int opcion;

    do{
    cout<<"0) Para Salir"<<endl
    <<"1) Para sumar dos polinomios"<<endl
    <<"2) Para restar dos polinoimios"<<endl
    <<"3) Para multiplicar dos polinomios"<<endl
    <<"4) Para dividir dos polinomios"<<endl
    <<"5) Para derivar un polinomio"<<endl
    <<"6) Para evaluar un polinomio"<<endl;

    cin>>opcion;
    }while(!CapturaSegura(opcion)||opcion>6||opcion<0);

    switch (opcion)
    {

        case 1:
            {
                //Hay que refactorizar esta parte, para que la peticion de datos se haga por parte de una funcion
            int* A = nullptr;
            int n1=CapturaArreglo(A);
            int* B = nullptr;
            int n2=CapturaArreglo(B);
            SumarPolinomio(A,B,n1,n2);

            delete[] A;
            delete[] B;
            break;
            }
        case 2:
            {
            int* A = nullptr;
            int n1=CapturaArreglo(A);
            int* B = nullptr;
            int n2=CapturaArreglo(B);
            RestarPolinomio(A,B,n1,n2);

            delete[] A;
            delete[] B;
            break;
            }
        case 3:
            {
            int* A = nullptr;
            int n1=CapturaArreglo(A);
            int* B = nullptr;
            int n2=CapturaArreglo(B);
            MultiplicacionPolinomio(A,B,n1,n2);

            delete[] A;
            delete[] B;
            break;

            }
        case 4:
        case 5:
            {
                Polinomio* Arreglo= nullptr;
                int n=CapturaArregloD(Arreglo);
                DerivarPolinomio(Arreglo,n);
                delete[] Arreglo;
                break;
            }
        case 6:
        {
            float valor;
            int* A = nullptr;
            int n=CapturaArreglo(A);
            cout<<"Introduzca el valor de x:";
            cin>>valor;
            EvaluarPolinomio(A,n,valor);
        }
    }




    return 0;
}

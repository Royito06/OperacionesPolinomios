#include "Operaciones.h"
#include "Captura.h"
#include "CapturaSegura.tpp"
#include "Gestion.h"
#include <windows.h>
/*
H  R   T
A  E   O
B  F   D               ..  .
R  A   O           ...    .
A  C                     .
   T               ...    .
Q  O                       .
U  R
E  I
   Z
   A   //NO SERÁ *TAN*  DIFICIL, HAY QUE USAR FUNCIONES YA HECHAS POR MI
   R
   */
void ControlOpciones(int opcion)
{
    int Repetir;

    switch (opcion)
    {
        system("CLS");
        case 1:
            {
            //Hay que refactorizar esta parte, para que la peticion de datos se haga por parte de una funcion
            Polinomio* A = nullptr;
            int n1=CapturaArregloD(A);
            Polinomio* B = nullptr;
            int n2=CapturaArregloD(B);
            SumarPolinomio(A,B,n1,n2);

            delete[] A;
            delete[] B;
            break;
            }
        case 2:
            {
            Polinomio* A = nullptr;
            int n1=CapturaArregloD(A);
            Polinomio* B = nullptr;
            int n2=CapturaArregloD(B);
            RestarPolinomio(A,B,n1,n2);

            delete[] A;
            delete[] B;
            break;
            }
        case 3:
            {
            Polinomio* A = nullptr;
            int n1=CapturaArregloD(A);
            Polinomio* B = nullptr;
            int n2=CapturaArregloD(B);
            MultiplicacionPolinomio(A,B,n1,n2);

            delete[] A;
            delete[] B;
            break;

            }
        case 4:
            {
                cout<<"El exponente del primer polinomio debe ser mayor o segundo que el primero"<<endl
                <<"De lo contrario el Residuo ser\246 igual al dividendo"<<endl;


                Polinomio* A = nullptr;
                int n1=CapturaArregloD(A);
                Polinomio* B = nullptr;
                int n2=CapturaArregloD(B);
                DividirPolinomio(A,B,n1,n2);





                delete[] A;
                delete[] B;
                break;
            }
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
            Polinomio* A = nullptr;
            int n=CapturaArregloD(A);
            cout<<"Introduzca el valor de x:";
            cin>>valor;
            EvaluarPolinomio(A,n,valor);
        }
    }


}

void ImprimirOps ()
{   Sleep(5);

    cout<<endl<<"0) Para Salir"<<endl
    <<"1) Para sumar dos polinomios"<<endl
    <<"2) Para restar dos polinoimios"<<endl
    <<"3) Para multiplicar dos polinomios"<<endl
    <<"4) Para dividir dos polinomios"<<endl
    <<"5) Para derivar un polinomio"<<endl
    <<"6) Para evaluar un polinomio"<<endl;
}



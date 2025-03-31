#include <iostream>
#include<string>
#include "Captura.h"
#include "Operaciones.h"
#include "CapturaSegura.tpp"
#include "Gestion.h"

using namespace std;

int main()
{
    int opcion;
    do{

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

        if(opcion!=0)
        {
            ControlOpciones(opcion);
        }
    }while(opcion!=0);



    return 0;
}

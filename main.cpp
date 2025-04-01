#include <iostream>
#include<string>
#include "Captura.h"
#include "Operaciones.h"
#include "CapturaSegura.tpp"
#include "Gestion.h"

using namespace std;

int main()
{
 /*
    do{

        do{
            IMprimirOps();

            cin>>opcion;
        }while(!CapturaSegura(opcion)||opcion>6||opcion<0);

        if(opcion!=0||Repetir!=0)
        {

            do{
                ControlOpciones(opcion);
                if(opcion==0)
                {
                    do{
                        cout<<"\250Desea realizar otra operaci\242n?"<<endl<<"0)Para No"<<endl<<"1) Para Si"<<endl;
                        cin>>Repetir;
                    }while(!CapturaSegura(Repetir)||Repetir>1||Repetir<0);
                }
            }while(Repetir!=0);

        }
    }while(opcion!=0||Repetir!=0);*/

    int opcion;
    do{

        do{
            cout<<endl;
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

#include <iostream>
#include <cmath>
#include "Captura.h"
#include "Operaciones.h"

using namespace std;

void SumarPolinomio(Polinomio* &A, Polinomio* &B,int nA,int nB)
{

    if(nA>=nB)
    {
        Polinomio* Suma=new Polinomio[nA];

        for(int i=0;i<nB;i++)
        {

        }
        cout<<"Suma: ";
        ImprimirArregloD(A,nA);
        cout<<"+";
        ImprimirArregloD(B,nB);
        cout<<"=";
        ImprimirArregloD(Suma,nA);
        delete[] Suma;
    }else
    {
        Polinomio* Suma=new Polinomio[nB];

        for(int i=0;i<nA;i++)
        {
            Suma[i].coeficiente=A[i].coeficiente+B[i].coeficiente;
        }
        cout<<"Suma: ";
        ImprimirArregloD(A,nA);
        cout<<"+";
        ImprimirArregloD(B,nB);
        cout<<"=";
        ImprimirArregloD(Suma,nB);
        delete[] Suma;
    }



}

void RestarPolinomio(Polinomio* &A, Polinomio* &B,int nA,int nB)
{

    if(nA>=nB)
    {
        Polinomio* Resta=new Polinomio[nA];

        for(int i=0;i<nB;i++)
        {
            Resta[i].coeficiente=A[i].coeficiente-B[i].coeficiente;
        }
        cout<<"Resta: ";
        ImprimirArregloD(A,nA);
        cout<<"-";
        ImprimirArregloD(B,nB);
        cout<<"=";
        ImprimirArregloD(Resta,nA);
        delete[] Resta;
    }else
    {
        Polinomio* Resta=new Polinomio[nB];

        for(int i=0;i<nA;i++)
        {
            Resta[i].coeficiente=A[i].coeficiente-B[i].coeficiente;
        }
        cout<<"Resta: ";
        ImprimirArregloD(A,nA);
        cout<<"-";
        ImprimirArregloD(B,nB);
        cout<<"=";
        ImprimirArregloD(Resta,nB);
        delete[] Resta;
    }



}

void MultiplicacionPolinomio(Polinomio* &A,Polinomio* &B, int nA,int nB)
{
    //Primero se van a multiplicar los 2 polinomios, ya despues reduciremos terminos semejantes
    int nInicial=nA*nB;
    Polinomio* MultiplicacionInicial= new Polinomio [nInicial];
    Polinomio* Exponente= new Polinomio [nInicial];

    //se llena de ceros los arreglos
    for(int j=0;j<nInicial;j++)
    {
        MultiplicacionInicial[j].coeficiente=0;
        MultiplicacionInicial[j].exponente=0;
    }
    int indice=0;

    for (int i=0;i<nA;i++)
    {
        for(int j=0;j<nB;j++)
        {
            MultiplicacionInicial[indice].coeficiente=A[i].coeficiente*B[j].coeficiente;
            MultiplicacionInicial[indice].exponente=i+j;
            indice++;
        }
    }


    //Aqui se imprime el arreglo antes de reducir terminos semejantes, para revisar que sea correcta la multiplicacion
    for (int i=nInicial-1; i>-1;i-- )
    {


        if(MultiplicacionInicial[i].coeficiente!=0)
        {
            if(i==nInicial-1)
            {
                cout<<MultiplicacionInicial[i].coeficiente<<"x^"<<MultiplicacionInicial[i].exponente;
            }else
            {
            cout<<(MultiplicacionInicial[i].coeficiente>0? "+":"")<<MultiplicacionInicial[i].coeficiente<<
            (MultiplicacionInicial[i].exponente>0?"x":"")<<(Exponente[i].coeficiente>1 ? "^"+ std::to_string(MultiplicacionInicial[i].exponente):"");
            }
        }
    }


    //Ahora se reducen terminos semejantes
    int n=(nA+nB)-1;
    int* MultiplicacionFinal=new int[n];
    for (int i=0;i<n;i++)
    {
        MultiplicacionFinal[i] = 0;
        for(int j=0;j<nInicial;j++)
        {
            if(Exponente[j]==i)
            {
                MultiplicacionFinal[i]+=MultiplicacionInicial[j];
            }
        }
    }
    cout<<endl;
    ImprimirArreglo(MultiplicacionFinal,n);

    delete[] MultiplicacionFinal;
    delete[] MultiplicacionInicial;
    delete[] Exponente;
}
//Este quedará pendiente
void DividirPolinomio(Polinomio* &A,Polinomio* &B, int nA,int nB)
{
    int nInicial=nB;

    Polinomio* DivisionInicial= new Polinomio [nInicial];


    DivisionInicial[0].coeficiente=B[0].coeficiente/A[0].coeficiente;
    DivisionInicial[0].exponente=B[0].exponente/A[0].exponente;

    cout<<endl;
    ImprimirArregloD(DivisionInicial,nInicial);

    delete[] DivisionInicial;

}

void DerivarPolinomio(Polinomio* &Arreglo, int n)
{
    Polinomio* Derivada= new Polinomio[n];

    for(int i=0;i<n;i++)
    {
        Derivada[i].coeficiente=Arreglo[i].coeficiente*Arreglo[i].exponente;
        Derivada[i].exponente=Arreglo[i].exponente-1;
    }


    ImprimirArregloD(Derivada,n);

    delete [] Derivada;
}
void EvaluarPolinomio(int* &Arreglo,int n,float valor)
{
    float Acumulado=0;

    for(int i=0; i<n;i++)
    {
        Acumulado+=Arreglo[i]*pow(valor,i);

    }

    cout<<Acumulado;
}


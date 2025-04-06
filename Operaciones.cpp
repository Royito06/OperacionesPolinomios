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

    int tam;

    if(nA>=nB)
    {

        tam=nA;
    }else
    {
        tam=nB;
    }
    Polinomio* Resta=new Polinomio[tam];

    for(int i=0;i<nB;i++)
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

void MultiplicacionPolinomio(Polinomio* &A,Polinomio* &B, int nA,int nB)
{
    //Primero se van a multiplicar los 2 polinomios, ya despues reduciremos terminos semejantes
    int nInicial=nA*nB;
    Polinomio* MultiplicacionInicial= new Polinomio [nInicial];


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
            (MultiplicacionInicial[i].exponente>0?"x":"")<<(MultiplicacionInicial[i].coeficiente>1 ? "^"+ std::to_string(MultiplicacionInicial[i].exponente):"");
            }
        }
    }


    //Ahora se reducen terminos semejantes
    int n=(nA+nB)-1;
    Polinomio* MultiplicacionFinal=new Polinomio[n];
    for (int i=0;i<n;i++)
    {
        MultiplicacionFinal[i].coeficiente = 0;
        for(int j=0;j<nInicial;j++)
        {
            if(MultiplicacionFinal[j].exponente==i)
            {
                MultiplicacionFinal[i].coeficiente+=MultiplicacionInicial[j].coeficiente;
            }
        }
    }
    cout<<endl;
    ImprimirArregloD(MultiplicacionFinal,n);

    delete[] MultiplicacionFinal;
    delete[] MultiplicacionInicial;

}

void DividirPolinomio(Polinomio* &A,Polinomio* &B, int nA,int nB)
{


    Polinomio* Cociente= new Polinomio [nA];
    Polinomio* Residuo = new Polinomio[nA];

    if(nA>nB)
    {
        //El residuo inicial será el mismo que el dividendo
        for(int i=0;i<nA;i++)
        {
            Cociente[i].coeficiente=A[i].coeficiente;
            Cociente[i].exponente=A[i].exponente;
        }


    }else
    {
        for(int i=0; i<nA; i++)
        {
            Residuo[i]=A[i];
            Cociente[i].coeficiente=0;
            Cociente[i].exponente=0;
        }

    }

    cout<<endl;
    cout<<"El resultado es: ";
    ImprimirArregloD(Cociente,nA);
    cout<<endl;
    cout<<"El residuo es: ";
    ImprimirArregloD(Residuo,nA);

    delete[] Residuo,Cociente;

}

void DerivarPolinomio(Polinomio* &Arreglo, int n)
{
    Polinomio* Derivada= new Polinomio[n];

    for(int i=0;i<n;i++)
    {
        Derivada[i].coeficiente=Arreglo[i].coeficiente*Arreglo[i].exponente;
        Derivada[i].exponente=Arreglo[i].exponente-1;
    }


    cout<<"La derivada es:";
    ImprimirArregloD(Derivada,n);

    delete [] Derivada;
}
void EvaluarPolinomio(Polinomio* &Arreglo,int n,float valor)
{
    float Acumulado=0;

    for(int i=0; i<n;i++)
    {
        Acumulado+=Arreglo[i].coeficiente*pow(valor,i);

    }

    cout<<Acumulado;
}


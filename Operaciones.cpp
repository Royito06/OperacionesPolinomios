#include <iostream>
#include <cmath>
#include "Captura.h"
#include "Operaciones.h"

using namespace std;

void SumarPolinomio(int* &A, int* &B,int nA,int nB)
{

    if(nA>=nB)
    {
        int* Suma=new int[nA];

        for(int i=0;i<nB;i++)
        {
            Suma[i]=A[i]+B[i];
        }
        cout<<"La suma de";
        ImprimirArreglo(A,nA);
        cout<<"+";
        ImprimirArreglo(B,nB);
        cout<<"=";
        ImprimirArreglo(Suma,nA);
        delete[] Suma;
    }else
    {
        int* Suma=new int[nB];

        for(int i=0;i<nA;i++)
        {
            Suma[i]=A[i]+B[i];
        }
        cout<<"La suma de";
        ImprimirArreglo(A,nA);
        cout<<"+";
        ImprimirArreglo(B,nB);
        cout<<"=";
        ImprimirArreglo(Suma,nB);
        delete[] Suma;
    }



}

void RestarPolinomio(int* &A, int* &B,int nA,int nB)
{

    if(nA>=nB)
    {
        int* Resta=new int[nA];

        for(int i=0;i<nB;i++)
        {
            Resta[i]=A[i]-B[i];
        }
        cout<<"La resta de";
        ImprimirArreglo(A,nA);
        cout<<"-";
        ImprimirArreglo(B,nB);
        cout<<"=";
        ImprimirArreglo(Resta,nA);
        delete[] Resta;
    }else
    {
        int* Resta=new int[nB];

        for(int i=0;i<nA;i++)
        {
            Resta[i]=A[i]-B[i];
        }
        cout<<"La resta de";
        ImprimirArreglo(A,nA);
        cout<<"-";
        ImprimirArreglo(B,nB);
        cout<<"=";
        ImprimirArreglo(Resta,nB);
        delete[] Resta;
    }



}

void MultiplicacionPolinomio(int* &A,int* &B, int nA,int nB)
{
    //Primero se van a multiplicar los 2 polinomios, ya despues reduciremos terminos semejantes
    int nInicial=nA*nB;
    int* MultiplicacionInicial= new int [nInicial];
    int* Exponente= new int [nInicial];

    //se llena de ceros los arreglos
    for(int j=0;j<nInicial;j++)
    {
        MultiplicacionInicial[j]=0;
        Exponente[j]=0;
    }
    int indice=0;

    for (int i=0;i<nA;i++)
    {
        for(int j=0;j<nB;j++)
        {
            MultiplicacionInicial[indice]=A[i]*B[j];
            Exponente[indice]=i+j;
            indice++;
        }
    }


    //Aqui se imprime el arreglo antes de reducir terminos semejantes, para revisar que sea correcta la multiplicacion
    for (int i=nInicial-1; i>-1;i-- )
    {


        if(MultiplicacionInicial[i]!=0)
        {
            if(i==nInicial-1)
            {
                cout<<MultiplicacionInicial[i]<<"x^"<<Exponente[i];
            }else
            {
            cout<<(MultiplicacionInicial[i]>0? "+":"")<<MultiplicacionInicial[i]<<
            (Exponente[i]>0?"x":"")<<(Exponente[i]>1 ? "^"+ std::to_string(Exponente[i]):"");
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
void DividirPolinomio(int* &A,int* &B, int nA,int nB)
{
    //Primero se van a multiplicar los 2 polinomios, ya despues reduciremos terminos semejantes
    int nInicial=nA*nB;
    int* DivisionInicial= new int [nInicial];
    int* Exponente= new int [nInicial];

    //se llena de ceros los arreglos
    for(int j=0;j<nInicial;j++)
    {
        DivisionInicial[j]=0;
        Exponente[j]=0;
    }
    int indice=0;

    for (int i=0;i<nA;i++)
    {
        for(int j=0;j<nB;j++)
        {
            DivisionInicial[indice]=A[i]*B[j];
            Exponente[indice]=i+j;
            indice++;
        }
    }


    //Aqui se imprime el arreglo antes de reducir terminos semejantes, para revisar que sea correcta la multiplicacion
    for (int i=nInicial-1; i>-1;i-- )
    {


        if(DivisionInicial[i]!=0)
        {
            if(i==nInicial-1)
            {
                cout<<DivisionInicial[i]<<"x^"<<Exponente[i];
            }else
            {
            cout<<(DivisionInicial[i]>0? "+":"")<<DivisionInicial[i]<<
            (Exponente[i]>0?"x":"")<<(Exponente[i]>1 ? "^"+ std::to_string(Exponente[i]):"");
            }
        }
    }


    //Ahora se reducen terminos semejantes
    int n=(nA+nB)-1;
    int* DivisionFinal=new int[n];
    for (int i=0;i<n;i++)
    {
        DivisionFinal[i] = 0;
        for(int j=0;j<nInicial;j++)
        {
            if(Exponente[j]==i)
            {
                DivisionFinal[i]+=DivisionInicial[j];
            }
        }
    }
    cout<<endl;
    ImprimirArreglo(DivisionFinal,n);

    delete[] DivisionFinal;
    delete[] DivisionInicial;
    delete[] Exponente;
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


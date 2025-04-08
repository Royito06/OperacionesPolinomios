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

/*void DividirPolinomio(Polinomio* P, int nP, Polinomio* Q, int nQ,Polinomio* &C, int &nC, Polinomio* &R, int &nR)
{

    //Creo q es P/Q
    // Por lo cual es P^R/Q^C
    if(Q[0]==0) throw "Divisi\242n por 0";

    double *D=new double [nP+1];

    for(int i=0;i<nP; i++)
    {
        D[i]=P[i];
    }

    if(nP>nQ)
    {
        C[0]=nC=0;
        nR=nP;
    }else
    {
        nC=nP-nQ;
        for(int i=0;i<nC;i++)
        {
            C[i]=D[i]/Q[0];
            for(int j=0;j<nQ;j++) D[i+j]-=C[i]*Q[j];
        }
        nR=nQ-1;



    }
    if (nQ==0) R[0]=nR=0;
    else
    {
        int inicio=nP-nR;
        for( ;nR>0 &&D[inicio]==0;inicio++)--nR;
        for(int i=0; i<nR; i++) R[i]=D[inicio+i];
    }

    delete[] P;
    delete[] Q;
    delete[] C;*/
void DividirPolinomio(Polinomio* P, int nP, Polinomio* Q, int nQ)
{
    // Verificar si el divisor es cero
    if (Q[0].coeficiente == 0) throw "División por 0";

    // Crear un arreglo auxiliar para trabajar con el dividendo (P)
    double* D = new double[nP + 1];
    for (int i = 0; i < nP; i++) {
        D[i] = P[i].coeficiente;
    }

    // Inicializar el cociente (C) y el residuo (R)
    Polinomio* cociente = new Polinomio[nP]; // Puede tener hasta nP términos
    int exponenteMaxCociente = 0;

    Polinomio* residuo = new Polinomio[nP];
    int exponenteMaxResiduo = nP;

    // Realizar la división (de la forma más parecida a una división larga)
    while (nP >= nQ) {
        // Obtener el coeficiente del cociente
        double coef = D[0] / Q[0].coeficiente;
        int exponente = nP - nQ;

        // Guardar el término en el cociente
        cociente[exponenteMaxCociente].coeficiente = coef;
        cociente[exponenteMaxCociente].exponente = exponente;
        exponenteMaxCociente++;

        // Restar el múltiplo del divisor al dividendo (D)
        for (int i = 0; i < nQ; i++) {
            D[i] -= coef * Q[i].coeficiente;
        }

        // Reducir el tamaño del dividendo
        nP--;
    }

    // El residuo será el contenido restante de D
    for (int i = 0; i < nP; i++) {
        residuo[i].coeficiente = D[i];
        residuo[i].exponente = i;
    }



    // Imprimir el cociente y el residuo
    cout << "Cociente: ";
    ImprimirArregloD(cociente, exponenteMaxCociente);
    cout << "\nResiduo: ";
    ImprimirArregloD(residuo, exponenteMaxResiduo);

    // Liberar la memoria
    delete[] D;
    delete[] cociente;
    delete[] residuo;
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


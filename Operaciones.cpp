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
    if (Q[0].coeficiente == 0) {
        cout << "Error: Division por cero" << endl;
        return;
    }

    // Si el grado del divisor es mayor que el dividendo, el cociente es 0 y el residuo es P
    if (nQ > nP) {
        cout << "Cociente: 0" << endl;
        cout << "Residuo: ";
        ImprimirArregloD(P, nP);
        return;
    }

    // Crear arreglos temporales para el cociente y residuo
    int maxGradoCociente = nP - nQ;
    Polinomio* cociente = new Polinomio[maxGradoCociente + 1];
    Polinomio* residuo = new Polinomio[nP];

    // Inicializar cociente y residuo
    for (int i = 0; i <= maxGradoCociente; i++) {
        cociente[i].coeficiente = 0;
        cociente[i].exponente = maxGradoCociente - i;
    }

    // Copiar P a residuo
    for (int i = 0; i < nP; i++) {
        residuo[i].coeficiente = P[i].coeficiente;
        residuo[i].exponente = P[i].exponente;
    }

    // Algoritmo de división de polinomios
    for (int i = 0; i <= maxGradoCociente; i++) {
        // Calcular el término actual del cociente
        double coef = residuo[i].coeficiente / Q[0].coeficiente;
        int exp = residuo[i].exponente - Q[0].exponente;

        cociente[i].coeficiente = coef;
        cociente[i].exponente = exp;

        // Restar el término multiplicado por el divisor
        for (int j = 0; j < nQ; j++) {
            int pos = i + j;
            if (pos < nP) {
                residuo[pos].coeficiente -= coef * Q[j].coeficiente;
            }
        }
    }

    // Determinar el grado real del residuo
    int gradoResiduo = 0;
    for (int i = 0; i < nP; i++) {
        if (residuo[i].coeficiente != 0) {
            gradoResiduo = residuo[i].exponente;
            break;
        }
    }

    // Imprimir resultados
    cout << "Division de polinomios:" << endl;
    cout << "Dividendo: ";
    ImprimirArregloD(P, nP);
    cout << endl << "Divisor: ";
    ImprimirArregloD(Q, nQ);
    cout << endl << "Cociente: ";
    ImprimirArregloD(cociente, maxGradoCociente + 1);
    cout << endl << "Residuo: ";

    // Solo imprimir términos no nulos del residuo
    bool todosCeros = true;
    for (int i = 0; i < nP; i++) {
        if (residuo[i].coeficiente != 0) {
            todosCeros = false;
            break;
        }
    }

    if (todosCeros) {
        cout << "0";
    } else {
        // Crear un arreglo solo con los términos no nulos
        int count = 0;
        for (int i = 0; i < nP; i++) {
            if (residuo[i].coeficiente != 0) count++;
        }

        Polinomio* residuoFinal = new Polinomio[count];
        int index = 0;
        for (int i = 0; i < nP; i++) {
            if (residuo[i].coeficiente != 0) {
                residuoFinal[index] = residuo[i];
                index++;
            }
        }

        ImprimirArregloD(residuoFinal, count);
        delete[] residuoFinal;
    }
    cout << endl;

    // Liberar memoria
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


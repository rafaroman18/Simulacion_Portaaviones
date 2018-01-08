#include <iostream>
#include "tadcolapseudoestatico.h"
#define N 4
void menu_aviones(Cola<int>& C,Cola<int>& E);
void entrada_avion(int mat,Cola<int>& C,Cola<int>& E);
void salida_avion(int mat,Cola<int>& C,Cola<int>& E);
int main()
{
    using namespace std;
    Cola<int> C (N);
    Cola<int> E (100);
    C.push(1234);
    C.push(1235);
    C.push(1236);
    C.push(1237);
    menu_aviones(C,E);
    /*while(!C.vacia())
    {
        cout<<C.frente()<<endl;
        C.pop();
    }
    while(!E.vacia())
    {
        cout<<E.frente()<<endl;
        E.pop();
    }*/
    return 0;
}

void menu_aviones(Cola<int>& C,Cola<int>& E)
{
    int mat;char D;Cola<int> W(N);Cola<int> Z(N);int X;
    while(D!='.')
    {
    cout<<"Introduzca matricula del avion que desea desplazar"<<endl;                   //VALORAR SI METER
        cin>>mat;
        cout << "Introduzca 'E' para la entrada o 'S' para la salida del avion indicado" << endl;
        cout << "Para terminar, introduzca '.'" << endl;
        cin >> D;
        cout<<endl;
        switch(D)
        {
            case 'E': {
                entrada_avion(mat,C,E);
                W=C;
                Z=E;
                cout<<"Elementos actuales de la cola: "<<endl;
                cout<<"Cola C:"<<endl;while(!W.vacia()){cout<<W.frente()<<endl;W.pop();};
                cout<<"Cola E:"<<endl;while(!Z.vacia()){cout<<Z.frente()<<endl;Z.pop();};
                cout<<endl;}break;
            case 'S': {
                salida_avion(mat,C,E);
                W=C;
                Z=E;
                cout<<"Elementos actuales de la cola: "<<endl;
                cout<<"Cola C:"<<endl;while(!W.vacia()){cout<<W.frente()<<endl;W.pop();};
                cout<<"Cola E:"<<endl;while(!Z.vacia()){cout<<Z.frente()<<endl;Z.pop();};
                cout<<endl;}break;
            case '.':;break;
            default: cout<<"Letra introducida no valida, por favor, introduzca de nuevo"<<endl;break;
        }

    }
}

void entrada_avion(int mat,Cola<int>& C,Cola<int>& E)
{
    int i;
    if(C.llena())
        E.push(mat);                //ESTARA AQUI HASTA QUE SALGA UN AVION DE LA COLA NORMAL O SE LE DE LA ORDEN DE SALIDA
    else
        C.push(mat);
}

void salida_avion(int mat,Cola<int>& C,Cola<int>& E)
{
    int i=0,CONT;
    Cola<int> AUX(N);
    Cola<int> COMP(0);
    AUX=C;
    while(mat != C.frente() && !AUX.vacia())             // REVISAR BIEN
    {
        CONT=C.frente();
        C.pop();
        C.push(CONT);
        AUX.pop();
    }
    if(!AUX.vacia())
    {
        C.pop();
        if (!E.vacia()){
            entrada_avion(E.frente(),C,E);
            E.pop();}
    }
    else
            salida_avion(mat,E,COMP);
}

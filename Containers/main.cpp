/*ESSE PROGRAMA É UMA IMPLEMENTAÇÃO DO CONCEITO DE PILHA
EM ESTRUTURAS DE DADOS.

O PROGRAMA SE BASEIA EM UM PÁTIO DE CONTEINERS EM QUE SE PODE
ARMAZENAR, RETIRAR E CONSULTAR CONTEINERS, ONDE A REGRA É SEMPRE
ARMAZENAR SOBRE O CONTEINER QUE ESTÁ NO TOPO OU RETIRAR O CONTEINER
QUE ESTÁ NO TOPO.

by DANIEL SANTANA
*/

#include <iostream>
#include <stdlib.h>
#include "Container.h"
using namespace std;

struct Conteiner{
        unsigned codigo;
        unsigned tamanho;
        float peso;
};

int main()
{
    system("color 3");
    //definindo o tamanho do pátio
    unsigned tamPatio,quadra;
    cout<<"DIGITE O TAMANHO DO PATIO\nNUMERO DE QUADRAS: ";
    cin>>tamPatio;
    //criando um vetor de tamanho do patio
    //de ponteiros p para Pilha<CC>
    Pilha<Conteiner> *p[tamPatio];
    //inicializando 10 pilhas de CC de tamanho = 5


    for(unsigned i=0;i<tamPatio;i++){
        p[i] = new Pilha<Conteiner>(5);
    }

    Conteiner cc; //c é uma variavel do tipo Conteiner
    int opc;

do{
    system("cls");
    cout<<"****PATIO DE CONTEINERS****"<<endl;
    cout<<"1 - ARMAZENAR CONTENEIR."<<endl;
    cout<<"2 - REMOVER CONTEINER."<<endl;
    cout<<"3 - CONSULTAR CONTEINER NO TOPO."<<endl;
    cout<<"4 - EXIBIR PATIO."<<endl;
    cout<<"9 - SAIR."<<endl;
    cout<<"SELECIONE:";
    cin>>opc;
    switch(opc){
    case 1:
        cout<<"\nDigite a quadra: ";
        cin>>quadra;
        if(quadra >)
        if(p[quadra]->pilhacheia()){
            cout<<"Quadra lotada..."<<endl;
            system("pause");
        }
        else{
            cout<<"Dados do conteiner."<<endl;
            cout<<"Digite o codigo do Conteiner: ";
            cin>>cc.codigo;
            cout<<"Digite o tamanho: ";
            cin>>cc.tamanho;
            cout<<"Digite o Peso: ";
            cin>>cc.peso;
            p[quadra]->empilhaContainer(cc);
            cout<<"Empilhamento com sucesso."<<endl;
            system("pause");
        }
        break;

    case 2:
        cout<<"\nDigite a quadra: ";
        cin>>quadra;
        if(p[quadra]->pilhavazia()){
            cout<<"Quadra Vazia"<<endl;
        }
        else{
            cc = p[quadra]->desempilha();
            cout<<"Dados do conteiner."<<endl;
            cout<<"Codigo:"<<cc.codigo<<endl;
            cout<<"Tamanho:"<<cc.tamanho<<endl;
            cout<<"Peso:"<<cc.peso<<endl;
            cout<<"O conteiner foi removido com sucesso.";
            system("pause");
        }
        break;

    case 3:
        cout<<"Digite a quadra: ";

        cin>>quadra;
        if(p[quadra]->pilhavazia()){
            cout<<"\nQuadra Vazia"<<endl;
        }
        else{
            cc = p[quadra]->elementodotopo();
            cout<<"Dados do conteiner."<<endl;
            cout<<"Codigo:"<<cc.codigo<<endl;
            cout<<"Tamanho:"<<cc.tamanho<<endl;
            cout<<"Peso:"<<cc.peso<<endl;
            system("pause");
        }
        break;

    case 4:
        cout<<"\nExibir o patio"<<endl;
        for(int q=0;q<tamPatio;q++){
            if(p[q]->pilhavazia()){
                cout<<q<<" - Quadra vazia."<<endl;
            }else{
                for(int i=0;i<=p[q]->getTopo();i++){
                    cc = p[q]->getValor(i);
                    cout<<q<<" - Quadra. Elemento do topo;\n\n";
                    cout<<"Dados do conteiner."<<endl;
                    cout<<"Codigo:"<<cc.codigo<<endl;
                    cout<<"Tamanho:"<<cc.tamanho<<endl;
                    cout<<"Peso:"<<cc.peso<<"\n\n";
                }
            }
        }
        system("pause");
        break;
    case 9:
        cout<<"FIM"<<endl;
        break;
    default:
        cout <<"Opcao invalida.\n";
        system("pause");
    }
}while(opc!=9);

return 0;
}

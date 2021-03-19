/*ESSE PROGRAMA É UMA IMPLEMENTAÇÃO DO CONCEITO DE
FILA EM ALOCAÇÃO SEQUENCIAL EM ESTRUTURAS DE DADOS.
*
*IMPLEMENTAÇÃO DE UMA FILA DE UM POSTO MÉDICO.
*0 ATENDIMENTO É VOLTADO À PACIENTES DO HOSPITAL GUARUJÁ.
*A ORDEM DE ATENDIMENTO É DE ACORDO COM A CHEGADA DO PACIENTE.
*A PRIMEIRA PESSOA QUE ENTRA NA FILA É A PRIMEIRA QUE SAI DO HOSPITAL.
*obs.: HOSPITAL DO GUARUJÁ É UM NOME FICTÍCIO.

by DANIEL SANTANA
*/


#include <iostream>
#include <stdlib.h>
#include "filaalocacaosequencial.h"
using namespace std;

int main()
{
    system("color 3");
    unsigned tam=30; // TAMANHO DA FILA
    int opc,senha=0;
    Fila<int> f(tam);
    cout<<"\tHOSPITAL DO GUARUJA\n\tSEJA BEM-VINDO!!!\n\n";

    do{

        cout<<"\n";
        cout<<"1 - GERAR SENHA PARA PACIENTE."<<endl;
        cout<<"2 - CHAMADA DE PACIENTE PARA O ATENDIMENTO."<<endl;
        cout<<"3 - MOSTRAR A PRIMEIRA SENHA DA FILA."<<endl;
        cout<<"4 - EXIBIR QTOS PACIENTES ESTAO ESPERANDO NA FILA."<<endl;
        cout<<"5 - SAIR."<<endl;
        cin>>opc;
        system("cls");

        switch(opc){
        case 1:
        //ADICIONA 1 PACIENTE NA FILA
        if(f.filacheia()){
            cout<<"A FILA ESTA CHEIA!!!"<<endl;
        }
        else{
            senha++;
            f.insereFim(senha);
            cout<<"VOCE PEGOU A SENHA:"<<senha<<"\nAGUARDE PARA SER CHAMADO!";
           }
        break;

        case 2:
        //RETIRAR 1 PACIENTE DA FILA
        if(f.filavazia()){
                cout<<"A FILA ESTA VAZIA!!!"<<endl;
            }
            else{
                cout<<"POR FAVOR, PACIENTE COM A SENHA: "<<f.primeiro()<<"\nCOMPARECA IMEDIATAMENTE NA SALA DO DOUTOR!"<<endl;
                f.removeInic();
            }
        break;

        case 3:
        cout<<"O PROXIMO PACIENTE A SER CHAMADO SERA: "<<f.primeiro()<<endl;
        break;

        case 4:
        if(f.filavazia()) {
                cout<<"A FILA ESTA VAZIA!!!"<<endl;
            }
            else{
                cout<<"PACIENTES EM ESPERA: ";
                if(f.getInic() <= f.getFim()) {
                    for(int i=f.getInic();i<=f.getFim();i++) {
                        cout<<f.getValor(i)<<", ";
                    }
                }
            }
        break;

        case 5:
        //SAIR
        cout<<"OBRIGADO POR COMPARECER NO HOSPITAL GUARUJA\nVOLTE ASSIM QUE PRECISAR!"<<endl;
        break;

        default:
        cout<<"OPCAO INVALIDA\nTENTE DIGITAR NOVAMENTE!!!"<<endl;
        break;
        }
    }while(opc!=5);
    return 0;
}

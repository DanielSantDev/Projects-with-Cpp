#include <iostream>
#include "pilha_.h"
using namespace std;

int main()
{
    cout << "Expressoes " << endl;
    Pilha<char> p;
    string expressao;
    unsigned i;
    bool valido;
    char s;
    int opc;
    do{
        cout<<"1 - Nova Expressao"<<endl;
        cout<<"9 - FIM\n";
        cout<<"Selecione:";
        cin>>opc;
        cin.ignore();
        switch(opc){
        case 1:
        cout<<"Digite a expressão: ";
        getline(cin,expressao);
        cout<<"digitado: "<<expressao<<endl;
        unsigned tam = expressao.size();
        i=0;
        valido=true;
        while(i<tam){
            s = expressao.at(i);
            if(s=='{' || s=='[' || s== '('){
                p.empilha(s);
               }
               else{
                    if(s=='}'||s==']'||s==')'){
                        if(p.pilhavazia()){
                            valido=false;
                        }
                        else{
                            if(s=='}' && p.elementodotopo()=='{'){
                                p.desempilha();
                            }
                            else{
                                if(s==']'&&p.elementodotopo()=='['){
                                    p.desempilha();
                                }
                                else{
                                    if(s==')'&&p.elementodotopo()=='('){
                                        p.desempilha();
                                    }
                                    else{
                                        break;
                                    }
                                }
                            }
                        }
                    }
               }
               i++;
            }
        }
    }while(opc != 9);

    if(p.pilhavazia() && valido){
        cout<<"a expressao: "<<expressao<<endl;
        cout<<"Estah correta!"<<endl;
    }
    else{
        cout<<"a expressao: "<<expressao<<endl;
        cout<<"Não estah correta!!!"<<endl;
    }
    return 0;
}

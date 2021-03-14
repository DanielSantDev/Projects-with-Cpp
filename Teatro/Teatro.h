#ifndef TEATRO_H_INCLUDED
#define TEATRO_H_INCLUDED

#include <iostream>

/****************************
CODIFICADO POR DANIEL SANTANA
*****************************/

using namespace std;

struct Teatro{

    unsigned Linhas;
    unsigned Colunas;
    unsigned Vendas;
    bool *Assentos;

    Teatro(){
    }

    Teatro(int linhas, int colunas) {
        Linhas = linhas;
        Colunas = colunas;
        Assentos = new bool[Linhas*Colunas];
        Vendas = 0;
        //zerar matriz
        for(int i = 0; i<Linhas;i++){
            for(int j = 0; j<Colunas;j++){
                Assentos[i*Colunas+j] = false;
            }
        }
    }

    /*verifica a disponibilidade do assento*/
    bool Disponibilidade(int linha, int coluna) {
        if(Assentos[linha*Colunas+coluna] == false && linha < Linhas && coluna < Colunas)
            return true;
    }
    void MarcarLugar(int linha, int coluna){
            Assentos[linha*Colunas+coluna] = true;
            Vendas += 1;
    }

    /*Reembolsa*/
    void Reembolso(int linha, int coluna) {
            Assentos[linha*Colunas+coluna] = false;
            Vendas -= 1;
    }

};

#endif // TEATRO_H_INCLUDED

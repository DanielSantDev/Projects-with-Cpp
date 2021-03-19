#ifndef FILAALOCACAOSEQUENCIAL_H_INCLUDED
#define FILAALOCACAOSEQUENCIAL_H_INCLUDED

template <typename Tipo>
class Fila{
private:
    int fim, inic;
    unsigned qtde;
    unsigned tamanho;
    Tipo *v;
public:
    Fila(unsigned tam){
        fim=-1;
        inic=0;
        qtde=0;
        tamanho = tam;
        v = new Tipo[tamanho];
    }
    ~Fila(){
        delete []v;
    }

    void insereFim(Tipo x){
        fim++;
        if(fim==tamanho){
            fim=0;
        }
        v[fim]=x;
        qtde++;
    }

    Tipo removeInic(){
        Tipo temp = v[inic];
        inic++;
        if(inic==tamanho){
            inic=0;
        }
        qtde--;
        return temp;
    }

    Tipo primeiro(){
        return v[inic];
    }

    Tipo ultimo(){
        return v[fim];
    }

    bool filacheia(){
        return qtde==tamanho;
    }

    bool filavazia(){
        return qtde==0;
    }

    int getFim(){
        return fim;
    }

    int getInic(){
        return inic;
    }

    Tipo getValor(unsigned posicao){
        return v[posicao];
    }
};


#endif // FILAALOCACAOSEQUENCIAL_H_INCLUDED

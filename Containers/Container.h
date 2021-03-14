#ifndef CONTAINER_H_INCLUDED
#define CONTAINER_H_INCLUDED

template <typename Tipo>
class Pilha {
private:
    Tipo *v;
    unsigned tamanho;
    int topo;
public:
    Pilha(unsigned tam) {
        tamanho = tam;
        v = new Tipo[tamanho];
        topo = -1;
    }

    ~Pilha() {
        delete []v;
    }

    void empilhaContainer(Tipo x) {
        topo++;
        v[topo] = x;
    }

    Tipo desempilha(){
        Tipo temp = v[topo];
        topo--;
        return temp;
    }

    Tipo elementodotopo(){
        return v[topo];
    }

    bool pilhacheia(){
        return topo == tamanho -1;
    }

    bool pilhavazia(){
        return topo == -1;
    }

    unsigned getTopo(){
        return topo;
    }

    unsigned getTamanho(){
        return tamanho;
    }

    Tipo getValor(unsigned posicao){
        return v[posicao];
    }
};

#endif // CONTAINER_H_INCLUDED

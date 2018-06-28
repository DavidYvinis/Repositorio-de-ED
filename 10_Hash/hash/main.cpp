#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

enum Marcador {VAZIO = 0, CHEIO = 1, DELETADO = 2};

struct Elem {
    int key;
    string value;

    Elem(int key = 0, string value = ""){
        this->key = key;
        this->value = value;
    }

    bool operator ==(Elem other){
        return key == other.key;
    }

    friend ostream& operator << (ostream& os, Elem e){
        os << e.key;
        return os;
    }
};

struct HashLinear{
    pair<Elem, Marcador> * vet;
    int cap;
    int size;

    HashLinear(int capacity){
        vet = new pair<Elem, Marcador>[capacity];
        this->cap = cap;
        this->size = 0;

        for(int i = 0; i < capacity; i++){
            vet[i].first = Elem();
            vet[i].second = VAZIO;
        }
    }


    bool insert(Elem elem){
        int ret_busca = busca(elem.key);
        if(ret_busca == -1)
            return false;

        int pos = elem.key % this->size;

        while((vet[pos].second != VAZIO) ||
                  (vet[pos].second != DELETADO))
            pos = (pos + 1) % cap;

            this->vet[pos].second = CHEIO;
            this->vet[pos].first = elem;
            this->size++;

    }



    int busca(int key){
        int base = key % cap;
        int a = 0;
        int pos = base;

        while ((vet[pos].first == 0) ||
                   (vet[pos].second != VAZIO)){
            a++;
            pos = (base + a * a) % cap;
        }

        if(vet[pos].second == VAZIO)
            return -1;

            return pos;
   }



    bool remove(int key){
        auto ret_busca = busca(key);
        if (ret_busca != -1){
            this->vet[ret_busca].second = DELETADO;
            size--;
            return true;
        }
        return false;
    }

};



int main()
{
    cout << "É nois mundão" << endl;
    return 0;
}

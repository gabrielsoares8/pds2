#include "energia.hpp"

Energia::Energia(int carga_inicial):carga_(carga_inicial){
    if (carga_ <0){
        carga_ = 0;
    }
}


int Energia::getCarga() const {
    return carga_;
}

void Energia::consumir(int quantidade) {
    if(quantidade > carga_){
        carga_ = 0;
    }
    else{
         carga_ -= quantidade;

    }

}

//3 erros achados
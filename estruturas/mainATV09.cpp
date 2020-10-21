#include <iostream>
#include "ArvoreBinaria.h"


int main(){
    // 61, 89, 43, 16, 100, 51, 90, 66, 79, 55, 11, 32, 77, 82
    ArvoreBinaria<int> * a1 = new ArvoreBinaria<int>();
    a1->inserir(13);
    a1->inserir(10);
    a1->inserir(2);
    a1->inserir(11);
    a1->inserir(25);
    a1->inserir(20);
    a1->inserir(26);
    a1->inserir(18);
    a1->inserir(24);

    a1->vizualizarEmOrdem();

    cout<<"max: "<<a1->max(a1->raiz)<<"\n";
    cout<<"min: "<<a1->min(a1->raiz)<<"\n";

    // a1->excluirSimples(25);
    a1->excluirFusao(25);
    //a1->excluirCopia(25);
    
    a1->vizualizarEmOrdem();
}
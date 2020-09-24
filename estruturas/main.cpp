#include <iostream>
#include "ArvoreBinaria.h"


int main(){
    // 61, 89, 43, 16, 100, 51, 90, 66, 79, 55, 11, 32, 77, 82
    ArvoreBinaria<int> * a1 = new ArvoreBinaria<int>();
    a1->inserir(61);
    a1->inserir(89);
    a1->inserir(43);
    a1->inserir(16);
    a1->inserir(100);
    a1->inserir(51);
    a1->inserir(90);
    a1->inserir(66);
    a1->inserir(79);
    a1->inserir(55);
    a1->inserir(11);
    a1->inserir(32);
    a1->inserir(77);
    a1->inserir(82);

    a1->vizualizarEmOrdem();



}
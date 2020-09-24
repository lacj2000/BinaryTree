#include <iostream>
using namespace std;

template <typename Tipo>
class No{
    public:
        Tipo valor;
        No<Tipo> *direita, *esquerda;
        No(Tipo elemento){
            this->valor = elemento;
            this->esquerda = 0;
            this->direita = 0;
        }
};

template <typename Tipo>
class ArvoreBinaria{
    public:
        No<Tipo> *raiz;

        ArvoreBinaria(No<Tipo> *r = 0){
            this->raiz = r;
        }
        ArvoreBinaria(Tipo elemento){
            this->raiz = new No<Tipo>(elemento);
        }
        
        bool ehVazia(){
            return (this->raiz == 0);
        }


        void visitar(No<Tipo> * elemento){
            cout<<elemento->valor<<" ";
        }


        void inserir(Tipo elemento){
            if(ehVazia()){
                this->raiz = new No<Tipo>(elemento);
            }else{               
                No<Tipo> *atual = this->raiz, *anterior = 0;
                int lado;
                do{
                    if (atual != 0){
                        anterior = atual;
                    }

                    if (elemento < atual->valor){
                        atual = atual->esquerda;
                        lado = 0;    
                    }
                    else{ 
                        atual = atual->direita;
                        lado = 1;    
                    }

                }while(atual != 0);
            
                if (lado==1){
                    anterior->direita = new No<Tipo>(elemento);
                }
                else{ 
                    anterior->esquerda = new No<Tipo>(elemento);
                }
            }
        }

        void emOrdem(No<Tipo> *no){
            No<Tipo> *atual = no;
            if (atual != 0){
                emOrdem(atual->esquerda);
                cout<<atual->valor<<" ";
                //this->visitar(atual);
                emOrdem(atual->direita);
            }
            return;
        }


        void vizualizarEmOrdem(){
            cout<<"Em Order: ";
            emOrdem(this->raiz);
            cout<<"\n";
        }


};



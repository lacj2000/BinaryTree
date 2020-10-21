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
                this->visitar(atual);
                emOrdem(atual->direita);
            }
        }


        void preOrdem(No<Tipo> *no){
            No<Tipo> *atual = no;
            if (atual != 0){
                this->visitar(atual);
                preOrdem(atual->esquerda);
                preOrdem(atual->direita);
            }     
        }


        void posOrdem(No<Tipo> *no){
            No<Tipo> *atual = no;
            if (atual != 0){
                posOrdem(atual->esquerda);
                posOrdem(atual->direita);
                this->visitar(atual);
            }     
        }



        void vizualizarEmOrdem(){
            cout<<"Em Ordem: ";
            if(this->raiz)
                emOrdem(this->raiz);
            else 
                cout<<"vazio";
            cout<<"\n";
        }

        void vizualizarPreOrdem(){
            cout<<"Pre Ordem: ";
            if(this->raiz)
            preOrdem(this->raiz);
            else 
                cout<<"vazio";
            cout<<"\n";
        }

        void vizualizarPosOrdem(){
            cout<<"Pos Ordem: ";
            if(this->raiz)
            posOrdem(this->raiz);
            else 
                cout<<"vazio";
            cout<<"\n";
        }

        
        Tipo max(No<Tipo> *inicio){
            No<Tipo> *atual = inicio, *elementoMax = 0;
            while(atual!=0){
                elementoMax = atual;
                atual = atual->direita;            
            }
            return elementoMax->valor;
        }


        Tipo min(No<Tipo> *inicio){
            No<Tipo> *atual = inicio, *elementoMin = inicio;
            while(atual!=0){
                elementoMin = atual;
                atual = atual->esquerda;            
            }
            return elementoMin->valor; 
        }

        void excluirFusao (Tipo elemento){
            excluirElementoFusao(elemento, this->raiz);
        }

        void excluirCopia (Tipo elemento){
            excluirElementoCopia(elemento, this->raiz, 0);
        }

        void excluirSimples (Tipo elemento){
            excluirElementoSimples(elemento, this->raiz, 0);
        }

        No<Tipo> excluirElementoSimples(Tipo elemento, No<Tipo> *atual, No<Tipo> *anterior = 0){
            if(atual!=0){
                if (elemento==atual->valor){
                    if (atual == this->raiz){
                        this->raiz = 0;    
                    }else{    
                        if(anterior->valor <= atual->valor){
                            anterior->direita = 0;
                        }else{
                            anterior->esquerda = 0;
                        }
                    }
                }

                else if(elemento < atual->valor){
                    excluirElementoSimples(elemento, atual->esquerda, atual);
                }
                else{
                    excluirElementoSimples(elemento, atual->direita, atual);
                }
            }

        }

        void excluirElementoFusao(Tipo elemento, No<Tipo> *raiz){
            if (raiz==0){
                cout<<"vazio";
            }else{
                No<Tipo> *atual, *anterior, *auxiliar;
                atual = raiz;
                while(1){
                    if (atual->valor==elemento){
                        if(atual->esquerda && atual->direita){
                            auxiliar = atual->direita;
                            if (anterior->valor > atual->valor){
                                anterior->esquerda = atual->esquerda;
                            }else anterior->direita = atual->esquerda;
                            atual = atual->esquerda;
                            while(1){
                                if(atual == 0){
                                    if (anterior->valor>auxiliar->valor){
                                        anterior->esquerda = auxiliar;
                                    }else anterior->direita = auxiliar;
                                    break;
                                }else anterior = atual;
                                if(atual->valor<auxiliar->valor){
                                    atual = atual->direita;
                                }else atual = atual->direita;
                            }


                        }else if (atual->direita){
                            if (anterior->valor > atual->valor){
                                anterior->esquerda = atual->direita;
                            }else anterior->direita = atual->direita; 
                        }else if (atual->esquerda){
                            if (anterior->valor > atual->valor){
                                anterior->esquerda = atual->esquerda;
                            }else anterior->direita = atual->esquerda; 
                        }else{
                            if (anterior->valor > atual->valor){
                                anterior->esquerda = 0;
                            }else anterior->direita = 0;    
                        }    
                        break;
                    }else if(atual!=0){
                        anterior = atual;
                        if(atual->valor>elemento){
                            atual = atual->esquerda;
                        }
                        else if(atual->valor < elemento){
                            atual = atual->direita;
                        }   
                    }else break;    

                }



            }
        
        }

        No<Tipo> excluirElementoCopia(Tipo elemento, No<Tipo> *atual, No<Tipo> *anterior = 0){
            if(atual!=0){
                if (elemento==atual->valor){
                    cout<<"excluindo: "<<elemento<<"  ";
                    // 2
                    if(atual->esquerda != 0 && atual->direita != 0){
                        cout<<"-2-\n";
                        Tipo valor = min(atual->direita);
                        atual->valor = valor;
                        excluirElementoCopia(valor, atual->direita, atual);
                    }
                    // 1 dir
                    else if(atual->direita != 0){
                        cout<<"1-\n";
                        if (atual->valor < anterior->valor){
                            anterior->esquerda = atual->direita;
                        }else{
                            anterior->direita = atual->direita;
                        }
                    }
                    // 1 esq
                    else if(atual->esquerda != 0){
                        cout<<"-1\n";
                        if (atual->valor < anterior->valor){
                            anterior->esquerda = atual->esquerda;
                        }else{
                            anterior->direita = atual->esquerda;
                        }

                    }
                    // 0 -ok 
                    else{
                        cout<<"-0-\n";
                        if (atual == this->raiz){
                            this->raiz = 0;    
                        }else{    
                            if(anterior->valor <= atual->valor){
                                anterior->direita = 0;
                            }else{
                                anterior->esquerda = 0;
                            }
                        }
                    }



                }
                else if(elemento < atual->valor){
                    excluirElementoCopia(elemento, atual->esquerda, atual);
                }
                else{
                    excluirElementoCopia(elemento, atual->direita, atual);
                }
            }

        }

};


    
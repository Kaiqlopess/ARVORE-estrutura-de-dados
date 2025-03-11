#include <iostream>

using namespace std;

class No{
	public:
		int dado;
		No* direita;
		No* esquerda;
		
		No(int d){
			dado = d;
			direita = NULL;
			esquerda = NULL;
		}
};

class Arvore{
	private:
		No* raiz;
		
		void imprimirArvore(No* no, int nivel){
			if(no == NULL){
				return;
			}
			
			imprimirArvore(no->direita, nivel + 1);
			
			for(int i = 0; i < nivel; i++){
				cout << "   ";
			}
			
			cout << no->dado << endl;
			
			imprimirArvore(no->esquerda, nivel + 1);
		}
		
	public:
		Arvore(){
			raiz = NULL;
		}
	
		void inserir(int d){
			No* novoNo = new No(d);
			
			if(raiz == NULL){
				raiz = novoNo;
				return;
			}
			
			No* temp = raiz;
			No* pai = NULL;
			
			while(temp != NULL){
				pai = temp;
				
				if(d < temp->dado){
					temp = temp->esquerda;
				}else{
					temp = temp->direita;
				}	
			}
			
			if(d < pai->dado){
				pai->esquerda = novoNo;
			}else{
				pai->direita = novoNo;
			}	
		}
		
		void imprimir(){
			imprimirArvore(raiz,0);
		}
		
		void remover(int d){
			if(raiz == NULL){
				cout << "Arvore vazia, nao tem nada pra remover" << endl;
				return;
			}
			
			No* temp = raiz;
			No* pai = NULL;
			
			while(temp != NULL && temp->dado != d){
				pai = temp;
				
				if(d < temp->dado){
					temp = temp->esquerda;
				}else{
					temp = temp->direita;
				}	
			}
			
			if(temp == NULL){
				cout << "Item " << d << " nao encontado na arvore!" << endl;
				return;
			}
			
			
			cout << "temp: " << temp->dado << endl;
			
			if(temp->esquerda == NULL && temp->direita == NULL){
				cout << temp->dado << " deletado!" << endl;
				
				if(raiz->dado == d){
					raiz = NULL;
				}else if(d < pai->dado){
					pai->esquerda = NULL;
				}else{
					pai->direita = NULL;
				}
				
				delete temp;
				return; 
			}
			
			if(temp->esquerda == NULL || temp->direita == NULL){
				cout << temp->dado << " deletado!" << endl;
				
				No* filho = NULL;
				
				if(temp->esquerda == NULL){
					filho = temp->direita;
				}else{
					filho = temp->esquerda;
				}
				
				if(raiz->dado == d){
					raiz = filho;
				}else if(pai->dado < d){
					pai->direita =  filho;
				}else{
					pai->esquerda =  filho;
				}
			   
			   delete temp;
			   return;
			}
			
			if(temp->esquerda != NULL && temp->direita != NULL){
				cout << temp->dado << " deletado!" << endl;
				
				No* filho = temp->direita;
				No* antecessorFilho = temp;
				
				while(filho->esquerda != NULL){
					antecessorFilho = filho;
					filho = filho->esquerda;
				}
				
				cout << antecessorFilho->dado << " af!" << endl;
				cout << temp->dado << " temp!" << endl;
				cout << filho->dado << " filho!" << endl;
				
				cout <<  endl;
				temp->dado = filho->dado;
				
				cout << antecessorFilho->dado << " af!" << endl;
				cout << temp->dado << " temp!" << endl;
					
				if(antecessorFilho == temp){
					antecessorFilho->direita = filho->direita;
				}else{
					antecessorFilho->esquerda = filho->direita;
				}
                
            	
				delete filho;
				return;
			}		
		}
		
		bool busca(int d){
				if(raiz == NULL){
					cout << "Arvore vazia" << endl;
					return false;
				}
				
				No* temp = raiz;
				
				while(temp != NULL && temp->dado != d){
					if(d < temp->dado){
						temp = temp->esquerda;
					}else{
						temp = temp->direita;
					}
				}
				
				if(temp == NULL){
					cout << d << " nao encontrado" << endl;
					return false;
				}
				
				cout << temp->dado << " encontrado" << endl;
				
				return true;
			    }
};

int main(int argc, char** argv){
	Arvore a;
	
	a.inserir(5);
	a.inserir(4);
	a.inserir(8);
	a.inserir(6);	
		
    a.imprimir();
	
	a.remover(5);
	
	a.imprimir();
	
	a.busca(6);


	return 0;
}

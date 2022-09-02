#include <iostream>
#include <vector>

#define MAX 50

using namespace std;
//template<class T>

class Fila{ 
// se utiliza static para poder guardar el valor despues de ser usado y su valor no sea reseteado 
static int numFilas;
static int tamanho;
int N=0;
int fila[MAX];

public:
    
    Fila(const Fila &obj) { //obj == es hace referencia a un nuevo objeto creado en la clase Fila 
        this->numFilas = obj.numFilas; //construtor de copia 
        this->tamanho += obj.N ;//this es la forma que se utiliza para referirse al objeto al que se está aplicando el operador como primer operando.
        numFilas++;
    }
    Fila() { //obj == es hace referencia a un nuevo objeto creado en la clase Fila 
        numFilas++;
    }

    ~Fila(){
       this->tamanho  = tamanho -N ;
        numFilas--;
    }

    void enqueue(int elemento){ 
    if(N < MAX){
            fila[N] = elemento;
            N++;
            tamanho++;
        }else{
            throw -1; //exeption
        }
    }

    int dequeue(){
        int indice = N;
    if (indice < 0 ) {//|| indice >= N
            throw -2;//exeption
        }
        int valor = fila[indice];
        fila[indice] = fila[indice+1];
        N--;
        tamanho--;
    return valor;
    }

    Fila *operator=(Fila &obj){ //sobrecarga operador de atribucao 
    this->tamanho = tamanho - N ;
     this->tamanho += obj.N ;
    return &obj;
    }

//método estático stats() 
    static void stats(){
        //imprime ao usuário a quantidade de filas existentes no momento da chamada
        cout<<"ha " << numFilas  << " filas com tamanho total "<< tamanho <<endl;
    }

};

int Fila::tamanho = 0;
int Fila::numFilas = 0;

int main(int argc, char const *argv[]){

Fila::stats();
Fila *a = new Fila();
for (int i=0;i<4;i++) a->enqueue(i);

Fila b = (*a);
Fila::stats();

b. enqueue (4);
b. enqueue (5);
Fila c = (*a);
Fila::stats();

c = b;
Fila::stats();

int x = c.dequeue();
delete a;
Fila::stats();

return 0;
}

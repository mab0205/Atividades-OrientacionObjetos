#include <iostream>
#include <vector>
#include <iomanip> 

using namespace std;

class Tradicional {
    double total;
protected:
    int cantidad;
    string tipo;
public:
    Tradicional (int X, string Y) : cantidad(X), tipo(Y){}
    virtual void setValorBuque(){
        total=cantidad*2;
   }
   virtual double getValorBuque(){
        return total;
   }
   virtual int getCantidad(){
       return cantidad;
   }
   virtual string getTipo(){
       return tipo;
   }
    
};

class Especial : public Tradicional {
double total;

public:
    Especial (int x, string Y): Tradicional(x, Y){} 
     void setValorBuque(){
        int decimal = (cantidad - (cantidad % 10)) / 10;
        int contador = 5;
        for ( int i=0 ; i < decimal; i++) contador += 5;
         total = (cantidad*2) + contador;
  }
    double getValorBuque(){
        return total;
   }
   int getCantidad(){
       return cantidad;
   }
    string getTipo(){
       return tipo;
   }
    
};

int main(){
    vector<Tradicional*> itens;
    vector<string> opcao;
    vector<double> cantidad;
    string texto;
    int num, num_opcao, i = 0, j=0 ,  TotRosas = 0;
    double totPagar = 0 ;
    cin >> texto >> num;
    opcao.push_back (texto);
    cantidad.push_back (num);

     while(texto.compare("fim") != 0){
        cin >> texto; 
        if(texto.compare("fim") == 0){
            opcao.push_back (texto);
        }else {
        cin >> num;
        opcao.push_back (texto);
        cantidad.push_back (num);
        }
    }

    //cout << cantidad.size()<< endl;

    do{
    if (opcao[i].compare("tradicional") == 0){
        num_opcao = 1;
    }else if (opcao[i].compare("especial") == 0 ){
        num_opcao = 2;
    }else {
        num_opcao = 3;
    }
    switch (num_opcao){
    case 1:
        itens.push_back(new Tradicional(cantidad[i],opcao[i]));
        itens[i]->setValorBuque();
        break;
    case 2:
        itens.push_back(new Especial(cantidad[i],opcao[i]));
        itens[i]->setValorBuque();
        break;
    }
    i++;

}while (opcao[i].compare("fim") != 0);

//>>>>>>>>>>>>> Prints >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

    cout << "Total: " << itens.size()<< " pedidos"<< endl;

    for(int k=0; k<itens.size(); k++) {
    cout << "Pedido "<< k+1 <<": R$ ";
    cout << fixed << setprecision(2) << itens[k]->getValorBuque() << endl;
    totPagar +=  itens[k]->getValorBuque();
    TotRosas += itens[k]->getCantidad();
    }
    cout << "Total de rosas: " << TotRosas << endl;  
    cout << "Valor total: R$ " << fixed << setprecision(2) << totPagar << endl;   
    
    return 0;
}

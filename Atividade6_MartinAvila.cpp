#include <iostream>
#include <vector>
#include <set>
#include <iomanip> 

using namespace std;

int main(){
set<int> conjunto;
char simbolo;
int num= 0;
int aux=0;
    while(simbolo != '*'){
        cin >> simbolo ;

        if (simbolo == '+'){
            cin >> num;
           conjunto.insert(num);
        }else if (simbolo == '-'){
            cin >> num;
            int removido = conjunto.erase(num);
        }else if (simbolo == '?'){
            cin >> num;
            set<int>::iterator it = conjunto.find(num);
            if (it != conjunto.end())cout << "Sim" <<endl;
                else cout << "Nao" <<endl;
        }else if (simbolo == '>'){
            for (set<int>::iterator it = conjunto.begin(); it != conjunto.end(); it++){
                aux = 0;
                if (*it > aux) aux = *it;
            }
            cout << aux << endl;
        } else if (simbolo == '<'){
            set<int>::iterator it = conjunto.begin();
            aux = *it;
            for (it; it != conjunto.end(); it++){
                if (*it < aux) aux = *it;
            }
            cout << aux << endl;
        } else {
            for (set<int>::iterator it = conjunto.begin(); it != conjunto.end(); it++){
                cout<< *it << " ";
            }

        }
    
    }

    return 0;
}

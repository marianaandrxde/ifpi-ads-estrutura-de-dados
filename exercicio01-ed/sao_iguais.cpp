#include <iostream>
using namespace std;

string f1;
string f2;

int main()
{
    cout<<"Palavra 1: ";
    cin>>f1;
    cout<<"Palavra 2: ";
    cin>>f2;

    // verifica o tamanho de cada palavra
    int tamanho1 = f1.length();
    int tamanho2 = f2.length();

    // verifica se são equivalentes
    if (tamanho1 != tamanho2){
        cout<<"São diferentes" << endl;
        return 0;

    } else {
        for (int i = 0; i < tamanho1; i++){
            if (f1[i] != f2[i]){
                cout<<"São diferentes" << endl;
                return 0;
            }
        }
    }

    cout<<"São iguais" << endl;

    return 0;
}

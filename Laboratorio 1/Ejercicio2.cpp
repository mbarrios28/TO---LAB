#include <iostream>
using namespace std;

int main (){
    int n = 10;
    int array [n];
    int menor = 0;
    for (int i = 0; i < n; i++){
        int mayor = 0;
        cout << "Ingrese un número: ";
        cin >> mayor;
        cout << endl;
        if (mayor < menor){
            cout << "El número tiene que ser mayor que: " << menor << endl;
            i--;
        } else {
            array[i] = mayor;
            menor = mayor;
        }
    }
    cout << "El arreglo es: [";
    for (int num: array){
        cout << "," << num;
    }
    cout << "]";
    return 0;
}
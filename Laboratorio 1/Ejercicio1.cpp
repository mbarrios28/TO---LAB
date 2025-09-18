#include <iostream>
using namespace std;

int main (){
    int n = 0;
    cout << "Ingrese la cantidad de datos del arreglo: ";
    cin >> n;
    cout << endl;
    int array [n];
    for (int i = 0; i < n; i++){
        int num = 0;
        cout << "Ingresa un número: ";
        cin >> num;
        array[i] = num;
    }
    int suma = 0;
    for (int num: array){
        suma += num;
    }
    cout << "La suma de este arreglo es: " << suma;
    return 0;
}
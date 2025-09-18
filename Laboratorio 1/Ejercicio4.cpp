#include <iostream>
using namespace std;

double menor3 (double num1, double num2, double num3){
    double menor = num1;
    if (menor > num2){
        menor = num2;
    }
    if (menor > num3){
        menor = num3;
    }
    return menor;
}
int main (){
    double num1, num2, num3 = 0.0;
    cout << "Ingrese un número: ";
    cin >> num1;
    cout << endl;
    cout << "Ingrese un número: ";
    cin >> num2;
    cout << endl;
    cout << "Ingrese un número: ";
    cin >> num3;
    cout << endl;
    double menor = menor3(num1, num2, num3);
    cout << "El menor de los 3 números es: " << menor << endl;
    return 0;
}
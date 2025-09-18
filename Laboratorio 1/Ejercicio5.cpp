#include <iostream>
using namespace std;

int main (){
    int horas = 0;
    cout << "Ingrese el número de horas: ";
    cin >> horas;
    double factura = 3+(horas-1)*0.5;
    if (factura > 12){
        factura = 12;
    }
    cout << endl << "La factura es: " << factura;
    return 0;
}
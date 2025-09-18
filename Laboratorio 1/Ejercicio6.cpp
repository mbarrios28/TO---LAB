#include <iostream>
using namespace std;

int main (){
    int horas, minutos, segundos = 0;
    cout << "Ingrese las horas: ";
    cin >> horas;
    cout << endl << "Ingrese los minutos: ";
    cin >> minutos;
    cout << endl << "Ingrese los segundos: ";
    cin >> segundos;
    int tiempo = horas*3600 + minutos*60 + segundos;
    cout << endl << "El tiempo en segundos es: " << tiempo;
}
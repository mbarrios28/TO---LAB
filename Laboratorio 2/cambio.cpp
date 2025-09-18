#include <iostream>
using namespace std;

int countCambio(int dinero, int i, int cambios[], int n) {
    if (dinero == 0) {
        return 1;
    } else if (dinero < 0 || i >= n) {
        return 0;
    }
    int usar = countCambio(dinero - cambios[i], i, cambios, n);
    int noUsar = countCambio(dinero, i + 1, cambios, n);

    return usar + noUsar;
}

int main() {
    int n = 0;
    int dinero = 0;
    cout << "Ingrese la cantidad de dinero para hacer un cambio: ";
    cin >> dinero;
    cout << "Ingrese la cantidad de monedas disponibles: ";
    cin >> n;

    int cambios[n];
    cout << "Ingrese las monedas de mayor a menor: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> cambios[i];
    }

    int formas = countCambio(dinero, 0, cambios, n);
    cout << "Número de formas de cambio: " << formas << endl;

    return 0;
}

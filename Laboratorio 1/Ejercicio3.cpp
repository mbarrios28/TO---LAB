#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main (){
    srand(time(NULL));
    int array[] = {0,0,0,0,0,0};
    for (int i = 0; i < 20000; i++){
        int dado= 1 + (rand() % (6));
        array[dado-1]++;
    }
    for (int i = 0; i < 6; i++){
        cout << "La frecuencia de " << i+1 << " es: " << array[i] << endl;
    }
    return 0;
}
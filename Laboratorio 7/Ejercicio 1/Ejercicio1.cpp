#include <iostream>
#include <memory>

using namespace std;

class Configuracion {
    private: 
        static unique_ptr <Configuracion> configuracion;
        string zona_horaria;
        string idioma;
        int brillo;
        int sonido;

        Configuracion(string zona_horaria, string idioma, int brillo, int sonido){
            this->zona_horaria = zona_horaria;
            this->idioma = idioma;
            this->brillo = brillo;
            this->sonido = sonido;
        }
    public:
        static Configuracion& iniciarConfiguracion(string z, string i, int b, int s){
            if (!configuracion){
                configuracion.reset(new Configuracion(z, i, b, s));
            }
            return *configuracion;
        }

        void mostrar_configuracion(){
            cout << "Zona horaria: " + zona_horaria << endl;
            cout << "Idioma: " + idioma << endl;
            cout << "Brillo: " + brillo << endl;
            cout << "Sonido: " + sonido << endl;
        }
};

unique_ptr <Configuracion> Configuracion::configuracion = nullptr;

int main(){
    Configuracion& conf1 = Configuracion::iniciarConfiguracion("GMT-5","Español",25,50);
    conf1.mostrar_configuracion();

    Configuracion& conf2 = Configuracion::iniciarConfiguracion("GMT-6","Ingles",40,20);
    conf2.mostrar_configuracion();

    Configuracion& conf3 = Configuracion::iniciarConfiguracion("GMT-2","Frances",80,70);
    conf3.mostrar_configuracion();
}
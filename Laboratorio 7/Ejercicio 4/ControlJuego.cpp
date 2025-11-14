#include <iostream>
#include <memory>

using namespace std;

class ControlJuego {
private:
    static unique_ptr<ControlJuego> control;
    int nivel_actual;
    int puntaje;
    int vida;

    ControlJuego(int puntaje, int vida) {
        this->nivel_actual = 1;
        this->puntaje = puntaje;
        this->vida = vida;
    }
    ControlJuego() {
        nivel_actual = 1;
        puntaje = 0;
        vida = 0;
    }

public:
    static ControlJuego& iniciarControl(int p, int v) {
        if (!control) {
            control.reset(new ControlJuego(p, v));
        }
        return *control;
    }

    static ControlJuego& iniciarControl() {
        if (!control) {
            control.reset(new ControlJuego());
        }
        return *control;
    }

    void mostrar_estado() {
        cout << "Nivel actual: " << nivel_actual << endl;
        cout << "Puntaje: " << puntaje << endl;
        cout << "Vidas: " << vida << endl;
    }

    void subir_nivel() {
        cout << endl << "Has subido de nivel" << endl;
        cout << "Ahora tu nivel es: " << ++nivel_actual << endl;
        vida = vida + 50;
        cout << "Tu vida ha incrementado, ahora tienes " << vida << endl;
    }

    void recibir_ataque(int n, string nombre) {
        this->vida -= n;
        cout << endl << "Recibiste " << n << " puntos de daño de " << nombre << endl;
        if (vida <= 0) {
            morir();
            return;
        }
        cout << "Ahora tienes: " << vida << " puntos de vida" << endl;
    }

    void curar(int n) {
        this->vida += n;
        cout << endl << "Te has curado " << n << endl;
        cout << "Tu vida actual es: " << vida << endl;
    }

    void subir_puntaje(int n) {
        this->puntaje = puntaje + n;
        cout << endl << "Aumentaste tu puntaje en: " << n << endl;
        cout << "Tu puntaje ahora es de: " << puntaje << endl;
        if (puntaje >= 500 * nivel_actual) {
            subir_nivel();
        }
    }

    void morir() {
        cout << endl << "Te has quedado sin vida" << endl;
        control.reset();
    }
};

unique_ptr<ControlJuego> ControlJuego::control = nullptr;

class Entidad {
private:
    string nombre;
    int ataque;

public:
    Entidad(string nombre, int ataque) {
        this->nombre = nombre;
        this->ataque = ataque;
    }

    string getNombre() {
        return nombre;
    }

    int getAtaque() {
        return ataque;
    }
};

class Enemigo : public Entidad {
private:
    bool vivo;
    int vida;

public:
    Enemigo(string nombre, int ataque, int vida) : Entidad(nombre, ataque) {
        this->vida = vida;
        this->vivo = true;
    }

    void atacar() {
        ControlJuego& jugador = ControlJuego::iniciarControl();
        jugador.recibir_ataque(getAtaque(), getNombre());
    }

    void recibir_ataque(int n) {
        vida -= n;
        cout << endl << "El enemigo " << getNombre() << "ha recibido " << n << " daño" << endl;
        if (vida <= 0) {
            vivo = false;
            cout << endl << "El enemigo " << getNombre() << " ha muerto" << endl;
            vida = 0;
            return;
        }
        cout << "Ahora tiene: " << vida << " puntos de vida" << endl;
    }

    bool getEstado() {
        return vivo;
    }

    void mostar_estado(){
        cout << endl <<"Nombre enemigo: " << getNombre() << endl;
        cout <<"Vida enemigo: " << vida << endl;
        cout <<"Ataque enemigo: " << getAtaque() << endl;
        if (vivo){
            cout << "El enemigo está vivo" << endl;
        } else {
            cout << "El enemigo está muerto" << endl;
        }
    }
};

class Jugador : public Entidad {
public:
    Jugador(string nombre, int ataque) : Entidad(nombre, ataque) {}

    void atacar(Enemigo& enemigo) {
        enemigo.recibir_ataque(Entidad::getAtaque());
        if (!enemigo.getEstado()) {
            ControlJuego& jugador = ControlJuego::iniciarControl();
            jugador.subir_puntaje(300);
        }
    }

    void mostrar_estado(){
        cout << endl <<"Nombre jugador: " << getNombre() << endl;
        ControlJuego& jugador = ControlJuego::iniciarControl();
        jugador.mostrar_estado();
        cout << "Ataque jugador: " << getAtaque() << endl;
    }
};

class Interfaz {
private:
    int curacion;
    int puntaje;

public:
    Interfaz(int curacion) {
        this->curacion = curacion;
        this->puntaje = 150;
    }

    void curar() {
        ControlJuego& jugador = ControlJuego::iniciarControl();
        cout << endl << "El jugador ha usado la interfaz para curarse" << endl;
        jugador.curar(curacion);
    }

    void subir_puntaje() {
        ControlJuego& jugador = ControlJuego::iniciarControl();
        cout << endl << "El jugador ha usado la interfaz para aumentar su puntaje" << endl;
        jugador.subir_puntaje(puntaje);
    }
};

int main() {
    // Inicializamos el ControlJuego con vidas y puntaje inicial
    ControlJuego& control = ControlJuego::iniciarControl(0, 200);
    
    cout << "==== ESTADO INICIAL DEL JUEGO ====" << endl;
    control.mostrar_estado();

    // Crear jugador y enemigo
    Jugador jugador("Heroe", 120);
    Enemigo enemigo("Goblin", 40, 150);

    jugador.mostrar_estado();
    enemigo.mostar_estado();

    enemigo.atacar();
    jugador.mostrar_estado();
    enemigo.mostar_estado();

    jugador.atacar(enemigo);
    jugador.mostrar_estado();
    enemigo.mostar_estado();

    jugador.atacar(enemigo);
    jugador.mostrar_estado();
    enemigo.mostar_estado();

    Interfaz interfaz(50);
    interfaz.curar();
    jugador.mostrar_estado();

    interfaz.subir_puntaje();
    jugador.mostrar_estado();

    interfaz.subir_puntaje();
    jugador.mostrar_estado();

    cout << endl << "==== ESTADO FINAL DEL JUEGO ====" << endl;
    control.mostrar_estado();

    return 0;
}


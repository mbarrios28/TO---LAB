#include <iostream>
#include <functional>
#include <cmath>
#include <stdexcept>
#include <iomanip>
#include <string>
#include <map>

// Clase para manejar excepciones personalizadas de integrales
class IntegracionException : public std::exception {
private:
    std::string mensaje;
public:
    explicit IntegracionException(const std::string& msg) : mensaje(msg) {}
    const char* what() const noexcept override {
        return mensaje.c_str();
    }
};


class MetodoTrapecio {
private:
    double a, b;  // Límites de integración
    int n;        // Número de trapecios
    
    // Función para calcular el ancho de cada trapecio (Inline)
    inline double calcularH() const {
        return (b - a) / n;
    }
    
    // Función para imprimir resultados (friend, implementada fuera de la clase)
    friend std::ostream& operator<<(std::ostream& os, const MetodoTrapecio& mt);

public:
    // Manejo de excepciones en el constructor
    MetodoTrapecio(double limite_a, double limite_b, int num_trapecios) 
        : a(limite_a), b(limite_b), n(num_trapecios) {
        if (a >= b) {
            throw IntegracionException("Error: El límite inferior debe ser menor que el superior");
        }
        if (n <= 0) {
            throw IntegracionException("Error: El número de trapecios debe ser positivo");
        }
    }
    
    /* 
        Para reutilizar código se usan funciones genéricas, o en c++ templates,
        con ello podemos tener cualquier clase de función y aplicar estos métodos.
    */
    template<typename Funcion>
    double integrar(Funcion f) const {
        try {
            double h = calcularH(); // Calcula el ancho de cada trapecio
            double suma = 0.0; // Suma de los f(x) intermedios
            
            // Evaluar los puntos intermedios
            for (int i = 1; i < n; i++) {
                double x = a + i * h;
                double fx = f(x);
                
                // Verificar si el resultado es válido
                if (std::isnan(fx) || std::isinf(fx)) {
                    throw IntegracionException("Error: La función produce valores inválidos (NaN o Inf)");
                }
                suma += fx;
            }
            
            // Evaluar extremos
            double fa = f(a);
            double fb = f(b);
            
            if (std::isnan(fa) || std::isinf(fa) || std::isnan(fb) || std::isinf(fb)) {
                throw IntegracionException("Error: La función produce valores inválidos en los extremos");
            }
            
            // Fórmula del trapecio: h/2 * [f(a) + 2*suma + f(b)]
            return (h / 2.0) * (fa + 2.0 * suma + fb);
            
        } catch (const std::exception& e) {
            throw IntegracionException(std::string("Error durante la integración: ") + e.what());
        }
    }
    
    // Sobrecarga del operador () para usar el objeto como functor
    template<typename Funcion>
    double operator()(Funcion f) const {
        return integrar(f);
    }
    
    // Getters const
    double getLimiteInferior() const { 
        return a; 
    }
    double getLimiteSuperior() const { 
        return b; 
    }
    int getNumTrapecios() const { 
        return n; 
    }
};

// Implementación del método friend
std::ostream& operator<<(std::ostream& os, const MetodoTrapecio& mt) {
    os << "Método del Trapecio [a=" << mt.a << ", b=" << mt.b 
       << ", n=" << mt.n << ", h=" << mt.calcularH() << "]";
    return os;
}

// Clase con funciones estáticas predefinidas
class Funciones {
public:
    static inline double cuadratica(double x) {
        return x * x;
    }
    
    static inline double cubica(double x) {
        return x * x * x;
    }
    
    static inline double seno(double x) {
        return std::sin(x);
    }
    
    static inline double coseno(double x) {
        return std::cos(x);
    }
    
    static inline double exponencial(double x) {
        return std::exp(x);
    }
    
    static inline double logaritmo(double x) {
        if (x <= 0) throw std::domain_error("Logaritmo de número no positivo");
        return std::log(x);
    }
    
    static inline double raizCuadrada(double x) {
        if (x < 0) throw std::domain_error("Raíz cuadrada de número negativo");
        return std::sqrt(x);
    }
    
    static inline double inverso(double x) {
        if (x == 0) throw std::domain_error("División por cero");
        return 1.0 / x;
    }
    
    static inline double tangenteHiperbolica(double x) {
        return std::tanh(x);
    }
};

// Función para mostrar el menú
void mostrarMenu() {
    std::cout << "\nSeleccione la función a integrar:" << std::endl;
    std::cout << "  1. Función cuadrática" << std::endl;
    std::cout << "  2. Función cúbica" << std::endl;
    std::cout << "  3. Función Seno" << std::endl;
    std::cout << "  4. Función Coseno" << std::endl;
    std::cout << "  5. Función Exponencial" << std::endl;
    std::cout << "  6. Función Logaritmo natural" << std::endl;
    std::cout << "  7. Función Raíz cuadrada" << std::endl;
    std::cout << "  8. Función Inverso" << std::endl;
    std::cout << "  9. Función Tangente hiperbólica" << std::endl;
    std::cout << "  0. Salir" << std::endl;
    std::cout << "\nOpción: ";
}

// Función para leer un número double con validación
double leerDouble(const std::string& prompt) {
    double valor;
    while (true) {
        std::cout << prompt;
        if (std::cin >> valor) {
            std::cin.ignore(10000, '\n');
            return valor;
        } else {
            std::cout << "Error: Debe ingresar un número válido." << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
    }
}

// Función para leer un número entero con validación
int leerInt(const std::string& prompt) {
    int valor;
    while (true) {
        std::cout << prompt;
        if (std::cin >> valor) {
            std::cin.ignore(10000, '\n');
            return valor;
        } else {
            std::cout << "Error: Debe ingresar un número entero válido." << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
    }
}

int main() {
    std::map<int, std::function<double(double)>> funciones = {
        {1, Funciones::cuadratica}, 
        {2, Funciones::cubica},
        {3, Funciones::seno},       
        {4, Funciones::coseno},
        {5, Funciones::exponencial},
        {6, Funciones::logaritmo},
        {7, Funciones::raizCuadrada},
        {8, Funciones::inverso},
        {9, Funciones::tangenteHiperbolica}
    };
    
    std::map<int, std::string> nombres = {
        {1, "Función cuadrática"},
        {2, "Función cúbica"},
        {3, "Seno"},
        {4, "Coseno"},
        {5, "Exponencial"},
        {6, "Logaritmo natural"},
        {7, "Raíz cuadrada"},
        {8, "Inverso"},
        {9, "Tangente hiperbólica"}
    };

    while (true) {
        mostrarMenu();
        int opcion = leerInt("");
        if (opcion == 0) break;
        if (funciones.count(opcion) == 0) {
            std::cout << "Opción no válida.\n";
            continue;
        }

        try {
            double a = leerDouble("Ingrese el límite inferior: ");
            double b = leerDouble("Ingrese el límite superior: ");
            int n = leerInt("Ingrese el número de trapecios: ");

            MetodoTrapecio trapecio(a, b, n);
            double resultado = trapecio(funciones[opcion]);

            std::cout << std::fixed << std::setprecision(6);
            std::cout << "\n" << nombres[opcion]
                      << " integrada en [" << a << ", " << b 
                      << "] = " << resultado << "\n";
        }
        catch (const std::exception& e) {
            std::cout << "\n" << e.what() << "\n";
        }
    }

    std::cout << "\nPrograma finalizado.\n";
    return 0;
}

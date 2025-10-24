#include <iostream>
#include <functional>
#include <cmath>
#include <stdexcept>
#include <iomanip>

// Clase para manejar excepciones personalizadas
class IntegracionException : public std::exception {
private:
    std::string mensaje;
public:
    explicit IntegracionException(const std::string& msg) : mensaje(msg) {}
    const char* what() const noexcept override {
        return mensaje.c_str();
    }
};

// Clase principal para el método del trapecio
class MetodoTrapecio {
private:
    double a, b;  // Límites de integración
    int n;        // Número de trapecios
    
    // Función inline para calcular el ancho de cada trapecio
    inline double calcularH() const {
        return (b - a) / n;
    }
    
    // Función friend para imprimir resultados
    friend std::ostream& operator<<(std::ostream& os, const MetodoTrapecio& mt);

public:
    // Constructor con validación
    MetodoTrapecio(double limite_a, double limite_b, int num_trapecios) 
        : a(limite_a), b(limite_b), n(num_trapecios) {
        if (a >= b) {
            throw IntegracionException("Error: El límite inferior debe ser menor que el superior");
        }
        if (n <= 0) {
            throw IntegracionException("Error: El número de trapecios debe ser positivo");
        }
    }
    
    // Método template para integrar cualquier tipo de función
    template<typename Funcion>
    double integrar(Funcion f) const {
        try {
            double h = calcularH();
            double suma = 0.0;
            
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
    double getLimiteInferior() const { return a; }
    double getLimiteSuperior() const { return b; }
    int getNumTrapecios() const { return n; }
};

// Sobrecarga del operador << para imprimir información
std::ostream& operator<<(std::ostream& os, const MetodoTrapecio& mt) {
    os << "Método del Trapecio [a=" << mt.a << ", b=" << mt.b 
       << ", n=" << mt.n << ", h=" << mt.calcularH() << "]";
    return os;
}

// Clase con funciones estáticas predefinidas
class Funciones {
public:
    // Función estática inline
    static inline double cuadratica(double x) {
        return x * x;
    }
    
    static inline double seno(double x) {
        return std::sin(x);
    }
    
    static inline double exponencial(double x) {
        return std::exp(x);
    }
};

int main() {
    std::cout << std::fixed << std::setprecision(6);
    
    try {
        // Ejemplo 1: Usando función lambda
        std::cout << "=== Ejemplo 1: Función Lambda ===" << std::endl;
        MetodoTrapecio trapecio1(0.0, 1.0, 100);
        std::cout << trapecio1 << std::endl;
        
        auto lambda = [](double x) { return x * x; };
        double resultado1 = trapecio1.integrar(lambda);
        std::cout << "Integral de x^2 en [0,1]: " << resultado1 << std::endl;
        std::cout << "Valor exacto: " << 1.0/3.0 << std::endl << std::endl;
        
        // Ejemplo 2: Usando función estática
        std::cout << "=== Ejemplo 2: Función Estática ===" << std::endl;
        MetodoTrapecio trapecio2(0.0, M_PI, 1000);
        double resultado2 = trapecio2.integrar(Funciones::seno);
        std::cout << "Integral de sen(x) en [0,π]: " << resultado2 << std::endl;
        std::cout << "Valor exacto: 2.0" << std::endl << std::endl;
        
        // Ejemplo 3: Usando std::function
        std::cout << "=== Ejemplo 3: std::function ===" << std::endl;
        std::function<double(double)> func = [](double x) { return 1.0 / (1.0 + x * x); };
        MetodoTrapecio trapecio3(0.0, 1.0, 500);
        double resultado3 = trapecio3(func);  // Usando operador()
        std::cout << "Integral de 1/(1+x²) en [0,1]: " << resultado3 << std::endl;
        std::cout << "Valor exacto (π/4): " << M_PI/4.0 << std::endl << std::endl;
        
        // Ejemplo 4: Lambda con captura
        std::cout << "=== Ejemplo 4: Lambda con Captura ===" << std::endl;
        double k = 2.0;
        auto lambdaCaptura = [k](double x) { return k * std::exp(x); };
        MetodoTrapecio trapecio4(0.0, 1.0, 200);
        double resultado4 = trapecio4(lambdaCaptura);
        std::cout << "Integral de 2*e^x en [0,1]: " << resultado4 << std::endl << std::endl;
        
        // Ejemplo 5: Manejo de excepciones - límites inválidos
        std::cout << "=== Ejemplo 5: Manejo de Excepciones ===" << std::endl;
        try {
            MetodoTrapecio trapecioInvalido(5.0, 1.0, 100);
        } catch (const IntegracionException& e) {
            std::cout << "Excepción capturada: " << e.what() << std::endl;
        }
        
        // Ejemplo 6: Función que produce valores inválidos
        try {
            MetodoTrapecio trapecio5(-1.0, 1.0, 100);
            auto funcionInvalida = [](double x) { return std::log(x); };  // log negativo
            trapecio5.integrar(funcionInvalida);
        } catch (const IntegracionException& e) {
            std::cout << "Excepción capturada: " << e.what() << std::endl;
        }
        
    } catch (const std::exception& e) {
        std::cerr << "Error no manejado: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
#include <iostream>
#include <string>
#include <memory>
#include <mutex>
using namespace std;
class ConexionBD {
private:
    static unique_ptr<ConexionBD> instancia;
    static mutex mutex;
    
    string nombreBD;
    bool conectado;
    
    ConexionBD() : nombreBD("BaseDatosPrincipal"), conectado(false) {
        std::cout << "Constructor de ConexionBD llamado" << std::endl;
    }
    
    ConexionBD(const ConexionBD&) = delete;
    ConexionBD& operator=(const ConexionBD&) = delete;

public:
    ~ConexionBD() {
        if (conectado) {
            std::cout << "Desconectando automáticamente de la BD..." << std::endl;
        }
    }
    
    static ConexionBD* obtenerInstancia() {
        std::lock_guard<std::mutex> lock(mutex);
        if (!instancia) {
            instancia = std::unique_ptr<ConexionBD>(new ConexionBD());
            std::cout << "Nueva instancia de ConexionBD creada" << std::endl;
        } else {
            std::cout << "Devolviendo instancia existente de ConexionBD" << std::endl;
        }
        return instancia.get();
    }
    
    bool conectar() {
        if (conectado) {
            cout << "Ya está conectado a la base de datos: " << nombreBD << std::endl;
            return true;
        }
        
        cout << "Conectando a la base de datos: " << nombreBD << "..." << std::endl;
        
        for (int i = 0; i < 3; ++i) {
            cout << ".";
        }
        cout << std::endl;
        
        conectado = true;
        cout << "¡Conexión exitosa a " << nombreBD << "!" << std::endl;
        return true;
    }
    
    void desconectar() {
        if (!conectado) {
            cout << "No hay conexión activa para desconectar" << std::endl;
            return;
        }
        
        cout << "Desconectando de la base de datos: " << nombreBD << "..." << std::endl;
        conectado = false;
        cout << "Desconexión completada" << std::endl;
    }
    
    void estado() const {
        cout << "Estado de la Conexión BD" << std::endl;
        cout << "Base de datos: " << nombreBD << std::endl;
        cout << "Estado: " << (conectado ? "CONECTADO" : "DESCONECTADO") << std::endl;
        cout << "Dirección de instancia: " << this << std::endl;
    }
    
    void ejecutarConsulta(const std::string& consulta) {
        if (!conectado) {
            cout << "Error: No hay conexión activa. Conecte primero a la BD." << std::endl;
            return;
        }
        
        cout << "Ejecutando consulta: " << consulta << std::endl;
        cout << "Consulta ejecutada exitosamente" << std::endl;
    }
    
    void cambiarBaseDatos(const std::string& nuevaBD) {
        if (conectado) {
            cout << "Desconectando de " << nombreBD << " antes del cambio..." << std::endl;
            desconectar();
        }
        
        nombreBD = nuevaBD;
        cout << "Base de datos cambiada a: " << nombreBD << std::endl;
    }
};

unique_ptr<ConexionBD> ConexionBD::instancia = nullptr;
mutex ConexionBD::mutex;

void demostrarSingleton() {
    
    cout << "\n1. Obteniendo primera instancia:" << std::endl;
    ConexionBD* conexion1 = ConexionBD::obtenerInstancia();
    conexion1->estado();
    
    cout << "\n2. Obteniendo segunda instancia:" << std::endl;
    ConexionBD* conexion2 = ConexionBD::obtenerInstancia();
    conexion2->estado();
    
    cout << "\n3. Verificando igualdad de instancias:" << std::endl;
    cout << "conexion1 == conexion2: " << (conexion1 == conexion2 ? "TRUE" : "FALSE") << std::endl;
    cout << "Dirección conexion1: " << conexion1 << std::endl;
    cout << "Dirección conexion2: " << conexion2 << std::endl;
}

void demostrarUsoConexion() {
    
    ConexionBD* conexion = ConexionBD::obtenerInstancia();
    
    cout << "\n1. Intentando ejecutar consulta sin conexión:" << std::endl;
    conexion->ejecutarConsulta("SELECT * FROM usuarios");
    
    cout << "\n2. Conectando a la base de datos:" << std::endl;
    conexion->conectar();
    conexion->estado();
    
    cout << "\n3. Ejecutando consultas:" << std::endl;
    conexion->ejecutarConsulta("SELECT * FROM usuarios");
    conexion->ejecutarConsulta("INSERT INTO logs (mensaje) VALUES ('Test de conexión')");
    
    cout << "\n4. Intentando conectar nuevamente:" << std::endl;
    conexion->conectar(); 
    
    cout << "\n5. Desconectando:" << std::endl;
    conexion->desconectar();
    conexion->estado();
    
    cout << "\n6. Cambiando de base de datos:" << std::endl;
    conexion->cambiarBaseDatos("BaseDatosSecundaria");
    conexion->conectar();
    conexion->estado();
}

void demostrarDesdeDiferentesPartes() {
    
    auto moduloUsuarios = []() {
        std::cout << "\n[Módulo Usuarios] Obteniendo conexión..." << std::endl;
        ConexionBD* conexion = ConexionBD::obtenerInstancia();
        conexion->conectar();
        conexion->ejecutarConsulta("SELECT nombre, email FROM usuarios");
        std::cout << "[Módulo Usuarios] Operación completada" << std::endl;
    };
    
    auto moduloProductos = []() {
        std::cout << "\n[Módulo Productos] Obteniendo conexión..." << std::endl;
        ConexionBD* conexion = ConexionBD::obtenerInstancia();
        conexion->ejecutarConsulta("SELECT * FROM productos WHERE stock > 0");
        std::cout << "[Módulo Productos] Operación completada" << std::endl;
    };
    
    auto moduloReportes = []() {
        std::cout << "\n[Módulo Reportes] Obteniendo conexión..." << std::endl;
        ConexionBD* conexion = ConexionBD::obtenerInstancia();
        conexion->estado();
        conexion->ejecutarConsulta("GENERATE REPORT ventas_mensuales");
        std::cout << "[Módulo Reportes] Operación completada" << std::endl;
    };
    
    moduloUsuarios();
    moduloProductos();
    moduloReportes();
}

int main() {
    std::cout << "CONEXIÓN A BASE DE DATOS CON PATRÓN SINGLETON" << std::endl;
    
    demostrarSingleton();
    demostrarUsoConexion();
    demostrarDesdeDiferentesPartes();
    
    
    return 0;
}
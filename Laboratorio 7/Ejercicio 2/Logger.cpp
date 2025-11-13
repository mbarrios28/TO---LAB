#include "Logger.h"

// Inicialización de la variable estática
Logger* Logger::instancia = nullptr;

Logger::Logger() : nombreArchivo("bitacora.log") {
    archivoLog.open(nombreArchivo, ios::app);
    if (!archivoLog.is_open()) {
        cerr << "Error: No se pudo abrir el archivo de log" << endl;
    } else {
        log("Logger: Sistema de registro inicializado");
    }
}

Logger* Logger::obtenerInstancia() {
    if (instancia == nullptr) {
        instancia = new Logger();
    }
    return instancia;
}

void Logger::log(const string& mensaje) {
    if (archivoLog.is_open()) {
        string horaActual = obtenerHoraActual();
        archivoLog << "[" << horaActual << "] " << mensaje << endl;
        // También mostrar en consola para verificación
        cout << "LOG: [" << horaActual << "] " << mensaje << endl;
    }
}

string Logger::obtenerHoraActual() {
    time_t ahora = time(nullptr);
    tm* tiempoLocal = localtime(&ahora);
    
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tiempoLocal);
    return string(buffer);
}

void Logger::cerrarLogger() {
    if (archivoLog.is_open()) {
        log("Logger: Cerrando sistema de registro");
        archivoLog.close();
    }
}

Logger::~Logger() {
    cerrarLogger();
}

void Logger::destruirInstancia() {
    if (instancia != nullptr) {
        delete instancia;
        instancia = nullptr;
    }
}
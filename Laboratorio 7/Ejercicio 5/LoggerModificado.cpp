#include "LoggerModificado.h"

// Inicialización CORREGIDA de las variables estáticas
atomic<Logger*> Logger::instancia{nullptr};
mutex Logger::mtx;

Logger::Logger() : nombreArchivo("bitacora.log") {
    archivoLog.open(nombreArchivo, ios::app);
    if (!archivoLog.is_open()) {
        cerr << "Error: No se pudo abrir el archivo de log" << endl;
    } else {
        log("Logger: Sistema de registro inicializado");
    }
}

Logger* Logger::obtenerInstancia() {
    // Primera verificación (sin bloqueo) - para eficiencia
    Logger* temp = instancia.load(memory_order_acquire);
    if (temp == nullptr) {
        lock_guard<mutex> lock(mtx); // Bloqueo para thread-safety
        temp = instancia.load(memory_order_relaxed);
        // Segunda verificación (con bloqueo) - double-checked locking
        if (temp == nullptr) {
            temp = new Logger();
            instancia.store(temp, memory_order_release);
        }
    }
    return temp;
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
    lock_guard<mutex> lock(mtx); // Bloqueo para thread-safety
    Logger* temp = instancia.load(memory_order_acquire);
    if (temp != nullptr) {
        delete temp;
        instancia.store(nullptr, memory_order_release);
    }
}
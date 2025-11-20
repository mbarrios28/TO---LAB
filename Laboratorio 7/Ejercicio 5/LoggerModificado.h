#ifndef LOGGERMODIFICADO_H
#define LOGGERMODIFICADO_H

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <mutex>
#include <atomic>

using namespace std;

class Logger {
private:
    static atomic<Logger*> instancia;
    static mutex mtx;
    ofstream archivoLog;
    string nombreArchivo;
    
    // Constructor privado
    Logger();
    
    // Prevenir copia y asignación
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

public:
    // Método para obtener la instancia única (THREAD-SAFE)
    static Logger* obtenerInstancia();
    
    // Método para registrar mensajes
    void log(const string& mensaje);
    
    // Método para obtener la hora actual formateada
    string obtenerHoraActual();
    
    // Método para cerrar el archivo
    void cerrarLogger();
    
    // Destructor
    ~Logger();
    
    // Método para liberar la instancia (THREAD-SAFE)
    static void destruirInstancia();
};

#endif // LOGGERMODIFICADO_H
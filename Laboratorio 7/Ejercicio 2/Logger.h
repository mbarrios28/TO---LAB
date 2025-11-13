#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

class Logger {
private:
    static Logger* instancia;
    ofstream archivoLog;
    string nombreArchivo;
    
    // Constructor privado
    Logger();
    
    // Prevenir copia y asignación
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

public:
    // Método para obtener la instancia única
    static Logger* obtenerInstancia();
    
    // Método para registrar mensajes
    void log(const string& mensaje);
    
    // Método para obtener la hora actual formateada
    string obtenerHoraActual();
    
    // Método para cerrar el archivo
    void cerrarLogger();
    
    // Destructor
    ~Logger();
    
    // Método para liberar la instancia
    static void destruirInstancia();
};

#endif // LOGGER_H
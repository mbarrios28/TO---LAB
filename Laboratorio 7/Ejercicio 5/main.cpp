#include <iostream>
#include "LoggerModificado.h"
#include "FuncionesPrueba.h"

using namespace std;

int main() {
    cout << "LOGGER SINGLETON - THREAD SAFE" << endl;
    
    // Obtener la instancia del logger
    Logger* logger1 = Logger::obtenerInstancia();
    Logger* logger2 = Logger::obtenerInstancia();
    
    // Verificar que es la misma instancia
    cout << "¿Misma instancia? " << (logger1 == logger2 ? "SI" : "NO") << endl;
    
    // Registrar mensajes desde diferentes puntos
    cout << "\nRegistrando mensajes desde main..." << endl;
    logger1->log("Main: Iniciando aplicacion");
    logger1->log("Main: Configurando sistema");
    
    cout << "\nLlamando funciones de prueba..." << endl;
    funcionPruebaA();
    funcionPruebaB();
    
    cout << "\nUsando logger desde una clase..." << endl;
    Procesador proc;
    proc.procesar();
    
    cout << "\nRegistrando mas mensajes desde main..." << endl;
    logger2->log("Main: Finalizando aplicacion");
    
    cout << "\n=== PRUEBA COMPLETADA ===" << endl;
    cout << "Revisa el archivo 'bitacora.log' para ver todos los mensajes" << endl;
    
    // Liberar memoria
    Logger::destruirInstancia();
    
    return 0;
}
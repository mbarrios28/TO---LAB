#include "FuncionesPrueba.h"

void funcionPruebaA() {
    Logger* logger = Logger::obtenerInstancia();
    logger->log("FuncionPruebaA: Iniciando proceso A");
    logger->log("FuncionPruebaA: Procesando datos...");
}

void funcionPruebaB() {
    Logger* logger = Logger::obtenerInstancia();
    logger->log("FuncionPruebaB: Iniciando proceso B");
    logger->log("FuncionPruebaB: Calculando resultados...");
}

void Procesador::procesar() {
    Logger* logger = Logger::obtenerInstancia();
    logger->log("Procesador: Iniciando procesamiento");
    logger->log("Procesador: Procesamiento completado");
}
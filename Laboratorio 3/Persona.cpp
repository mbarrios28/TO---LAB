#include "Persona.h"

Persona::Persona(const std::string& nombre, int edad) : nombre(nombre), edad(edad) {}

std::string Persona::getNombre() const { return nombre; }
void Persona::setNombre(const std::string& n) { nombre = n; }

int Persona::getEdad() const { return edad; }
void Persona::setEdad(int e) { edad = e; }

std::string Persona::toString() const {
    return "Nombre: " + nombre + ", Edad: " + std::to_string(edad);
}

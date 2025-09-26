#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include <iostream>

class Persona {
protected:
    std::string nombre;
    int edad;

public:
    Persona(const std::string& nombre, int edad);

    std::string getNombre() const;
    void setNombre(const std::string& n);

    int getEdad() const;
    void setEdad(int e);

    virtual std::string toString() const;
    virtual ~Persona() = default;
};

#endif

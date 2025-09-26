#ifndef PROFESOR_H
#define PROFESOR_H

#include "Persona.h"
#include <vector>
#include <string>
#include <iostream>

class Curso;

class Profesor : public Persona {
private:
    std::string especialidad;
    std::vector<Curso*> cursos;

public:
    Profesor(const std::string& nombre, int edad, const std::string& especialidad);

    void asignarCurso(Curso* curso);
    std::vector<Curso*> getCursos() const;

    std::string toString() const override;
};

std::ostream& operator<<(std::ostream& os, const Profesor& profesor);

#endif

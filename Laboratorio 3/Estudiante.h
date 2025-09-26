#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include "Persona.h"
#include <vector>
#include <string>
#include <iostream>

class Curso;

class Estudiante : public Persona {
private:
    std::string carrera;
    std::vector<Curso*> cursos;

public:
    Estudiante(const std::string& nombre, int edad, const std::string& carrera);

    void inscribirCurso(Curso* curso);
    std::vector<Curso*> getCursos() const;

    std::string toString() const override;
};

std::ostream& operator<<(std::ostream& os, const Estudiante& estudiante);

#endif

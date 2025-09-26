#ifndef UNIVERSIDAD_H
#define UNIVERSIDAD_H

#include "Curso.h"
#include <string>
#include <vector>
#include <iostream>

class Universidad {
private:
    std::string nombre;
    std::vector<Curso*> cursos;

public:
    Universidad(const std::string& nombre);

    std::string getNombre() const;
    void setNombre(const std::string& n);

    void agregarCurso(Curso* c);
    std::vector<Curso*> getCursos() const;

    std::string toString() const;
};

std::ostream& operator<<(std::ostream& os, const Universidad& uni);

#endif

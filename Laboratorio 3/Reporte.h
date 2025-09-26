#ifndef REPORTE_H
#define REPORTE_H

#include "Curso.h"
#include <map>
#include <string>
#include <iostream>

class Reporte {
private:
    Curso* curso;
    std::map<std::string, int> notas;

public:
    Reporte(Curso* c);

    void generarNotas();
    std::string generar() const;
    std::string toString() const;
};

std::ostream& operator<<(std::ostream& os, const Reporte& r);

#endif

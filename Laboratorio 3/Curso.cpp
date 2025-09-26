#include "Curso.h"
#include <sstream>

Curso::Curso(const std::string& nombre, const Horario& horario, Profesor* profesor)
    : nombre(nombre), horario(horario), profesor(profesor) {}

Curso::Curso(const std::string& nombre, const std::string& dia, const std::string& inicio, const std::string& fin, Profesor* profesor)
    : nombre(nombre), horario(dia, inicio, fin), profesor(profesor) {}

std::string Curso::getNombre() const { return nombre; }
void Curso::setNombre(const std::string& n) { nombre = n; }

Horario Curso::getHorario() const { return horario; }
void Curso::setHorario(const Horario& h) { horario = h; }

Profesor* Curso::getProfesor() const { return profesor; }
void Curso::setProfesor(Profesor* p) { profesor = p; }

void Curso::agregarEstudiante(Estudiante* e) {
    estudiantes.push_back(e);
}

void Curso::listarEstudiantes() const {
    std::cout << "Estudiantes en " << nombre << ":\n";
    for (const auto& est : estudiantes) {
        std::cout << "  - " << est->toString() << std::endl;
    }
}

const std::vector<Estudiante*>& Curso::getEstudiantes() const {
    return estudiantes;
}

std::string Curso::toString() const {
    std::ostringstream oss;
    oss << "Curso: " << nombre
        << ", Profesor: " << (profesor ? profesor->getNombre() : "Ninguno")
        << ", Horario: " << horario.toString();
    return oss.str();
}

std::ostream& operator<<(std::ostream& os, const Curso& c) {
    os << c.toString();
    return os;
}

#include "Profesor.h"
#include "Curso.h"

Profesor::Profesor(const std::string& nombre, int edad, const std::string& especialidad)
    : Persona(nombre, edad), especialidad(especialidad) {}

void Profesor::asignarCurso(Curso* curso) {
    cursos.push_back(curso);
}

std::vector<Curso*> Profesor::getCursos() const {
    return cursos;
}

std::string Profesor::toString() const {
    std::string info = "Profesor: " + getNombre() + ", Edad: " + std::to_string(getEdad()) + ", Especialidad: " + especialidad;
    if (!cursos.empty()) {
        info += "\n   Cursos dictados:";
        for (auto c : cursos) {
            info += "\n      - " + c->getNombre();
        }
    }
    return info;
}

std::ostream& operator<<(std::ostream& os, const Profesor& profesor) {
    os << profesor.toString();
    return os;
}

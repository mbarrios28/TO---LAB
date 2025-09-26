#include "Estudiante.h"
#include "Curso.h"

Estudiante::Estudiante(const std::string& nombre, int edad, const std::string& carrera)
    : Persona(nombre, edad), carrera(carrera) {}

void Estudiante::inscribirCurso(Curso* curso) {
    cursos.push_back(curso);
}

std::vector<Curso*> Estudiante::getCursos() const {
    return cursos;
}

std::string Estudiante::toString() const {
    std::string info = "Estudiante: " + getNombre() + ", Edad: " + std::to_string(getEdad()) + ", Carrera: " + carrera;
    if (!cursos.empty()) {
        info += "\n   Cursos inscritos:";
        for (auto c : cursos) {
            info += "\n      - " + c->getNombre();
        }
    }
    return info;
}

std::ostream& operator<<(std::ostream& os, const Estudiante& estudiante) {
    os << estudiante.toString();
    return os;
}

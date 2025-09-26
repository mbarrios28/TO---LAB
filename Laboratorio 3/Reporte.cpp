#include "Reporte.h"
#include <sstream>
#include <cstdlib>
#include <ctime>

Reporte::Reporte(Curso* c) : curso(c) {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

void Reporte::generarNotas() {
    notas.clear();
    if (curso == nullptr) return;

    for (Estudiante* e : curso->getEstudiantes()) {
        int nota = rand() % 21;
        notas[e->getNombre()] = nota;
    }
}

std::string Reporte::generar() const {
    if (curso == nullptr) return "No hay curso asociado al reporte.";

    std::ostringstream oss;
    oss << "Reporte del curso: " << curso->getNombre() << "\n";
    oss << "Profesor: " << (curso->getProfesor() ? curso->getProfesor()->getNombre() : "Ninguno") << "\n";
    oss << "Horario: " << curso->getHorario().toString() << "\n\n";
    oss << "Notas de estudiantes:\n";

    if (notas.empty()) {
        oss << "  (No se han generado notas aún)\n";
    } else {
        for (const auto& par : notas) {
            oss << "  - " << par.first << ": " << par.second << "\n";
        }
    }

    return oss.str();
}

std::string Reporte::toString() const {
    return generar();
}

std::ostream& operator<<(std::ostream& os, const Reporte& r) {
    os << r.toString();
    return os;
}

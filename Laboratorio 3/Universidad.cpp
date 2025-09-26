#include "Universidad.h"

Universidad::Universidad(const std::string& nombre) : nombre(nombre) {}

std::string Universidad::getNombre() const { return nombre; }
void Universidad::setNombre(const std::string& n) { nombre = n; }

void Universidad::agregarCurso(Curso* c) {
    cursos.push_back(c);
}

std::vector<Curso*> Universidad::getCursos() const {
    return cursos;
}

std::string Universidad::toString() const {
    std::string info = "Universidad: " + nombre + "\nCursos:\n";
    if (cursos.empty()) {
        info += "  (No hay cursos registrados)\n";
    } else {
        for (size_t i = 0; i < cursos.size(); i++) {
            info += "  - " + cursos[i]->toString() + "\n";
        }
    }
    return info;
}

std::ostream& operator<<(std::ostream& os, const Universidad& uni) {
    os << uni.toString();
    return os;
}

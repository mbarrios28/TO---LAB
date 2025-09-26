#include "Horario.h"

Horario::Horario(const std::string& dia, const std::string& inicio, const std::string& fin)
    : dia(dia), horaInicio(inicio), horaFin(fin) {}

std::string Horario::getDia() const { return dia; }
void Horario::setDia(const std::string& d) { dia = d; }

std::string Horario::getHoraInicio() const { return horaInicio; }
void Horario::setHoraInicio(const std::string& h) { horaInicio = h; }

std::string Horario::getHoraFin() const { return horaFin; }
void Horario::setHoraFin(const std::string& h) { horaFin = h; }

std::string Horario::toString() const {
    return dia + " de " + horaInicio + " a " + horaFin;
}

std::ostream& operator<<(std::ostream& os, const Horario& horario) {
    os << horario.toString();
    return os;
}

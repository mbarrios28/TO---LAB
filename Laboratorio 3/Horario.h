#ifndef HORARIO_H
#define HORARIO_H

#include <string>
#include <iostream>

class Horario {
private:
    std::string dia;
    std::string horaInicio;
    std::string horaFin;

public:
    Horario(const std::string& dia, const std::string& inicio, const std::string& fin);

    std::string getDia() const;
    void setDia(const std::string& d);

    std::string getHoraInicio() const;
    void setHoraInicio(const std::string& h);

    std::string getHoraFin() const;
    void setHoraFin(const std::string& h);

    std::string toString() const;
};

std::ostream& operator<<(std::ostream& os, const Horario& horario);

#endif

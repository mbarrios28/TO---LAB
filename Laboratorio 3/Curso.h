#ifndef CURSO_H
#define CURSO_H

#include <string>
#include <vector>
#include "Horario.h"
#include "Profesor.h"
#include "Estudiante.h"

class Curso {
private:
    std::string nombre;
    Horario horario;
    Profesor* profesor;
    std::vector<Estudiante*> estudiantes;

public:
    Curso(const std::string& nombre, const Horario& horario, Profesor* profesor);
    Curso(const std::string& nombre, const std::string& dia, const std::string& inicio, const std::string& fin, Profesor* profesor);

    std::string getNombre() const;
    void setNombre(const std::string& n);

    Horario getHorario() const;
    void setHorario(const Horario& h);

    Profesor* getProfesor() const;
    void setProfesor(Profesor* p);

    void agregarEstudiante(Estudiante* e);
    void listarEstudiantes() const;
    const std::vector<Estudiante*>& getEstudiantes() const;

    std::string toString() const;
};

std::ostream& operator<<(std::ostream& os, const Curso& c);

#endif

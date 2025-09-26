#include "Reporte.h"
#include "Universidad.h"
#include <iostream>
using namespace std;

int main() {
    Profesor p1("Carlos Pérez", 45, "Matemáticas");
    Profesor p2("Ana Gómez", 39, "Programación");
    Profesor p3("Luis Torres", 50, "Física");

    Estudiante e1("Luis Ramos", 20, "Ingeniería de Sistemas");
    Estudiante e2("María López", 21, "Ingeniería Industrial");
    Estudiante e3("Juan Torres", 19, "Matemática");
    Estudiante e4("Pedro Sánchez", 22, "Ingeniería Mecánica");
    Estudiante e5("Lucía Martínez", 20, "Ingeniería de Software");
    Estudiante e6("Andrea Castro", 18, "Física");

    Curso c1("Álgebra", "Lunes", "08:00", "10:00", &p1);
    Curso c2("Programación I", "Martes", "10:00", "12:00", &p2);
    Curso c3("Física General", "Miércoles", "14:00", "16:00", &p3);

    c1.agregarEstudiante(&e1);
    c1.agregarEstudiante(&e2);
    c1.agregarEstudiante(&e3);

    c2.agregarEstudiante(&e1);
    c2.agregarEstudiante(&e4);
    c2.agregarEstudiante(&e5);

    c3.agregarEstudiante(&e3);
    c3.agregarEstudiante(&e5);
    c3.agregarEstudiante(&e6);

    Universidad uni("Universidad Nacional de San Agustín");
    uni.agregarCurso(&c1);
    uni.agregarCurso(&c2);
    uni.agregarCurso(&c3);

    cout << "INFORMACIÓN DE LA UNIVERSIDAD" << endl;
    cout << uni << endl;

    cout << "\nREPORTES DE CURSOS" << endl;

    Reporte r1(&c1);
    r1.generarNotas();
    cout << r1 << endl;

    Reporte r2(&c2);
    r2.generarNotas();
    cout << r2 << endl;

    Reporte r3(&c3);
    r3.generarNotas();
    cout << r3 << endl;

    return 0;
}

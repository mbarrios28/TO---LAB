#include <QCoreApplication>
#include <QDebug>
#include <QVector>
#include <QRandomGenerator>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    const int cantidad = 15;
    QVector<int> numeros;
    numeros.reserve(cantidad);

    for (int i = 0; i < cantidad; ++i) {
        int valor = QRandomGenerator::global()->bounded(51);
        numeros.append(valor);
    }

    qDebug() << "Números generados:";
    for (int v : numeros) {
        qDebug() << v;
    }

    auto esImparYMenor20 = [](int n) -> bool {
        return ((n % 2) != 0) && (n < 20);
    };

    int conteo = 0;
    qDebug() << "Números impares y menores que 20: ";
    for (int n : numeros) {
        if (esImparYMenor20(n)) {
            qDebug() << n;
            ++conteo;
        }
    }

    qDebug() << "Cantidad de números impares y menores de 20:" << conteo;

    return 0;
}

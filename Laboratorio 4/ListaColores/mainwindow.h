#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Slot para cuando se selecciona un color
    void onColorSelected();

private:
    Ui::MainWindow *ui;

    // Función para inicializar la lista de colores
    void inicializarListaColores();
};

#endif // MAINWINDOW_H

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListWidgetItem>
#include <QColor>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Inicializar la lista de colores
    inicializarListaColores();

    // Conectar la señal del ListWidget al slot
    connect(ui->listWidgetColores, &QListWidget::itemClicked,
            this, &MainWindow::onColorSelected);

    // Configuración inicial
    ui->labelColorSeleccionado->setText("Selecciona un color de la lista");
    ui->labelColorSeleccionado->setAlignment(Qt::AlignCenter);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::inicializarListaColores()
{
    // Lista de colores con sus nombres en español
    QStringList colores;
    colores << "Rojo" << "Azul" << "Verde" << "Amarillo"
            << "Naranja" << "Morado" << "Rosa" << "Marrón"
            << "Gris" << "Negro" << "Blanco" << "Cian"
            << "Magenta" << "Turquesa" << "Oro" << "Plateado";

    // Agregar colores al ListWidget
    foreach (const QString &color, colores) {
        QListWidgetItem *item = new QListWidgetItem(color);
        ui->listWidgetColores->addItem(item);
    }
}

void MainWindow::onColorSelected()
{
    // Obtener el ítem seleccionado
    QListWidgetItem *item = ui->listWidgetColores->currentItem();

    if (item) {
        QString colorNombre = item->text();

        // Actualizar el Label con el color seleccionado
        ui->labelColorSeleccionado->setText("Color seleccionado:\n" + colorNombre);

        // Cambiar el color del texto según el color seleccionado
        QColor color;

        // Mapear nombres de colores a QColor
        if (colorNombre == "Rojo") color = Qt::red;
        else if (colorNombre == "Azul") color = Qt::blue;
        else if (colorNombre == "Verde") color = Qt::green;
        else if (colorNombre == "Amarillo") color = Qt::yellow;
        else if (colorNombre == "Naranja") color = QColor(255, 165, 0);
        else if (colorNombre == "Morado") color = QColor(128, 0, 128);
        else if (colorNombre == "Rosa") color = Qt::magenta;
        else if (colorNombre == "Marrón") color = QColor(139, 69, 19);
        else if (colorNombre == "Gris") color = Qt::gray;
        else if (colorNombre == "Negro") color = Qt::black;
        else if (colorNombre == "Blanco") color = Qt::white;
        else if (colorNombre == "Cian") color = Qt::cyan;
        else if (colorNombre == "Magenta") color = Qt::magenta;
        else if (colorNombre == "Turquesa") color = QColor(64, 224, 208);
        else if (colorNombre == "Oro") color = QColor(255, 215, 0);
        else if (colorNombre == "Plateado") color = QColor(192, 192, 192);
        else color = Qt::black; // Color por defecto

        // Aplicar el color al texto
        QPalette palette = ui->labelColorSeleccionado->palette();
        palette.setColor(QPalette::WindowText, color);
        ui->labelColorSeleccionado->setPalette(palette);

        // Mostrar información adicional en el Text Edit
        QString info = QString("Color: %1\n"
                               "Valor RGB: (%2, %3, %4)\n"
                               "Código HEX: %5")
                           .arg(colorNombre)
                           .arg(color.red())
                           .arg(color.green())
                           .arg(color.blue())
                           .arg(color.name());

        ui->textEditInfo->setText(info);
    }
}

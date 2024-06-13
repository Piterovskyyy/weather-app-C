#include "../headerFiles/mainwindow.h"
#include "../headerFiles/Ui/mainwindowUi.h"
#include <QIcon>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , dateWidget(new Date(this))
{
    ui->setupUi(this);

    setWindowTitle("Aplikacja Pogodowa - Podstawy Programowania");

    setWindowIcon(QIcon("../images/icons/02d.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

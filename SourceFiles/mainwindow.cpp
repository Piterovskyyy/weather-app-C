#include "../headerFiles/mainwindow.h"
#include "../headerFiles/Ui/mainwindowUi.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , dateWidget(new Date(this))
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

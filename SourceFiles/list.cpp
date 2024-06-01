#include "../headerFiles/list.h"
#include "../headerFiles/Ui/listUi.h"

List::List(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::List)
{
    ui->setupUi(this);
}

List::~List()
{
    delete ui;
}

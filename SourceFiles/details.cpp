#include "../headerFiles/details.h"
#include "../headerFiles/Ui/detailsUi.h"

Details::Details(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Details)
{
    ui->setupUi(this);
}

Details::~Details()
{
    delete ui;
}

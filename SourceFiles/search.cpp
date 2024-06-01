#include "../headerFiles/search.h"
#include "../headerFiles/searchUi.h"

Search::Search(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Search)
{
    ui->setupUi(this);
}

Search::~Search()
{
    delete ui;
}

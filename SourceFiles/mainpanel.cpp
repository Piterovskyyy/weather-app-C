#include "../headerFiles/mainpanel.h"
#include "../headerFiles/Ui/mainpanelUi.h"

MainPanel::MainPanel(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainPanel)
{
    ui->setupUi(this);
}

MainPanel::~MainPanel()
{
    delete ui;
}

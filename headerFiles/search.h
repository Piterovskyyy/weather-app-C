#ifndef SEARCH_H
#define SEARCH_H

#include <QWidget>
#include "../headerFiles/WeaterData.h"

namespace Ui {
    class Search;
}

class Search : public QWidget
{
    Q_OBJECT

public:
    explicit Search(QWidget *parent = nullptr);
    ~Search();

    private slots:
        void setCity();
    void updateUI();

private:
    Ui::Search *ui;
};

#endif // SEARCH_H

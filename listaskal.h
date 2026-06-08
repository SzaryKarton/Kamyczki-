#ifndef LISTASKAL_H
#define LISTASKAL_H

#include <QWidget>
#include "datamanager.h"
#include "mainWindow.h"
#include "nawigator.h"
#include "skalka.h"

namespace Ui {
class ListaSkal;
}

class ListaSkal : public QWidget
{
    Q_OBJECT

public:
    explicit ListaSkal(QWidget *parent = nullptr);
    ~ListaSkal();
    void obslugaKliknieciaSkalki();

private:
    Ui::ListaSkal *ui;
private slots:
    void on_dodajSkale_clicked();
    void on_backButton_clicked();

signals:
    void requestOpenSkala();
};


#endif // LISTASKAL_H

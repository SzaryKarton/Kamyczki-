#ifndef LISTASKAL_H
#define LISTASKAL_H

#include <QWidget>

namespace Ui {
class ListaSkal;
}

class ListaSkal : public QWidget
{
    Q_OBJECT

public:
    explicit ListaSkal(QWidget *parent = nullptr);
    ~ListaSkal();

private:
    Ui::ListaSkal *ui;
private slots:
    void on_skala1Button_clicked();
signals:
void requestOpenSkala();
};


#endif // LISTASKAL_H

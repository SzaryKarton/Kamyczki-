#ifndef PROFIL_H
#define PROFIL_H

#include <QWidget>
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui {
class Profil;
}
QT_END_NAMESPACE

class Profil : public QWidget
{
    Q_OBJECT

public:
    explicit Profil(QWidget *parent = nullptr);
    ~Profil();

private slots:
    void on_accedit_button_clicked();
    void on_accsave_button_clicked();
    void on_add_skill_clicked();
    void on_remove_skill_clicked();
    void on_add_eq_clicked();
    void on_remove_eq_clicked();

private:
    Ui::Profil *ui;
};

#endif // PROFIL_H

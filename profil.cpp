#include "profil.h"
#include "ui_profil.h"
#include "nawigator.h"
#include "databasemanager.h"
#include "datamanager.h"
#include "menu.h"
#include "mainWindow.h"

Profil::Profil(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Profil)
{
    ui->setupUi(this);

    // Inicjalizacja stanu widoku profilu
    ui->nick_label->show();
    ui->nick_lineEdit->hide();

    ui->info2->hide();
    ui->info4->hide();

    ui->add_skill->hide();
    ui->add_eq->hide();
    ui->remove_skill->hide();
    ui->remove_eq->hide();

    ui->eq_LineEdit->hide();
    ui->skill_LineEdit->hide();

    ui->profile_info->setReadOnly(true);
    ui->accsave_button->setEnabled(false);

    //Database
    auto& db = dataManager::instance();
    ui->nick_label->setText(db.nick);
    ui->profile_info->setPlainText(db.opis);

    ui->skills_ListWidget->clear();
    ui->eq_ListWidget->clear();

    for(const QString& skill : db.skills)
    {
        ui->skills_ListWidget->addItem(skill);
    }

    for(const QString& eq : db.equipment)
    {
        ui->eq_ListWidget->addItem(eq);
    }
}

Profil::~Profil()
{
    delete ui;
}

void Profil::on_accedit_button_clicked()
{
    ui->nick_lineEdit->setText(ui->nick_label->text());

    // Odblokowanie edycji profilu
    ui->nick_label->hide();
    ui->nick_lineEdit->show();
    ui->profile_info->setReadOnly(false);

    ui->info2->show();
    ui->info4->show();

    ui->add_skill->show();
    ui->add_eq->show();
    ui->remove_skill->show();
    ui->remove_eq->show();

    ui->eq_LineEdit->show();
    ui->skill_LineEdit->show();

    // Włączenie przycisku zapisu zmian
    ui->accsave_button->setEnabled(true);
}

void Profil::on_accsave_button_clicked()
{
    ui->nick_label->setText(ui->nick_lineEdit->text());

    // Zablokowanie edycji profilu
    ui->nick_lineEdit->hide();
    ui->nick_label->show();
    ui->profile_info->setReadOnly(true);

    ui->info2->hide();
    ui->info4->hide();

    ui->add_skill->hide();
    ui->add_eq->hide();
    ui->remove_skill->hide();
    ui->remove_eq->hide();

    ui->eq_LineEdit->hide();
    ui->skill_LineEdit->hide();

    //Database
    auto& db = dataManager::instance();
    db.nick = ui->nick_label->text();
    db.opis = ui->profile_info->toPlainText();

    db.skills.clear();

    for(int i = 0;
         i < ui->skills_ListWidget->count();
         i++)
    {
        db.skills.append(
            ui->skills_ListWidget
                ->item(i)
                ->text()
            );
    }

    db.equipment.clear();

    for(int i = 0;
         i < ui->eq_ListWidget->count();
         i++)
    {
        db.equipment.append(
            ui->eq_ListWidget
                ->item(i)
                ->text()
            );
    }

    DatabaseManager::instance().saveProfile();


    // Wyłączenie przycisku zapisu
    ui->accsave_button->setEnabled(false);
}

void Profil::on_add_skill_clicked()
{
    QString skill = ui->skill_LineEdit->text();

    if(!skill.isEmpty())
    {
        ui->skills_ListWidget->addItem(skill);
        ui->skill_LineEdit->clear();
    }
}

void Profil::on_remove_skill_clicked()
{
    QListWidgetItem *item = ui->skills_ListWidget->currentItem();

    if(item != nullptr)
    {
        delete item;
    }
}

void Profil::on_add_eq_clicked()
{
    QString eq = ui->eq_LineEdit->text();

    if(!eq.isEmpty())
    {
        ui->eq_ListWidget->addItem(eq);
        ui->eq_LineEdit->clear();
    }
}

void Profil::on_remove_eq_clicked()
{
    QListWidgetItem *item = ui->eq_ListWidget->currentItem();

    if(item != nullptr)
    {
        delete item;
    }
}

void Profil::on_cofnijTemp_clicked() {
    MainWindow *glowneOkno =
        qobject_cast<MainWindow*>(
            this->window()
            );

    Nawigator n;

    Menu *do_otwarcia =
        new Menu(glowneOkno);

    n.openWidget(
        glowneOkno,
        do_otwarcia
        );
}


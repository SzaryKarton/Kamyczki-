#include "listaskal.h"
#include "ui_listaskal.h"


ListaSkal::ListaSkal(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ListaSkal)
{
    ui->setupUi(this);

    auto& db = dataManager::instance();
    QVBoxLayout *ukladPionowy = new QVBoxLayout(ui->scrollAreaWidgetContents);
    ukladPionowy->setAlignment(Qt::AlignTop); // Przyciski będą się układać od góry

    for (int i = 0; i < db.wszystkie_skalki.size(); ++i)
    {
        SkalkaUniversal* skalka = db.wszystkie_skalki[i];

        if (skalka != nullptr)
        {
            // PRZYKŁAD A: Jeśli chcesz dodawać przyciski do układu pionowego (np. ukladSkalek):
            QPushButton *btn = new QPushButton("Skałka " + QString::number(i + 1), this);
        ukladPionowy->addWidget(btn);
        }

    }
}
ListaSkal::~ListaSkal()
{
    delete ui;
}
void ListaSkal::on_pushButton_4_clicked()
{
    SkalkaUniversal *n_skalka = new SkalkaUniversal;
    dataManager::instance().wszystkie_skalki.append(n_skalka);
    Nawigator n;
    MainWindow *glowneOkno = qobject_cast<MainWindow*>(this->window());
    //ListaSkal *do_otwarcia = new ListaSkal(glowneOkno);
    n.openWidget(glowneOkno, n_skalka);


}


#include "nawigator.h"
#include <QVBoxLayout>
#include "mainWindow.h"
#include <QFrame>
#include <QDebug>
#include "trasa.h"
void Nawigator::openWidget(
    MainWindow *okno,
    QWidget *nowyWidget
    )
{
    okno->setCentralWidget(nowyWidget);
}

/*void Nawigator:: openInFrameTrasa(
    QFrame *targetFrame,
    Trasa *widgetPointer
    )
{
    QVBoxLayout *frameLayout = qobject_cast<QVBoxLayout*>(targetFrame->layout());
    widgetPointer = new Trasa(targetFrame);

    // 4. Wrzucamy go do układu ramki
    frameLayout->addWidget(widgetPointer);
}*/
void Nawigator::openInFrameTrasa(QFrame *targetFrame, Trasa *widgetPointer)
{
    // Zabezpieczenie przed crashem, jeśli layout nie istnieje
    if (!targetFrame || !targetFrame->layout() || !widgetPointer)
    {qDebug()<< "nie wyszlo";
        if (!targetFrame)
            qDebug()<< "no target frame";
        if (!targetFrame->layout())
            qDebug()<< "no target frame->layout";
        if (!widgetPointer)
            qDebug()<< "no widget pointer";
        return;}

    QVBoxLayout *frameLayout = qobject_cast<QVBoxLayout*>(targetFrame->layout());
    if (frameLayout) {
        frameLayout->addWidget(widgetPointer);
        qDebug()<< "teorytycznie dodano";
    }
}
//Nawigator::Nawigator() {}

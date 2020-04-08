#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include <QFile>
#include <QString>
#include <QGridLayout>
#include <QTimeEdit>
#include <QElapsedTimer>
#include "Pawn.h"
#include "Indicator.h"

namespace Ui {
class View;
}

class View : public QMainWindow
{
    Q_OBJECT

public:
    explicit View(QWidget *parent = 0);
    ~View();
    void loadUi(const int & size, Pawn * pawns);
    void loadUi(const int & size, Pawn * pawns, Indicator * indicator);
    void loadTestPawn();
    void stopMetronome();

public slots:
    void onTimerTimeout();

private:

    QGridLayout* loadPawnsOnGrid(const int & size, Pawn * pawns);
    QGridLayout* loadPawnsOnGrid(const int & size, Pawn * pawns, Indicator * indicator);
    Ui::View *ui;
    QTimeEdit *_chronometer;
    QTimer * _metronome;
    QElapsedTimer *_time;
};

#endif

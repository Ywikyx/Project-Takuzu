#include "Pawn.h"
#define PI 3.14159
Pawn::Pawn(QWidget *parent) : QWidget(parent)
{
   _design = new BrightCircle;

}

void Pawn::paintEvent(QPaintEvent *) {
    switch (_state){
    case State::Empty:
        //_design->displayEmptyPawn(this);
       // _design->displayLockPawn(this);
        break;
    case State::Black:

        displayBlackPawn();
        displayLockPawn();
        break;
    case State::White:
        displayWhitePawn();
        displayLockPawn();
        break;
    }
}

void Pawn::mousePressEvent(QMouseEvent *) {
    if (!_isLock) {
        switch (_state){
        case White:
            _state = Empty;
            break;
        case Black:
            _state = White;
            break;
        case Empty:
            _state = Black;
            break;
        }
        emit onClicked(_id,_state);
        update();
    }

}

void Pawn::setId(const int &id)
{
    _id = id;
}

void Pawn::setFalse(bool isFalse)
{
    _isFalse = isFalse;
}

void Pawn::setLock(bool isLock)
{
    _isLock = isLock;
}

void Pawn::setState(const State &state)
{
    _state = State(state);
}

State Pawn::getState()
{
    return _state;
}

bool Pawn::operator==(const Pawn &other)
{
    return _state == other._state;
}

void Pawn::displayWhitePawn()
{
    QPainter painter(this);

    QBrush brush(Qt::white);
    QPen pen(Qt::white);
    if(_isFalse) {
        painter.fillRect(rect(),Qt::red);
    } else {
        painter.fillRect(rect(),Qt::gray);
    }
    painter.setBrush(brush);
    painter.setPen(pen);
    painter.drawEllipse(width()*0.05,height()*0.05,width()*0.9,height()*0.9);
}

void Pawn::displayBlackPawn()
{
    QPainter painter(this);
    QBrush brush(Qt::black);
    if(_isFalse) {
        painter.fillRect(rect(),Qt::red);
    } else {
        painter.fillRect(rect(),Qt::gray);
    }
    painter.setBrush(brush);
    painter.drawEllipse(width()*0.05,height()*0.05,width()*0.9,height()*0.9);

}

void Pawn::displayEmptyPawn()
{
    QPainter painter(this);
    painter.fillRect(rect(),Qt::gray);
}

void Pawn::displayLockPawn(){
    if (_isLock) {
        QPainter painter(this);
        QBrush brush(Qt::gray);
        QPen pen(Qt::gray);

        if(_isFalse) {
            pen.setColor(Qt::red);
            brush.setColor(Qt::red);
        } else {
            pen.setColor(Qt::gray);
            brush.setColor(Qt::gray);
        }
        painter.setBrush(brush);
        painter.setPen(pen);

        int marginX = width() * 0.45;
        int marginY = height() * 0.45;
        int diameterX = width()-2*marginX;
        int diameterY = height() -2*marginY;

        painter.drawEllipse(marginX, marginY, diameterX, diameterY);
    }
}


void Pawn::BrightCircle::displayEmptyPawn(Pawn *pawn)
{
    QPainter painter(pawn);
    painter.fillRect(pawn->rect(),Qt::gray);
}

void Pawn::BrightCircle::displayLockPawn(Pawn *pawn)
{
    if (pawn->_isLock) {
        QPainter painter(pawn);
        QBrush brush(Qt::gray);
        QPen pen(Qt::gray);

        if(pawn->_isFalse) {
            pen.setColor(Qt::red);
            brush.setColor(Qt::red);
        } else {
            pen.setColor(Qt::gray);
            brush.setColor(Qt::gray);
        }
        painter.setBrush(brush);
        painter.setPen(pen);

        int marginX = pawn->width() * 0.45;
        int marginY = pawn->height() * 0.45;
        int diameterX = pawn->width()-2*marginX;
        int diameterY = pawn->height() -2*marginY;

        painter.drawEllipse(marginX, marginY, diameterX, diameterY);
    }
}


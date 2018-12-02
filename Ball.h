#ifndef BALL_H
#define BALL_H

#include <QGraphicsRectItem>
#include <QObject>
#include "Paddle.h"

class Ball: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Ball();
    void startGame();
    void keyPressEvent(QKeyEvent * event);
    Paddle * paddle;
    QGraphicsTextItem * helpscreen;
    QGraphicsTextItem * helphint;

public slots:
    void move();

private:
    int direction;
    QTimer * timer;
    int numBlocks = 0;
};



#endif // Ball.h

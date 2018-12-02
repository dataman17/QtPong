#ifndef PADDLE_H
#define PADDLE_H
#include <QGraphicsRectItem>
#include <QKeyEvent>

class Paddle: public QGraphicsRectItem{
public:
    void keyPressEvent(QKeyEvent * event);
    Paddle * paddlePtr;
};

#endif // PADDLE_H

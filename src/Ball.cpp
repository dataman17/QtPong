#include "inc/Ball.h"
#include "inc/Block.h"
#include "inc/Paddle.h"
#include <QTimer>
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QLabel>

Ball::Ball()
{
    setRect(0,0,50,50);
    this->direction = 0;
    this->setPos(325,425);
    timer = new QTimer();

}

void Ball::startGame()
{
    //connect the ball and start the timer
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);

}

void Ball::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Space){
        scene()->removeItem(this->helphint);
        Paddle * paddlePtr;
        paddlePtr = this->paddle;
        paddlePtr->setFocus();
        startGame();
    }
    if(event->key() == Qt::Key_H){
        scene()->addItem(this->helpscreen);
    }
    if(event->key() == Qt::Key_C){
        scene()->removeItem(this->helpscreen);
    }

}

void Ball::move(){
    //check for a collision with the blocks or paddle
    QList<QGraphicsItem *> colliding_items = collidingItems();
    int n = colliding_items.size();
    for(int i = 0; i < n; ++i){
        if(typeid(*(colliding_items[i])) == typeid(Block)){
            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
            if(direction == 1)
                direction = 0;
            else if(direction == 2)
                direction = 3;
            else if(direction == 0)
                direction = 3;
            else if(direction == 3)
                direction = 0;
            numBlocks++;
            return;
        }
        if(typeid(*(colliding_items[i])) == typeid(Paddle)){
            if(direction == 0)
                direction = 1;
            else if(direction == 3)
                direction = 2;
            else if(direction == 1)
                direction = 2;
            else if(direction == 2)
                direction =1;
        }
    }
    //else check for a collision with the four sides
    if(direction == 0){
        if(pos().x()+50 < 800){
            setPos(x()+10, y());
        }
        else{
            setPos(x()-10, y());
            direction = 3;
        }
        if(pos().y() +50 >= 600){
            //set the ball to focus and stop moving
            timer->stop();
            QLabel * label = new QLabel();
            label->setText("GAME OVER!!!");
            label->setGeometry(QRect(325, 200, 100, 50));
            scene()->addWidget(label);
            direction = 4;
        }
        else{
            setPos(x(), y()+5);
        }
    }
    if(direction == 1){
        if(pos().x()+50 < 800){
            setPos(x()+10, y());
        }
        else{
            setPos(x()-10, y());
            direction = 2;
        }
        if(pos().y() > 0){
            setPos(x(), y()-10);
        }
        else{
            setPos(x(), y()+10);
            direction = 0;
        }
    }
    if(direction == 2){
        if(pos().x() > 0){
             setPos(x()-10, y());
         }
        else{
            setPos(x()+10, y());
            direction = 1;
        }
        if(pos().y() > 0){
            setPos(x(), y()-10);
        }
        else{
            setPos(x(), y()+10);
            direction = 3;
        }
    }
    if(direction == 3){
        if(pos().x() > 0){
             setPos(x()-10, y());
        }
        else{
            setPos(x()+10, y());
            direction = 0;
        }
        if(pos().y()+50 >= 600){
            //set the ball to stop moving Game Over
            timer->stop();
            QLabel * label = new QLabel();
            label->setText("GAME OVER!!!");
            label->setGeometry(QRect(325, 200, 100, 50));
            scene()->addWidget(label);
            direction= 4;
        }
        else{
            setPos(x(), y()+10);
        }
    }
    if(direction == 4){
        return;
    }
    if(numBlocks >= 16){
        timer->stop();
        QLabel * label = new QLabel();
        label->setText("YOU WIN!!!");
        label->setGeometry(QRect(325, 200, 100, 50));
        scene()->addWidget(label);
        return;
    }
}



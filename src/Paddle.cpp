#include <Paddle.h>
#include <QKeyEvent>

void Paddle::keyPressEvent(QKeyEvent * event){
    if(event->key() == Qt::Key_Left){
       if(pos().x() > 0){
            setPos(x()-10, y());
        }
    }
    if(event->key() == Qt::Key_Right){
        if(pos().x()+100 < 800){
            setPos(x()+10, y());
        }
    }
}

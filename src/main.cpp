#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QLabel>
#include "inc/Paddle.h"
#include "inc/Ball.h"
#include "inc/Block.h"

int main(int argc, char *argv[])
{
    const int h = 600;
    const int w = 800;

    QApplication a(argc, argv);

    //create a scene
    QGraphicsScene * scene = new QGraphicsScene();

    //create the paddle
    Paddle * paddle = new Paddle();
    paddle->setRect(0,0,100,25);

    //add paddle to the scene
    scene->addItem(paddle);

    //create ball
    Ball * ball = new Ball();
    ball->paddle = paddle;

    //add ball to the scene
    scene->addItem(ball);

    //make the help screen
    QGraphicsTextItem * helpscreen = new QGraphicsTextItem();
    helpscreen->setPlainText("Press 'c' to exit help screen\n Press spacebar to start\n Press <- and -> to move the paddle\n Don't let the ball touch the bottom!");
    helpscreen->setPos(325, 200);
    ball->helpscreen = helpscreen;

    //make ball focusable and set focus for the start of the game
    ball->setFlag(QGraphicsItem::ItemIsFocusable);

    //make paddle focusable
    paddle->setFlag(QGraphicsItem::ItemIsFocusable);
    ball->setFocus();

    //create a view to visualize the scene
    QGraphicsView *view = new QGraphicsView(scene);

    //turn off the scrollbars
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //set the view and screen sizes
    view->setFixedSize(w, h);
    scene->setSceneRect(0, 0, w, h);

    //show the view
    view ->show();

    //create blocks and set their positions
        Block * block = new Block();
        Block * block2 = new Block();
        Block * block3 = new Block();
        Block * block4 = new Block();
        Block * block5 = new Block();
        Block * block6 = new Block();
        Block * block7 = new Block();
        Block * block8 = new Block();
        Block * block9 = new Block();
        Block * block10 = new Block();
        Block * block11 = new Block();
        Block * block12 = new Block();
        Block * block13 = new Block();
        Block * block14 = new Block();
        Block * block16 = new Block();
        Block * block15 = new Block();
        scene->addItem(block);
        scene->addItem(block2);
        scene->addItem(block3);
        scene->addItem(block4);
        scene->addItem(block5);
        scene->addItem(block6);
        scene->addItem(block7);
        scene->addItem(block8);
        scene->addItem(block9);
        scene->addItem(block10);
        scene->addItem(block11);
        scene->addItem(block12);
        scene->addItem(block13);
        scene->addItem(block14);
        scene->addItem(block15);
        scene->addItem(block16);
        block->setPos(0,0);
        block2->setPos(100,0);
        block3->setPos(200,0);
        block4->setPos(300,0);
        block5->setPos(400,0);
        block6->setPos(500,0);
        block7->setPos(600,0);
        block8->setPos(700,0);
        block9->setPos(0,50);
        block10->setPos(100,50);
        block11->setPos(200,50);
        block12->setPos(300,50);
        block13->setPos(400,50);
        block14->setPos(500,50);
        block15->setPos(600,50);
        block16->setPos(700,50);

//set the help screen menue widget
        QGraphicsTextItem * label = new QGraphicsTextItem();
        label->setPlainText("Press 'h' for the help screen");
        ball->helphint = label;
        scene->addItem(label);
    //set paddle position
    paddle->setPos((view->width()/2)-50,view->height()-paddle->rect().height());

    return a.exec();
}

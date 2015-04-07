#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(moveSnake()));
    timer->start(1000);
    tempX=120;
    tempY=120;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::moveSnake()
{


    repaint();

}

void MainWindow::moveRight()
{

    tempX=tempX+5;

}

void MainWindow::moveUp()
{

    tempY=tempY-5;
}

void MainWindow::moveDown()
{
    tempY=tempY+5;
}

void MainWindow::moveLeft()
{
    tempX=tempX-5;
}


void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter mPainter(this);
    QColor mYellow(0,0,255);
    mPainter.setPen(mYellow);
    mPainter.setBrush(Qt::SolidPattern);
    mPainter.drawRect(tempX,tempY,20,10);
    mPainter.drawRect(tempX+20, tempY, 20,10);

}

void MainWindow::keyPressEvent(QKeyEvent *k)
{
    auto key =  QString(k->text()).toLower();
    if( key == "w")
        moveUp();
    else if( key == "s")
        moveDown();
    else if( key == "d")
        moveRight();
    else if( key == "a")
        moveLeft();

}

enum direction{
//    'w'=1,
//    "s"=-1,
//    'a'=-1,
//    'd'=1
};

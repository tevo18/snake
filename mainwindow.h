#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QColor>
#include <QDebug>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    int tempX, tempY;
    void moveRight();
    void moveUp();
    void moveDown();
    void moveLeft();

private slots:
    void moveSnake();


protected:
    void paintEvent(QPaintEvent *);
    void keyPressEvent( QKeyEvent *k );
};

#endif // MAINWINDOW_H

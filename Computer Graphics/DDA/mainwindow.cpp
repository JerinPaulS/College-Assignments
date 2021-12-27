#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

QImage img(500, 500, QImage::Format_RGB888);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    img.fill(Qt::white); //This will retain all the lines in the canvas
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //img.fill(Qt::white); This is used when fresh line is to be drawn on every button click
    int x1, y1, x2, y2;
    x1 = ui->textEdit->toPlainText().toInt();
    y1 = ui->textEdit_2->toPlainText().toInt();
    x2 = ui->textEdit_4->toPlainText().toInt();
    y2 = ui->textEdit_3->toPlainText().toInt();
    DDA(std::min(x1, x2), min(y1, y2), max(x1, x2),max(x2, y2));
    ui->label->setPixmap(QPixmap::fromImage((img)));
}

void MainWindow::DDA(int x1, int y1, int x2, int y2)
{
    float X, Y, dx, dy, Xinc, Yinc;
    int steps;
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);

    steps = dx > dy ? dx : dy;

    Xinc = dx / (float) steps;
    Yinc = dy / (float) steps;

    X = x1;
    Y = y1;
    for (int i = 0; i <= steps; i++)
    {
        img.setPixel(X, Y, qRgb(1, 1, 1));
        X += Xinc;
        Y += Yinc;
    }
}

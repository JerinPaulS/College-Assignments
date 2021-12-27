#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"QMessageBox"
#include"math.h"

QImage image(500, 500, QImage::Format_RGB888);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int x, y, radius;
    x=ui->textEdit->toPlainText().toInt();
    y=ui->textEdit_2->toPlainText().toInt();
    radius=ui->textEdit_3->toPlainText().toInt();
    if(radius==0)
    {
        QMessageBox msg;
        msg.setText("Invalid radius!!");
        msg.exec();
    }
    Circle(x,y,radius);
    ui->label->setPixmap(QPixmap::fromImage((image)));
}

void MainWindow::Circle(int x, int y, int radius)
{
    image.fill(Qt::white);
    int xc,yc,pk;
    xc=0;
    yc=radius;
    pk=3-(2*radius);
    while(xc<=yc)
    {
        if(pk<=0)
        {
            xc++;
            pk+=4*xc+6;
        }
        else
        {
            xc++;
            yc--;
            pk+=4*(xc-yc)+10;
        }
        image.setPixel(x+xc,y+yc,1);
        image.setPixel(x-xc,y+yc,1);
        image.setPixel(x+xc,y-yc,1);
        image.setPixel(x-xc,y-yc,1);
        image.setPixel(x+yc,y+xc,1);
        image.setPixel(x-yc,y+xc,1);
        image.setPixel(x+yc,y-xc,1);
        image.setPixel(x-yc,y-xc,1);
    }
}

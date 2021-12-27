#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"math.h"
#include"QMessageBox"

QImage image(500,500,QImage::Format_RGB888);

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
    image.fill(Qt::white);
    float x1, x2, y1, y2;
    x1=ui->textEdit->toPlainText().toFloat();
    x2=ui->textEdit_3->toPlainText().toFloat();
    y1=ui->textEdit_2->toPlainText().toFloat();
    y2=ui->textEdit_4->toPlainText().toFloat();
    if(x1==x2 && y1==y2)
    {
        QMessageBox msg;
        msg.setText("Invalid coordinates!!");
        msg.exec();
        return;
    }
    else if(x1<0 || x2<0 || y1<0 || y2<0)
    {
        QMessageBox msg;
        msg.setText("Invalid coordinates!!");
        msg.exec();
        return;
    }
    Bress(x1,x2,y1,y2);
    ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::Bress(float x1, float x2, float y1, float y2)
{
    int dx,dy,xend,x,y,p;
    dx=abs(x2-x1);
    dy=abs(y2-y1);
    p=2*(dy-dx);
    if(x1>x2)
    {
        x=x2;
        y=y2;
        xend=x1;
    }
    else
    {
        x=x1;
        y=y1;
        xend=x2;
    }
    while(x<xend)
    {
        x++;
        if(p<0)
            p=p+2*dy;
        else
        {
            p=p+2*(dy-dx);
            y++;
        }
        image.setPixel(x,y,qRgb(1,1,1));
    }
}

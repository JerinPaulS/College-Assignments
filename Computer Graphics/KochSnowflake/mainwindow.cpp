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

void MainWindow::k_curve(float x1, float y1, float x2, float y2, int itr, int direction)
{
    float ang=(direction*60)*M_PI/180;
    float x3=((2*x1)+x2)/3;
    float y3=((2*y1)+y2)/3;

    float x4=(x1+(2*x2))/3;
    float y4=(y1+(2*y2))/3;

    float x=x3+(x4-x3)*cos(ang)+(y4-y3)*sin(ang);
    float y=y3-(x4-x3)*sin(ang)+(y4-y3)*cos(ang);

    if(itr>0)
    {
        k_curve(x1,y1,x3,y3,itr-1, direction);
        k_curve(x3,y3,x,y,itr-1, direction);
        k_curve(x,y,x4,y4,itr-1, direction);
        k_curve(x4,y4,x2,y2,itr-1, direction);
    }
    else{
        line(x1,y1,x3,y3);
        line(x3,y3,x,y);
        line(x,y,x4,y4);
        line(x4,y4,x2,y2);
    }
}

void MainWindow::line(float x1, float y1, float x2, float y2)
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


void MainWindow::on_pushButton_clicked()
{
    image.fill(Qt::white);
    k_curve(100, 100, 400, 100, 5, 1);
    k_curve(100, 400, 400, 400, 5, -1);
    k_curve(100, 100, 100, 400, 5, 1);
    k_curve(400, 100, 400, 400, 5, -1);
    ui->label->setPixmap(QPixmap::fromImage(image));
}

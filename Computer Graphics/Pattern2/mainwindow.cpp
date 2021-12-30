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
    int x,y,r,s,d;
    image.fill(Qt::white);
    x=ui->textEdit->toPlainText().toFloat();
    y=ui->textEdit_2->toPlainText().toFloat();
    r=ui->textEdit_3->toPlainText().toFloat();
    d = 2 * r;
    s = d / sqrt(2);
    if(r==0)
    {
        QMessageBox msg;
        msg.setText("Invalid radius!!");
        msg.exec();
    }
    Circle(x,y,r);
    line(x, x + s, y - s, y);
    line(x - s, x, y, y - s);
    line(x, x + s, y + s, y);
    line(x - s, x, y,  y + s);
    line(x - s, x - s, y - s, y + s);
    line(x + s, x + s, y - s, y + s);
    line(x - s, x + s, y - s, y - s);
    line(x - s, x + s, y + s, y + s);
    ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::line(float x1,float x2,float y1,float y2){
    int dx,dy,steps,xt,yt;
    float xi,yi,x,y;
    x=x1;
    xt=x1;
    y=y1;
    yt=y1;
    dx=x2-x1;
    dy=y2-y1;
    if(abs(dx)>abs(dy))
        steps=abs(dx);
    else
        steps=abs(dy);
    xi=(float)dx/steps;
    yi=(float)dy/steps;
    image.setPixel(x1,y1,qRgb(1,1,1));
    for(int i=0;i<steps;i++)
    {
           x=x+xi;
           y=y+yi;
           xt=x+0.5;
           yt=y+0.5;
           image.setPixel(xt,yt,qRgb(1,1,1));
    }
}

void MainWindow::Circle(int x, int y, int radius){
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

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<math.h>
#include<stdlib.h>
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

void MainWindow::move(float j,float h,float &x,float &y){
    if(j==1)
        y-=h;
    else if(j==2)
        x+=h;
    else if(j==3)
        y+=h;
    else if(j==4)
        x-=h;
    line(x,y, x+10, y+10);
}

void MainWindow::hilbert(float r,float d,float l,float u,float i,float h,float &x,float &y){
    if(i>0)
    {
        i--;
        hilbert(d,r,u,l,i,h,x,y);
        move(r,h,x,y);
        hilbert(r,d,l,u,i,h,x,y);
        move(d,h,x,y);
        hilbert(r,d,l,u,i,h,x,y);
        move(l,h,x,y);
        hilbert(u,l,d,r,i,h,x,y);
    }
}

void MainWindow::on_pushButton_clicked(){
    image.fill(Qt::white);
    float n;
    n = ui->textEdit->toPlainText().toFloat();
    float x0=50,y0=150,x,y,h=10,r=2,d=3,l=4,u=1;
    x=x0;y=y0;
    hilbert(r,d,l,u,n,h,x,y);
    ui->label->setPixmap(QPixmap::fromImage(image));
}


void MainWindow::line(float x1, float x2, float y1, float y2){
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

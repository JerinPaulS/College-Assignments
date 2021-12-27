#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"QMessageBox"
#include"math.h"

QImage image(500,500,QImage::Format_RGB888);

using namespace std;

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

void MainWindow::circle(int x, int y, int radius)
{
      int xc,yc,pk;
      xc=0;
      yc=radius;
      pk=1-radius;
      image.setPixel(x+xc,y+yc,qRgb(1,1,1));
      image.setPixel(x-xc,y+yc,qRgb(1,1,1));
      image.setPixel(x+xc,y-yc,qRgb(1,1,1));
      image.setPixel(x-xc,y-yc,qRgb(1,1,1));
      image.setPixel(x+yc,y+xc,qRgb(1,1,1));
      image.setPixel(x-yc,y+xc,qRgb(1,1,1));
      image.setPixel(x+yc,y-xc,qRgb(1,1,1));
      image.setPixel(x-yc,y-xc,qRgb(1,1,1));
      while(xc<=yc)
      {
          if(pk<=0)
          {
              xc++;
              pk+=2*xc+1;
          }
          else
          {
              xc++;
              yc--;
              pk+=2*(xc-yc)+1;
          }
          image.setPixel(x+xc,y+yc,qRgb(1,1,1));
          image.setPixel(x-xc,y+yc,qRgb(1,1,1));
          image.setPixel(x+xc,y-yc,qRgb(1,1,1));
          image.setPixel(x-xc,y-yc,qRgb(1,1,1));
          image.setPixel(x+yc,y+xc,qRgb(1,1,1));
          image.setPixel(x-yc,y+xc,qRgb(1,1,1));
          image.setPixel(x+yc,y-xc,qRgb(1,1,1));
          image.setPixel(x-yc,y-xc,qRgb(1,1,1));
      }
}

void MainWindow::line(float x1,float x2,float y1,float y2)
{
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

void MainWindow::on_pushButton_clicked()
{
    int x,y,r1,r2;
    image.fill(Qt::white);
    x=ui->textEdit->toPlainText().toFloat();
    y=ui->textEdit_2->toPlainText().toFloat();
    r2=ui->textEdit_3->toPlainText().toFloat();
    r1=2 * r2;
    if(r2==0 && r1==0)
    {
        QMessageBox msg;
        msg.setText("Invalid radius!!");
        msg.exec();
    }
    circle(x,y,r1);
    circle(x,y,r2);
    line(x,x+sqrt((r1 * r1) - (r2 * r2)),(y-r1),(y+r2));
    line(x,(x-sqrt((r1 * r1) - (r2 * r2))),(y-r1),(y+r2));
    line(x-sqrt((r1 * r1) - (r2 * r2)),x+sqrt((r1 * r1) - (r2 * r2)),(y+r2),(y+r2));
    ui->label->setPixmap(QPixmap::fromImage(image));
}

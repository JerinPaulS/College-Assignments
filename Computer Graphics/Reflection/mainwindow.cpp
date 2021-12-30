#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"math.h"
#include"QMessageBox"

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

void MainWindow::line(float x1,float x2,float y1,float y2,QImage &image){

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
    ui->screen->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::poly(float x1,float x2,float y1,float y2,QImage &image){
    line(x1,x2,y1,y1,image);
    line(x1,x1,y1,y2,image);
    line(x2,x2,y1,y2,image);
    line(x1,x2,y2,y2,image);
}

void MainWindow::yaxis(float x1,float x2,float y1,float y2,QImage &image){
    line((500-x1),(500-x2),y1,y1,image);
    line((500-x1),(500-x1),y1,y2,image);
    line((500-x2),(500-x2),y1,y2,image);
    line((500-x1),(500-x2),y2,y2,image);
}

void MainWindow::xaxis(float x1,float x2,float y1,float y2,QImage &image){
    line(x1,x2,(500-y1),(500-y1),image);
    line(x1,x1,(500-y1),(500-y2),image);
    line(x2,x2,(500-y1),(500-y2),image);
    line(x1,x2,(500-y2),(500-y2),image);
}

void MainWindow::on_pushButton_clicked(){
       QImage *image=new QImage(500,500,QImage::Format_RGB888);
       image->fill(Qt::white);
       float x1, x2, y1,y2;
       x1=ui->textEdit->toPlainText().toFloat();
       x2=ui->textEdit_3->toPlainText().toFloat();
       y1=ui->textEdit_2->toPlainText().toFloat();
       y2=ui->textEdit_4->toPlainText().toFloat();
       if(x1==x2 && y1==y2)
       {
           QMessageBox msg;
           msg.setText("Plaese enter distant values!");
           msg.exec();
           return;
       }
       else if(x1<0 || x2<0 || y1<0 || y2<0)
       {
           QMessageBox msg;
           msg.setText("Please enter positive numbers!");
           msg.exec();
           return;
       }
       else if(x1>=250 || x2>=250 || y1>=250 || y2>=250)
       {
           QMessageBox msg;
           msg.setText("Please vales for 1st quadrant!");
           msg.exec();
           return;
       }
       line(250,250,0,500,*image);
       line(0,500,250,250,*image);
       poly(x1,x2,y1,y2,*image);
}

void MainWindow::on_pushButton_2_clicked(){
       QImage *image2=new QImage(500,500,QImage::Format_RGB888);
       image2->fill(Qt::white);
       float x1, x2, y1,y2;
       x1=ui->textEdit->toPlainText().toFloat();
       x2=ui->textEdit_3->toPlainText().toFloat();
       y1=ui->textEdit_2->toPlainText().toFloat();
       y2=ui->textEdit_4->toPlainText().toFloat();
       if(x1==x2 && y1==y2)
       {
           QMessageBox msg;
           msg.setText("Plaese enter distant values!");
           msg.exec();
           return;
       }
       else if(x1<0 || x2<0 || y1<0 || y2<0)
       {
           QMessageBox msg;
           msg.setText("Please enter positive numbers!");
           msg.exec();
           return;
       }
       else if(x1>=250 || x2>=250 || y1>=250 || y2>=250)
       {
           QMessageBox msg;
           msg.setText("Please vales for 1st quadrant!");
           msg.exec();
           return;
       }
       line(250,250,0,500,*image2);
       line(0,500,250,250,*image2);
       yaxis(x1,x2,y1,y2,*image2);
}


void MainWindow::on_pushButton_3_clicked()
{
    QImage *image2=new QImage(500,500,QImage::Format_RGB888);
    image2->fill(Qt::white);
    float x1, x2, y1,y2;
    x1=ui->textEdit->toPlainText().toFloat();
    x2=ui->textEdit_3->toPlainText().toFloat();
    y1=ui->textEdit_2->toPlainText().toFloat();
    y2=ui->textEdit_4->toPlainText().toFloat();
    if(x1==x2 && y1==y2)
    {
        QMessageBox msg;
        msg.setText("Plaese enter distant values!");
        msg.exec();
        return;
    }
    else if(x1<0 || x2<0 || y1<0 || y2<0)
    {
        QMessageBox msg;
        msg.setText("Please enter positive numbers!");
        msg.exec();
        return;
    }
    else if(x1>=250 || x2>=250 || y1>=250 || y2>=250)
    {
        QMessageBox msg;
        msg.setText("Please vales for 1st quadrant!");
        msg.exec();
        return;
    }
    line(250,250,0,500,*image2);
    line(0,500,250,250,*image2);
    xaxis(x1,x2,y1,y2,*image2);
}

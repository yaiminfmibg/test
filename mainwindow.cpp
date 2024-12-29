#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setPalette(QPalette(Qt::white));
    setAutoFillBackground(true);
    this->resize(400,200);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent */*event*/)
{
    QPainter painter(this);

#if 0
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::TextAntialiasing);
    int w = this->width();
    int h = this->height();
    QRect rect(w/4,h/4,w/2,h/2); // 中心区域矩形
    // 设置画笔
    QPen pen;
    pen.setWidth(3);
    pen.setColor(Qt::red);
    pen.setStyle(Qt::DashDotLine);
    pen.setCapStyle(Qt::RoundCap);    // 线条端点样式
    pen.setJoinStyle(Qt::MiterJoin); // 线条连接样式
    painter.setPen(pen);
    // 设置画刷
    QBrush brush;
    brush.setColor(Qt::yellow);
    brush.setStyle(Qt::SolidPattern); // 画刷填充样式
    painter.setBrush(brush);

    // 绘图
    painter.drawRect(rect);
    event->accept();
#endif

    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::TextAntialiasing);
    int w = this->width();
    int h = this->height();
    painter.drawPoint(QPoint(w/2,h/2));
    // 绘制一批点
    QPoint points[] =
    {
        QPoint(5*w/12,h/4),
        QPoint(3*w/12,5*h/12),
        QPoint(2*w/4,5*h/12)
    };
    painter.drawPoints(points,3);
    //绘制直线
    QLine line(w/4,h/4,w/2,h/2);
    painter.drawLine(line);

    //event->accept();
}

void MainWindow::on_pushButton_clicked()
{
    qDebug() << "hello world";
}


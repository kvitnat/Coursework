#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    N = 50;
    for(int i = 0; i < N; ++i)
        numbers.append(QRandomGenerator::global()->generate() % 16);
    chart1 = new MyChart(nullptr, numbers);
    chart2 = new MyChart(nullptr, numbers);
    ui->sort1Layout->addWidget(chart1->getChartView());
    ui->sort2Layout->addWidget(chart2->getChartView());
    connect(&thread1, &QThread::finished, this, &MainWindow::enableButtons);
    connect(&thread1, &QThread::started, chart1, &MyChart::sortBubble);
    connect(&thread2, &QThread::finished, this, &MainWindow::enableButtons);
    connect(&thread2, &QThread::started, chart2, &MyChart::sortInsert);
}

MainWindow::~MainWindow()
{
    thread1.quit();
    thread2.quit();
    thread1.wait();
    thread2.wait();
    delete ui;
}


void MainWindow::on_generateButton_clicked()
{
    numbers.clear();
    for(int i = 0; i < N; ++i)
        numbers.append(QRandomGenerator::global()->generate() % 16);
    chart1->newNumbers(numbers);
    chart2->newNumbers(numbers);
}

void MainWindow::on_sortButton_clicked()
{
    chart1->moveToThread(&thread1);
    chart2->moveToThread(&thread2);
    ui->generateButton->setDisabled(true);
    ui->sortButton->setDisabled(true);
    //connect(&thread1, &QThread::finished, chart1, &QObject::deleteLater);

    thread1.start();
    thread2.start();
}

void MainWindow::enableButtons()
{
    if(thread1.isFinished() && thread2.isFinished()){
        ui->generateButton->setEnabled(true);
        ui->sortButton->setEnabled(true);
    }
}

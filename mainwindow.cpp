#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList quantities;
    quantities.append("10");
    quantities.append("15");
    quantities.append("25");
    quantities.append("50");
    quantities.append("100");

    ui->comboBox->insertItems(0, quantities);
    ui->comboBox->setCurrentIndex(2);
    N = 25;
    for(int i = 0; i < N; ++i)
        numbers.append(QRandomGenerator::global()->generate() % 16);

    chart1 = new MyChart(nullptr, numbers);
    chart2 = new MyChart(nullptr, numbers);
    ui->sort1Layout->addWidget(chart1->getChartView());
    ui->sort2Layout->addWidget(chart2->getChartView());
    algo1 = new QComboBox(); algo2 = new QComboBox();
    QStringList algorithms;
    algorithms.append("Bubble Sort");
    algorithms.append("Insert Sort");
    algorithms.append("Heap Sort");
    algorithms.append("Merge Sort");
    algorithms.append("Quick Sort");
    algo1->insertItems(0, algorithms); algo1->setCurrentIndex(0); index1 = 0;
    algo2->insertItems(0, algorithms); algo2->setCurrentIndex(1); index2 = 1;
    ui->sort1Layout->addWidget(algo1);
    ui->sort2Layout->addWidget(algo2);
    connect(&thread1, &QThread::finished, this, &MainWindow::enableButtons);
    connect(&thread1, &QThread::started, chart1, &MyChart::bubbleSort);
    connect(&thread2, &QThread::finished, this, &MainWindow::enableButtons);
    connect(&thread2, &QThread::started, chart2, &MyChart::insertSort);

    connect(algo1, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::algo1_currentIndexChanged);
    connect(algo2, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::algo2_currentIndexChanged);

    chart1->moveToThread(&thread1);
    chart2->moveToThread(&thread2);
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
//    switch(ui->comboBox->currentIndex())
//    {
//    case 0:
//        N = 10;
//        break;
//    case 1:
//        N = 15;
//        break;
//    case 2:
//        N = 25;
//        break;
//    case 3:
//        N = 50;
//        break;
//    case 4:
//        N = 100;
//        break;
//    default:
//        break;
//    }

    for(int i = 0; i < N; ++i)
        numbers.append(QRandomGenerator::global()->generate() % 16);
    chart1->newNumbers(numbers);
    chart2->newNumbers(numbers);
}

void MainWindow::on_sortButton_clicked()
{
    ui->generateButton->setDisabled(true);
    ui->sortButton->setDisabled(true);

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

void MainWindow::algo1_currentIndexChanged(int index)
{
    if(index == index1)
        return;
    switch(index1)
    {
    case 0:
        disconnect(&thread1, &QThread::started, chart1, &MyChart::bubbleSort);
        break;
    case 1:
        disconnect(&thread1, &QThread::started, chart1, &MyChart::insertSort);
        break;
    case 2:
        disconnect(&thread1, &QThread::started, chart1, &MyChart::heapSort);
        break;
    case 3:
        disconnect(&thread1, &QThread::started, chart1, &MyChart::mergeSort);
        break;
    case 4:
        disconnect(&thread1, &QThread::started, chart1, &MyChart::quickSort);
        break;
    default:
        break;
    }

    switch (index)
    {
    case 0:
        connect(&thread1, &QThread::started, chart1, &MyChart::bubbleSort);
        break;
    case 1:
        connect(&thread1, &QThread::started, chart1, &MyChart::insertSort);
        break;
    case 2:
        connect(&thread1, &QThread::started, chart1, &MyChart::heapSort);
        break;
    case 3:
        connect(&thread1, &QThread::started, chart1, &MyChart::mergeSort);
        break;
    case 4:
        connect(&thread1, &QThread::started, chart1, &MyChart::quickSort);
        break;
    default:
        break;
    }
    index1 = index;

}



void MainWindow::algo2_currentIndexChanged(int index)
{
    if(index == index2)
        return;
    switch(index2)
    {
    case 0:
        disconnect(&thread2, &QThread::started, chart2, &MyChart::bubbleSort);
        break;
    case 1:
        disconnect(&thread2, &QThread::started, chart2, &MyChart::insertSort);
        break;
    case 2:
        disconnect(&thread2, &QThread::started, chart2, &MyChart::heapSort);
        break;
    case 3:
        disconnect(&thread2, &QThread::started, chart2, &MyChart::mergeSort);
        break;
    case 4:
        disconnect(&thread2, &QThread::started, chart2, &MyChart::quickSort);
        break;
    default:
        break;
    }

    switch (index)
    {
    case 0:
        connect(&thread2, &QThread::started, chart2, &MyChart::bubbleSort);
        break;
    case 1:
        connect(&thread2, &QThread::started, chart2, &MyChart::insertSort);
        break;
    case 2:
        connect(&thread2, &QThread::started, chart2, &MyChart::heapSort);
        break;
    case 3:
        connect(&thread2, &QThread::started, chart2, &MyChart::mergeSort);
        break;
    case 4:
        connect(&thread2, &QThread::started, chart2, &MyChart::quickSort);
        break;
    default:
        break;
    }
    index2 = index;
}

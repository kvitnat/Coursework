#include "mychart.h"

QT_CHARTS_USE_NAMESPACE

MyChart::MyChart(QObject *parent, QList<int> numbers) : QObject(parent)
{
    set = new QBarSet("numbers");
    for(auto i : numbers)
        set->append(i);
    series = new QBarSeries();
    series->append(set);
    chart = new QChart();
    chart->addSeries(series);
    //axisX = new QBarCategoryAxis();
    //axisX->append(categories);
    //axisY = new QValueAxis();
    //axisY->setRange(0,15);
    //axisY->applyNiceNumbers();
    //chart->addAxis(axisY, Qt::AlignLeft);
    //series->attachAxis(axisY);
    chart->legend()->setVisible(false);
    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
}


void MyChart::newNumbers(QList<int> numbers)
{
    set->remove(0, set->count());
    for(auto i : numbers)
        set->append(i);
}

void MyChart::sortBubble()
{
    bool swapped;
    do {
        this->thread()->msleep(10);
        swapped = false;
        for(int i = 0; i < set->count() - 1; ++i)
        {
            this->thread()->msleep(20);
            if((*set)[i] > (*set)[i+1])
            {
                this->thread()->msleep(30);
                swapped = true;
                swap(i, i+1);
            }
        }
    } while(swapped == true);
    this->thread()->quit();
}

void MyChart::sortInsert()
{
    int index = 1;
    this->thread()->msleep(20);
    while(index < set->count()){
        this->thread()->msleep(20);
        if((*set)[index] < (*set)[index-1]){
            this->thread()->msleep(20);
            insert(index);
        }
        index++;
    }
    this->thread()->quit();
}

void MyChart::insert(int index)
{
    int indexTo;
    this->thread()->msleep(20);
    for(indexTo = 0; indexTo < index; indexTo++){
        this->thread()->msleep(20);
        if((*set)[indexTo] >= (*set)[index])
        {
            this->thread()->msleep(50);
            int temp = (*set)[index];
            set->remove(index);
            set->insert(indexTo, temp);
        }
    }
}

void MyChart::swap(int i, int j)
{
    if (i >= set->count() || j >= set->count() || i == j)
        return;
    int temp = (*set)[i];
    set->remove(i);
    set->insert(i, (*set)[j-1]);
    set->remove(j);
    set->insert(j, temp);
}



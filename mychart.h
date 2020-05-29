#ifndef MYCHART_H
#define MYCHART_H

#include <QObject>
#include <QWidget>
#include <QtCore>
#include <QDebug>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include "func.h"


QT_CHARTS_USE_NAMESPACE

class MyChart : public QObject
{
    Q_OBJECT


    QBarSet *set;
    QBarSeries *series;
    QChart *chart;
    QChartView *chartView;

    void swap(int, int);
    void insert(int);
    void heapify(int, int);
    void merge(int, int, int);
    void mergeSortRec(int, int);
    void quickSortRec(int, int);
    int  partition (int, int);


public:
    explicit MyChart(QObject *parent = nullptr, QList<int> numbers = QList<int>());
    QChartView* getChartView() { return chartView; }

    void newNumbers(QList<int> numbers);


public slots:
    void bubbleSort();
    void insertSort();
    void heapSort();
    void mergeSort();
    void quickSort();

signals:

};

#endif // MYCHART_H

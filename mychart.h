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


QT_CHARTS_USE_NAMESPACE

class MyChart : public QObject
{
    Q_OBJECT

    QBarSet *set;
    QBarSeries *series;
    QChart *chart;
    QChartView *chartView;
    QBarCategoryAxis *axisX;
    QValueAxis *axisY;
    QStringList categories;
    void swap(int, int);
    void insert(int);

public:
    explicit MyChart(QObject *parent = nullptr, QList<int> numbers = QList<int>());
    QChartView* getChartView(){
        return chartView;
    }


    void newNumbers(QList<int> numbers);

public slots:
    void sortBubble();
    void sortInsert();

signals:

};

#endif // MYCHART_H

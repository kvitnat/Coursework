#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include "mychart.h"
#include "func.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QList<int> numbers;
    int N;
    MyChart *chart1, *chart2;
    QThread thread1, thread2;
    QComboBox *algo1, *algo2;
    int index1, index2;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_generateButton_clicked();

    void on_sortButton_clicked();

    void enableButtons();

    void algo1_currentIndexChanged(int);

    void algo2_currentIndexChanged(int);


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

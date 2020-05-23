#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mychart.h"

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
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_generateButton_clicked();

    void on_sortButton_clicked();

    void enableButtons();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

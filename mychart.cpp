#include "mychart.h"

QT_CHARTS_USE_NAMESPACE

MyChart::MyChart(QObject *parent, QList<int> numbers) : QObject(parent)
{
    series = new QBarSeries();

    set = new QBarSet("numbers");
    for(auto i : numbers)
        set->append(i);

    series->append(set);
    chart = new QChart();
    chart->addSeries(series);
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

void MyChart::bubbleSort()
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

void MyChart::insertSort()
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



void MyChart::heapSort()
{
    int n = set->count();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(n, i);

    for (int i=n-1; i>=0; i--)
    {
        this->thread()->msleep(100);
        swap(0, i);
        heapify(i, 0);
    }
    this->thread()->quit();
}

void MyChart::heapify(int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    this->thread()->msleep(100);
    if (l < n && (*set)[l] > (*set)[largest])
        largest = l;
    if (r < n && (*set)[r] > (*set)[largest])
        largest = r;

    if (largest != i)
    {
        swap(i, largest);
        heapify(n, largest);
    }
}


void MyChart::mergeSort()
{
    mergeSortRec(0, set->count()-1);
    this->thread()->quit();
}

void MyChart::mergeSortRec(int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSortRec(l, m);
        mergeSortRec(m+1, r);

        merge(l, m, r);
    }
}

void MyChart::merge(int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    this->thread()->msleep(50);

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
    {   L[i] = (*set)[l + i];     this->thread()->msleep(50); }
    for (j = 0; j < n2; j++)
    {   R[j] = (*set)[m + 1+ j];  this->thread()->msleep(50); }

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            this->thread()->msleep(50);
            set->replace(k, L[i]);
            i++;
        }
        else
        {
            this->thread()->msleep(50);
            set->replace(k, R[j]);
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        this->thread()->msleep(50);
        set->replace(k, L[i]);
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        this->thread()->msleep(50);
        set->replace(k, R[j]);
        j++;
        k++;
    }
}

void MyChart::quickSort()
{
    quickSortRec(0, set->count()-1);
    this->thread()->quit();
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void MyChart::quickSortRec(int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(low, high);
        this->thread()->msleep(50);

        // Separately sort elements before
        // partition and after partition
        quickSortRec(low, pi - 1);
        quickSortRec(pi + 1, high);
    }
}

int MyChart::partition (int low, int high)
{
    int pivot = (*set)[high]; // pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j < high; j++)
    {   this->thread()->msleep(50);
        // If current element is smaller than the pivot
        if ((*set)[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(i, j);
        }
    }
    this->thread()->msleep(50);
    swap(i + 1, high);
    return (i + 1);
}



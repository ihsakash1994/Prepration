#include<iostream>
#include<cstdio>

using namespace std;

int n = 10;
int a[10] = {10, 20, 90, 80, 40, 30, 15, 60, 65, 5};

int Partition(int start, int end1)
{
    int partitionIndex = start;
    //cout << "Comapring with : " << a[end1] << endl;
    for(int i = start; i <= end1-1; i++)
    {
        if (a[i] <= a[end1])
        {
            //cout << "Swapping : " << a[i] << " : " << a[partitionIndex] << endl;
            swap(a[partitionIndex], a[i]);
            partitionIndex++;
        }
    }

    swap(a[partitionIndex], a[end1]);
    return partitionIndex;
}

void QuickSort(int start, int end1)
{
    if (start >= end1)return;
    //cout << a[start] << " " << a[end1] << endl;
    int pivot = Partition(start, end1);
    //cout << a[pivot] << endl;
    //for (int i = start; i <= end1; i++)cout << a[i] << " "; cout << endl;
    QuickSort(start, pivot-1);
    QuickSort(pivot+1, end1);
}

int main()
{
    QuickSort(0, 9);

    for(int i = 0 ; i < n; i++)cout << a[i] << " "; cout << endl;
}

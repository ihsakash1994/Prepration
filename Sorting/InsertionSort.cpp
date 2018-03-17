#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    int n = 10;
    int a[n] = {10, 20, 90, 80, 40, 30, 15, 60, 65, 5};

    for (int i = 1; i < n; i++)
    {
        for (int j = i-1; j >= 0; j--)
        {
            if (a[j] > a[j+1])swap(a[j+1], a[j]);
            else break;
        }
    }

    for (int i = 0; i < n; i++)cout << a[i] << " ";
    cout << endl;
}

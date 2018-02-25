#include <bits/stdc++.h>

using namespace std;

bool isPossible(vector<int> &A, int ans, int m)
{
    for(int i = 0; i < A.size(); i++)
    {
        if (A[i] > ans) return false;
    }

    int j = 0, total = A.size();
    for(int i = 1; i <= m; i++)
    {
        int temp = 0;
        int flag = 0;
        while(j < total && (total - j - 1) >= (m - i) && (temp+A[j]) <= ans)
        {
            temp += A[j];
            j++;
            flag = 1;
        }

        //cout << i << " : " << temp << endl;

        if (flag == 0)return false;
    }

    if (j < total)return false;
    return true;
}

long long binarySearch(vector<int> &A, int left, int right, int m)
{
    //cout << left << " " << right <<   " " <<(left+right) / 2 << endl;
    if (left == right) return left;

    int mid = (left+right) / 2;

    if (isPossible(A, mid, m))
    {
        return binarySearch(A, left, mid, m);
    }
    else
    {
        return binarySearch(A, mid+1, right, m);
    }
}

int books(vector<int> &A, int B) {
    int m = B;

    long long sum = 0;
    for (int i = 0; i < A.size(); i++)
    {
        sum = sum + (long long)A[i];
    }

    if (m > A.size()) return -1;

    return binarySearch(A, 1, sum, m);
}

int main()
{
    //91, 20, 62, 33, 97, 31, 88, 89, 73, 77, 4, 58, 0, 54, 60, 15, 47, 80, 30, 55, 46, 7, 38, 0, 26, 35, 57, 13
    vector<int> v;
    v.push_back(91);
    v.push_back(20);
    v.push_back(62);
    v.push_back(33);
    v.push_back(97);v.push_back(31);v.push_back(88);v.push_back(89);v.push_back(73);
    v.push_back(4);v.push_back(58);v.push_back(0);v.push_back(54);v.push_back(60);
    v.push_back(15);v.push_back(47);v.push_back(80);v.push_back(30);v.push_back(55);
    v.push_back(46);v.push_back(7);v.push_back(38);v.push_back(0);v.push_back(26);
    v.push_back(35);v.push_back(57);v.push_back(13);
    cout << books(v, 24) << endl;
}

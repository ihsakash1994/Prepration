#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int n = 10;
int a[10] = {10, 20, 90, 80, 40, 30, 15, 60, 65, 5};

vector<int> MergeSort(vector<int> v)
{
    if (v.size() == 1)return v;

    int len = v.size() / 2;
    vector<int> vl1, vr1;

    //cout << len << endl;
    for(int i = 0; i < len; i++)vl1.push_back(v[i]);
    for(int i = len; i < v.size(); i++)vr1.push_back(v[i]);
    //cout << vl1.size() << " " << vr1.size() << endl;
    vector<int> vl = MergeSort(vl1);
    vector<int> vr = MergeSort(vr1);
    //cout << "a \n";
    //v.clear();

    vector<int> ans;
    int l = 0, r = 0;
    while (l < vl.size() || r < vr.size())
    {
        if (r >= vr.size() || vl[l] < vr[r])
        {
            ans.push_back(vl[l]);
            l++;
        }
        else if (l >= vl.size() || vl[l] >= vr[r])
        {
            ans.push_back(vr[r]);
            r++;
        }
        //cout << v.size() << endl;
    }

    return ans;

}

int main()
{
    vector<int> v;
    for (int i = 0 ; i < n; i++)v.push_back(a[i]);
    v.push_back(2);
    v.push_back(1);
    v = MergeSort(v);

    for (int i = 0; i < v.size(); i++)cout << v[i] << " "; cout << endl;
}


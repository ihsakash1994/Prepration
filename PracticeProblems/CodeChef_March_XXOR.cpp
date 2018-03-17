#include<iostream>
#include<cstdio>

#define maxn 112345

using namespace std;

long long a[maxn];
long long ans[maxn][32];
long long power[32];

int main()
{
    int n, q;
    cin >> n >> q;

    power[0] = (long long)1;
    for (int i = 1; i < 31; i++)
    {
        power[i] = (long long)2 * power[i-1];
    }

    //cout << power[31] << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < 31; j++)
        {
            if ((a[i] & power[j]) > 0)
            {
                ans[i][j] = 1;
            }
            else
            {
                ans[i][j] = 0;
            }
        }
    }

    for (int j = 0; j < 31; j++)
    {
        for (int i = 1; i < n; i++)
        {
            ans[i][j] += ans[i-1][j];
        }
    }

    while(q--)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;

        int len = (y- x + 2) / 2;

        //cout <<  " len : " << len << endl;
        long long fans = (long long)0;

        for (int j = 0; j < 31; j++)
        {
            int ct = ans[y][j];
            if (x > 0)ct -= ans[x-1][j];

            //if (j <= 4)cout << ct << " " << power[j] << endl;

            if (ct < len)
            {
                //cout << ct << " "<<j<< " " <<   endl;
                fans += power[j];
            }
        }

        cout << fans << endl;
    }

}

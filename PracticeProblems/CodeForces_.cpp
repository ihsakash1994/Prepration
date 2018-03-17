#include <bits/stdc++.h>

#define maxn 112345

using namespace std;

long long a[maxn], m[maxn];
priority_queue <long long, vector<long long>, greater<long long> > pq;


long long solve(long long melt, long long x, long long tm)
{
    //cout << melt <<  " : " << x << " " << tm << endl;
    if (pq.size() == 0)
    {
        if (x > 0)
        {
            pq.push(x);
        }
        return 0;
    }

    long long ans = 0;
    while (!pq.empty())
    {
        long long temp = (pq.top() - (melt-tm));
        if (temp <= 0)
        {
            pq.pop();
            continue;
        }
        else if (temp <= tm)
        {
            ans += temp;
            pq.pop();
        }
        else
        {
            break;
        }
    }


    long long temp = ans + (long long)pq.size() * tm;

    if (x > 0)
    {
        pq.push(x);
    }

    return temp;


}

int main()
{
    /*gquiz.push(10);
    gquiz.push(30);
    gquiz.push(20);
    gquiz.push(5);
    gquiz.push(1);

    cout << "The priority queue gquiz is : ";
    showpq(gquiz);*/

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)cin >> a[i];
    for (int i = 1; i <= n; i++)cin >> m[i];

    long long totalMelt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (m[i] == 0)
        {
            cout << 0 << " ";
            pq.push(a[i] + (totalMelt - m[i]));
            continue;
        }

        totalMelt += m[i];
        long long ans = 0;
        if (a[i] <= m[i])
        {
            ans = a[i];
        }
        else
        {
            ans = m[i];
        }

        long long temp = solve(totalMelt, a[i] + totalMelt - m[i], m[i]);

        //cout << ans << " " << temp << endl;
        printf("%lld ", ans +  temp);//<< " ";
    }

    cout << "\n";

}

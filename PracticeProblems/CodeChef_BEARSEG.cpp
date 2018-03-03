#include<iostream>
#include<cstdio>
#include<map>
#include<set>

#define maxm 112345

using namespace std;

long long a[maxm], sum[maxm];
map<long long, long long> mp;


int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long n , p;
        cin >> n >> p;

        for(int i = 1; i <= n; i++)
        {
            long long x;
            cin >> x;
            a[i] = x % p;
        }

        sum[0] = 0;
        sum[a] = a[1];
        mp[a[1]] = 1;
        for(int i = 2; i <= n; i++)
        {
            sum[i] = (sum[i-1] + a[i]) % p;
        }


    }
}

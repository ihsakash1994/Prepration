#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define maxm 51234
#define maxn 100004
using namespace std;
using namespace __gnu_pbds;

int a[maxm];

vector<int> t[maxm];
bool prime[maxn];

//set<int> akash[maxn];

tree<int,         /* key                */
         null_type,   /* mapped             */
         less<int>,   /* compare function   */
         rb_tree_tag, /* red-black tree tag */
         tree_order_statistics_node_update> akash[maxn];

int power2(int x)
{
    int ans = 1;
    for(int i = 1; i <= x; i++)ans = ans * 2;
    return ans;
}

void SieveOfEratosthenes(long long n)
{

    for (int i = 0; i < n+1; i++)prime[i] = true;

    for (long long p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
}

void InsertAndEraseInAkash(int ix, int maxBit, vector<int> v, bool isErase)
{
    for(int j = 1; j <= maxBit; j++)
    {
        int y = j, ct = 0, temp = 1;
        while(y != 0)
        {
            if (y%2 == 1)
            {
                temp = temp * v[ct];
            }

            y = y/2;
            ct++;
        }

        if (isErase)akash[temp].erase(ix);
        else akash[temp].insert(ix);
    }
}

vector<int> PrimeVec(int num)
{
    vector<int> temp;
    for (int j = 1; j <= (int)sqrt(num); j++)
    {
        if (num % j == 0)
        {
            int a = j, b = num / j;
            if (a != 1 && prime[a])temp.push_back(a);
            if (a != b && prime[b])temp.push_back(b);
        }
    }

    return temp;
}

int CalAns(int maxBit, vector<int> v, int l, int r)
{
    int ans = (r - l + 1);
    //cout << ans << endl;
    for(int j = 1; j <= maxBit; j++)
    {
        int y = j, ct = 0, temp = 1, setc = 0;
        while(y != 0)
        {
            if (y%2 == 1)
            {
                setc++;
                temp = temp * v[ct];
            }

            y = y/2;
            ct++;
        }

        if (setc % 2 == 0)
        {
            int ct1 = akash[temp].order_of_key(l);//std::distance(akash[temp].begin(), akash[temp].lower_bound(l));
            int ct2 = akash[temp].order_of_key(r+1);//std::distance(akash[temp].begin(), akash[temp].upper_bound(r));
            ans += (ct2 - ct1);
            //cout << setc << " " <<temp << ": " << (ct2 - ct1) << endl;
        }
        else
        {
            int ct1 = akash[temp].order_of_key(l);//std::distance(akash[temp].begin(), akash[temp].lower_bound(l));
            int ct2 = akash[temp].order_of_key(r+1);//std::distance(akash[temp].begin(), akash[temp].upper_bound(r));
            ans -= (ct2 - ct1);
            //cout <<setc << " " << temp << ": " << -(ct2 - ct1)<< endl;
        }
    }

    return ans;
}

int main()
{
    SieveOfEratosthenes(100000);

    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        a[i] = x;
        t[i] = PrimeVec(x);
    }

    for(int i = 1; i <= n; i++)
    {
        //for(int j = 0; j < t[i].size(); j++)cout << t[i][j] << " "; cout << endl;
    }


    for (int i = 1; i <= n; i++)
    {
        InsertAndEraseInAkash(i, power2(t[i].size()) - 1, t[i], false);
    }

    int q;
    scanf("%d", &q);

    while(q--)
    {
        int type;
        scanf("%d", &type);
        if (type == 1)
        {
            int x, y;
            scanf("%d %d", &x, &y);

            int temp1 = a[x];
            vector<int> temp = PrimeVec(a[x]);
            InsertAndEraseInAkash(x, power2(temp.size()) - 1, temp, true);

            temp.clear();
            temp = PrimeVec(y);
            InsertAndEraseInAkash(x, power2(temp.size()) - 1, temp, false);

            a[x] = y;
        }

        if (type == 2)
        {
            int l, r, g;
            scanf("%d%d%d", &l, &r, &g);
            vector<int> temp = PrimeVec(g);

            //for(int i = 0; i < temp.size(); i++)cout << temp[i] << " "; cout << endl;
            printf("%d\n", CalAns(power2(temp.size()) - 1, temp, l, r));//<< CalAns(power2(temp.size()) - 1, temp, l, r) << endl;// << " " << ans<< endl;
        }
    }
}

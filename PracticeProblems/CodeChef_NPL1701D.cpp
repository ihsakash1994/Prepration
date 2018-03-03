#include <iostream>
#include<vector>

#define mod 1000000007
using namespace std;

vector<int> graph[112345];
int visited[112345];
long long nodes[112345];
long long fact[112345];

long long power(long long a, long long b)
{
    long long ans = 1;
    while(b)
    {
        if (b % 2 == 1)ans = (ans * a) % mod;

        b = b / 2;
        a = (a * a) % mod;
    }

    //cout << a << " " <<  b << " " << ans << endl;
    return ans;
}

long long inverse(long long x)
{
    return power(x, mod-2);
}

long long nCr(long long x ,long long y)
{
    //cout << x << " nCr " << y << " : " << fact[x] << " " << fact[y] << endl;
    long long temp1 = (fact[x] * inverse(fact[y])) % mod;
    //cout << temp1 << " <-\n";
    temp1 = (temp1 * inverse(fact[x-y])) % mod;

    return temp1;
}

long long calVertex(int root)
{
    visited[root] = 1;
    long long ans = (long long)1;
    for (int i = 0; i < graph[root].size(); i++)
    {
        if (visited[graph[root][i]] == 0)
        {
            ans = ans + calVertex(graph[root][i]);
        }
    }

    nodes[root] = ans;
    return ans;
}

long long solve(int root)
{
    visited[root] = 1;
    int ans = 1;
    vector<int> childSize;
    for (int i = 0; i < graph[root].size(); i++)
    {
        if (visited[graph[root][i]] == 0)
        {
            ans = (ans * solve(graph[root][i])) % mod;
            childSize.push_back(nodes[graph[root][i]]);
        }
    }

    if (childSize.size() == 2)
    {
        ans = (ans * nCr(childSize[0]+childSize[1], childSize[0])) % mod;
    }

    return ans;
}

int main()
{
    int n;
    int root;
    cin >> n >> root;

    fact[0] = (long long)1;
    for (int i = 0; i <= n+1; i++)
    {
        visited[i] = 0;
        nodes[i] = 0;

        if (i != 0)
        {
            fact[i] = ((long long)i * fact[i-1]) % mod;
            //cout << fact[i] << endl;
        }
    }

    //cout << nCr(5, 2) << endl;

    for(int i = 1; i <= n-1; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    calVertex(root);

    for (int i = 0; i <= n+1; i++)
    {
        visited[i] = 0;
    }

    cout << solve(root) << endl;

    //for(int i = 1; i <= n; i++)cout << nodes[i] << " ";
}

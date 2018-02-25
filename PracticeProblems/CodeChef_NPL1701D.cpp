#include <iostream>
#include<vector>

#define mod 1000000007
using namespace std;

vector<int> grpah[112345];
int visited[112345];

long long solve(int root)
{
    visited[root] = 1;
    long long num = 0, ans = 1;
     //cout << root << " " << num << " " << ans << endl;
    for(int i = 0; i < grpah[root].size(); i++)
    {
        if (visited[grpah[root][i]] == 0)
        {
            ans = (ans * solve(grpah[root][i])) % mod;
            num++;
        }
    }

    //cout << root << " " << num << " " << ans << endl;
    if(num == 0)return 1;
    else return (num*ans) % mod;
}

int main()
{
    int n;
    int root;
    cin >> n >> root;
    for (int i = 0; i <= n+1; i++)visited[i] = 0;


    for(int i = 1; i <= n-1; i++)
    {
        int x, y;
        cin >> x >> y;
        grpah[x].push_back(y);
        grpah[y].push_back(x);
    }

    long long ans = solve(root);

    cout << ans << endl;
}

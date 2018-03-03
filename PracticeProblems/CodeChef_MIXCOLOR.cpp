#include<iostream>
#include<cstdio>
#include<map>

using namespace std;

map<int, int> mp;
map<int,int>::iterator it;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        mp.clear();
        int n;
        cin >> n;

        for(int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            it = mp.find(x);

            if (it != mp.end())
            {
                mp[x] = mp[x] + 1;
            }
            else
            {
                mp[x] = 1;
            }

        }

        long long ans = 0;

        for (it = mp.begin(); it != mp.end(); ++it)
        {
            //std::cout << it->first << " => " << it->second << '\n';
            ans = ans + (it->second-1);
        }

        cout << ans << endl;
    }
}

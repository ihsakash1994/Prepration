#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>

#define maxm 112345

using namespace std;

struct Node
{
    long long val;
    long long l;
    long long r;

    Node(long long lt, long long rt, long long vl) : val(vl), l(lt), r(rt) {}
};

long long a[maxm];
long long ans[maxm];
vector<Node *> v;

int main()
{
    /** Node* n = new Node();
    n->val = 1;
    //cout << n-> val << " " << n->l << endl;
    v.push_back(n);
    //cout << v[0]->val << endl; **/

    long long t;
    cin >> t;

    while(t--)
    {
        v.clear();
        long long n;
        cin >> n;
        long long len = sqrt(n);

        for (long long i = 0; i <= n+2; i++)ans[i] = 0;
        for (long long i = 1; i <= n; i++)cin >> a[i];

        //cout << "Sqrt: " << len << endl;

        for (long long i = n-1; i >= 1; i--)
        {
            //cout << "First loop for : " << i << endl;
            if (v.size() == 0)
            {
                v.push_back(new Node(i, i, a[i]));
                ans[i+1] += 1;
                ans[i+2] -= 1;

                //cout << "l : " << i+1 << " , " << "r : " << i+2 << endl;
                continue;
            }

            long long l = i + 1, r, temp = 0;

            for (long long j = v.size()-1; j >= 0; j--)
            {
                //cout << "Sqrt Loop : " << j << endl;
                temp = temp + v[j]->val;
                //cout << " temp : " << temp << endl;

                //cout << v[j]->l << " : " << v[j]->r << " : " << v[j]->val << endl;
                if (temp < a[i])
                {
                    r = v[j]->r + 1;
                    continue;
                }
                else if (temp == a[i])
                {
                    r = v[j]->r + 1;
                    break;
                }
                else
                {
                    temp = temp - v[j]->val;
                    for (long long x = v[j]->l; x <= v[j]->r; x++)
                    {
                        temp += a[x];
                        if (temp < a[i])continue;
                        else if (temp == a[i])
                        {
                            r = x+1;
                            break;
                        }
                        else
                        {
                            r = x;
                            break;
                        }
                    }
                    break;

                }
            }

            r++;

            //cout << "l : " << l << " , " << "r : " << r << endl;
            ans[l] += 1;
            ans[r] -= 1;

            if ((v[v.size()-1]->r - v[v.size()-1]->l + 1) < len)
            {
                v[v.size()-1]->l = i;
                v[v.size()-1]->val += a[i];
            }
            else
            {
                v.push_back(new Node(i, i, a[i]));
            }
        }

        v.clear();

        for (long long i = 2; i <= n; i++)
        {
            //cout << "First loop for : " << i << endl;
            if (v.size() == 0)
            {
                v.push_back(new Node(i, i, a[i]));
                //cout << "l : " << i-1 << " , " << "r : " << i << endl;
                ans[i] -= 1;
                ans[i-1] += 1;
                continue;
            }

            long long l, r = i, temp = 0;

            for (long long j = v.size()-1; j >= 0; j--)
            {
                temp = temp + v[j]->val;
                if (temp < a[i])
                {
                    l = v[j]->l;
                    continue;
                }
                else if (temp == a[i])
                {
                    l = v[j]->l;
                    break;
                }
                else
                {
                    temp = temp - v[j]->val;
                    for (long long x = v[j]->r; x >= v[j]->l; x--)
                    {
                        temp += a[x];
                        if (temp < a[i])continue;
                        else if (temp == a[i])
                        {
                            l = x;
                            break;
                        }
                        else
                        {
                            l = x+1;
                            break;
                        }
                    }
                    break;

                }
            }

            l--;
            //cout << "l : " << l << " , " << "r : " << r << endl;
            ans[l] += 1;
            ans[r] -= 1;

            if ((v[v.size()-1]->r - v[v.size()-1]->l + 1) < len)
            {
                v[v.size()-1]->r = i;
                v[v.size()-1]->val += a[i];
            }
            else
            {
                v.push_back(new Node(i, i, a[i]));
            }
        }

        long long temp1 = 0;
        for (long long i = 1; i <= n; i++)
        {
            cout << (temp1 + ans[i]) << " ";
            temp1 += ans[i];
        }

        cout << endl;
    }
}

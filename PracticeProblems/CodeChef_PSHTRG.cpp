#include<iostream>
#include<cstdio>
#include<vector>
#include <algorithm>

#define maxm 112345

using namespace std;

int a[maxm];
vector<int> v;

struct Node
{
    int left;
    int right;
    vector<int> vec;
};

Node SegmentTree[2123456];

void construct(int i, int j, int ix)
{
    if (i == j)
    {
        Node ans;
        ans.left = i;
        ans.right = j;
        vector<int> temp1;
        temp1.push_back(a[i]);
        ans.vec = temp1;

        SegmentTree[ix] = ans;

        return;
    }

    int mid = (i+j) / 2;

    construct(i, mid, 2*ix);
    construct(mid+1, j, 2*ix+1);

    vector<int> temp;

    int x = 0, y = 0;
    while(temp.size() <= 61)
    {
        if(x == (SegmentTree[2*ix].vec).size() && y == (SegmentTree[2*ix + 1].vec).size())break;
        else if (y == (SegmentTree[2*ix + 1].vec).size())
        {
            temp.push_back(SegmentTree[2*ix].vec[x]);
            x++;
        }
        else if (x == (SegmentTree[2*ix]).vec.size())
        {
            temp.push_back(SegmentTree[2*ix+1].vec[y]);
            y++;
        }
        else if(SegmentTree[2*ix].vec[x] > SegmentTree[2*ix + 1].vec[y])
        {
            temp.push_back(SegmentTree[2*ix].vec[x]);
            x++;
        }
        else
        {
            temp.push_back(SegmentTree[2*ix+1].vec[y]);
            y++;
        }
    }

    Node ans;
    ans.left = i;
    ans.right = j;
    ans.vec = temp;

    SegmentTree[ix] = ans;
}

void update1(int pos, int val, int ix)
{
    int mn = SegmentTree[ix].left, mx = SegmentTree[ix].right;

    if (mn == mx)
    {
        vector<int> temp;
        temp.push_back(val);
        SegmentTree[ix].vec = temp;
        return;
    }

    int lmn = SegmentTree[2*ix].left, lmx = SegmentTree[2*ix].right;
    if (pos <= lmx && pos >= lmn)
    {
        update1(pos, val, 2*ix);
    }
    else
    {
        update1(pos, val, 2*ix+1);
    }

    vector<int> temp;
    int x = 0, y = 0;
    while(temp.size() <= 61)
    {
        if(x == (SegmentTree[2*ix].vec).size() && y == (SegmentTree[2*ix + 1].vec).size())break;
        else if (y == (SegmentTree[2*ix + 1].vec).size())
        {
            temp.push_back(SegmentTree[2*ix].vec[x]);
            x++;
        }
        else if (x == (SegmentTree[2*ix]).vec.size())
        {
            temp.push_back(SegmentTree[2*ix+1].vec[y]);
            y++;
        }
        else if(SegmentTree[2*ix].vec[x] > SegmentTree[2*ix + 1].vec[y])
        {
            temp.push_back(SegmentTree[2*ix].vec[x]);
            x++;
        }
        else
        {
            temp.push_back(SegmentTree[2*ix+1].vec[y]);
            y++;
        }
    }

    SegmentTree[ix].vec = temp;
}

void update(int pos, int val)
{
    a[pos] = val;
}

vector<int> query1(int l, int r, int ix)
{
    //cout << l << " " << r << " " << ix << endl;
    int mn = SegmentTree[ix].left, mx = SegmentTree[ix].right;
    //cout << mn << " " << mx << endl;
    if (l == mn && r == mx)
    {
        return SegmentTree[ix].vec;
    }


    vector<int> temp1;
    if (l <= SegmentTree[2*ix].right)temp1 = query1(l, min(r,SegmentTree[2*ix].right), 2*ix);
    else temp1.clear();
    vector<int> temp2;
    if (r >= SegmentTree[2*ix+1].left)temp2 = query1(max(l, SegmentTree[2*ix+1].left), r, 2*ix+1);
    else temp2.clear();

    vector<int> temp;
    int x = 0, y = 0;
    while(temp.size() <= 61)
    {
        if(x == temp1.size() && y == temp2.size())break;
        else if (y == temp2.size())
        {
            temp.push_back(temp1[x]);
            x++;
        }
        else if (x == temp1.size())
        {
            temp.push_back(temp2[y]);
            y++;
        }
        else if(temp1[x] > temp2[y])
        {
            temp.push_back(temp1[x]);
            x++;
        }
        else
        {
            temp.push_back(temp2[y]);
            y++;
        }
    }

    return temp;
}

long long query(int l, int r)
{
    v.clear();
    for (int i = l; i <= r; i++)
    {
        v.push_back(a[i]);
    }

    sort (v.begin(), v.begin()+v.size());

    long long ans = (long long)0;
    for (int i = v.size()-1; i >= 2; i--)
    {
        if ((v[i-1] + v[i-2]) > v[i])
        {
            ans = (long long)v[i-1] + (long long)v[i-2] + (long long)v[i];
            break;
        }
    }

    return ans;
}

int main()
{
    int n, q;
    scanf("%d%d", &n, &q);

    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }

    construct(1, n, 1);

    /**for(int i = 1; i <= 10; i++)
    {
        for(int j = 0; j < SegmentTree[i].vec.size(); j++)
        {
            cout << SegmentTree[i].vec[j] << " ";
        }
        cout << endl;
    }
    cout << endl;**/

    while(q--)
    {
        int type;
        scanf("%d", &type);

        if (type == 1)
        {
            int pos, val;
            scanf("%d%d", &pos, &val);
            //update(pos, val);
            update1(pos, val, 1);
        }
        else
        {
            int l, r;
            scanf ("%d%d", &l, &r);
            vector<int> ans1 = query1(l, r, 1);

            long long ans = (long long)0;
            //cout << ans1.size() << endl;
            int num = ans1.size();
            for (int i = 0; i <= num -3; i++)
            {
                //cout << i << " i:s " << ans1.size() <<  " " << num- 3 <<endl;
                //cout << ans1[i] << " -<\n";
                if ((ans1[i+1] + ans1[i+2]) > ans1[i])
                {
                    ans = (long long)ans1[i+1] + (long long)ans1[i+2] + (long long)ans1[i];
                    break;
                }
            }

            //printf("%lld\n", query(l, r));
            printf("%lld\n", ans);
        }
    }
}

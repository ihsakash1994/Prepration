#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include <string>

#include <sstream>

using namespace std;

string IntToString (int a)
{
    ostringstream temp;
    temp<<a;
    return temp.str();
}


struct Node
{
    vector<Node *> child;
    int ct;
};

string intToString(int num)
{
    vector<int> temp, temp1;
    if (num == 0)temp.push_back(0);
    while(num)
    {
        temp.push_back(num%10);
        num = num / 10;
    }

    string s = "";
    for(int j = temp.size()-1; j >= 0; j--)
    {
        //cout << temp[j];
        s = s + (char)(temp[j] - '0');
    }

    return s;
}

vector<int> fans;

Node* createTrie(Node *root, vector<int> v, int pos)
{
    //if (pos < v.size())cout << v[pos] << endl;
    if (root == NULL)
    {
        root = new Node();
        root->ct = 0;
        for(int i = 0; i < 10; i++)root->child.push_back(NULL);
    }

    root->ct++;

    if (pos < v.size())
    {
        root->child[v[pos]] = createTrie(root->child[v[pos]], v, pos+1);
    }

    return root;

}

void prinTrie(Node *root, int num)
{
    //if (root == NULL)cout << "Root is null\n";
    //cout << "Num : " <<num << endl;

    int x = num % 10;
    int ix = 9;

    for(; ix >= 0  ; ix--)
    {

    }
    int childCt = 0;
    for(int i = 0; i < 10; i++)
    {
        if(root->child[i] != NULL)
        {
            //cout << "For :" << i << endl;
            childCt += (root->child[i])->ct;
        }
    }

    //cout << "ChildCt : " <<childCt << endl;

    int ct = root->ct - childCt;

    //if
    while(ct--)cout << (num) << endl;

    for(int i = 9; i >= 0; i--)
    {
        if(root->child[i] != NULL)
        {
            prinTrie(root->child[i], num*10 + i);
        }
    }
}


void largestNumber(const vector<int> &A)
{
    Node* root = NULL;
    for(int i = 0; i < A.size(); i++)
    {
        int num = A[i];
        vector<int> temp, temp1;
        if (num == 0)temp.push_back(0);
        while(num)
        {
            temp.push_back(num%10);
            num = num / 10;
        }

        for(int j = temp.size()-1; j >= 0; j--)
        {
            cout << temp[j];
            temp1.push_back(temp[j]);
        }
        cout << endl;

        root = createTrie(root, temp1, 0);
    }

    cout << endl << endl;

    prinTrie(root, 0);
}

int main()
{
    cout << endl << IntToString(10) << endl;;
    //cout << iThDigir(40, 3) << endl;
    vector<int> v;
    v.push_back(89);
    v.push_back(8);
    //v.push_back(669);
    //v.push_back(9983248);
    //v.push_back(660);
    //v.push_back(99);

    largestNumber(v);
}


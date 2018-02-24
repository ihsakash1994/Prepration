#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int val;
    int flag;
    Node* left;
    Node* right;

    Node(int val)
    {
        this->flag = 0;
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST
{
    public:
      BST()
      {
          this->Root = NULL;
      }

      Node* Root;

      Node* AddNode(Node* subRoot, int val)
      {
          if (subRoot == NULL)
          {
              return new Node(val);
          }
          else if (val <= subRoot->val)
          {
              subRoot->left = this->AddNode(subRoot->left, val);
          }
          else
          {
              subRoot->right = this->AddNode(subRoot->right, val);
          }

          return subRoot;
      }

      void InOrder(Node* subRoot)
      {
          if (subRoot == NULL)return;

          InOrder(subRoot->left);
          cout << subRoot->val << " ";
          InOrder(subRoot->right);
      }

      void InOrderIterativeApproach()
      {
          stack<Node*> st;
          if (this->Root == NULL)return;

          st.push(this->Root);

          while (!st.empty())
          {
              Node* top = st.top();
              if (top->left != NULL && top->left->flag == 0)
              {
                   st.push(top->left);
              }
              else if (top->right != NULL && top->right->flag == 0)
              {
                    top->flag = 1;
                    st.pop();
                    cout << top->val << " ";
                    st.push(top->right);
              }
              else
              {
                  top->flag = 1;
                  st.pop();
                  cout << top->val << " ";
              }
          }
      }

      void InOrderIterativeApproachInPlace()
      {
          if (this->Root == NULL)
          {
              return;
          }

          stack<Node*> st;
          Node* current = this->Root;
          bool flag = true;

          while (flag)
          {
              if (current != NULL)
              {
                  st.push(current);
                  current = current->left;
              }
              else if (!st.empty())
              {
                  current = st.top();
                  cout << current->val << " ";
                  st.pop();

                  current = current->right;
              }
              else
              {
                  flag = false;
              }
          }
      }
};

int main()
{
    BST* bst = new BST();
    bst->Root = bst->AddNode(bst->Root, 10);
    bst->AddNode(bst->Root, 20);
    bst->AddNode(bst->Root, 70);
    bst->AddNode(bst->Root, 90);
    bst->AddNode(bst->Root, 80);
    bst->AddNode(bst->Root, 40);
    bst->AddNode(bst->Root, 90);
    bst->AddNode(bst->Root, 100);
    bst->InOrder(bst->Root);
    cout << endl;
    cout << "Iterative 1:" << endl;
    bst->InOrderIterativeApproach();
    cout << endl <<"Iterative 2:" << endl;
    bst->InOrderIterativeApproachInPlace();
    cout << endl;
}

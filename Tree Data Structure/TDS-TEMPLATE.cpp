#include <iostream>
#include <string>
#include <sstream>
#include <bits/stdc++.h>
#include <stack>
#include <cmath>
#include <iomanip>
#include <map>
#include <iterator>
#include <string.h>
#define M 1000000007
using namespace std;

struct TreeNode 
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}};

//Printers

    void printVec(vector<int> &v)
    {
        int N = v.size();
        for(int i=0;i<N;i++)
        {
            cout << v[i] << " ";
        }
        cout <<endl;}

    void printVecvec(vector<vector<int>> &vec)  
    {
        for(int i=0;i<vec.size();i++)
        {
            for(int j=0;j<vec[i].size();j++)
                cout << vec[i][j] << " ";
            cout << endl;        
        }}

    void showpq(priority_queue<int> gq)
    {
        priority_queue<int> g = gq;
        while (!g.empty()) {
            cout << '\t' << g.top();
            g.pop();
        }
        cout << '\n';}

    void minshowpq(priority_queue<int, vector<int>, greater<int> > gq)
    {
        priority_queue<int, vector<int>, 
                                    greater<int> > g = gq;
        while (!g.empty()) {
            cout << '\t' << g.top();
            g.pop();
        }
        cout << '\n';}

    void PrintMap(map<int,int> &mp)
    {
        map<int, int>::iterator itr;
        for (itr = mp.begin(); itr != mp.end(); ++itr) {
            cout << '\t' << itr->first
                 << '\t' << itr->second << '\n';}}

    void printDeque(deque<int> &mydeque)
    {
        for (auto it = mydeque.begin(); it != mydeque.end(); ++it)
            cout << ' ' << *it;
        cout<<endl;}

    struct Trunk
    {
        Trunk *prev;
        string str;
     
        Trunk(Trunk *prev, string str)
        {
            this->prev = prev;
            this->str = str;
        }
    };
     
    // Helper function to print branches of the binary tree
    void showTrunks(Trunk *p)
    {
        if (p == nullptr) {
            return;
        }
     
        showTrunks(p->prev);
        cout << p->str;
    }
     
    // Recursive function to print a binary tree.
    // It uses the inorder traversal.
    void printTree(TreeNode* root, Trunk *prev, bool isLeft)
    {
        if (root == nullptr) {
            return;
        }
     
        string prev_str = "    ";
        Trunk *trunk = new Trunk(prev, prev_str);
     
        printTree(root->right, trunk, true);
     
        if (!prev) {
            trunk->str = "———";
        }
        else if (isLeft)
        {
            trunk->str = ".———";
            prev_str = "   |";
        }
        else {
            trunk->str = "`———";
            prev->str = prev_str;
        }
     
        showTrunks(trunk);
        cout << root->data << endl;
     
        if (prev) {
            prev->str = prev_str;
        }
        trunk->str = "   |";
     
        printTree(root->left, trunk, false);
    }    

int maxValue(struct TreeNode* node)
{  
    /* loop down to find the rightmost leaf */
    struct TreeNode* current = node;
    while (current->right != NULL)
        current = current->right;
     
    return (current->data);}

TreeNode* getSuccessor(TreeNode* root, int B)
{
    if(B>=maxValue(root)) return NULL;

    //Initialising with root
    TreeNode* temp = root;
    TreeNode* ancestor = root;

    int error = 10;
    cout<<"Temp : "<<temp->data<<" -> ";

    //Seaching the element
    while((temp->left || temp->right) && error)
    {
        if(temp->data > B)
        {
            ancestor = temp;
            temp = temp->left;
        }
        else if(temp->data < B)
            temp = temp->right;
        else
            break;
        
        cout<<temp->data<<" -> ";
        error--;
    }

    /*if(temp->data != B)
    {
        if(temp->left->data >= B) temp = temp->left;
        else temp = temp->right;}
    cout<<temp->data<<" -> ";*/

    //If RST Exists
    if(temp->right)
    {
        temp = temp->right;
        cout<<temp->data<<" -> ";

        if(temp->left)
        {
            while(temp->left)
            {
                temp = temp->left;
                cout<<temp->data<<" -> ";
            }
        }
        return temp;
    }

    cout<<endl<<"Ancestor Data :"<<ancestor->data<<endl;
    //If RST doesn't exists
    if(!temp->right)
    {
        if(ancestor->left->data > B)
            ancestor = ancestor->left;
        return ancestor;
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt     
    freopen("input1.txt","r",stdin);
    // for writing output to output.txt
    freopen("output.txt","w",stdout);
  #endif
  
    TreeNode* root = new TreeNode(15);

    root->left  = new TreeNode(10);
    root->right = new TreeNode(20);

    root->left->left   = new TreeNode(8);
    root->left->right  = new TreeNode(12);
    root->right->left  = new TreeNode(17);
    root->right->right = new TreeNode(25);

    root->left->left->left    = new TreeNode(6);
    root->left->right->left   = new TreeNode(11);
    root->right->left->left   = new TreeNode(16);
    root->right->right->right = new TreeNode(27);

    int B = 30;

    printTree(root, nullptr, false);
    cout<<endl<<"We need the node corresponding to "<<B<<endl<<endl;

    TreeNode* ans = getSuccessor(root,B);
    cout<<endl<<"Answer : "<<ans->data<<endl;

    return 0;
}
/*
Given the tree
               100
              /   \
            98    102
           /  \
         96    99
          \
           97
Given 97, you should return the node corresponding to 
98 as thats the value just greater than 97 in the tree.
If there are no successor in the tree ( the value is the 
largest in the tree, return NULL).

Given the tree
               20
              /  \
             8   22
            / \
           4  12
              / \
             10 14

In the above diagram, inorder successor of 8 is 10, 
inorder successor of 10 is 12 and inorder successor of 14 is 20.

Given the tree
               15
              /  \
             10   20
            / \   / \
           8  12 17 25
          /   /  /   \
         6   11 16   27

*/


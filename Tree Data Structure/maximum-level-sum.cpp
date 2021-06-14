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

int maxLevelSum(TreeNode* root)
{
    //Creating Variables
    int max_sum = INT_MIN;

    //BASE CASE
    if(root==NULL) return 0;

    //Preparing for Level Order Traversal
    queue<TreeNode*> q; 
    q.push(root);

    while(!q.empty())
    {
        int sum = 0;
        int count = q.size();

        while(count--)
        {
            TreeNode* temp = q.front();
            q.pop();

            sum += temp->data;
            if(temp->left != NULL)
                q.push(temp->left);
            if(temp->right != NULL)
                q.push(temp->right);
        }

        max_sum = max(max_sum,sum);
    }

    return max_sum;
}

int main()
{
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt     
    freopen("input1.txt","r",stdin);
    // for writing output to output.txt
    freopen("output.txt","w",stdout);
  #endif
  
    TreeNode* root = new TreeNode(4);

    root->left  = new TreeNode(2);
    root->right = new TreeNode(-5);

    root->left->left   = new TreeNode(-1);
    root->left->right  = new TreeNode(3);
    root->right->left  = new TreeNode(-2);
    root->right->right = new TreeNode(6);

    //root->left->left->left    = new TreeNode(6);
    //root->left->right->left   = new TreeNode(11);
    //root->right->left->left   = new TreeNode(16);
    //root->right->right->right = new TreeNode(27);

    printTree(root, nullptr, false);

    int ans = maxLevelSum(root);
    cout<<endl<<"Answer : "<<ans<<endl;

    return 0;
}
/*
Given the root of a binary tree, the level of its root is 1, 
the level of its children is 2, and so on.

Return the smallest level x such that the sum of all the 
values of nodes at level x is maximal.

Given the tree
               1
              / \
             0   7
            / \
           -8  7

Input: root = [1,7,0,7,-8,null,null]
Output: 2
Explanation: 
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.    
So we return the level with the maximum sum which is level 2.      
        
Given the tree
               989
                 \
                 10250
                  / \
             98693  -89388
                      \
                      -32127
Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
Output: 2

Input :               4
                    /   \
                   2    -5
                  / \    /\
                -1   3 -2  6
Output: 6
Explanation :
Sum of all nodes of 0'th level is 4
Sum of all nodes of 1'th level is -3
Sum of all nodes of 0'th level is 6
Hence maximum sum is 6

Input :          1
               /   \
             2      3
           /  \      \
          4    5      8
                    /   \
                   6     7  
Output :  17

*/


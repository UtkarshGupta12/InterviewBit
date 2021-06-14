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

TreeNode* getSuccessor(TreeNode* root, int B)
{
    pair<int,TreeNode*> pr;
    TreeNode* temp = root;

    //Initialising with root
    pr.first = root->data;
    pr.second = root;

    while(temp->left && temp->right)
    {
        if(temp->right->data > B && temp->left->data > B)
            temp = temp->left;
        else if(temp->right->data < B && temp->left->data < B)
            temp = temp->right;
        else if(temp->right->data > B && temp->left->data < B)
            break;
        else if(temp->right->data == B || temp->left->data == B)
            break;            
        cout<<temp->data<<" -> ";
    }

    return pr.second;
}

int main()
{
 
    TreeNode* root = new TreeNode(100);
    root->left = new TreeNode(98);
    root->right = new TreeNode(102);
    root->left->left = new TreeNode(96);
    root->left->right = new TreeNode(99);
    root->left->left->right = new TreeNode(97);
    int B = 97;

    //printTree(root, nullptr, false);
    cout<<endl<<"We need the node corresponding to "<<B<<" ."<<endl;

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
*/


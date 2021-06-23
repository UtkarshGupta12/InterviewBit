// TO BE CONTINUED

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
#define INF INT_MAX-1
using namespace std;

//Printers

    struct TreeNode 
    {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}};

    void printQueue(queue<int> q)
    {
    //printing content of queue 
    while (!q.empty())
    {
        cout<<" "<<q.front();
        q.pop();
    }
    cout<<endl;}

    void printVectorPair(vector<pair<int,int>> &vec)
    {
    for (auto i = 0; i < vec.size(); ++i) {
        cout << "(" << vec.at(i).first << ","
            << vec.at(i).second << ")" << "; ";
    }
    cout << endl;
    }

    void printVectorPairPair(vector<pair<int,pair<int,int>>> &vec)
    {
    for (auto i = 0; i < vec.size(); ++i) {
        cout << vec.at(i).first << "->"
            <<"("<< vec.at(i).second.first << "," << vec.at(i).second.second<< ") | ";
    }
    cout << endl;
    }

    void printMap(map<int,int> &order)
    {
        for(auto i = order.begin(); i!= order.end(); i++) 
        {
        std::cout <<"{"<< i->first<< ":"<< i->second << "},";
        }
        cout<<endl;
    }

    void printVec(vector<int> &v)
    {
        int N = v.size();
        for(int i=0;i<N;i++)
        {
            cout << v[i] << " ";
        }
        cout <<endl;}

    void printString(vector<string> &v)
    {
        int N = v.size();
        for(int i=0;i<N;i++)
        {
            cout << v[i] << " ";
        }
        cout <<endl;}    

    void PrintStack(stack<int> s)
    {
        // If stack is empty then return
        if (s.empty())
            return;
         
     
        int x = s.top();
     
        // Pop the top element of the stack
        s.pop();
     
        // Recursively call the function PrintStack
        PrintStack(s);
     
        // Print the stack element starting
        // from the bottom
        cout << x << " ";
     
        // Push the same element onto the stack
        // to preserve the order
        s.push(x);
    }    

    void printTreeVec(vector<TreeNode*> v)
    {
        int N = v.size();
        for(int i=0;i<N;i++)
        {
            cout << v[i]->data << " ";
        }
        cout <<endl;}    

    void printTreeVecvec(vector<vector<TreeNode*>> &vec)
    {
        for(int i=0;i<vec.size();i++)
        {
            for(int j=0;j<vec[i].size();j++)
                cout << vec[i][j]->data << " ";
            cout << endl;}}    

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

void subsetsUtil(vector<int>& A, vector<vector<int> >& res,
                 vector<int>& subset, int index)
{
    res.push_back(subset);
    for (int i = index; i < A.size(); i++) {
  
        // include the A[i] in subset.
        subset.push_back(A[i]);
  
        // move onto the next element.
        subsetsUtil(A, res, subset, i + 1);
  
        // exclude the A[i] from subset and triggers
        // backtracking.
        subset.pop_back();
    }
  
    return;}

vector<vector<int>> solve(vector<int> &A)
{
    sort(A.begin(),A.end());
    int n = A.size();
    int m = accumulate(A.begin(),A.end(),0);
    float avg = ((float)m)/((float)n);
    cout<<"Average : "<<avg<<endl;

    int dp[n+1][m+1];

    //Initialising dp
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(i==0) dp[i][j]=INF;
            if(j==0) dp[i][j]=0;    
        }}    

    //Preparing Recursive Code
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(j>=A[i-1]){
                dp[i][j]= min(1+dp[i-1][j-A[i-1]],dp[i-1][j]);
            }
            else
            dp[i][j]=dp[i-1][j];
            
        }}
    
    //Observing last terms for avg
    int subset_size = -1;
    for(int j=1;j<m;j++)
        if(dp[n][j]!=INF && (float)dp[n][j]*avg==(float)j) subset_size = dp[n][j];

    //Printing Matrix
    /*for (int i = 0; i <=n; i++){
        for (int j = 0; j <=m; j++)
        {
            if(dp[i][j]==INF) 
                cout << "I" << " ";
            else
                cout << dp[i][j] << " ";
        }
        cout << endl;}*/
    cout<<"Subset Size : "<<subset_size<<endl;

    int sum = subset_size*avg;
    cout<<"Sum of subset : "<<sum<<endl;
  
    //Finding Sets with the given sum
    vector<vector<int>> res;
    vector<int> subset;  
    subsetsUtil(A,res,subset,0);
    sort(res.begin(),res.end());

    //Deleting all subsets without any value
    for(int i=0;i<res.size();i++)
    {
        if(res[i].size()!=subset_size)
        {
            res.erase(res.begin()+i);
            i--;
        }}

    for(int i=0;i<res.size();i++)
    {
        int sum1 = accumulate(res[i].begin(),res[i].end(),0);
        if(sum1!=sum)
        { 
            res.erase(res.begin()+i);
            i--;
        }    
    }

    return res;
}

int main()
{
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt     
    freopen("input1.txt","r",stdin);
    // for writing output to output.txt
    freopen("output.txt","w",stdout);
  #endif
  
    vector<int> A = {1,7,9,11,15,29};
    //vector<int> B = {1,5,8,9,10,17,17,20};
    //int C = 29;
    
    cout<<"A : ";printVec(A);
    //cout<<"Price (B)  : ";printVec(B);
    //cout<<"Sum : "<<C<<endl<<endl;

    vector<vector<int>> ans = solve(A);
    cout<<endl<<"Answer -> ";printVecvec(ans);

    return 0;}

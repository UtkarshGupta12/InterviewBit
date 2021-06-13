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

vector<int> dNums(vector<int> &A, int B) 
{
    //Handling B > A.size()
    if(B>A.size()) return {};

    vector<int> res;
    map<int,int> mp;
    deque<int> dq;

    //Initailising the dq
    for(int i=0;i<B;i++)
    {
        dq.push_back(A[i]);
        if(mp.find(A[i])!=mp.end())
            mp[A[i]]++;
        else    
            mp.insert(make_pair(A[i],1));}
    PrintMap(mp);
    res.push_back(mp.size());

    //Processing Further
    for(int i=B;i<A.size();i++)
    {
        dq.push_back(A[i]);

        //Removing First Element
        if(mp.find(dq.front())!=mp.end())
        {
            mp[dq.front()]--;
            if(mp[dq.front()]<1)
                mp.erase(dq.front());
        }

        //Adding First Elements
        if(mp.find(A[i])!=mp.end())
            mp[A[i]]++;
        else
            mp.insert(make_pair(A[i],1));

        dq.pop_front();
        printDeque(dq);PrintMap(mp);
        res.push_back(mp.size());
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
  
    vector<int> A = { 1, 1, 2, 2, 4, 3};
    int B = 1;
    cout<<"Ques : ";printVec(A);
    cout<<"Window Size : "<<B<<endl;

    vector<int> ans = dNums(A,B);
    cout<<endl<<"Answer : ";printVec(ans);

    return 0;
}
/*
For example,
A=[1, 2, 1, 3, 4, 3] and K = 3
All windows of size K are
[1, 2, 1]
[2, 1, 3]
[1, 3, 4]
[3, 4, 3]
So, we return an array [2, 3, 3, 2].
*/


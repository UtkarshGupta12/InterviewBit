#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <stack>
#include <map>
#include <iterator>
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

void printMap(unordered_map<int,int> &mp)
{
    cout << "KEY\tELEMENT\n";
    for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
        cout << itr->first<< '\t' << itr->second << '\n';}}

void showdq(deque <int> g)
{
    deque <int> :: iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';}

int solve(vector<int> &A) 
{
    if(A.empty())
        return 0;

    //Converting to 1 & -1
    for(int i=0;i<A.size();i++)
    {
        if(A[i]==0)
            A[i]=-1;} 
    printVec(A);    

    //Creating a map with currsum
    int max_len = INT_MIN;
    int sum = 0;
    unordered_map<int,int> ump;
    for(int i=0;i<A.size();i++)
    {
        sum +=A[i];

        if(sum==1)
            max_len = i+1;

        if(ump.find(sum)==ump.end())
            ump.insert({sum,i});

        if(ump.find(sum-1)!=ump.end())
        {
            if(max_len < (i - ump[sum-1]))
                max_len = i - ump[sum-1];

        }

        printMap(ump);
    }

    return max_len;
}


int main() {
#ifndef ONLINE_JUDGE
    // for getting input from input.txt     
    freopen("input1.txt","r",stdin);
    // for writing output to output.txt
    freopen("output.txt","w",stdout);
  #endif

    vector<int> A;
    A.push_back(0);
    A.push_back(1);
    A.push_back(1);
    A.push_back(0);
    A.push_back(0);
    A.push_back(1);

    printVec(A);

    int ans = solve(A);
    cout <<"Answer : "<<ans<<endl;   

    return 0;
}


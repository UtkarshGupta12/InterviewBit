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

int solve(vector<int> &A,int B)
{
    unordered_map<int,int> ump;
    int res = 0;
    int curr_sum = 0;

    //Converting to 1 & 0
    for(int i=0;i<A.size();i++)
    {
        if(A[i]%2==0)
            A[i]=0;
        else
            A[i]=1;}
    cout<<"Binary : ";printVec(A);    

    //Calculating sub-arrays with sum = B
    for(int i=0;i<A.size();i++)
    {
        curr_sum += A[i];

        if(curr_sum==B)
            res++;

        if(ump.find(curr_sum - B) != ump.end())
            res+= ump[curr_sum - B];

        ump[curr_sum]++;
        printMap(ump);
    }

    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    // for getting input from input.txt     
    freopen("input1.txt","r",stdin);
    // for writing output to output.txt
    freopen("output.txt","w",stdout);
  #endif

    vector<int> A;
    A.push_back(4);
    A.push_back(3);
    A.push_back(2);
    A.push_back(3);
    A.push_back(4);
    int B = 2;

    cout<<"Ques   : ";printVec(A);

    int ans = solve(A,B);
    cout << endl <<"Answer : "<<ans<<endl;   

    return 0;
}

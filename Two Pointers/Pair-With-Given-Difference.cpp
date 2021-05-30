#include <iostream>
#include <string>
#include <bits/stdc++.h>
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

int solve(vector<int> &A, int t)
{
    /*sort(A.begin(),A.end());
    printVec(A);

    int j = 1;
    int i = 0;

    while(i<A.size()&&j<A.size())
    {
        if(i != j && A[j]-A[i]==t)
            return 1;
        else if(i != j && A[j]-A[i]<t)
            j++;
        else if(i != j && A[j]-A[i]>t)
            i++;}*/

    for(int i=0;i<A.size();i++)
    {
        for(int j=A.size()-1;j>i;j--)
        {
            if(A[j]-A[i]==t||A[i]-A[j]==t)
                return 1;
        }}
    return 0;
}

int main() {
#ifndef ONLINE_JUDGE
    // for getting input from input.txt     
    freopen("input1.txt","r",stdin);
    // for writing output to output.txt
    freopen("output.txt","w",stdout);
  #endif

    vector<int> ques;
    ques.push_back(5);
    ques.push_back(2);
    ques.push_back(3);
    ques.push_back(80);
    ques.push_back(5);
    ques.push_back(20); 
    cout <<"Question  : ";printVec(ques);

    int target = 17;
    cout <<"Target : "<<target<<endl<<endl;

    int ans ;
    ans = solve(ques,target);
    cout << endl<<"Answer : "<< ans <<endl;
}

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

int solve(vector<int> &A, int B)
{
    int sum ,count = 0;
    for(int i=0;i<A.size();i++)
    {
        sum = 0;
        for(int j=i;j<A.size();j++)
        {
            sum +=A[j];
            if(sum<B)
                count++;
            else if(sum>=B)
                break;
        }
    }
    return count;

}


int main() {
#ifndef ONLINE_JUDGE
    // for getting input from input.txt     
    freopen("input1.txt","r",stdin);
    // for writing output to output.txt
    freopen("output.txt","w",stdout);
  #endif

    vector<int> ques;
    ques.push_back(1);
    ques.push_back(11);
    ques.push_back(2);
    ques.push_back(3);
    ques.push_back(15); 
    cout <<"Question  : ";printVec(ques);

    int ans ;
    ans = solve(ques,10);
    cout << endl<<"Answer : "<< ans <<endl;
}

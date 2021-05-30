// TO BE CONTINUED
#include <iostream>
#include <string>
#include <bits/stdc++.h>
#define M 1000000007
using namespace std;

int solve(int n)
{
    if(n==1)
        return 1;
    else if(n==2)
        return 3;

    int ans,count=1,len=1;
    int p;

    while(count<n)
    {
        len++;
        if(len%2==0) 
            p=(len-2)/2;
        else
            p = len/2;
        count+=pow(2,p);
    }

    return INT_MAX;
}

int main() {
#ifndef ONLINE_JUDGE
    // for getting input from input.txt     
    freopen("input1.txt","r",stdin);
    // for writing output to output.txt
    freopen("output.txt","w",stdout);
  #endif

    int ques = 13;
    cout <<"Question  : "<<ques<<"th "<<endl<<endl;

    int ans ;
    ans = solve(ques);
    cout << endl<<"Answer : "<< ans <<endl;
}

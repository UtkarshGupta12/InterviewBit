// TO BE CONTINUED
#include <iostream>
#include <string>
#include <bits/stdc++.h>
#define M 1000000007
using namespace std;

bool IsEven(int SUM, int n)
{
    int num;
    int sum=0;

    for(int i=0;i<n;i++)
    {
        num = pow(2,i);
        sum += num;
        if(SUM==sum)
            return true;

        sum += num;
        if(sum==SUM)
            return false;
    }

}

int solve(int n)
{
    if(n==1)
        return 1;
    else if(n==2)
        return 3;
    
    int num;
    int sum = 0;
    bool odd = false;
    bool even = false;

    for(int i=0;i<n;i++)
    {
        num = pow(2,i);
        sum += num;
        if(n/sum==1&&n%sum<num)
            break;

        sum += num;
        if(n/sum==1&&n%sum<num*2)
        {
            if(n==sum)
                break;
            else
                num*=2;
            break; 
        }}  

    cout << "Num : "<<num<<" & Sum : "<<sum<<endl;  
    even = IsEven(sum,n);
    cout << "Even : "<<even<<endl;


    return INT_MAX;
}

int main() {
#ifndef ONLINE_JUDGE
    // for getting input from input.txt     
    freopen("input1.txt","r",stdin);
    // for writing output to output.txt
    freopen("output.txt","w",stdout);
  #endif

    int ques = 4;
    cout <<"Question  : "<<ques<<"th "<<endl<<endl;

    int ans ;
    ans = solve(ques);
    cout << endl<<"Answer : "<< ans <<endl;
}

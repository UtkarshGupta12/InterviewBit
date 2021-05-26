#include <iostream>
#include <string>
#include <bits/stdc++.h>
#define M 10000003
using namespace std;

int solve(string A)
{
    string sample = "()";
    int i = A.size();

    while(i)
    {
        size_t found = A.find(sample);
        size_t temp = found;
        if(found != string::npos)
            A.erase(found,2); 
        else 
            break;
        i--;
        cout<<A<<endl;
    }
    return A.size();
}

int main() {
  #ifndef ONLINE_JUDGE
    // for getting input from input.txt     
    freopen("input1.txt","r",stdin);
    // for writing output to output.txt
    freopen("output.txt","w",stdout);
  #endif

    //"(((()" ")))))("
    string ques = ")(()((((()))))))()()(()(()(())()()()))())())()))()(())))))(()((((((((()()((())())(((((()(()())((()))))((()()())((())))((()()))()((()((())))))";

    int ans = solve(ques);
    cout << endl << ans << endl;
}

// METHOD - 2 BY Pushkar Agarwal

int Solution::solve(string str) 
{
    int i;
    int a=0;
    int b=0;
    
    for(i=0; i<str.length();i++)
    {
       //char c=str[i];
        if(str[i]=='(')
            a=a+1;
        else
            a=a-1;
        if(a==-1)
        {
            a=a+1;
            b=b+1;
        }
    }
    return(a+b);
} 

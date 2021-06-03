#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include<stack>
#define M 1000000007
using namespace std;

void PrintStack(stack<char> s)
{
    // If stack is empty then return
    if (s.empty())
        return;
 
    char x = s.top();
 
    // Pop the top element of the stack
    s.pop();
 
    // Recursively call the function PrintStack
    PrintStack(s);
 
    // Print the stack element starting
    // from the bottom
    cout << x << " ";
 
    // Push the same element onto the stack
    // to preserve the order
    s.push(x);}
 
void printString(vector<string> &str)
{
    for(int i=0;i<str.size();i++)
    {
        cout << str[i] << "   ";
    }
    cout << endl;} 

int solve(string A)
{
    stack<char> s;

    for(int i=0;i<A.size();i++)
    {
        if(A[i]=='(')
            s.push('(');
        else 
        {
            if(s.empty())
                return 0;
            else
                s.pop();
        }
        PrintStack(s);cout<<endl;
    }

    if(s.empty())
        return 1;
    else
        return 0;

} 

int main() {
#ifndef ONLINE_JUDGE
    // for getting input from input.txt     
    freopen("input1.txt","r",stdin);
    // for writing output to output.txt
    freopen("output.txt","w",stdout);
  #endif

    string A = "(()())";

    cout<<"Ques : "<<A<<endl;

    int ans = solve(A);
    cout << endl <<"Answer : "<<ans<<endl;   

    return 0;
}

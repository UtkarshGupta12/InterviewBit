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

void showq(queue<char> gq)
{
    queue<char> g = gq;
    while (!g.empty()) {
        cout << '\t' << g.front();
        g.pop();
    }
    cout << '\n';}

int braces(string A)
{
    if(A.size()==0) return 0;

    stack<char> s;

    for(int i=0;i<A.size();i++)
    {
        if(A[i]=='('||A[i]=='+'||A[i]=='-'||A[i]=='*'||A[i]=='/'||A[i]==')')
            continue;
        else
        {
            A.erase(A.begin()+i);  
            i--;
        }     
            cout<<A<<endl;}

    for(int i=0;i<A.size();i++)
    {
        if(A[i]=='(')
            s.push(A[i]);
        else if(A[i]=='/'||A[i]=='+'||A[i]=='-'||A[i]=='*')
            s.push(A[i]);
        else if(A[i]==')')
        {
            if(s.top()=='(')
                return 1;
            else
                while(!s.empty() && s.top()!='(')
                    s.pop();
                s.pop();
        }
    }
    
    return 0;
}

int main() {
#ifndef ONLINE_JUDGE
    // for getting input from input.txt     
    freopen("input1.txt","r",stdin);
    // for writing output to output.txt
    freopen("output.txt","w",stdout);
  #endif

    string A = "(a+((b*c)+c))";

    cout<<"Ques : "<<A<<endl;

    int ans = braces(A);
    cout << endl <<"Answer : "<<ans<<endl;   

    return 0;
}

/*
Input:

    ((a+b))
    (a+(b)/c)
    (a+b*(c-d))
    Output: 
    Yes
    Yes
    No

Explanation:

    1. ((a+b)) can reduced to (a+b), this Redundant
    2. (a+(b)/c) can reduced to (a+b/c) because b is
        surrounded by () which is redundant.
    3. (a+b*(c-d)) doesn't have any redundant or multiple
        brackets.

*/

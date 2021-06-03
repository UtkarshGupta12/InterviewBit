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
 
char Compliment(char c)
{
    if(c=='{')
        return '}';
    else if(c=='[')
        return ']';
    else if(c=='(')
        return ')';}

bool opening(char c)
{
    if(c=='{'||c=='['||c=='(')
        return true;
    else
        return false;}

int isValid(string A) 
{
    int n = A.size();
    stack<char> S;
    S.push('0');
    
    for(int i=0;i<n;i++)
    {
        if(opening(A[i])==true)
            S.push(A[i]);
        else 
        {
            if(S.size()==1)
                return 0;
            else if(A[i]==Compliment(S.top()))     
                S.pop();
        }
        PrintStack(S);cout<<endl;
    }
    
    if(S.size()==1)
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

    //"((((({)))))";
    string A = "((((([{()}[]]]{{{[]}}})))))";
    cout<<"Ques : "<<A<<endl;

    int ans = isValid(A);
    cout <<"Answer : "<<ans<<endl;   

    return 0;
}

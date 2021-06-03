#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include<stack>
#define M 1000000007
using namespace std;

void PrintStack(stack<int> s)
{
    // If stack is empty then return
    if (s.empty())
        return;
 
    int x = s.top();
 
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

bool arithmetic(string s)
{
    if(s=="+"||s=="-"||s=="/"||s=="*")
        return true;
    else
        return false;}

int evalRPN(vector<string> &A)
{
    stack<int> s;
    int a , b;

    for(int i=0;i<A.size();i++)
    {
        if(arithmetic(A[i])==true)
        {
            a = s.top();
            s.pop();
            b = s.top();
            s.pop();

            if(A[i]=="+")
                s.push(a+b);
            else if(A[i]=="-")
                s.push(b-a);
            else if(A[i]=="/")
                s.push(b/a);
            else 
                s.push(b*a);
        }
        else 
            s.push(stoi(A[i]));
        PrintStack(s);cout<<endl;
    }

    return s.top();
}

int main() {
#ifndef ONLINE_JUDGE
    // for getting input from input.txt     
    freopen("input1.txt","r",stdin);
    // for writing output to output.txt
    freopen("output.txt","w",stdout);
  #endif

    //["3", "5", "+", "7", "2", "–", "*"] -> 40
    //["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
    //["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
    vector<string> A ;
    A.push_back("4");
    A.push_back("13");
    A.push_back("5");
    A.push_back("/");
    A.push_back("+");
    //A.push_back("-");
    //A.push_back("*");

    cout<<"Ques : ";printString(A);

    int ans = evalRPN(A);
    cout <<"Answer : "<<ans<<endl;   

    return 0;
}

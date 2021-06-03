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

void printVec(vector<int> &v)
{
    int N = v.size();
    for(int i=0;i<N;i++)
    {
        cout << v[i] << " ";
    }
    cout <<endl;}

vector<int> prevSmaller(vector<int> &A)
{
    vector<int> ans; 
    stack<int> s;
    ans.push_back(-1);
    s.push(A[0]);

    if(A.size()==1)
        return ans;

    for(int i=1;i<A.size()-1;i++)
    {
        if(A[i]>s.top())
        {
            ans.push_back(s.top());
            s.push(A[i]);}
        else
        {
            while(!s.empty() && s.top()>=A[i])
                s.pop();
            if(s.size()==0)
            {
                ans.push_back(-1);
                s.push(A[i]);}
            else
            {
                ans.push_back(s.top());
                s.push(A[i]);
            }}
        PrintStack(s);cout<<endl;
    }

    //LAST CASE
    while(!s.empty()&&A.back()<=s.top())
        s.pop();

    if(s.empty())
        ans.push_back(-1);
    else
        ans.push_back(s.top());    

    PrintStack(s);cout<<endl;
    return ans;
} 

int main() {
#ifndef ONLINE_JUDGE
    // for getting input from input.txt     
    freopen("input1.txt","r",stdin);
    // for writing output to output.txt
    freopen("output.txt","w",stdout);
  #endif

    //Input : A : [4, 5, 2, 10, 8]
    //Return : [-1, 4, -1, 2, 2]

    //Input : A : [3, 2, 1]
    //Return : [-1, -1, -1]

    //A : [ 34, 35, 27, 42, 5, 28, 39, 20, 28 ]
    //-1 34 -1 27 -1 5 28 5 20 

    //A : [ 7, 6, 5, 4, 3, 2, 1 ]
    //-1 -1 -1 -1 -1 -1 -1 

    //A : [ 39, 27, 11, 4, 24, 32, 32, 1 ]
    //-1 -1 -1 -1 4 24 24 -1 

    vector<int> A ;
    A.push_back(39);
    A.push_back(27);
    A.push_back(11);
    A.push_back(3);
    A.push_back(24);
    A.push_back(32);
    A.push_back(32);
    A.push_back(3);

    cout<<"Ques : ";printVec(A);

    vector<int> ans = prevSmaller(A);
    cout << endl <<"Answer : ",printVec(ans);cout<<endl;   

    return 0;
}

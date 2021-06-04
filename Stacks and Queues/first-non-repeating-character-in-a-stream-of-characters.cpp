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

string solve(string str)
{
    queue<char> q;
    vector<int> CharCount(26,0);
    string ans = "";
    for(int i=0;i<str.size();i++)
    {
        char c = str[i];    
        CharCount[c-'a']++;
        q.push(c);
        while(!q.empty())
        {
            if(CharCount[q.front()-'a']>1)
                q.pop();
            else
            {
                ans+=q.front();
                break;
            }
        }

        if(q.empty())
        ans+='#';

        //showq(q);
    }

    return ans;
} 

int main() {
#ifndef ONLINE_JUDGE
    // for getting input from input.txt     
    freopen("input1.txt","r",stdin);
    // for writing output to output.txt
    freopen("output.txt","w",stdout);
  #endif

    string A = "abcabc";

    cout<<"Ques : "<<A<<endl;

    string ans = solve(A);
    cout << endl <<"Answer : "<<ans<<endl;   

    return 0;
}

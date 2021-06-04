#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include<stack>
#define M 1000000007
using namespace std;

void PrintStack(stack<string> s)
{
    // If stack is empty then return
    if (s.empty())
        return;
 
    string x = s.top();
 
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

string simplifyPath(string str)
{
    stack<string> s;
    string temp = "";
    string ans = "/";
    int j;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='/')
            continue;
        else if(str[i]=='.')
        {
            i++;
            if(str[i]=='.')
            {
                if(!s.empty()) s.pop();
                continue;
            }
        }
        else
        {
            temp+=str[i];
            for(j=i+1;j<str.size();j++)
            {
                if(str[j]=='/'||str[j]=='.')
                    break;
                else
                    temp+=str[j];
            }
        
            i = j-1;
            reverse(temp.begin(),temp.end());
            s.push(temp);
            temp = "";
        }

        PrintStack(s);cout<<endl;
    }

    while(!s.empty())
    {
        ans +=s.top();
        s.pop();
        ans +='/';
    }

    reverse(ans.begin(),ans.end());

    if(ans.back()=='/' && ans.size()>1)
        ans.erase(ans.size()-1);

    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    // for getting input from input.txt     
    freopen("input1.txt","r",stdin);
    // for writing output to output.txt
    freopen("output.txt","w",stdout);
  #endif

    string A = "/a/./b/./c/./d/home/";

    cout<<"Ques : "<<A<<endl;

    string ans = simplifyPath(A);
    cout << endl <<"Answer : "<<ans<<endl;   

    return 0;
}

/*
"/a/./"   --> means stay at the current directory 'a'
"/a/b/.." --> means jump to the parent directory
              from 'b' to 'a'
"////"    --> consecutive multiple '/' are a  valid  
              path, they are equivalent to single "/".

Input : /home/
Output : /home

Input : /a/./b/../../c/
Output : /c

Input : /a/..
Output:/

Input : /a/../
Output : /

Input : /../../../../../a
Output : /a

Input : /a/./b/./c/./d/
Output : /a/b/c/d

Input : /a/../.././../../.
Output:/

Input : /a//b//c//////d
Output : /a/b/c/d */

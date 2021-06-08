#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <stack>
#include <map>
#include <iterator>
#define M 1000000007
using namespace std;
 
void printVec(vector<int> &v)
{
    int N = v.size();
    for(int i=0;i<N;i++)
    {
        cout << v[i] << " ";
    }
    cout <<endl;}

void printMap(unordered_map<char,int> &mp)
{
    cout << "KEY\tELEMENT\n";
    for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
        cout << itr->first<< '\t' << itr->second << '\n';}}

void showdq(deque <char> g)
{
    deque <char> :: iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';}

int lengthOfLongestSubstring(string A)
{
    unordered_map<char,int> ump;
    deque<char> dq;

    int len;
    int max_len = INT_MIN;

    for(int i=0;i<A.size();i++)
    {
        if(ump.find(A[i])!=ump.end())
        {
            while(dq.front()!=A[i])
            {
                ump.erase(dq.front());
                dq.pop_front();
            }

            dq.pop_front();
            dq.push_back(A[i]);
        }
        else
        {
            dq.push_back(A[i]);
            ump.insert({A[i],i+1});
        }

        len = ump.size();
        max_len = max(len,max_len); 
        printMap(ump);cout<<endl;
        showdq(dq);cout<<endl;
    }

    return max_len;
}

int main() {
#ifndef ONLINE_JUDGE
    // for getting input from input.txt     
    freopen("input1.txt","r",stdin);
    // for writing output to output.txt
    freopen("output.txt","w",stdout);
  #endif

    string A = "GeeksforGeeks";
    //string A = "abcaf";

    cout<<"Ques : "<<A<<endl<<endl;

    int ans = lengthOfLongestSubstring(A);
    cout << endl <<"Answer : "<<ans<<endl;   

    return 0;
}

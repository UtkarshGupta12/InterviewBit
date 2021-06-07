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

void printMap(unordered_map<int,int> &mp)
{
    cout << "KEY\tELEMENT\n";
    for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
        cout << itr->first<< '\t' << itr->second << '\n';}}

int firstRepeatingElement(vector<int> &A)
{   
    int n = A.size();
    unordered_map<int, int> ump;

    for(int i=0;i<n;i++)
    {
        if(ump.find(A[i])!=ump.end())
        {
            if(ump[A[i]]>=0)  
            {   int temp = ump[A[i]];
                ump.erase(A[i]);
                ump.insert({A[i],-temp});
            }
        }
        else
            ump.insert({A[i],i+1}); 
        printMap(ump);cout<<endl;       
    }

    int k=-1;
    for(int i=0;i<n;i++)
    {
        if(ump[A[i]]<=0)
        {
            k = i;
            break;
        }
    }

    if(k>=0) return A[k];
    else return -1;
}

int main() {
#ifndef ONLINE_JUDGE
    // for getting input from input.txt     
    freopen("input1.txt","r",stdin);
    // for writing output to output.txt
    freopen("output.txt","w",stdout);
  #endif

    vector<int> A;
    A.push_back(10);
    A.push_back(5);
    A.push_back(3);
    A.push_back(4);
    A.push_back(3);
    A.push_back(5);
    A.push_back(6);

    cout<<"Ques : ";printVec(A);

    int ans = firstRepeatingElement(A);
    cout << endl <<"Answer : "<<ans<<endl;   

    return 0;
}
/*
    Input : 
        A : [1 2 3 3 4 5 6]
        B : [3 3 5]
    Output : [3 3 5]
    Input : 
        A : [1 2 3 3 4 5 6]
        B : [3 5]
    Output : [3 5]  */

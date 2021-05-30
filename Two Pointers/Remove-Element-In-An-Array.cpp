// In ques it says to modify theoriginal array but in answer it doesnt seem so
#include <iostream>
#include <string>
#include <bits/stdc++.h>
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

int solve(vector<int> &A, int B)
{
    for(int i=0;i<A.size();i++)
    {
        if(A[i]==B)  
        {  
            A.erase(A.begin()+i);
            i--;
        }
        
        printVec(A);    
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

    vector<int> ques;
    ques.push_back(4);
    ques.push_back(1);
    ques.push_back(1);
    ques.push_back(2);
    ques.push_back(1);
    ques.push_back(3); 
    cout <<"Question  : ";printVec(ques);

    int ans ;
    ans = solve(ques,1);
    cout << endl<<"Answer : "<< ans <<endl;
}

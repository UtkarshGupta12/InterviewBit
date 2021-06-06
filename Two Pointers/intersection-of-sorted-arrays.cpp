#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <stack>
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

vector<int> intersect(const vector<int> &A, const vector<int> &B) 
{
    vector<int> ans;
    int size_A = A.size();
    int size_B = B.size();
    int i=0, j=0;

    while(i<A.size() && j<B.size())
    {
        cout<<"A : "<<A[i]<<" & B : "<<B[j]<<endl;
        if(A[i]>B[j])
            j++;
        else if(A[i]==B[j])
        {
            ans.push_back(A[i]);
            i++;
            j++;}
        else
            i++;
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

    vector<int> A;
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.push_back(3);
    A.push_back(4);
    A.push_back(5);
    A.push_back(6);

    vector<int> B;
    B.push_back(3);
    //B.push_back(3);
    B.push_back(5);

    cout<<"List I  : ";printVec(A);
    cout<<"List II : ";printVec(B);

    vector<int> ans = intersect(A,B);
    cout << endl <<"Answer : ";printVec(ans);cout<<endl;   

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

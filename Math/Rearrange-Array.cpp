#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void printVec(vector<int> &v)
{
    int N = v.size();
    for(int i=0;i<N;i++)
    {
        cout << v[i] << " ";
    }
    cout <<endl;
}

void arrange(vector<int> &A)
{
    int N = A.size();
    for(int i=0;i<N;i++)
        A[i] = A[i]+(A[A[i]]%N)*N;
    
    printVec(A);
    
    for(int i=0;i<N;i++)
        A[i] = A[i]/N;
}

int main()
{   
    vector<int> A;
    A.push_back(3);
    A.push_back(2);
    A.push_back(4);
    A.push_back(1);
    A.push_back(0);
    
    printVec(A);
    arrange(A);
    printVec(A);
}

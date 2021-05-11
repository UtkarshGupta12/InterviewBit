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


int main()
{
    vector<int> A;
    A.push_back(5);
    A.push_back(5);
    A.push_back(2);
    A.push_back(5);
    A.push_back(8);
    
    printVec(A);
    
    int sol = solve(A);
    
    cout<< sol << endl; 
}

#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &A) 
{
    vector<int> vec;
    int max; 
    
    for(int i=0;i<A.size();i++)
    {
        max = *max_element(A.begin()+i+1, A.end());
        if(A[i]>max && i < A.size()-1)
            vec.push_back(A[i]);
    }
    vec.push_back(A[A.size()-1]);
    return vec;
}

int main()
{
    vector<int> A,sol;
    A.push_back(16);
    A.push_back(17);
    A.push_back(4);
    A.push_back(3);
    A.push_back(5);
    A.push_back(2);
    
    sol = solve(A);
    
    cout<< A[0] <<" "<< A[1] <<" "<< A[2] <<" "<< A[3] <<" "<< A[4] <<" "<<A[5] <<" "<< endl;
    
    cout<< sol[0] <<" "<< sol[1] <<" "<< sol[2] <<endl;
}

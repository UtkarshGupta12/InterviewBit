#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

bool checker(vector<int> &A)
{
    int sumE=0,sumO=0;
    for(int i=0;i<A.size();i++)
    {
        if(i%2==0)
            sumE+=A[i];
        else if(i%2==1)
            sumO+=A[i];    
    }
    if(sumE == sumO)
        return true;
    else 
        return false;
}

int solve(vector<int> &A) 
{
    int temp,count = 0;
    for(int i=0;i<A.size();i++)
    {
        temp=A[i];
        A.erase(A.begin()+i);
        if(checker(A))
            count++;
        A.insert(A.begin()+i,temp);    
    }
    return count;
}

int main()
{
    vector<int> A;
    A.push_back(5);
    A.push_back(5);
    A.push_back(2);
    A.push_back(5);
    A.push_back(8);
    
    cout<< A[0] <<" "<< A[1] <<" "<< A[2] <<" "<< A[3] <<" "<< A[4] << endl;
    
    int sol = solve(A);
    
    cout<< sol << endl; 
}

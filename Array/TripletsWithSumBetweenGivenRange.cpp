// Showing some error
// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

bool isinA(double x)
{
    if(x>0 && x < 2.0/3.0)
        return true;
    else
        return false;
}

bool isinB(double x)
{
    if(x>=2.0/3.0 && x < 1.0)
        return true;
    else
        return false;    
}

bool isinC(double x)
{
    if(x>=1.0 && x < 2.0)
        return true;
    else
        return false;    
}

bool caseAAA(vector<double> &A)
{
    int n = A.size();
    if(n>=3)
    {
        if(A[n-1] + A[n-2] + A[n-3] > 1 )
            return true;
    }
    else
      return false;
}

bool caseAAB(vector<double> &A,vector<double> &B)
{
    int nA = A.size();
    int nB = B.size();
    if(nA>=2 && nB>=1)
    {
        if(A[nA-1] + A[nA-2] + B[nB-1] > 1 && A[nA-1] + A[nA-2] + B[nB-1] < 2)
            return true;
        else if(A[0]+A[1]+B[0]>1 && A[0]+A[1]+B[0]<2)
            return true;
    }
    else
      return false;
}

bool caseAAC(vector<double> &A,vector<double> &C)
{
    int nA = A.size();
    int nC = C.size();
    if(nA>=2 && nC>=1)
    {
        if(A[0]+A[1]+C[0]<2.0)
            return true;
    }
    else 
      return false;
}

bool caseABB(vector<double> &A,vector<double> &B)
{
    int nA = A.size();
    int nB = B.size();
    if(nA>=1 && nB>=2)
    {
        if(A[0]+B[0]+B[1]<2.0)
            return true;
    }
    else
        return false;
}

bool caseABC(vector<double> &A,vector<double> &B,vector<double> &C)
{
    int nA = A.size();
    int nB = B.size();
    int nC = C.size();
    if(nA>=1 && nB>=1 && nC>=1)
    {
        if(A[0]+B[0]+C[0]<2)
            return true;
    }
    else
      return false;
}

int caseReturn(vector<double> &A,vector<double> &B,vector<double> &C)
{
    if (caseAAA(A) == true)
        return 1;
    else if (caseAAB(A,B) == true)  
        return 2;
    else if (caseAAC(A,C) == true)  
        return 3;
    else if (caseABB(A,B) == true)  
        return 4;
    else if (caseABC(A,B,C) == true)
        return 5;
    else 
        return 0;
}

int Solution::solve(vector<string> &str) 
{
    vector<double> v;
    for(int i=0;i<str.size();i++)
        v.push_back(stod(str[i]));
    
    vector<double> A,B,C;
    
    if(v.size()==3)
    {
        if(v[0]+v[1]+v[2] < 2.0 && v[0]+v[1]+v[2] > 1.0 )
            return 1;
        else
            return 0;
    }
    
    for(int j=0;j<v.size();j++)
    {
        if(isinA(v[j]))
            A.push_back(v[j]);
            
        else if(isinB(v[j]))
            B.push_back(v[j]);
            
        else if(isinC(v[j]))
            C.push_back(v[j]);    
    }
    
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    sort(C.begin(),C.end());
    
    if(caseReturn(A,B,C) >=1)
        return 1;
    else    
        return 0;
        
}   


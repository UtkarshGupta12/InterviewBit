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

int perfectPeak(vector<int> &A) 
{
    vector<int> B;
    B = A;
    int i,a,b,c,d,temp;
    sort(B.begin(),B.end());
    for(i=1;i<A.size()-1;i++)
    {
        if(A[i]==B[i])
        {
            a = *max_element(A.begin(), A.begin()+i);
            b = *max_element(A.begin()+i+1, A.end());
            if(a < A[i] && b > A[i] && B[i+1]!=B[i] && B[i]!=B[i-1])
                return 1;
        }
    }
    return 0;
}

int main()
{
    //1, 2, 3, 4, 5, 4, 3, 2, 3, 10
    vector<int> A;
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.push_back(4);
    A.push_back(5);
    A.push_back(4);
    A.push_back(3);
    A.push_back(2);
    A.push_back(3);
    A.push_back(10);
    
    printVec(A);
    
    int B = perfectPeak(A);
    
    cout << B << endl;
    //cout<< sol << endl; 
}

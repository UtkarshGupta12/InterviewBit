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

vector<int> hotspots(vector<int> &A, int B)
{
    vector<int> v(A.size(),0);
    for(int i=0;i<A.size();i++)
    {
        if(A[i]==1)
        {
            for(int j=i-B+1;j<i+B;j++)
            {
                if(j > -1 && j < A.size())
                    v[j]=v[j]+1;
            }    
        }
        printVec(v);
    }
    return v;
}


int solve(vector<int> &A, int B)
{
    vector<int> vec;
    vec = hotspots(A,B);
    int n = *min_element(vec.begin(), vec.end());
    int k = (A.size()/(2*B-1))+1;
    if (n>0)
        return k;
    else
        return -1;
}



int main()
{
    // 0 0 1 1 1 0 0 1
    // 0 0 0 1 0
    // 1 1 1 1
    // [ 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0 ]
    vector<int> A,C;
    A.push_back(0);
    A.push_back(0);
    A.push_back(0);
    A.push_back(1);
    A.push_back(1);
    A.push_back(0);
    A.push_back(1);
    A.push_back(0);
    A.push_back(0);
    A.push_back(0);
    A.push_back(0);
    A.push_back(0);
    A.push_back(0);
    A.push_back(1);
    A.push_back(0);
    A.push_back(0);
    
    printVec(A);
    
    C = hotspots(A,4);
    
    int B = solve(A,4);
    
    cout  << B <<endl;
    
    //cout<< sol << endl; 
}

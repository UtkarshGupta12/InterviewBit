#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void updatePascal(vector<int> &A)
{
    vector<int> temp;
    temp = A;
    A.clear();
    A.resize(temp.size()+1);
    A[0]=A[temp.size()]=1;
    for(int i=1;i<temp.size();i++)
    {
        A[i] = temp[i-1]+temp[i];
    }
    temp.clear();
}

vector<int> getRow(int N)
{
    vector<int> v1,v2;
    v1.resize(1);
    v2.resize(2);
    
    v1[0] = 1;
    v2[0] = 1;
    v2[1] = 1;
    
    if(N==0)
        return v1;
    else if(N==1)
        return v2;
    else
    {
        v1.clear();
        for(int i=2;i<N+1;i++)
        {
            updatePascal(v2);
        }
        return v2;    
    }
}


int main() 
{
    // Write C++ code here
    vector<int> A;
    int N = 2;
    A = getRow(N);
    
    for(int i=0;i<N+1;i++)
    {
        cout << A[i] <<" ";
    }
    cout<<endl;

    return 0;
}

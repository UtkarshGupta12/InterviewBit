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

string convert(string A,int B)
{
    string ans="";
    
    if(A.size()==1)
        return A;
    else if(B == 1)
        return A;
    
    int n = B-1;
    vector<int> vec;
    for(int i=0;i<B-1;i++)
    {
        vec.push_back(2*(n-1)+2);
        n--;
    }
    vec.push_back(vec[0]);
    printVec(vec);
    
    for(int i=0;i<B;i++)
    {
        int k=i,count=1;
        while(k < A.size())
        {
            ans+=A[k];
            if(count%2==1)
                k+=vec[i];
            else if(count%2==0)
                k+=vec[B-i-1];
            count++;    
        }
        cout << ans << endl;
    }
    
    return ans;
}

int main()
{
    string ans = "";
    ans = convert("PAYPALISHIRING",3);
    
    cout << ans << endl;
}

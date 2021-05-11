//TLE
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

int solve(vector<int> &A) 
{
    int N = A.size();
    int count = 0;
    int B1_L,B1_R,B2_L,B2_R;
    
    vector<int> B1(N,0),B2(N,0);
    for(int i=0;i<N;i++)
    {
        if(i%2==0)
            B1[i]=A[i];
        else    
            B2[i]=A[i];
    }
    
    printVec(B1);
    printVec(B2);
    cout << endl;
    
    for(int k=-1;k<N-1;k++) 
    {
        B1_L=accumulate(B1.begin(),B1.begin()+k+1,0);
        B1_R=accumulate(B1.begin()+k+2,B1.end(),0);
        B2_L=accumulate(B2.begin(),B2.begin()+k+1,0);
        B2_R=accumulate(B2.begin()+k+2,B2.end(),0);
        cout <<B1_L<<" "<<B1_R<<" "<<B2_L<<" "<<B2_R<<endl;
        
        if(B1_L+B2_R==B1_R+B2_L)
            count++;
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
    
    printVec(A);
    
    int sol = solve(A);
    
    cout<< sol << endl; 
}

//METHOD 2 - By Sourabh

int Solution::solve(vector<int> &A) {
    
    vector<int>odd,even;
    int n=A.size();
    int evsum=0,oddsum=0;
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
        {
            evsum+=A[i];
            even.push_back(evsum);
            odd.push_back(oddsum);
        }
        else
        {
            oddsum+=A[i];
            odd.push_back(oddsum);
             even.push_back(evsum);
 
        }
    }
    int cnt=0;
    int ev=0,od=0;
    for(int i=1;i<n;i++)
    {
        ev=odd[n-1]-odd[i]+even[i-1];
        od=even[n-1]-even[i]+odd[i-1];
        if(od==ev)
        cnt++;
    }
    if(evsum-A[0]==oddsum)
    cnt++;
    return cnt;
}

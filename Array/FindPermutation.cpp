//Partially Correct , Need to shorten it 
#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int checker(vector<int> &A,const string s)
{
    int i=0;
    while(i<A.size()-1)
    {
        if(s.at(i)=='D' && A[i+1]<A[i])
            i++;
        else if(s.at(i)=='I' && A[i+1]>A[i])
            i++; 
        else
            break;
    }
    return i;
}


vector<int> findPerm(const string s, int B)
{
    vector<int> A;
    
    for(int i=0;i<B;i++)
        A.push_back(B-i);
    
    int i=checker(A,s);
    while(i<B-1)
    {
        swap(A[i],A[i+1]);
        cout<<A[0]<<" "<<A[1]<<" "<<A[2]<<" "<<A[3]<<" "<<A[4]<<endl;
        i = checker(A,s);
        if(i==B-1)
            break;
    }    
    
    return A;
}

int main() 
{
    int B=5;
    vector<int> A;
    const string s = "DIDD";
        
    for(int i=0;i<B;i++)
       cout << B-i<<" ";     
    cout<<endl;
        
    A=findPerm(s,B);
    for(int i=0;i<s.length()+1;i++)
        cout << A[i]<<" ";

    cout << endl;
    

    return 0;
}

//Runtime Error , Need to shorten code
#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &A) 
{
    vector<int> B;
    int N = A.size(),max_it,it_before_max,max,i;
    
    for (i = N-2; i>=0; i--)
    {
        if (A[i] < A[i + 1])
        break;
    }
    
    if (i == -1) 
    {
        reverse(A.begin(), A.end());
        return;
    }
    
    max = *max_element(A.begin(), A.end());

    for(int i=0;i<N;i++)
        if(A[i]==max)
        {
            max_it = i;
            break;
        }  
            
    it_before_max = max_it - 1;  
    sort(A.begin()+it_before_max+1,A.end());
        
    if(A[it_before_max]<A[max_it])
    {
        swap(A[it_before_max],A[max_it]);
        return;
    }
        
    else
    {
        while(A[it_before_max]>A[max_it])
            max_it++;
        swap(A[it_before_max],A[max_it]);
        sort(A.begin()+it_before_max+1,A.end());
        return;
    }

}       


int main() 
{
    //[ 1 2 3 6 5 4 ]
    //[ 1 2 4 3 5 6 ]
    vector<int> A;
    A.push_back(1);
    A.push_back(2);
    A.push_back(4);
    A.push_back(6);
    A.push_back(5);
    A.push_back(3);
    
    for(int i=0;i<A.size();i++)
        cout << A[i]<<" ";

    cout << endl;
    
    nextPermutation(A);
    
    for(int i=0;i<A.size();i++)
        cout << A[i]<<" ";

    cout << endl;

    return 0;
}

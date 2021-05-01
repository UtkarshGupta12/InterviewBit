//Run Time Error
//Need to look for shorter codes

#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

vector<int> Solution::plusOne(vector<int> &A)
{
    int temp = 0;
    temp = accumulate(A.begin(), A.end(), 0);
    int n = A.size();
    int i=0;
    if(n==1)
    {
        if(A[0] == 9){
            A.erase(A.begin());
            A.push_back(1);
            A.push_back(0);
        }
        else{
            A[i] = A[i] + 1;
        }
       
    }
    else if(n > 1 && temp != 9*n)
    {
        if(A[n-1]< 9)
        {
            A[n-1] = A[n-1] + 1;
        }
        else if(A[n-1] == 9)
        {
            int i=n;
            while(A[i-1] == 9 || A[i-1] == 10)
            {
              while(i >= 2)
              {
                A[i-1] = 0;
                A[i-2] = A[i-2] + 1;
                i--;
              }
            }
        }
    }
    else
   {
        A.clear();
        A.push_back(1);
        for(int l=1;l<n+1;l++)
        {
   
         A.push_back(0);
        }
      
    }
        
    int k=0;   
    while(A[k] == 0)
    {
        A.erase(A.begin());
        k++;
    }
    return A;

}

#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

vector<int> Solution::wave(vector<int> &A) {
    
        std::sort(A.begin(),A.end());
        int n = A.size();
        if(n%2 == 0)
        {
            for(int i=0;i<n;i=i+2)
            {
                swap(A[i],A[i+1]);
            }
        }
        else
        {
            int temp = A[n-1];
            for(int i=0;i<n;i=i+2)
            {
                swap(A[i],A[i+1]);

            }
            
            A[n-1] = temp;
        }

        return A;
}

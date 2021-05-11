#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B) 
{
    int sum,max_sum,N=A.size();
    
    sum = accumulate(A.begin(), A.end()-N+B, 0);
    max_sum = sum;
    
    for(int i=0;i<B;i++)
    {
        sum = sum - A[B-i-1] + A[N-i-1];
        max_sum = max(sum,max_sum);
            
        cout << i << " " << sum << " " << max_sum << endl;    
    }
    return max_sum;
}


int main()
{
    vector<int> A;
    A.push_back(5);
    A.push_back(-2);
    A.push_back(3);
    A.push_back(1);
    A.push_back(2);
    
    int sol,B = 3;
    
    cout<< A[0] <<" "<< A[1] <<" "<< A[2] <<" "<< A[3] <<" "<< A[4]<< endl;
    
    sol = solve(A,B);
    
    cout<< sol << endl; 
}

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

int sqrt(int A)
{
    if(A==0 || A==1)
        return A;
    long int low = 1, high = A,  ans;
    while(low<=high)
    {
        long int mid = (low+high)/2;
        cout <<"low = "<<low<<" , high = "<< high<<" , mid = "<< mid << endl;
        if(mid*mid <= A && (mid+1)*(mid+1) > A)
            return mid;
        else if(mid*mid > A)
            high = mid-1;
        else if(mid*mid < A)
            low = mid+1;
    }
}

int main()
{
    int n = sqrt(2147483647);
    cout << n << endl;
}

// TLE
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

int whichcase(int low,int mid,int high)
{
    if(mid>=low && mid >= high)
        return 1;
    else if(mid<=low && mid <= high)
        return 2;
    else if (mid >= low && mid <= high)
        return 0;
    else
        return 0;
}

int search(const vector<int> &A, int x) 
{
    int low = 0;
    int high = A.size()-1;
    int N = A.size();
    int mid = 0;
    
    while(low<=high)
    {
        mid = low + (high-low)/2;
        int choosecase = whichcase(A[low],A[mid],A[high]);
        
        if(A[mid] == x)
            return mid;
            
        else if(choosecase==1)
        {
            if(x>=A[low] && x<=A[mid])
                high = mid-1;
            else if(x<=A[mid])
                low = mid+1;
            else if(x >= A[mid])
                low = mid+1;
        }
        
        else if(choosecase==2)
        {
            if(x>=A[mid] && x <=A[high])
                low = mid+1;
            else if(x>=A[low])
                high = mid-1;
        }
        
        else if(choosecase==0)
        {
            if(x>=A[mid])
                low = mid+1;
            else
                high = mid-1;
        }
        
    }
    return mid;
}

int main() {
    vector<int> A;
    A.push_back(6);
    A.push_back(7);
    A.push_back(8);
    A.push_back(9);
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.push_back(4);
    A.push_back(5);
    printVec(A);
    
    int n = 3;

    int ans = search(A,n);
    cout << endl << ans << endl;
}

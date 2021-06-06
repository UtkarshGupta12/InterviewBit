#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <stack>
#define M 1000000007
using namespace std;
 
void printVec(vector<int> &v)
{
    int N = v.size();
    for(int i=0;i<N;i++)
    {
        cout << v[i] << " ";
    }
    cout <<endl;}

int last(vector<int> &arr, int x)
{
    int n = arr.size();
    int low = 0, high = n - 1, res = -1;
    while (low <= high) {
        // Normal Binary Search Logic
        int mid = (low + high) / 2;
        if (arr[mid] > x)
            high = mid - 1;
        else if (arr[mid] < x)
            low = mid + 1;
 
        // If arr[mid] is same as x, we
        // update res and move to the right
        // half.
        else {
            res = mid;
            low = mid + 1;
        }
    }
    return res;}

int removeDuplicates(vector<int> &A) 
{
    for(int i=0;i<A.size();i++)
    {
        if(i+2<A.size() && A[i]==A[i+2])
        {
            int l = last(A,A[i]);
            A.erase(A.begin()+i,A.begin()+l-1);
            i--;
        }
        else 
            continue;
        printVec(A);
    }

    return A.size();
}

int main() {
#ifndef ONLINE_JUDGE
    // for getting input from input.txt     
    freopen("input1.txt","r",stdin);
    // for writing output to output.txt
    freopen("output.txt","w",stdout);
  #endif

    vector<int> A;
    A.push_back(0);
    A.push_back(0);
    A.push_back(0);
    A.push_back(0);
    A.push_back(0);
    A.push_back(0);
    A.push_back(0);
    A.push_back(0);
    A.push_back(0);
    A.push_back(0);
    A.push_back(0);
    A.push_back(0);
    A.push_back(0);
    A.push_back(0);
    A.push_back(0);
    A.push_back(0);
    A.push_back(0);
    A.push_back(0);
    A.push_back(1);
    A.push_back(1);
    A.push_back(1);
    A.push_back(1);
    A.push_back(1);
    A.push_back(1);
    A.push_back(1);
    A.push_back(1);
    A.push_back(1);
    A.push_back(1);
    A.push_back(1);
    A.push_back(1);
    A.push_back(1);
    A.push_back(1);
    A.push_back(1);
    A.push_back(1);
    A.push_back(1);
    A.push_back(2);
    A.push_back(2);
    A.push_back(2);
    A.push_back(2);
    A.push_back(2);
    A.push_back(2);
    A.push_back(2);
    A.push_back(2);
    A.push_back(2);
    A.push_back(2);
    A.push_back(2);
    A.push_back(2);
    A.push_back(2);
    A.push_back(2);
    A.push_back(2);
    A.push_back(2);
    A.push_back(2);
    A.push_back(3);
    A.push_back(3);
    A.push_back(3);
    A.push_back(3);
    A.push_back(3);
    A.push_back(3);
    A.push_back(3);
    A.push_back(3);
    A.push_back(3);
    A.push_back(3);
    A.push_back(3);
    A.push_back(3);
    A.push_back(3);
    A.push_back(3);
    A.push_back(3);
    A.push_back(3);
    A.push_back(3);
    A.push_back(3);

    cout<<"Ques : ";printVec(A);

    int ans = removeDuplicates(A);
    cout << endl <<"Answer : "<<ans<<endl;   

    return 0;
}
/*
    Input : 
        A : [1 2 3 3 4 5 6]
        B : [3 3 5]
    Output : [3 3 5]
    Input : 
        A : [1 2 3 3 4 5 6]
        B : [3 5]
    Output : [3 5]  */

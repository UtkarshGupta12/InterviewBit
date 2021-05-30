#include <iostream>
#include <string>
#include <bits/stdc++.h>
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

void sliceit(vector<int> &v, int m, int n)
{
    int k = n - m + 1;
 
    auto it = v.cbegin() + m;
    while (it != v.cend() && k--) {
        it = v.erase(it);
    }}    

int removeDuplicates(vector<int> &A)
{
    if(A.size()==1)
        return  1;
    int j = 0;
    int n = A.size();
    for(int i=0;i<A.size();i++)
    {
        j = last(A,A[i]);
        if(j==i)
            continue;
        else 
            sliceit(A,i+1,j);
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

    vector<int> ques;
    ques.push_back(1);
    ques.push_back(1);
    ques.push_back(2);
    ques.push_back(2);
    ques.push_back(3);
    ques.push_back(3); 
    cout <<"Question  : ";printVec(ques);

    int ans ;
    ans = removeDuplicates(ques);
    cout << endl<<"Answer : "<< ans <<endl;
}

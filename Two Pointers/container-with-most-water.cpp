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

int maxArea(vector<int> &A) 
{
    if(A.size()<=1)
        return 0;

    int l = 0, r = A.size()-1;
    int max_water = INT_MIN;
    int area = 0;
    while(l<r)
    {
        area = (r-l)*min(A[l],A[r]);
        if(A[l]<A[r])
            l++;
        else
            r--;
        cout<<"Area : "<<area<<endl;
        max_water = max(area,max_water);
    }

    return max_water;
}
int main() {
#ifndef ONLINE_JUDGE
    // for getting input from input.txt     
    freopen("input1.txt","r",stdin);
    // for writing output to output.txt
    freopen("output.txt","w",stdout);
  #endif

    vector<int> A;
    A.push_back(1);
    A.push_back(5);
    A.push_back(4);
    A.push_back(3);

    cout<<"Ques : ";printVec(A);

    int ans = maxArea(A);
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

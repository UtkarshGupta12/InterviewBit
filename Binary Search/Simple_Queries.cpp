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

void printPair(vector<pair<int,int>> &pair1)
{
    for(int i = 0; i < pair1.size(); i++)
         cout <<"["<< pair1[i].first << "," << pair1[i].second<<"],";

    cout << endl;  }

int multiplyFactors(int n)
{
    int prod = 1;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            // If factors are equal,
            // multiply only once
            if (n / i == i)
                prod = (prod * i) % M;
 
            // Otherwise multiply both
            else {
                prod = (prod * i) % M;
                prod = (prod * n / i) % M;
            }
        }
    }
    return prod;}

int FindLowerRange(vector<int> A,int i)
{
    if(i==0)
        return 0;

    int low = i-1;
    while(A[low]<A[i])
        low--;
    
    low++;
    return low;}

int FindUpperRange(vector<int> A,int i)
{
    if(i==A.size()-1)
        return i;

    int high = i+1;
    while(A[high]<=A[i])
        high++;
    
    high--;
    if(high == A.size())
           high--; 
    return high;}

void ConvertPair(vector<pair<int,int>> &A)
{
    for(int i=0;i<A.size();i++)
        A[i].first = multiplyFactors(A[i].first); }

vector<pair<int,int>> FindMaxElement(vector<int> &A)
{
    int N = A.size();
    vector<pair<int,int>> pair1;
    int count = 0;
    int flag = -1;
    int low,high;

    for(int i=0;i<N;i++)
    {   
        low = FindLowerRange(A,i);
        high = FindUpperRange(A,i);
        //cout <<"Lower Index for "<<A[i]<<" : "<<low<<endl;
        //cout <<"Upper Index for "<<A[i]<<" : "<<high<<endl<<endl;

        int len = high - low + 1;
        //cout <<"Length for "<<A[i]<<" : "<<len<<endl;

        count = len*(i-low+1) - (i-low)*(i-low+1);
        //cout <<"Count for "<<A[i]<<" : "<<count<<endl;

        pair1.push_back(make_pair(A[i],count));
    }
    printPair(pair1);

    return pair1;}

void ProduceSum(vector<pair<int,int>> &pair1,vector<int> &A)
{
    int len = distance(A.begin(),unique(A.begin(), A.end()));
    //cout << len << endl;

    int i=0;
    while(pair1.size()!=len)
    {
        if(pair1[i].first!=pair1[i+1].first)
            i++;
        else if(pair1[i+1].first==pair1[i].first)
        {
            pair1[i].second += pair1[i+1].second;
            pair1.erase(pair1.begin()+i+1);
            i--;
        }                
    }}

void FindKthElement(vector<pair<int,int>> &A)
{
    for(int i=0;i<A.size()-1;i++)
        A[i+1].second += A[i].second;}    

int solve(vector<int> &A,int K)
{
    int N = A.size();
    vector<pair<int,int>> B;

    B = FindMaxElement(A);
    sort(B.begin(),B.end());
    //reverse(B.begin(),B.end());
    printPair(B);

    sort(A.begin(),A.end());
    //printVec(A);

    ProduceSum(B,A);
    reverse(B.begin(),B.end());
    printPair(B);
    ConvertPair(B);
    printPair(B);
    FindKthElement(B);
    printPair(B);

    for(int i=0;i<B.size();)
    {
        if(K<=B[i].second)
            return B[i].first;
        else
            i++;               
    }

    return INT_MAX;}

int main() {
  #ifndef ONLINE_JUDGE
    // for getting input from input.txt     
    freopen("input1.txt","r",stdin);
    // for writing output to output.txt
    freopen("output.txt","w",stdout);
#endif

	vector<int> A;
    A.push_back(6);
    A.push_back(5);
    A.push_back(3);
    A.push_back(5);
    A.push_back(2);
    A.push_back(3);
    A.push_back(8);
    A.push_back(2);

    cout << "Array is : ";
    printVec(A);

    int K = 20;
    cout <<"Kth Element : "<<K<<endl<<endl;

    int ans = solve(A,K);
    cout << endl << ans << endl;
}

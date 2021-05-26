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

int FindIndexofPeak(vector<int> &A)
{
    int low = 0, high = A.size()-1,mid = -1;
    int error = 10;

    while(low<=high || error>0) 
    {
        mid = low + (high-low)/2;
        cout <<"low = "<<low<<" , high = "<< high<<" , mid = "<< mid << endl;

        if(A[mid]>A[mid+1]&&A[mid]>A[mid-1])
            return mid;

        else if(A[mid+1]>A[mid])
            low = mid+1;
        else if(A[mid-1]>A[mid])
            high = mid-1;        

        error--;
    }

    return -1;}

int SearchLeft(vector<int> &A, int B)
{
    int low = 0, high = A.size()-1,mid = -1;
    int error = 10;

    while(low<=high)
    {
        mid = low + (high-low)/2;
        cout <<"low = "<<low<<" , high = "<< high<<" , mid = "<< mid << endl;

        if(A[mid]==B)
            return mid;  
        else if(A[mid]<B)
            low = mid+1;
        else    
            high = mid-1;
    }

    return -1;}    

int SearchRight(vector<int> &A, int B)
{
    int low = 0, high = A.size()-1,mid = -1;
    int error = 10;

    while(low<=high)
    {
        mid = low + (high-low)/2;
        cout <<"low = "<<low<<" , high = "<< high<<" , mid = "<< mid << endl;

        if(A[mid]==B)
            return mid;  
        else if(A[mid]<B)
            high = mid-1;
        else    
            low = mid+1;
    }

    return -1;}

vector<int> ProduceLeft(vector<int> &A,int index)
{
    vector<int> Left;
    for(int i=0;i<index+1;i++)
        Left.push_back(A[i]);
    
    return Left;} 

vector<int> ProduceRight(vector<int> &A,int index)
{
    vector<int> Right;
    for(int i=index+1;i<A.size();i++)
        Right.push_back(A[i]);
    
    return Right;}       

int solve(vector<int> &A, int B)
{
    int peak_index = FindIndexofPeak(A);
    cout  <<"Peak Index : "<<peak_index<<endl;
    vector<int> Left,Right;
    Left = ProduceLeft(A,peak_index);
    Right = ProduceRight(A,peak_index);

    printVec(Left);
    printVec(Right);

    int ans = SearchLeft(Left,B);
    if(ans != -1)
        return ans;    

    ans = SearchRight(Right,B);        
    if(ans != -1)
         return ans+peak_index+1;   

    return -1;
}

int main() {
  #ifndef ONLINE_JUDGE
    // for getting input from input.txt     
    freopen("input1.txt","r",stdin);
    // for writing output to output.txt
    freopen("output.txt","w",stdout);
  #endif

     //A = [3, 9, 10, 20, 17, 5, 1]
     //     0  1   2   3   4  5  6
    // B = 20
	vector<int> A;
    A.push_back(3);
    A.push_back(9);
    A.push_back(10);
    A.push_back(20);
    A.push_back(17);
    A.push_back(5);
    A.push_back(1);

    cout << "Bitonic Array : ";
    printVec(A);

    int B = 17;
    cout <<"Element to be Searched : "<<B<<endl<<endl;

    int ans = solve(A,B);
    cout << endl << ans << endl;
}

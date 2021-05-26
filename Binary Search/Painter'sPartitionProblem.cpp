#include <iostream>
#include <string>
#include <bits/stdc++.h>
#define M 10000003
using namespace std;

void printVec(vector<int> &v)
{
    int N = v.size();
    for(int i=0;i<N;i++)
    {
        cout << v[i] << " ";
    }
    cout <<endl;}

/*int SumofPainters(vector<int> &A, int num)
{
    int sum = 0;
    int count = 0;
    int max_sum = INT_MIN;

    for(int i=0;i<A.size();i++)
    {
        sum+=A[i];
        max_sum = max(sum,max_sum);

        if(sum>=x)
        {
            count++;
            sum = 0;
        }
    }
    return max_sum;}*/

int NumberofPainters(vector<int> &A, int x)
{
    int sum = 0;
    int  count = 1;
    for(int i=0;i<A.size();i++)
    {
        sum+=A[i];
        if(sum>=x)
        {
            count++;
            sum = 0;
        }
    }
    return count;}

int paint(int B, int T, vector<int> &A) 
{
    int low = *max_element(A.begin(),A.end());
    int high = accumulate(A.begin(),A.end(),0);
    int mid = -1;
    int error = 10;
    int num_painters;

    while(low<=high || error>0)
    {
        mid = low +(high-low)/2;
        num_painters = NumberofPainters(A,mid);
        cout<<"Numeber of Painters : "<<num_painters<<" & mid : "<<mid<<endl;

        //if(num_painters == B)
        //    return mid;        
        if(num_painters<=B)
            high = mid-1;
        else        
            low = mid+1;

        error--;
    }

    return INT_MAX;
}

int main() {
  #ifndef ONLINE_JUDGE
    // for getting input from input.txt     
    freopen("input1.txt","r",stdin);
    // for writing output to output.txt
    freopen("output.txt","w",stdout);
  #endif

    // Boards = [10, 20, 15, 30, 24, 35, 28, 15, 10]
    //            0   1   2   3   4   5   6   7   8
    // Painters = 4;
    // Unit Time = 5;
    vector<int> A;
    A.push_back(10);
    A.push_back(20);
    A.push_back(15);
    A.push_back(30);
    A.push_back(24);
    A.push_back(35);
    A.push_back(28);
    A.push_back(15);
    A.push_back(10);

    cout << "Boards : ";
    printVec(A);

    int B = 4;
    cout <<"Number of Painters are : "<<B<<endl;

    int T = 5;
    cout <<"Unit Time : "<<T<<endl;    

    int ans = paint(B,T,A);
    cout << endl << ans << endl;
}

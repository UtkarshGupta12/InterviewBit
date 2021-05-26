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

long long SumofPainters(vector<int> &A, long long num)
{
    long long sum = 0;
    long long max_sum = INT_MIN;

    for(int i=0;i<A.size();i++)
    {
        sum+=A[i];
        max_sum = max(sum,max_sum);
        if(sum>num)
            sum = 0;
    }

    return max_sum;}

long long NumberofPainters(vector<int> &A, long long x)
{
    long long sum = 0;
    int  count = 1;
    for(int i=0;i<A.size();i++)
    {
        sum+=A[i];
        if(sum>=x)
        {
            count++;
            sum = A[i];
        }
    }
    return count;}

int paint(int B, int T, vector<int> &A) 
{
    long long low = *max_element(A.begin(),A.end());
    int max_vector = *max_element(A.begin(),A.end());
    long long high = accumulate(A.begin(),A.end(),0);
    long long mid = -1;
    int error = 25;
    long long num_painters;

    if(A.size()<=B)
        return (max_vector*T)%M;

    while(low<high && error>0)
    {
        mid = low +(high-low)/2;
        num_painters = NumberofPainters(A,mid);
        cout<<"Number of Painters : "<<num_painters<<" & mid : "<<mid<<endl;
     
        if(num_painters<=B)
            high = mid;
        else        
            low = mid+1;

        error--;}

    if(num_painters<B)
        return T*max_vector%M;
    else        
        return T*SumofPainters(A,mid)%M;}

int main() {
  #ifndef ONLINE_JUDGE
    // for getting input from input.txt     
    freopen("input1.txt","r",stdin);
    // for writing output to output.txt
    freopen("output.txt","w",stdout);
  #endif

    // Boards = [ 449, 792, 564, 261, 584, 798, 514, 616 ]
    //              0    1    2    3    4    5    6    7
    // Painters = 2;
    // Unit Time = 10;
	vector<int> A;
    A.push_back(449);
    A.push_back(792);
    A.push_back(564);
    A.push_back(261);
    A.push_back(584);
    A.push_back(798);
    A.push_back(514);
    A.push_back(616);
    //A.push_back(10);

    cout << "Boards : ";
    printVec(A);

    int B = 2;
    cout <<"Number of Painters are : "<<B<<endl;

    int T = 10;
    cout <<"Unit Time : "<< T << endl << endl;    

    int ans = paint(B,T,A);
    cout << endl << ans << endl;
}

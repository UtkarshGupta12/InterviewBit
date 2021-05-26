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

int ProivdeValue(vector<int> &A,int K)
{
    int sum = 0;
    int max = A[0] - K;
    for(int i=0;i<A.size();i++)
        if(A[i]-max >0)
            sum+= A[i] - max;
    
    return sum;}    
 
int solve(vector<int> &A, int B)
{
    sort(A.begin(),A.end(),greater<int>());
    printVec(A);

    int error = 10;

    int low = 0,high = A[0],mid = -1;
    while(low<=high || error>0)
    {
        mid = low + (high-low)/2;
        int getvalue = ProivdeValue(A,mid);
        cout << "Mid : "<<mid <<" & Value of Trees : "<<getvalue<<endl;

        if(getvalue==B)
            return A[0]-mid;
        else if(getvalue>B)
            high = mid-1;
        else
            low = mid+1;   
        error--;                 
    }


    return A[0]-mid;
}

int main() {
  #ifndef ONLINE_JUDGE
    // for getting input from input.txt     
    freopen("input1.txt","r",stdin);
    // for writing output to output.txt
    freopen("output.txt","w",stdout);
  #endif

    //A : [ 117, 84, 50, 119, 74, 128 ]
    //B : 58
	vector<int> A;
    A.push_back(4);
    A.push_back(42);
    A.push_back(40);
    A.push_back(26);
    A.push_back(46);

    cout << "Height of trees are : ";
    printVec(A);

    int K = 20;
    cout <<"Cut off wood : "<<K<<endl<<endl;

    int ans = solve(A,K);
    cout << endl << ans << endl;
}

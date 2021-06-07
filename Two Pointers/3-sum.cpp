// NOT COMPLETED YET

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

int threeSumClosest(vector<int> &A, int B) 
{
    if(A.size()<4)
        return accumulate(A.begin(),A.end(),0);

    sort(A.begin(),A.end());
    printVec(A);

    int sum, diff,global_sum;
    int diff_min = INT_MAX;
    for(int i=1;i<A.size()-1;)
    {
        int l = i-1;
        int r = i+1;

        while(l>=0 && r<A.size())
        {  
            sum = A[l]+A[i]+A[r];
            diff = abs(B-sum);
            diff_min = min(diff,diff_min);
            if(diff_min == diff)
                global_sum = sum;
            cout<<"Sum : "<<sum<<"    & Diff : "<<diff<<endl;

            if(diff > diff_min && sum > global_sum)
                if(l>=0) l--;
            else if(diff > diff_min && sum < global_sum)
                if(r<A.size()) r++;
            else
                break;
        }
    }

    return sum;
}

int main() {

    vector<int> A;
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.push_back(4);
    A.push_back(-5);
    int B = 10;

    cout<<"Ques : ";printVec(A);cout<<"B : "<<B<<endl;

    int ans = threeSumClosest(A,B);
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

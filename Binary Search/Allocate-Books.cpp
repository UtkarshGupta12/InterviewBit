#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void printVec(vector<int> &v){
    int N = v.size();
    for(int i=0;i<N;i++)
    {
        cout << v[i] << " ";
    }
    cout <<endl;}

int minStudents(vector<int> &A, int max){
    int students = 1,sum=0;
    for(int i=0;i<A.size();i++)
    {
        sum+=A[i];
        if(sum >= max)
        {
            students++;
            sum=0; 
            i--;
        }
    }    

    return students;}

int books(vector<int> &A, int B)
{
    int start = *max_element(A.begin(),A.end());
    int end = accumulate(A.begin(),A.end(),0)-*min_element(A.begin(),A.end());        
    int mid = -1;
    
    while(start<=end)
    {
        mid = start + (end-start)/2;
        cout <<"Start = "<<start<<" , End = "<< end <<" , mid = "<< mid << endl;
        cout  << "MinStudents : "<<minStudents(A,mid)<<endl<<endl;
        int K = minStudents(A,mid);

        if(K<=B)
            end = mid-1; 

        else if(K>B)
            start = mid+1;    
    }

    return mid;
}

int main() {
#ifndef ONLINE_JUDGE
    // for getting input from input.txt     
    freopen("input1.txt","r",stdin);
    // for writing output to output.txt
    freopen("output2.txt","w",stdout);
#endif

    vector<int> A;

    A.push_back(5);
    A.push_back(7);
    A.push_back(100);
    A.push_back(11);

    cout << "A : ";
    printVec(A);

    int B = 4;
    cout << "No. of students : "<<B<<endl<<endl;

    int ans = books(A,B);

    cout << endl << "Result : "<<ans<<endl;

}

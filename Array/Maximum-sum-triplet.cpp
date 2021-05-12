// Time Complexity O(N^2) , Need to recosider the approach
#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void printPair(vector<pair<int,int>> &p)
{
    int N = p.size();
    for(int i=0;i<N;i++)
    {
        cout << p[i].first  << " ";
    }
    cout <<endl;
}

void printVec(vector<int> &v)
{
    int N = v.size();
    for(int i=0;i<N;i++)
    {
        cout << v[i] << " ";
    }
    cout <<endl;
}


int solve(vector<int> &A)
{
    int N = A.size();
    int sum,max_sum=INT_MIN;
    //Erasing Unnecessary Elements
    int maxElementIndex = max_element(A.begin(),A.end()) - A.begin();
    int minElementIndex = min_element(A.begin(),A.end()) - A.begin();
    
    if( maxElementIndex == 0 ||maxElementIndex == 1 )
        A.erase(A.begin()+maxElementIndex);
        
    if( minElementIndex == N-1 ||minElementIndex == N-2 )
        A.erase(A.begin()+minElementIndex);    
    
    printVec(A);
    
    
    for(int i=1;i<N-1;i++)
    {
        int b = A[i];
        int a=0;
        for (int j = 0; j < i; ++j)
            if (A[j] < A[i])
                a = max(a, A[j]);
        int c = *max_element(A.begin()+i+1,A.end());
        
        if( b < c)
        {
            sum = a+b+c;
            max_sum = max(max_sum,sum);
            cout << a <<" "<< b <<" "<< c <<endl;
        }
    }
    
    return max_sum;
}

int main()
{
    // [ 2 5 3 1 4 9 ]
    // [ 1 2 3 ]
    // [ 18468, 6335, 26501, 19170, 15725, 11479, 29359, 26963, 24465, 5706, 28146, 23282, 16828, 9962, 492, 2996, 11943, 4828, 5437, 32392, 14605 ]
    //[ 32592, 18763, 1656, 17411, 6360, 27625, 20538, 21549, 6484, 27596 ]
    vector<int> A,B;
    A.push_back(32592);
    A.push_back(18763);
    A.push_back(1656);
    A.push_back(17411);
    A.push_back(6360);
    A.push_back(27625);
    A.push_back(20538);
    A.push_back(21549);
    A.push_back(6484);
    A.push_back(27596);
    
    printVec(A);
    
    int sum = solve(A);

    cout<< sum << endl; 
}

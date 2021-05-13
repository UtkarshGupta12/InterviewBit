#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void printVec(vector<int> &v)
{
    int N = v.size();
    for(int i=0;i<N;i++)
    {
        cout << v[i] << " ";
    }
    cout <<endl;
}

bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
 
    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;
 
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
 
    return true;
}

vector<int> find_sumPair(vector<int> A,int K)
{ 
    int n = A.size(); 
    int i = 0;
    int j = n -1; 
    vector<int> B;
    while (i < j)
    {
       if(A[i] + A[j] == K)
       {
           B.push_back(A[i]);
           B.push_back(A[j]);
           break;
       }
       else if(A[i] + A[j] < K)
         i = i+1;
       else
         j = j-1;
    } 
    return B;
}

vector<int> primesum(int A)
{
    vector<int> B,sol;
    for(int i=2;i<A;i++)
        if(isPrime(i))
            B.push_back(i);
    
    printVec(B);
    sol = find_sumPair(B,A); 
    
    return sol;
}

int main()
{
    vector<int> A;
    
    A = primesum(10);
    printVec(A);
}

#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

string solver(string A)
{
    string B ="";
    int N = A.size();
    int count=0;
    for(int i=0;i<N;i++)
    {
        count = 1;
        for(int j=i+1;j<N;j++)
        {
            if(A[i]==A[j])
                count++;
            else
                break;
        }
        i+=count-1;
        B+=to_string(count);
        B+= A[i];
    }
    
    return B;
}

string countAndSay(int n)
{
    string ans = "1";
    if(n==1)
        return ans;
    for(int i=1;i<n;i++)
    {
       ans = solver(ans); 
       cout <<ans<<endl;
    }  
    
    return ans;
}

int main()
{
    cout << countAndSay(100)<<endl;
}

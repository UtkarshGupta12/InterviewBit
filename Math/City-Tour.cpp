//Answer seems to be correct but memory taken should be less
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

void printPairs(vector<pair<int,int>> &vec)
{
    for (int i = 0; i < vec.size(); i++) {
        cout << "(" << vec[i].first << ","
            << vec[i].second << ")" << "; ";
    }
    cout << endl;
}

void increaseNbrs(vector<pair<int,int>> &pair1)
{
    for(int i=0;i<pair1.size();i++)
    {

        if(pair1[i].second > 0 && pair1[i].first > 1 )
        {
            pair1[i-1].second = 1;
            pair1[i+1].second = 1;
            i++;
        }
        else if(pair1[i].second > 0 && pair1[i].first == 1 )
        {
            pair1[i+1].second = 1;
            i++;
        }    
        else if(pair1[i].second > 0 && pair1[i].first == pair1.size())
        {
            pair1[i-1].second = 1;
        }    
          
        printPairs(pair1);
        cout << endl;
    }
    cout << endl;
}

void placeRemaining(vector<int> &B,vector<pair<int,int>> &pair1)
{
    for(int i=0;i<B.size();i++)
    {
        //if()
    }
}

int solve(int A, vector<int> &B) 
{
    vector<pair<int,int>> pair1(A);
    for(int i=0;i<A;i++)
    {
        pair1[i].first = i+1;
        pair1[i].second = 0;
    }
    printPairs(pair1);
    
    for(int i=0;i<B.size();i++)
        if(B[i]==pair1[B[i]-1].first)
            pair1[B[i]-1].second = 1;
    printPairs(pair1);
    
    increaseNbrs(pair1);
    printPairs(pair1);
        
    increaseNbrs(pair1);
    printPairs(pair1);    
    
    return 0;
}

int main()
{
    int A = 7;
    vector<int> B;
    B.push_back(2);
    B.push_back(6);
    
    cout <<"A : " << A << endl;
    cout <<"B : ";
    printVec(B);
    
    int ans  = solve(A,B);
    cout <<"Answer is : "<< ans << endl;
    
}

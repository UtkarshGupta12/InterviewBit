//Failing for larger test cases

#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <stack>
#define M 1000000007
using namespace std;

void PrintStack_pair(stack<pair<int,int>> s)
{
    // If stack is empty then return
    if (s.empty())
        return;
 
    int x = s.top().first;
    int y = s.top().second;
 
    // Pop the top element of the stack
    s.pop();
 
    // Recursively call the function PrintStack
    PrintStack_pair(s);
 
    // Print the stack element starting
    // from the bottom
    //cout << x << " "<< y <<" ";
    cout <<"["<< x << "," << y <<"],";
 
    // Push the same element onto the stack
    // to preserve the order
    s.push({x,y});}
 
void printPair(vector<pair<int,int>> &pair1)
{
    for(int i = 0; i < pair1.size(); i++)
         cout <<"["<< pair1[i].first << "," << pair1[i].second<<"],";

    cout << endl;  } 

void printVec(vector<int> &v)
{
    int N = v.size();
    for(int i=0;i<N;i++)
    {
        cout << v[i] << " ";
    }
    cout <<endl;}

int maxSpecialProduct(vector<int> &A)
{
    if(A.size()<3)
        return 0;

    int N = A.size();
    int prod_max=INT_MIN;
    vector<pair<int,int>> p(N);
    stack<pair<int,int>> st;
    vector<int> GreatestRight;
    vector<int> GreatestLeft;

    //Making pairs
    for(int i=0;i<A.size();i++)
    {
        p[i].first = A[i];
        p[i].second = i; }
    printPair(p);cout<<endl;

    //Greatest Integer to Left
    GreatestLeft.push_back(-1);
    st.push(p[0]);
    for(int i=1;i<N;i++)
    {
        if(p[i].first < st.top().first)
        {
            GreatestLeft.push_back(st.top().second);
            st.push(p[i]);
        }
        else if(p[i].first >= st.top().first)
        {
            while(!st.empty() && p[i].first >= st.top().first)
                st.pop();
            if(st.empty()==true)
                GreatestLeft.push_back(-1);
            else if(!st.empty())
                GreatestLeft.push_back(st.top().second);
            st.push(p[i]);
        }}
    cout<<"Greatest to Left : ";printVec(GreatestLeft);
    while(!st.empty())
        st.pop(); 

    //Greatest Integer to Right
    GreatestRight.push_back(-1);
    st.push(p[N-1]);
    for(int i=A.size()-2;i>=0;i--)
    {
        if(p[i].first < st.top().first)
        {
            GreatestRight.push_back(st.top().second);
            st.push(p[i]);
        }
        else if(p[i].first >= st.top().first)
        {
            while(!st.empty() && p[i].first >= st.top().first)
                st.pop();
            if(st.empty()==true)
                GreatestRight.push_back(-1);
            else if(!st.empty())
                GreatestRight.push_back(st.top().second);
            st.push(p[i]);
        }}
    reverse(GreatestRight.begin(),GreatestRight.end());
    cout<<"Greatest to Right : ";printVec(GreatestRight);

    //Testing out prducts
    for(int i=1;i<N-1;i++)
    {
        int left = GreatestLeft[i];
        int right = GreatestRight[i];
        if(left<0 || right<0)
            continue;
        int prod = left*right;
        cout <<left<<"*"<<right<<" = "<<prod<<endl;
        prod_max = max(prod,prod_max);
    }
    
    return prod_max%M;
}

int main() {
#ifndef ONLINE_JUDGE
    // for getting input from input.txt     
    freopen("input1.txt","r",stdin);
    // for writing output to output.txt
    freopen("output.txt","w",stdout);
  #endif

    //For example,
    //Given [1,4,3,4] -> 3
    //Given [10,7,100] -> 0
    vector<int> A;
    A.push_back(10);
    A.push_back(7);
    A.push_back(100);
    //A.push_back(4);
    /*A.push_back(6);
    A.push_back(4);
    A.push_back(6);
    A.push_back(9);
    A.push_back(5);
    A.push_back(4);
    A.push_back(9);*/

    cout<<"Ques : ";printVec(A);

    int ans = maxSpecialProduct(A);
    cout << endl <<"Answer : "<<ans<<endl;   

    return 0;
}



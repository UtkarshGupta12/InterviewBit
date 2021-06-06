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

void printDeque(deque<int> &mydeque)
{
    for (auto it = mydeque.begin(); it != mydeque.end(); ++it)
            cout << ' ' << *it;}

vector<int> slidingMaximum(const vector<int> &A, int B)
{
    vector<int> ans;

    if(B>=A.size())
    {
        ans.push_back(*max_element(A.begin(),A.end()));
        return ans;}

    //Process first B elemets
    deque<int> Qi(B);
    int i;
    cout<<"        I"<<endl;
    for(i=0;i<B;i++)
    {
        while(!Qi.empty() && A[i] >= A[Qi.back()])
            Qi.pop_back();
        Qi.push_back(i);
        printDeque(Qi);cout<<endl;}    

    cout<<"       II"<<endl;
    //Processing rest of the elements
    for(;i<A.size();i++)
    {
        ans.push_back(A[Qi.front()]);

        // Remove the elements which are out of this window
        while(!Qi.empty() && Qi.front() <= i-B)
            Qi.pop_front();

        // Remove all elements smaller than the currently 
        // being added element (remove useless elements)
        while(!Qi.empty() && A[i] >= A[Qi.back()])
            Qi.pop_back();

        // Add current element at the rear of Qi
        Qi.push_back(i);
        printDeque(Qi);cout<<endl;
    }

    ans.push_back(A[Qi.front()]);

    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    // for getting input from input.txt     
    freopen("input1.txt","r",stdin);
    // for writing output to output.txt
    freopen("output.txt","w",stdout);
  #endif

    //For example,
    //The array is [1 3 -1 -3 5 3 6 7], and w is 3.
    vector<int> A;
    A.push_back(1);
    A.push_back(3);
    A.push_back(-1);
    A.push_back(-3);
    A.push_back(5);
    A.push_back(3);
    A.push_back(6);
    A.push_back(7);

    cout<<"Ques : ";printVec(A);

    vector<int> ans = slidingMaximum(A,3);
    cout << endl <<"Answer : ";printVec(ans);cout<<endl;   

    return 0;
}



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

int trap(const vector<int> &A)
{
    if(A.empty())
        return 0;

    int N = A.size();
    stack<pair<int,int>> st;
    vector<int> GreatestRight;
    vector<int> GreatestLeft;
    vector<pair<int,int>> Pair(N);

    for(int i=0;i<N;i++)
    {
        Pair[i].first = A[i];
        Pair[i].second = i;}
    printPair(Pair);    

    //Greatest Integer to Left
    GreatestLeft.push_back(-1);
    st.push(Pair[0]);
    for(int i=1;i<N;i++)
    {
        if(Pair[i].first < st.top().first)
        {
            GreatestLeft.push_back(st.top().second);
            st.push(Pair[i]);
        }
        else if(Pair[i].first >= st.top().first)
        {
            while(!st.empty() && Pair[i].first >= st.top().first)
                st.pop();
            if(st.empty()==true)
                GreatestLeft.push_back(-1);
            else if(!st.empty())
                GreatestLeft.push_back(st.top().second);
            st.push(Pair[i]);
        }}
    cout<<"Greatest to Left : ";printVec(GreatestLeft);
    while(!st.empty())
        st.pop(); 

    //Greatest Integer to Right
    GreatestRight.push_back(-1);
    st.push(Pair[N-1]);
    for(int i=A.size()-2;i>=0;i--)
    {
        if(Pair[i].first < st.top().first)
        {
            GreatestRight.push_back(st.top().second);
            st.push(Pair[i]);
        }
        else if(Pair[i].first >= st.top().first)
        {
            while(!st.empty() && Pair[i].first >= st.top().first)
                st.pop();
            if(st.empty()==true)
                GreatestRight.push_back(-1);
            else if(!st.empty())
                GreatestRight.push_back(st.top().second);
            st.push(Pair[i]);
        }}
    reverse(GreatestRight.begin(),GreatestRight.end());
    cout<<"Greatest to Right : ";printVec(GreatestRight);   

    //Deleting All -1s
    vector<int> iterators;
    int temp_i = -1;
    for(int i=0;i<GreatestLeft.size();i++)
    {
        temp_i++;
        if(GreatestRight[i]==-1||GreatestLeft[i]==-1)
        {
            GreatestLeft.erase(GreatestLeft.begin()+i);
            GreatestRight.erase(GreatestRight.begin()+i);
            i--;}
        else
            iterators.push_back(temp_i);}    
    
    cout<<"End   : ";printVec(GreatestRight);
    cout<<"Start : ";printVec(GreatestLeft);

    //Removing Duplicates
    for(int i=0;i<GreatestLeft.size();i++)
    {
        if(i<GreatestLeft.size()-1 && GreatestRight[i+1] <= GreatestRight[i] && GreatestLeft[i+1] >= GreatestLeft[i])
        {
            GreatestLeft.erase(GreatestLeft.begin()+i+1);
            GreatestRight.erase(GreatestRight.begin()+i+1);
            i--;
        }
        else if(i<GreatestLeft.size()-1 && GreatestLeft[i+1] == GreatestLeft[i] && GreatestRight[i+1] > GreatestRight[i])
        {
            GreatestLeft.erase(GreatestLeft.begin()+i);
            GreatestRight.erase(GreatestRight.begin()+i);
            i--;
        }
    }

    cout<<"End   : ";printVec(GreatestRight);
    cout<<"Start : ";printVec(GreatestLeft);

    // Calculating Heights
    int height = 0;
    for(int i=0;i<GreatestLeft.size();i++)
    {
        int bar = min(A[GreatestRight[i]],A[GreatestLeft[i]]);
        int sum = bar*(GreatestRight[i] - GreatestLeft[i]-1);

        cout<<endl<<"Bar : "<<bar<<endl;
        cout <<"Sum : "<<sum<<endl<<endl;

        for(int j=GreatestLeft[i]+1;j<GreatestRight[i];j++)
        {
            sum -= A[j];}
        height += sum;    
    }   

    return height;
} 

int main() {
#ifndef ONLINE_JUDGE
    // for getting input from input.txt     
    freopen("input1.txt","r",stdin);
    // for writing output to output.txt
    freopen("output.txt","w",stdout);
  #endif

    //For example,
    //Given height = [0,1,0,2,1,0,1,3,2,1,2,1]
    //return 6
    vector<int> A;
    A.push_back(2);
    A.push_back(0);
    A.push_back(2);
    /*A.push_back(2);
    A.push_back(1);
    A.push_back(0);
    A.push_back(1);
    A.push_back(3);
    A.push_back(2);
    A.push_back(1);
    A.push_back(2);
    A.push_back(1);*/

    cout<<"Ques : ";printVec(A);

    int ans = trap(A);
    cout << endl <<"Answer : "<<ans<<endl;   

    return 0;
}



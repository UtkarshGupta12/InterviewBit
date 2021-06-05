#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include<stack>
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

int largestRectangleArea(vector<int> &A)
{
    if(A.empty())
        return 0;

    int N = A.size();
    vector<pair<int,int>> Pair(N);

    //Attach with pairs and index;
    for(int i=0;i<A.size();i++)
    {
        Pair[i].first = A[i];
        Pair[i].second = i;}
    printPair(Pair);cout<<endl;

    stack<pair<int,int>> st;

    //Index of Smaller Integer to Right
    vector<int> SmallestRight;
    SmallestRight.push_back(-1);
    st.push(Pair[N-1]);
    //cout<<"Smallest to Right : ";printVec(SmallestRight);
    //cout<<"Stack : ";PrintStack_pair(st);cout<<endl<<endl;
    for(int i=A.size()-2;i>=0;i--)
    {
        if(Pair[i].first >= st.top().first)
        {
            SmallestRight.push_back(st.top().second);
            st.push(Pair[i]);
        }
        else if(Pair[i].first < st.top().first)
        {
            while(!st.empty() && Pair[i].first < st.top().first)
                st.pop();
            if(st.empty()==true)
                SmallestRight.push_back(-1);
            else if(!st.empty())
                SmallestRight.push_back(st.top().second);
            st.push(Pair[i]);
        }
        //cout<<"Smallest to Right : ";printVec(SmallestRight);
        //cout<<"Stack : ";PrintStack_pair(st);cout<<endl<<endl;

    }
    reverse(SmallestRight.begin(),SmallestRight.end());
    cout<<"Smallest to Right : ";printVec(SmallestRight);
    while(!st.empty())
        st.pop();    


    //Index of Smaller Integer to Left
    vector<int> SmallestLeft;
    SmallestLeft.push_back(-1);
    st.push(Pair[0]);
    //cout<<"Smallest to Left : ";printVec(SmallestLeft);
    //cout<<"Stack : ";PrintStack_pair(st);cout<<endl<<endl;
    for(int i=1;i<A.size();i++)
    {
        if(Pair[i].first >= st.top().first)
        {
            SmallestLeft.push_back(st.top().second);
            st.push(Pair[i]);
        }
        else if(Pair[i].first < st.top().first)
        {
            while(!st.empty() && Pair[i].first < st.top().first)
                st.pop();
            if(st.empty()==true)
                SmallestLeft.push_back(-1);
            else if(!st.empty())
                SmallestLeft.push_back(st.top().second);
            st.push(Pair[i]);
        }
        //cout<<"Smallest to Left : ";printVec(SmallestLeft);
        //cout<<"Stack : ";PrintStack_pair(st);cout<<endl<<endl;
    }
    cout<<"Smallest to Left Final : ";printVec(SmallestLeft);

    //Indentating Smallest to Right 
    for(int i=0;i<N;i++)
    {
        if(SmallestRight[i]==-1)
            SmallestRight[i]=N-1;
        else
            SmallestRight[i]--;}
    cout<<"Smallest to Right Final : ";printVec(SmallestRight); 
    
    //Indentating Smallest to Left 
    for(int i=0;i<N;i++) SmallestLeft[i]++;
    cout<<"Smallest to Left Final : ";printVec(SmallestLeft); 

    //Calculating Area
    int area_max = INT_MIN;
    for(int i=0;i<N;i++)
    {
        int area = (SmallestRight[i] - SmallestLeft[i] + 1)*A[i];
        area_max = max(area,area_max);
        cout << "Area for index "<<i<<" is "<<area<<endl;
    }   

    return area_max;
}

int main() {
#ifndef ONLINE_JUDGE
    // for getting input from input.txt     
    freopen("input1.txt","r",stdin);
    // for writing output to output.txt
    freopen("output.txt","w",stdout);
  #endif

    //For example,
    //Given height = [2,1,5,6,2,3]
    //return 10
    vector<int> A;
    A.push_back(2) ;
    A.push_back(1) ;
    A.push_back(5) ;
    A.push_back(6) ;
    A.push_back(2) ;
    A.push_back(3) ;
 


    cout<<"Ques : ";printVec(A);

    int ans = largestRectangleArea(A);
    cout << endl <<"Answer : "<<ans<<endl;   

    return 0;
}



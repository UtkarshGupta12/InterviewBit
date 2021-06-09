// Problematic Approac , try going for N^3 solution

#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <stack>
#include <map>
#include <iterator>
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

void printMap(unordered_map<int,int> &mp)
{
    cout << "KEY\tELEMENT\n";
    for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
        cout << itr->first<< '\t' << itr->second << '\n';}}

void printPair(vector<pair<int,int>> &pair1)
{
    for(int i = 0; i < pair1.size(); i++)
         cout <<"["<< pair1[i].first << "," << pair1[i].second<<"],";

    cout << endl;  }

vector<vector<int>> fourSum(vector<int> &A, int X)
{
    sort(A.begin(),A.end());
    printVec(A);
    vector<vector<int>> res;
    pair<int,int> p;

    //Create a vector of sum of pairs in C++
    vector<int> vec;
    vector<pair<int,int>> pr;

    for(int i=0;i<A.size()-1;i++)
    {
        for(int j=i+1;j<A.size();j++)
        {
            int sum=A[i]+A[j];
            vec.push_back(sum);
            pr.push_back(make_pair(A[i],A[j]));
        }}

    cout<<endl<<"Sum : ";printVec(vec);
    cout<<endl<<"Pair : ";printPair(pr); cout<<endl; 

    unordered_map<int,pair<int,int>> ump;  

    for(int i=0;i<vec.size();i++)
    {
        int diff = X - vec[i];
        if(ump.find(diff)!=ump.end())
        {
            int count = ump[diff].first;
            //cout << "(" << diff << ", "
            //<< vec[i] << ")" << " -> "<<ump[diff].second 
            //<<" to "<< i <<endl;

            int l = i;
            int r = ump[diff].second;

            vector<int> temp;
            temp.push_back(pr[l].first);
            temp.push_back(pr[l].second);
            temp.push_back(pr[r].first);
            temp.push_back(pr[r].second);

            sort(temp.begin(),temp.end());

            //cout<<"l : "<<l<<" & r : "<<r<<endl;
            //printMap(ump);cout<<endl;
            printVec(temp);cout<<endl;

            res.push_back(temp);
            temp.clear();
        }
        ump[vec[i]].first++;
        ump[vec[i]].second = i;
        //printMap(ump);
    }

    sort(res.begin(),res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    return res;   
}

int main() {
#ifndef ONLINE_JUDGE
    // for getting input from input.txt     
    freopen("input1.txt","r",stdin);
    // for writing output to output.txt
    freopen("output.txt","w",stdout);
  #endif

    vector<int> A;
    A.push_back(1);
    A.push_back(0);
    A.push_back(-1);
    A.push_back(0);
    A.push_back(-2);
    A.push_back(2);

    printVec(A);

    vector<vector<int>> ans = fourSum(A,0);
    //cout <<"Answer : "<<ans<<endl;   

    return 0;
}
/*Input: array = {10, 2, 3, 4, 5, 9, 7, 8} 
       X = 23 
Output: 3 5 7 8
Sum of output is equal to 23, 
i.e. 3 + 5 + 7 + 8 = 23.

Input: array = {1, 2, 3, 4, 5, 9, 7, 8}
       X = 16 
Output: 1 3 5 7
Sum of output is equal to 16, 
i.e. 1 + 3 + 5 + 7 = 16. */

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

vector<int> solve(vector<int> &A) 
{
    unordered_map<int,int> ump;
    for(int i=0;i<A.size();i++)
    {
        if(ump.find(A[i])!=ump.end())
        {
            int temp = ump[A[i]];
            A[temp]++;
            int incremented = A[temp];
            ump[incremented] = temp;
            ump[A[i]] = i;
        }
        else
            ump.insert({A[i],i});
        printMap(ump);  
        printVec(A);  
    }        
    
    return A;
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
    A.push_back(2);
    A.push_back(3);
    A.push_back(2);
    A.push_back(3);

    cout<<"A : ";printVec(A);

    vector<int> ans = solve(A);
    cout << endl <<"Answer : ";printVec(ans);   

    return 0;
}
/*Input: arr[] = {1, 2, 3, 2, 3}, K = 1
Output: [1, 4, 3, 2, 3]

*/

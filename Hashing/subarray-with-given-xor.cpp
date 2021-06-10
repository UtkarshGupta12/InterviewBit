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

int solve(vector<int> &A, int B) 
{
    cout<<"XOR must equal to : "<<B<<endl;
    int count = 0;
    int XOR = 0;

    unordered_map<int,int> ump;

    for(int i=0;i<A.size();i++)
    {
        XOR = A[i]^XOR;
        
        if(XOR==B)
            count++;

        if(ump.find(XOR^B)!=ump.end())
            count+=ump[XOR^B];
        ump[XOR]++;
    }    
    printMap(ump);  

    return count;
}


int main() {
#ifndef ONLINE_JUDGE
    // for getting input from input.txt     
    freopen("input1.txt","r",stdin);
    // for writing output to output.txt
    freopen("output.txt","w",stdout);
  #endif

    vector<int> A;
    A.push_back(5);
    A.push_back(6);
    A.push_back(7);
    A.push_back(8);
    A.push_back(9);

    cout<<"A : ";printVec(A);

    int ans = solve(A,5);
    cout << endl <<"Answer : "<<ans<<endl;   

    return 0;
}


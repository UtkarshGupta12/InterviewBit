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

vector<int> solve(vector<int> &A, vector<int> &B, vector<int> &C) 
{
    vector<int> res;
    unordered_map<int,int> ump_A;
    unordered_map<int,int> ump_B;
    unordered_map<int,int> ump_C;

    //For A
    for(int i=0;i<A.size();i++)
    {
        if(ump_A.find(A[i])!=ump_A.end())
            ump_A[A[i]]++;
        else
            ump_A.insert({A[i],1});}
    //cout<<endl<<"A ->"<<endl;printMap(ump_A);    

    //For B
    for(int i=0;i<B.size();i++)
    {
        if(ump_B.find(A[i])!=ump_B.end())
            ump_B[B[i]]++;
        else
            ump_B.insert({B[i],1});}
    //cout<<endl<<"B ->"<<endl;printMap(ump_B);   

    //For C
    for(int i=0;i<C.size();i++)
    {
        if(ump_C.find(A[i])!=ump_C.end())
            ump_C[C[i]]++;
        else
            ump_C.insert({C[i],1});}
    //cout<<endl<<"C ->"<<endl;printMap(ump_C);  

    //Common in A & B
    for(auto i:ump_A)
    {
        if(ump_B.find(i.first)!=ump_B.end())
            res.push_back(i.first);}

    //Common in B & C
    for(auto i:ump_B)
    {
        if(ump_C.find(i.first)!=ump_C.end())
            res.push_back(i.first);} 

    //Common in C & A
    for(auto i:ump_C)
    {
        if(ump_A.find(i.first)!=ump_A.end())
            res.push_back(i.first);}            

    sort(res.begin(),res.end());    
    vector<int>::iterator it;
    it = unique(res.begin(), res.end());
    res.resize(distance(res.begin(), it));
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
    A.push_back(56);
    A.push_back(56);
    A.push_back(34);
    A.push_back(34);
    A.push_back(72);
    A.push_back(71);

    vector<int> B;
    B.push_back(56);
    B.push_back(56);
    B.push_back(34);
    B.push_back(34);
    B.push_back(72);
    B.push_back(71);

    vector<int> C;
    C.push_back(56);
    C.push_back(56);
    C.push_back(34);
    C.push_back(34);
    C.push_back(72);
    C.push_back(71);

    cout<<"A : ";printVec(A);
    cout<<"B : ";printVec(B);
    cout<<"C : ";printVec(C);

    vector<int> ans = solve(A,B,C);
    cout << endl <<"Answer : ";printVec(ans);   

    return 0;
}
/*Input: A = [1, 1, 2]
         B = [2, 3]
         C = [3] 
         -> [2, 3]
1 is only present in A. 2 is present in A and B. 
3 is present in B and C.

A : [ 56, 56, 34, 34, 72, 71 ]
B : [ 56, 56, 34, 34, 72, 71 ]
C : [ 56, 56, 34, 34, 72, 71 ]
-> 34 56 71 72 

*/

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

int main() {
#ifndef ONLINE_JUDGE
    // for getting input from input.txt     
    freopen("input1.txt","r",stdin);
    // for writing output to output.txt
    freopen("output.txt","w",stdout);
  #endif

    vector<int> A;
    A.push_back(10);
    A.push_back(5);
    A.push_back(3);
    A.push_back(4);
    A.push_back(3);
    A.push_back(5);
    A.push_back(6);

    cout<<"Ques : ";printVec(A);

    int ans = firstRepeatingElement(A);
    cout << endl <<"Answer : "<<ans<<endl;   

    return 0;
}
/*
    Input : 
        A : [1 2 3 3 4 5 6]
        B : [3 3 5]
    Output : [3 3 5]
    Input : 
        A : [1 2 3 3 4 5 6]
        B : [3 5]
    Output : [3 5]  */

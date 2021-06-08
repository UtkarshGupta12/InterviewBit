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

void showdq(deque <int> g)
{
    deque <int> :: iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';}

int xorPairCount(vector<int> &A,int x)
{
    unordered_map<int,int> ump;
    int res=0;

    for(int i=0;i<A.size();i++)
    {
        int temp = A[i]^x;
        if(ump.find(temp)!=ump.end())
            res++;
        else
            ump.insert({A[i],1});
        printMap(ump);
    }
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
    A.push_back(5);
    A.push_back(4);
    A.push_back(10);
    A.push_back(15);
    A.push_back(7);
    A.push_back(6);
    int B = 5;

    cout<<"Ques   : ";printVec(A);

    int ans = xorPairCount(A,B);
    cout <<"Answer : "<<ans<<endl;   

    return 0;
}
/*Input : arr[] = {5, 4, 10, 15, 7, 6}, x = 5
Output : 1
Explanation :  (10 ^ 15) = 5

Input : arr[] = {3, 6, 8, 10, 15, 50}, x = 5
Output : 2
Explanation : (3 ^ 6) = 5 and (10 ^ 15) = 5 */

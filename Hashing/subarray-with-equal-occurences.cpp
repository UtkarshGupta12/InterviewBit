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

int solve(vector<int> &A, int B, int C) 
{
    int x = B;
    int y = C;

    cout<<"x : "<<x<<" & y : "<<y<<endl;

    //Converting to binary
    for(int i=0;i<A.size();i++)
    {
        if(A[i]==x)
            A[i]=1;
        else if(A[i]==y)
            A[i]=-1;
        else
            A[i]=0;} 
    printVec(A);    

    //Number of sub arrays with sum 0
    unordered_map<int,int> ump;
    int res = 0;
    int currsum = 0;

    for(int i=0;i<A.size();i++)
    {
        currsum += A[i];

        if(currsum==0)
            res++;

        if(ump.find(currsum-0)!=ump.end())
            res += ump[currsum-0];
        ump[currsum]++;
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
    A.push_back(1);
    A.push_back(2);
    A.push_back(2);
    A.push_back(3);
    A.push_back(4);
    A.push_back(1);

    printVec(A);

    int ans = solve(A,2,3);
    cout <<"Answer : "<<ans<<endl;   

    return 0;
}
/* arr[] = {1, 2, 2, 3, 4, 1};
   x = 2, y = 3;
   Ans : 7
*/

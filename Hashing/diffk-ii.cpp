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

int diffPossible(const vector<int> &A, int B) 
{
    unordered_map<int,int> ump;

    for(int i=0;i<A.size();i++)
    {
        // y - x = B
        int y = B + A[i];
        int x = A[i] - B;
        if(ump.find(y)!=ump.end()||ump.find(x)!=ump.end())
            return 1;
        else
            ump.insert({A[i],i});
        printMap(ump);
    }

    return 0;
}

int main() {
#ifndef ONLINE_JUDGE
    // for getting input from input.txt     
    freopen("input1.txt","r",stdin);
    // for writing output to output.txt
    freopen("output.txt","w",stdout);
  #endif

    vector<int> A;
    A.push_back(90);
    A.push_back(70);
    A.push_back(20);
    A.push_back(80);
    A.push_back(50);
    int B = 45;

    cout<<"Ques : ";printVec(A);
    cout<<"Diff  : ";cout<<B<<endl<<endl;

    int ans = diffPossible(A,B);
    cout <<"Answer : "<<ans<<endl;   

    return 0;
}
/*Input: arr[] = {5, 20, 3, 2, 50, 80}, n = 78
Output: Pair Found: (2, 80)

Input: arr[] = {90, 70, 20, 80, 50}, n = 45
Output: No Such Pair
*/

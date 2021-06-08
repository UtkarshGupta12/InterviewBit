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

vector<int> twoSum(const vector<int> &A, int B)
{
    vector<int> ans;
    unordered_map<int,int> ump;

    for(int i=0;i<A.size();i++)
    {
        int x = B - A[i];
        if(ump.find(x)!=ump.end())
        {
            cout<<"x : "<<x<<" & ump[x] : "<<ump[x]<<endl;
            ans.push_back(ump[x]);
            ans.push_back(i+1);
        }
        else 
            ump.insert({A[i],i+1});
        //printMap(ump);cout<<endl;
    }

    if(ans.size()>2)
    {
        for(int i=1;i<ans.size();i=i+2)
        {
            if(ans[i]>ans[i+2]) 
            {
                ans.erase(ans.begin()+i);
                ans.erase(ans.begin()+i-1);
            }
        }    }    
    else if(ans.size()==0) return ans;
    
    ans.resize(2);    
    return ans;
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
    A.push_back(4);
    A.push_back(45);
    A.push_back(6);
    A.push_back(10);
    A.push_back(-8);
    A.push_back(12);
    A.push_back(4);
    int B = 16;

    cout<<"Ques : ";printVec(A);
    cout<<"Sum  : ";cout<<B<<endl<<endl;

    vector<int> ans = twoSum(A,B);
    cout <<"Answer : ";printVec(ans);   

    return 0;
}
/*Input: arr[] = {0, -1, 2, -3, 1}
    Sum: -2
 Let an array be {1, 4, 45, 6, 10, -8} and sum to find be 16   

*/

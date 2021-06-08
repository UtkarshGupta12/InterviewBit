// Problem with Solution
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

vector<int> lszero(vector<int> &A)
{
    vector<int> ans;
    unordered_map<int,int> ump;
    int len;
    int max_len = INT_MIN;
    int sum=0;
    int pos;

    for(int i=0;i<A.size();i++)
    {
        sum+=A[i];
        if(ump.find(sum)!=ump.end())
        {
            len = i - ump[sum];
            max_len = max(len,max_len);
            ump.erase(sum);
            ump.insert({sum,i - len});
            cout<<"max_len : "<<max_len<<endl;

            if(len==max_len)
            {
                int temp = pos;
                pos  = i - max_len + 1;
                if(pos>temp) pos = temp;
                cout<<"Pos : "<<pos<<endl;
            }
        }
        else if(sum==0)
        {
            len = i+1;
            max_len = max(max_len,len);
            if(len==max_len)
            {
                int temp = pos;
                pos  = i - max_len + 1;
                if(pos>temp) pos = temp;
                cout<<"Pos : "<<pos<<endl;
            }
            ump.insert({sum,i});
        }
        else
            ump.insert({sum,i});    
        //printMap(ump);
    }

    cout<<endl<<"max_len : "<<max_len<<endl;
    cout<<"Pos : "<<pos<<endl<<endl;

    if(sum==0) return A;

    for(int i=pos;i<max_len+pos;i++)
        ans.push_back(A[i]);

    if(ans.size()==0)
    {
        ans.push_back(0);
        return ans;
    }
    else return ans;
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
    A.push_back(-3);
    A.push_back(3);
    //A.push_back(-1);
    //A.push_back(1);
    //A.push_back(1);
    //A.push_back(-1);

    cout<<"Ques : ";printVec(A);

    vector<int> ans = lszero(A);
    cout <<"Answer : ";printVec(ans);   

    return 0;
}
/*Input: arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
Output: 5
Explanation: The longest sub-array with 
elements summing up-to 0 is {-2, 2, -8, 1, 7} 
A : [ -1, 1, 1, -1, -1, 1, 1, -1 ]
Soln : -1 1 1 -1 -1 1 1 -1 
A : [ 1, 2, -1, 1, 3, -1, 1, 4 ]
Soln : -1 1

*/

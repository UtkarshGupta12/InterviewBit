#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <stack>
#include <map>
#include <iterator>
#include <string.h>
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

void printString(vector<string> &v)
{
    int N = v.size();
    cout<<"| ";
    for(int i=0;i<N;i++)
    {
        cout << v[i] << " | ";
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

void showdq(deque<char> mydeque)
{
    for (auto it = mydeque.begin(); it != mydeque.end(); ++it)
        cout << ' ' << *it;cout<<endl;}

string fractionToDecimal(int num, int den)
{
    string res = "";
    
    int sign = (num < 0) ^ (den < 0) ? -1 : 1;
    if(sign==-1) res+="-";

    num = abs(num);
    den = abs(den);

    res += to_string(num/den);

    if(num%den==0) return res;
    else res+=".";

    unordered_map<int,int> ump;
    int rem = num%den;

    while(rem!=0)
    {
        if(ump.find(rem)!=ump.end())
        {
            res.insert(ump[rem],1,'(');
            res+=')';
            break;
        }

        ump[rem] = res.size();

        rem *= 10;
        int temp = rem/den;
        res += to_string(temp);
        rem = rem%den;
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

    int num = -2147483648;
    int den = -1;

    cout<<"Num : "<<num<<endl;
    cout<<"---   -"<<endl;
    cout<<"Den : "<<den<<endl;

    string ans = fractionToDecimal(num,den);
    cout << endl <<"Answer : "<<ans<<endl;   

    return 0;
}
/*
Input: Numerator = 1, Denominator = 2
Output: "0.5"
1/2 = 0.5 with no repeating part.

//2147483647
//2147483648

Input: Numerator = 50, Denominator = 22
Output: "2.(27)"
50/22 = 2.27272727... Since fractional part (27) 
is repeating, it is enclosed in parentheses.

*/

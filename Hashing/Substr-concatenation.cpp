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

void printMap(unordered_map<char,int> &mp)
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

void eraseSubStr(string &mainStr,const string &toErase)
{
    // Search for the substring in string
    size_t pos = mainStr.find(toErase);
    if (pos != std::string::npos)
    {
        // If found then erase it from string
        mainStr.erase(pos, toErase.length());
    }}

vector<int> findSubstring(string A, const vector<string> &B)
{
    vector<int> res;
    string temp ="";

    //COMMENTS
        /*unordered_map<char,int> ump;
        deque<char> dq;
        int count = 0;
        int lenA = A.size();
        int lenB = 0;

        //Creating a map with count of chars of B
        for(int i=0;i<B.size();i++)
        {
            lenB += B[i].size();
            for(int j=0;j<B[i].size();j++)
                ump[B[i][j]]++;}
        printMap(ump);    
        cout<<"Total Length of B : "<<lenB<<endl;

        //Inititalising the window
        for(int i=0;i<lenB;i++)
        {
            dq.push_back(A[i]);
            if(ump.find(A[i])!=ump.end())
            {
                ump[A[i]]--;
                if(ump[A[i]]>-1) count++;
            }}
        //showdq(dq);printMap(ump);cout<<"Count : "<<count<<endl<<"---------------"<<endl;
        if(count==lenB) res.push_back(0);  

        //Iterating through the window further 
        for(int i=lenB;i<lenA;i++)
        {
            if(ump.find(dq.front())!=ump.end())
            {
                if(ump[dq.front()]>-1) count--;
                ump[dq.front()]++;   
            }
            dq.pop_front();

            dq.push_back(A[i]);
            if(ump.find(A[i])!=ump.end())
            {
                ump[A[i]]--;
                if(ump[A[i]]>-1) count++;
            }

            cout<<"For i : "<<i-lenB+1<<" -> ";showdq(dq);printMap(ump);cout<<"Count : "<<count<<endl<<"---------------"<<endl;
            if(count==lenB) res.push_back(i-lenB+1);}*/

    for(int i=0;i<B.size();i++)
    {
        for(int j=0;j<B[i].size();j++)
            temp += B[i][j];}        
    sort(temp.begin(),temp.end());
    cout<<"Temp : "<<temp<<endl<<endl;

    if(A.size()<temp.size()) return res;

    string compare = "";
    for(int i=0;i<temp.size();i++)
        compare += A[i];
    string str = compare;
    sort(str.begin(),str.end());
    //cout<<"Comp : "<<compare<<endl;

    if(temp==str) res.push_back(0);

    for(int i=temp.size();i<A.size();i++)
    {
        compare += A[i];
        compare.erase(compare.begin());
        str = compare;
        sort(str.begin(),str.end());
        //cout<<"Comp : "<<compare<<endl;
        if(temp==str) res.push_back(i-temp.size()+1);}        

    for(int i=0;i<res.size();i++)
    {
        string ques = A.substr(res[i],temp.size());
        cout<<"Ques : "<<ques<<endl;
        for(int j=0;j<B.size();j++)
        {
            if(ques.find(B[j])==string::npos)
            {
                res.erase(res.begin()+i);
                i--;
                break;
            }
            else
                eraseSubStr(ques,B[j]);
        }
        printVec(res);
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

    string A = "abbaccaaabcabbbccbabbccabbacabcacbbaabbbbbaaabaccaacbccabcbababbbabccabacbbcabbaacaccccbaabcabaabaaaabcaabcacabaa";
    vector<string> B;
    B.push_back("cac");
    B.push_back("aaa");
    B.push_back("aba");
    B.push_back("aab");
    B.push_back("abc");

    cout<<"A : "<<A<<endl;
    cout<<"    ";printString(B);

    vector<int> ans = findSubstring(A,B);
    cout << endl <<"Answer : ";printVec(ans);cout<<endl;   

    return 0;
}
/*Input : S: "barfoothefoobarman" 
        L: ["foo", "bar"]                     
Output : 0 9
Explanation : 
// at index 0 : barfoo
// at index 9 : foobar 

Input : S: "catbatatecatatebat"
        L: ["cat", "ate", "bat"] 
Output : 0 3 9
Explanation : 
// at index 0 : catbatate
// at index 3 : batatecat
// at index 9 : catatebat    

Input : S : "abcdababcd"
        L : ["ab", "ab", "cd"]
Output : 0 2 4 
Explanation :
// at index 0 : abcdab
// at index 2 : cdabab
// at index 4 : ababcd

Input : S : "abcdababcd"
        L : ["ab", "ab"]
Output : 4

A : "abbaccaaabcabbbccbabbccabbacabcacbbaabbbbbaaabaccaacbccabcbababbbabccabacbbcabbaacaccccbaabcabaabaaaabcaabcacabaa"
B : [ "cac", "aaa", "aba", "aab", "abc" ]
-> 97 

*/

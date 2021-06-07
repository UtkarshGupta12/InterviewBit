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

void printMap(unordered_map<long long,bool> &mp)
{
    cout << "KEY\tELEMENT\n";
    for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
        cout << itr->first<< '\t' << itr->second << '\n';}}

int colorful(int A)
{
    //Storing the num in string
    string num = "";
    while(A)
    {
        num += (char)(A%10 + '0');
        A = A/10;}
    reverse(num.begin(),num.end());        
    cout <<"Number : "<<num<<endl;     

    unordered_map<long long,bool> ump;

    //Checking Product at every step
    for(int i=0;i<num.size();i++)
    {
        long long prod = 1;
        for(int j=i;j<num.size();j++)
        {
            prod *= (int)(num[j]-'0');

            if(ump.find(prod)!=ump.end())
                return 0;
            else
                ump.insert({prod,true});
            printMap(ump);cout<<endl;
        }
    }

    return 1;
}

int main() {
#ifndef ONLINE_JUDGE
    // for getting input from input.txt     
    freopen("input1.txt","r",stdin);
    // for writing output to output.txt
    freopen("output.txt","w",stdout);
  #endif

    /*vector<int> A;
    A.push_back(10);
    A.push_back(5);
    A.push_back(3);
    A.push_back(4);
    A.push_back(3);
    A.push_back(5);
    A.push_back(6);*/

    int A = 1234;

    cout<<"Ques : "<<A<<endl;

    int ans = colorful(A);
    cout << endl <<"Answer : "<<ans<<endl;   

    return 0;
}

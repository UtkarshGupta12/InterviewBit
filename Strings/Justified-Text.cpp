#include <iostream>
#include <string>
#include <bits/stdc++.h>
#define M 10000003
using namespace std;

void printString(vector<string> &str)
{
    cout << "[ ";
    for(int i=0;i<str.size();i++)
    {
        cout << str[i] << " , ";
    }
    cout <<" ]"<< endl;}

void printVec(vector<int> &v)
{
    int N = v.size();
    for(int i=0;i<N;i++)
    {
        cout << v[i] << " ";
    }
    cout <<endl;}

int count(string s, char c)
{
    // Count variable
    int res = 0;
  
    for (int i=0;i<s.length();i++)
  
        // checking character in string
        if (s[i] == c)
            res++;
  
    return res;}

vector<int> LengthofWords(vector<string> &A)
{
    vector<int> len;
    for(int i=0;i<A.size();i++)
        len.push_back(A[i].size());
    
    return len;}

vector<int> JustificationNumbers(vector<int> &len, int B)
{
    int word_count = 0;
    int sum = 0;
    vector<int> Words;

    for(int i=0;i<len.size();i++)
    {
        sum += len[i];
        if(sum+word_count-1<=B)
            word_count++;
        else
        {
            Words.push_back(word_count);
            sum = 0;
            word_count = 0;
            i--;
        }
    } 
    Words.push_back(len.size()-accumulate(Words.begin(),Words.end(),0));
    //printVec(Words);

    return Words;}    

void CombineWordsinRows(vector<string> &ans,vector<string> &A,vector<int> &count_words)
{
    int sum = 0;
    for(int i=0;i<count_words.size();i++)
    {
        for(int j=sum ; j<count_words[i]+sum;j++)
        {
            ans[i]+=A[j];
            ans[i]+="$";
        }
        sum += count_words[i];
        ans[i].erase(ans[i].size()-1);
    }}   

void IncreaseExtraSpaces(string &str, int B, int count_words)
{
    string spaces = "";
    int countofspaces = (B-str.size())/(count_words-1);

    for(int i=0;i<countofspaces;i++)
        spaces+=" ";

    cout <<"Spaces : "<<spaces<<endl;
    
    int j = 0;
    //cout << i << endl;
    while(j<B)
    { 
        if(str[j]=='$')
            str.insert(j+1,spaces);
        j++;    
    }}
    
void EquallySpace(vector<string> &str,int B,vector<int> &count_words)
{
    for(int i=0;i<str.size()-1;i++)
        IncreaseExtraSpaces(str[i],B,count_words[i]);

    for(int i=0;i<str.size()-1;i++)
    {
        if(str[i].size()<B)
        {
            int count = B - str[i].size();
            int j = 0;
            int error = 10;

            while(count>0&&error>0)
            {
                if(str[i][j]=='$')
                {
                    str[i].insert(j+1," "); 
                    count--;       
                }
                j++;
                error--;}
        }
    }

    for(int i=0;i<str.size();i++)
    {
        for(int j=0;j<str[i].size();j++)
        {
            if(str[i][j]=='$')
                str[i].replace(j,1," "); 
        }
    }   }  

vector<string> fullJustify(vector<string> &A, int B)
{
    vector<int> len,count_words;
    len = LengthofWords(A);
    cout << "Length of Words : ";
    printVec(len);

    count_words = JustificationNumbers(len,B);
    cout <<"Count of Words in each sentence : ";printVec(count_words);cout<<endl;

    int num_rows = count_words.size();
    vector<string> ans(num_rows);
    CombineWordsinRows(ans,A,count_words);
    printString(ans);cout << endl;

    EquallySpace(ans,B,count_words);
    printString(ans);

    return ans;}

int main() {
#ifndef ONLINE_JUDGE
    // for getting input from input.txt     
    freopen("input1.txt","r",stdin);
    // for writing output to output.txt
    freopen("output.txt","w",stdout);
  #endif

    vector<string> ques = {"This","is","an","example","of","text","justification."};
    int L = 16;
    cout << "Question : ";
    printString(ques);
    cout << "L : "<<L<<endl;

    vector<string> ans = fullJustify(ques,L);
    cout << endl<<"Answer : ";
    printString(ans);
    cout << endl <<endl;
}

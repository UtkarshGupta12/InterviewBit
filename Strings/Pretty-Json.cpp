#include <iostream>
#include <string>
#include <bits/stdc++.h>
#define M 1000000007
using namespace std;

void printString(vector<string> &str)
{
    for(int i=0;i<str.size();i++)
    {
        cout << str[i] << endl;
    }
    cout << endl;}

void InsertTab(string &str,int k)
{str.insert(0,k,'\t');}

string RemoveCharacters(string A)
{
    for(int i=0;i<A.size();i++)
        if(A[i]=='{'||A[i]=='['||A[i]==']'||A[i]=='}'||A[i]==',')
            A[i]=' ';

    if(A[0]==' ')
        A.erase(A.begin());    

    return A;    }

vector<string> removeDupWord(string &A)
{
    vector<string> v;
    string word = "";
    for (int i=0;i<A.size();i++) 
    {
        if (A[i] == ' ')
        { 
            v.insert(v.end(),word);
            word = "";
        }
        else {
            word+=A[i];
        }
        
    }
    return v;}

void FinalOutput(vector<string> &words,vector<string> &ans)
{
    int j=0;
    int k =0;
    for(int i=0;i<ans.size();i++)
    {
        k=0;
        if(ans[i].back()=='{'||ans[i].back()=='}'||ans[i].back()=='['||ans[i].back()==']')
            continue;
        else 
        {
            while(ans[i][k]=='\t')
                k++;
            ans[i].insert(k,words[j]);
            j++;
        }
    }}

void RemoveEmpty(vector<string> &words)
{
    for(int i=0;i<words.size();i++)
    {
        if(words[i]==""||words[i]==" "||words[i]=="\t")
            words.erase(words.begin()+i);
        continue;
    }}    

vector<string> prettyJSON(string A)
{
    vector<string> ans;

    for(int i=0;i<A.size();i++)
    {
        string temp ;
        temp.push_back(A[i]);

        if(A[i]=='{'||A[i]=='[')
            ans.insert(ans.end(),temp);
        else if(A[i]=='}'||A[i]==']')
            ans.insert(ans.end(),temp);
        else if(A[i]==',')
            ans.insert(ans.end(),temp);
        temp.clear();}

    for(int i=0;i<ans.size();i++)
    {
        if(ans[i][0]==',')
        {
            if(ans[i+1][0]=='{'||ans[i+1][0]=='['||ans[i+1][0]==']'||ans[i+1][0]=='}')
                ans.insert(ans.begin()+i+1,"");
        }    }    

    int braces = 0,flag=0;
    for(int i=0;i<ans.size()-1;i++)
    {
        if(ans[i].back()=='{'||ans[i].back()=='[')
            braces++;
        else if(ans[i].back()=='}'||ans[i].back()==']')
        {
            if(flag==0)
                braces=braces-2;
            else if(flag==1)
                braces--;
            flag = 1;
        }

        //cout <<"Braces : "<<braces<<endl;
        InsertTab(ans[i+1],braces); }

    int stop = 0;
    for(int i=ans.size()-1;i>=0;i--)
    {
        if(ans[i].back()=='}'||ans[i].back()==']')
            if(!(ans[i-1].back()=='}'||ans[i-1].back()==']'))
            {
                ans[i].erase(ans[i].begin(),ans[i].begin()+1);
                stop = i;       
            }}        

    vector<string> words;  

    A = RemoveCharacters(A);
    //cout << A << endl;  
    words = removeDupWord(A);   

    RemoveEmpty(words);
    FinalOutput(words,ans);

    printString(words);
    printString(ans);
}

int main() {
#ifndef ONLINE_JUDGE
    // for getting input from input.txt     
    freopen("input1.txt","r",stdin);
    // for writing output to output.txt
    freopen("output.txt","w",stdout);
  #endif

    //"{A:\"B\",C:{D:\"E\",F:{G:\"H\",I:\"J\"}}}";
    string ques =  "[\"foo\", {\"bar\":[\"baz\",null,1.0,2]}]";
    cout <<"Question  : "<<ques<<endl<<endl;

    vector<string> ans ;
    ans = prettyJSON(ques);
    cout << endl<<"Answer : ";printString(ans);cout<<endl;
}

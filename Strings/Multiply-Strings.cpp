#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void printVec(vector<int> &v)
{
    int N = v.size();
    for(int i=0;i<N;i++)
    {
        cout << v[i] << " ";
    }
    cout <<endl;
}

void printPair(vector<pair<int,int>> &A)
{
    for(int i = 0; i < A.size(); i++)
        cout << "(" << A.at(i).first << ","<< A.at(i).second << ")" << "; ";
    cout << endl;    
}

bool sortbysecdesc(const pair<int,int> &a,
                   const pair<int,int> &b)
{
       return a.second>b.second;
}

string multiply(string str1, string str2)
{
    if(str1=="0"||str2=="0")
        return "0";
    
    string ans ="";
    vector<int> A,B;
    for(int i=0;i<str1.size();i++)
        A.push_back(str1[i]-'0');
        
    for(int i=0;i<str2.size();i++)
        B.push_back(str2[i]-'0');    
    
    while(A[0]==0)
        A.erase(A.begin());
    
    while(B[0]==0)
        B.erase(B.begin());
    
    cout << "A : ";
    printVec(A);
    cout << "B : ";
    printVec(B);
    
    vector<pair<int,int>> result;

    for(int i=0;i<B.size();i++)
    {
        for(int j=0;j<A.size();j++)
        {
            result.push_back(make_pair(A[j]*B[i], i+j));
            printPair(result);
        }
    }
    
    sort(result.begin(), result.end(), sortbysecdesc);
    printPair(result);
    
    int X_size = result[0].second;
    vector<int> X(X_size+1,0);

    for(int i=0;i<result.size();i++)
    {
        X[result[i].second]+=result[i].first;
    }
    printVec(X);
    
    for(int i=X.size()-1;i>0;i--)
    {
       X[i-1]+=X[i]/10;
       X[i]=X[i]%10;
    }
    printVec(X);
    
    for(int i=0;i<X.size();i++)
        ans+=to_string(X[i]);

    return ans;
}

int main()
{
    string A = "6020453667958309279424408570378228292268488402";
    string B = "0021473700594524297017810575200827941459805716642468749607585313713214621412";
    cout << "Numbers are : "<< A <<" & "<<B<<endl;
    string ans = multiply(A,B);
    cout << "Ans  : "<< ans << endl;
    
}

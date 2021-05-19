// Thought it correct but answer is greater than unsigned long long so look at editorial solution below

#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void printVec(vector<unsigned long long> &v)
{
    int N = v.size();
    for(int i=0;i<N;i++)
    {
        cout << v[i] << " ";
    }
    cout <<endl;
}

vector<unsigned long long> string2vec(string v)
{
    string temp="";
    vector<unsigned long long> ver;
    for(int i = 0;i<v.size();i++)
    {
        if(v[i]=='.')
        {
            ver.push_back(stoull(temp,nullptr,0));    
            temp = "";
            continue;
        }    
        else if(v[i]!='.')
        {
            temp+=v[i];
            //cout << temp<<endl;
            continue;
        }    
        
        // EDITORIAL SOLUTION
        
        int Solution::compareVersion(string A, string B) {
    
    unsigned long long a = 0,b=0;
    for(int i=0,j=0; (i<A.length())||(j<B.length());)
    {
        while(i<A.length() && A[i]!='.')
        {
            a+= a*10 + (A[i]-'0');
            i++;
        }
        
        while(j<B.length() && B[j]!='.')
        {
            b+= b*10 + (B[j]-'0');
            j++;
        }
        
        if(a>b){return 1;}
        if(b>a){ return -1; }
        a=0; b=0;
        i++; j++;
    }
return 0;
}

        
    }
    ver.push_back(stoull(temp,nullptr,0));
    printVec(ver);
    return ver;
}

int compareVersion(string v1, string v2)
{
    string int_maxx = "18446744073709551615";
    if (v1>int_maxx && v2<int_maxx)
        return 1;
    else if(v2>int_maxx && v1<int_maxx)
        return -1;
    else if(v2>int_maxx && v1>int_maxx && v2.size()>19 && v1.size()>19)
    {
        for(int i=0;i<max(v1.size(),v2.size());i++)
        {
            cout << v1[i] <<" "<<v2[i]<<endl;
            if(v1[i]>v2[i])
                return 1;
            else if(v1[i]<v2[i])
                return -1;
            else if(v1[i]==v2[i])
                continue;
        }
    }
    
    vector<unsigned long long> ver1,ver2;
    ver1 = string2vec(v1);
    ver2 = string2vec(v2);
    
    int m = ver1.size();
    int n = ver2.size();
    
    if(m>n)
    {
        for(int i=0;i<m-n;i++)
            ver2.push_back(0);
        
    }
    else if(n>m)
    {
        for(int i=0;i<n-m;i++)
            ver1.push_back(0);
    }
    
    for(int i = 0;i<ver1.size();i++)
    {
        if(ver1[i]>ver2[i])
            return 1;
        else if(ver1[i]<ver2[i])
            return -1;
        else 
            continue;
    }
    return 0;
}

int main()
{
    // 0.1 < 1.1 < 1.2 < 1.13 < 1.13.4 
    //If version1 > version2 return 1,
    //If version1 < version2 return -1,
    //otherwise return 0.
    // 18,446,744,073,709,551,615
    // 44,444,444,444,444,444,444,444,4
    string version1 = "8.88888888888888888888888888888";
    string version2 = "8.888888888888888";
    int ans = compareVersion(version1,version2);
    
    cout << ans << endl;
    
}

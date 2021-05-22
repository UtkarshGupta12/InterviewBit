#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int strStr(const string &haystack, const string &needle)
{
    int index = -1;
    int m = haystack.size();
    int n = needle.size();
    int count = 0,count_max=INT_MIN;
    
    if(n>m)
        return -1;
    else if(haystack.empty()||needle.empty())
        return -1;
        
    for(int i=0;i<m;i++)
    {
        count = 0;
        if(haystack[i]==needle[0])
        {
            for(int j=0;j<n;j++)
            {
                if(haystack[i+j]!=needle[j])
                    break;
                else
                    count++;
            }
        }
        if(count > count_max)
            index = i;
        count_max = max(count,count_max);
        
    }
    
    if(count_max >= n)
        return index;
    return -1;
}

int main()
{
    string A = "babaaaabbbbbabbaababbaaabbabaaaabaaaabbaabaabababaabbaabbaaaaababba";
    string B = "bbaa";
    cout << "Haystack : "<< A <<endl;
    cout << "Needle   : "<< B <<endl;
    int ans = strStr(A,B);
    cout << "Ans  : "<< ans << endl;
    
}

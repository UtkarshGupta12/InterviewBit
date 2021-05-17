#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int lengthOfLastWord(const string str)
{
    if(str.empty())
        return 0;
        
    int end = str.length()-1;
    
    while(!isalpha(str[end]))
        end--;
        
    int start = end;
    while(!isspace(str[start])&&start>=0)
        start--;
    
    return end-start;
}

int main()
{
    //"Hello World"
    string str="abc";
    cout <<str<<endl;
    
    int ans;
    ans = lengthOfLastWord(str);
    cout << ans << endl;
}




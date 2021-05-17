#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

bool isVowel(char ch)
{
    ch = toupper(ch);
    return (ch=='A' || ch=='E' || ch=='I' ||
                       ch=='O' || ch=='U');
}

int solve(string str)
{
    int count=0;
    for(int i=0;i<str.size();i++)
        if(isVowel(str[i]))
            count+= str.size()-i;
        
    return count % 10003;
}

int main()
{
    //"Hello World"
    string str="ABec";
    cout <<str<<endl;
    
    int ans;
    ans = solve(str);
    cout << ans << endl;
}




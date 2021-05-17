#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int isPalindrome(string str) 
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    cout << str << endl;
    str.erase(remove(str.begin(), str.end(), ':'), str.end());
    cout << str << endl;
    str.erase(remove(str.begin(), str.end(), ','), str.end());
    cout << str << endl;
    str.erase(remove(str.begin(), str.end(), '"'), str.end());
    cout << str << endl;
  
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    cout << str << endl;
    
    int count=0;

    for(int i=0;i<str.size()/2;i++)
    {
        cout << "str["<<i<<"]="<<str[i]<<" , str["<<str.size()-i-1<<"]="<<str[str.size()-i-1]<<endl;
        if(str[i]==str[str.size()-i-1])
            count++;
        else
            break;
    }
    if(count>=str.size()/2)
        return 1;
    else    
        return 0;
}

int main()
{
    string str = "abbba";
    cout << str << endl;
    cout << isPalindrome(str)<<endl;
    
}




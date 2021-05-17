#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

//To remove specific characters from a string
//str.erase(remove(str.begin(), str.end(), ' '), str.end());

//To transform allc character to lower case
//transform(str.begin(), str.end(), str.begin(), ::tolower);


int main()
{
    string str = "abbba";
    cout << str << endl;
    cout << isPalindrome(str)<<endl;
    
}




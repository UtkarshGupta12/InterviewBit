#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void printString(vector<string> &str)
{
    for(int i=0;i<str.size();i++)
    {
        cout << str[i] << " , ";
    }
    cout << endl;
}

string longestCommonPrefix(vector<string> &str)
{
    string ans="";
    int nrows = str.size();
    int ncols = str[0].size();
    int word_count = 0;
    for(int i=0;i<ncols;i++)
    {
        int count = 1;
        for(int j=1;j<nrows;j++)
        {
            char key = str[0][i];
            if(str[j][i]==key)
                count++;
            else
                break;
        }
        if(count>=nrows)
            word_count++;
    }
    
    for(int i=0;i<word_count;i++)
        ans+=str[0][i];

    return ans;
}

int main()
{
    //"abcdefgh", "aefghijk", "abcefgh"
    vector<string> str(3);
    str[0] = "apple";
    str[1] = "appl";
    str[2] = "app";
    
    printString(str);
    
    string ans;
    ans = longestCommonPrefix(str);
    cout << ans << endl;
}




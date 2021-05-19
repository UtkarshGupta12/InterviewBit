#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void printString(vector<string> &str)
{
    for(int i=0;i<str.size();i++)
    {
        cout << str[i] << "   ";
    }
    cout << endl;
}

bool valid(string s) 
{
    if (s.size() > 1 && s[0] == '0')
        return false;
    else if (stoi(s) <= 255 && stoi(s) >= 0)
        return true;
    else
        return false;
}

vector<string> restoreIpAddresses(string s)
{
    vector<string> ans;
    string A,B,C,D;
    int n = s.size();
    
    int start=1,end=n-2;
    while(start<4)
    {
        end=n-2;
        
        A = s.substr(0,start);
        if(!valid(A))
            break;
            
        while(end>n-5)
        {
            D = s.substr(end+1,n-end);
            if(!valid(D))
                break;
            for(int k=start+1;k<end+1;k++)
            {
                
                B = s.substr(start,k-start);
                C = s.substr(k,end-k+1);
                
                if(valid(B)&&valid(C))
                {
                    cout <<A<<" "<<B<<" "<<C<<" "<<D<<endl<<endl;
                   // ans.push_back(A+"."+B+"."+C+"."+D);
                }
            }
            end--;
        }
        start++;
    }
    
    cout<<endl;
    return ans;
}

int main()
{
    //0.10.0.100 & 0.100.10.0 
    vector<string> ans;
    
    string s = "0100100";
    ans = restoreIpAddresses(s);
    
    printString(ans);
}

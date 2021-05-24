#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

string removeZeroes(string str) 
{
    str.erase(remove(str.begin(), str.end(), '0'), str.end());
    return str;
}

string solve(string A, int B) 
{
    string temp = "";
    int N = A.size();
    for(int i=0;i<B;i++)
        temp+='0';
    cout << temp << endl;
    
    int index = -1,count=1;
    for(int i=0;i<N-1;)
    {
        count = 1;
        if(A[i+1]!=A[i])
            i++;
        else if(A[i+1]==A[i])
        {
            index = i;
            while(A[index+1]==A[index])
            {
                //cout << index << endl;
                index++;
                count++;
            }    
            if(count==B)
                A.replace(i,B,temp);
            i=i+count;    
        }
        cout << A <<endl;
    }
    
    A = removeZeroes(A);
    
    return A;
}


int main() {

    // a a b b b c c d
    // 0 1 2 3 4 5 6 7
    string A = "aabbbccd";
    cout << A <<endl<<endl;
    
    string ans = solve(A,3);
    cout <<endl<< ans << endl;
}

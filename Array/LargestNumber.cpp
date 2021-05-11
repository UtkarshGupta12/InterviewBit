#include <iostream>
#include<string> 
using namespace std;


int concat(int a, int b)
{
    // Convert both the integers to string
    string s1 = to_string(a);
    string s2 = to_string(b);
    // Concatenate both strings
    string s = s1 + s2;
    // Convert the concatenated string to integer
    int c = stoi(s);
    // return the formed integer
    return c;
}

bool compare(int a,int b)
{   
    int x = concat(a,b);
    int y = concat(b,a);
    if( x < y)
    {
        return true;
    }
    else{
        return false;
    }
}

string Solution::largestNumber(const vector<int> &A) {
    
    vector<int> arr = A;
    int n = arr.size();
    
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(compare(arr[i],arr[j]) == true)
            {
               swap(arr[i],arr[j]);
            }
        }
    }
    
    string str ;
    
    if(arr[0] == 0)
    {
        str = to_string(0);
    }
    
    else{
        for(int m=0;m<n;m++)
        {
        str += to_string(arr[m]);
        }
    }
    
    return str;
    
}

bool isNumeric(char ch)
{
    return (ch >= '0' && ch <= '9') ? true : false;
}

int Solution::atoi(const string &A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    
    int res = 0, sign = 1, i = 0;
    
    while(A[i] == ' ') 
        i++;
    if(A[0] == '-' || A[0] == '+')
    {
        if(A[i++] == '-') 
            sign = -1;
        else 
            sign = 1;
    }
    
    while(isNumeric(A[i]))
    {
        if(res > INT_MAX/10 || (res == INT_MAX/10 && A[i]-'0' > 7))
        {
            if(sign == 1)
                return INT_MAX;
            else return INT_MIN;
        }
        
        res = res*10 + (A[i++]-'0');
    }
    
    return sign*res;
    
}


METHOD - 2 - Minor Mistake

#include <iostream>
#include <string>
#include <bits/stdc++.h>
#define M 1000000007
using namespace std;

bool isNumeric(char ch)
{ return (ch >= '0' && ch <= '9') ? true : false;}

bool isAlpha(char ch)
{
    if((ch >= 'a' && ch <= 'z')||(ch >= 'A' && ch <= 'Z'))
        return true;
    else
        return false;}    

bool isNegative(const string &A,int start)
{
    for(int i=0;i<start;i++)
    {
        if(A[i]=='-')
            return true;
    }

    return false;}    

int Convert2Number(const string &A,int start, int end)
{
    int num=0;
    for(int i=start;i<end;i++)
    {
        int temp = A[i]-'0';
        num = num*10 +temp;
        if(num > INT_MAX/10 || (num == INT_MAX/10 && temp > 7))
            return INT_MAX;
        cout <<"Num : "<<num<<endl;
    }
    return num;}    

int atoi(const string &A)
{
    int start = 0;

    int i = 0;
    while(!isNumeric(A[i]))
        i++;
    start = i;

    if(A[0]=='-'||A[0]=='+')
    if(start > 1)
        return 0;

    for(int j=0;j<start;j++)
    {
        if(isAlpha(A[j]))
            return 0;}

    while(isNumeric(A[i]))
        i++;
    int end = i;
    cout <<"Start : "<<start<<" & End : "<<end<<endl;

    int ans = Convert2Number(A,start,end);
    if(isNegative(A,start) && ans != INT_MAX)
        return ans*(-1);
    else if(isNegative(A,start) && ans == INT_MAX)
        return INT_MIN;
    else
        return ans;
} 

int main() {
#ifndef ONLINE_JUDGE
    // for getting input from input.txt     
    freopen("input1.txt","r",stdin);
    // for writing output to output.txt
    freopen("output.txt","w",stdout);
  #endif

    /*Questions:
    Q1. Does string contain whitespace characters before the number?
    A. Yes
    Q2. Can the string have garbage characters after the number?
    A. Yes. Ignore it.
    Q3. If no numeric character is found before encountering garbage characters, what should I do?
    A. Return 0.
    Q4. What if the integer overflows?
    A. Return INT_MAX if the number is positive, INT_MIN otherwise.
    INT_MAX : 2147483647 , INT_MIN : -2147483647
              614273316  */ 

    string ques = {"614273316 072BT097 0 N818 Q 74571983Q7391995080P1810U 9070955Q90 T04437 545N792730 73"};
    cout <<"Question  : "<<ques<<endl;

    int ans = atoi(ques);
    cout << endl<<"Answer : "<< ans <<endl;
}

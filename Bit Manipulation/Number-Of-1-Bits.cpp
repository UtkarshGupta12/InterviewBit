#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int numSetBits(unsigned int A) 
{
    int count=0;
    for(unsigned long int i=4294967296;i>0;i=i/2)
    {
        if(A/i==1)
            count++;
        A=A%i; 
        cout << count << " ";
    }
    return count;
}

int main() 
{
    // 4294967296
    // 4294967295
    unsigned int A = 4294967295;
    
    cout << "A : "<<A<<endl;
    cout <<"Answer : "<<numSetBits(A) << endl;
    
    return 0;
}

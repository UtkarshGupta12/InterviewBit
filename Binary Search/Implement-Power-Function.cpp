#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void printVec(vector<int> &v)
{
    int N = v.size();
    for(int i=0;i<N;i++)
    {
        cout << v[i] << " ";
    }
    cout <<endl;
}

int pow(int x, int n, int p) {
    if (n == 0) return 1 % p;
 
    long long ans = 1, base = x;
     
    while (n > 0) 
    {
        if (n % 2 == 1) {
            ans = (ans * base) % p;
            n--;
        } 
        else {
            base = (base * base) % p;
            n /= 2;
        }
    }
     
    if (ans < 0) ans = (ans + p) % p;
    return ans;
}

int main() {

	int x = -1;
	int n = 1;
	int p = 20;

    int ans = pow(x,n,p);
    cout << endl << ans << endl;
}    

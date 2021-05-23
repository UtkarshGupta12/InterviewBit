#include <iostream>
// YET TO BE COMPLETED
#include <string>
#include <bits/stdc++.h>
using namespace std;

int pow(int x, int n, int d)
{
	int res = x;

	while(n-1)
	{
		cout << res <<"*"<<res<<" = ";
		res =  res*res;
		cout << res << endl;
		n=n/2;
	}

	return res%d;
}

int main() {
#ifndef ONLINE_JUDGE
    // for getting input from input.txt 	
	freopen("input1.txt","r",stdin);
	// for writing output to output.txt
	freopen("output1.txt","w",stdout);
#endif

	int x = 3, n = 9 , d = 7;
	cout << "x : "<< x << endl <<"n : "<< n << endl <<"d : "<< d << endl;
	int ans = pow(x,n,d);
	cout <<endl<<"Answer is : "<<ans<<endl;

}


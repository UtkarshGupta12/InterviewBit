#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int solve(string A) 
{
    int N1  = A.size();
	int i = 0;
	int j = A.size()-1;
	while(i<=j)
	{
	    cout <<"A["<<i<<"] : "<<A[i]<<" & A["<<j<<"] : "<<A[j]<<endl;
		if(A[i]==A[j])
		{
			i++;
			j--;
		}
		else if(A[i]!=A[j])
		{
			A.erase(A.begin()+i);
			i=0;
			j=A.size()-1;
		}
	}
	
	int N2 = A.size();
	
	if(N1-N2==1)
	    return 1;
	else if(N1==N2 && N1%2==1)
	    return 1;
	else
	    return 0;
}


int main() {

    string A = "abcba";
    cout << A <<endl<<endl;
    
    int ans = solve(A);
    cout <<endl<< ans << endl;
}

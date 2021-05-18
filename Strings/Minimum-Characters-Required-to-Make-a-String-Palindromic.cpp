//METHOD 1 - Shows TLE though
#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int solve(string A) 
{
    string B;
    B = A;
    reverse(B.begin(), B.end());
    
    int count = 0;
    while(B!=A)
    {
        B.erase(B.begin());
        A.pop_back();
        count++;
        cout << B <<" = "<<A<<endl;
    }
    
    return count;
}

int main()
{
    string input = "AACECAAAA";
    cout << solve(input)<<endl;
}

//METHOD - 2

int Solution::solve(string A) {
	int start = 0, end = A.length() - 1;
	int temp_end = end;

	/*Idea is to find longest palindrome length starting from index 0.
    Difference of this length from string length is the required value */

	while (start <= temp_end) {
		if (A[start] == A[temp_end]) {
			start++;
			temp_end--;
		} else {
			start = 0;
			temp_end = --end;
		}
	}

	return A.length() - (end + 1);
}

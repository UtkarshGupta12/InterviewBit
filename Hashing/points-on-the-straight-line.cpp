#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <stack>
#include <map>
#include <iterator>
#include <string.h>
#define M 1000000007
using namespace std;
 
void printVec(vector<int> &v)
{
    int N = v.size();
    for(int i=0;i<N;i++)
    {
        cout << v[i] << " ";
    }
    cout <<endl;}

void printString(vector<string> &v)
{
    int N = v.size();
    cout<<"| ";
    for(int i=0;i<N;i++)
    {
        cout << v[i] << " | ";
    }
    cout <<endl;}

void printMap(unordered_map<string,int> &mp)
{
    cout << "KEY\tELEMENT\n";
    for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
        cout << itr->first<< '\t' << itr->second << '\n';}}

void printPair(vector<pair<int,int>> &pair1)
{
    for(int i = 0; i < pair1.size(); i++)
         cout <<"["<< pair1[i].first << "," << pair1[i].second<<"],";

    cout << endl;  }

void showdq(deque<char> mydeque)
{
    for (auto it = mydeque.begin(); it != mydeque.end(); ++it)
        cout << ' ' << *it;cout<<endl;}

float slopeCalculater(int x1,int x2,int y1,int y2)
{
    float ans;
    ans = ((float)y2 - (float)y1)/((float)x2 - (float)x1);
    return ans;}

float interceptCalculator(int y1,int x1,float slope)
{
    float intercept;
    intercept = (float)y1 - slope*(float)x1;
    return intercept;}

bool PointonLine(int x1,int y1,float slope, float intercept)
{
    if(intercept == (float)y1 - slope*(float)x1)
        return true;
    else if(isnan(slope) && isnan(intercept))
        return true;
    else    
        return false;}

int maxPoints(vector<int> &X, vector<int> &Y)
{
    if(X.size()==0) return 0;
    else if(X.size()==1) return 1;
    else if(X.size()==2) return 2;
    string temp;
    int res=0;
    float global_slope,global_intercept;

    int count;
    int count_max = INT_MIN;

    int n = X.size();
    //vectors index relates to maps key
    unordered_map<string,int> ump;

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int x1 = X[i];
            int x2 = X[j];
            int y1 = Y[i];
            int y2 = Y[j];
            string str;

            float slope = slopeCalculater(x1,x2,y1,y2);
            float intercept = interceptCalculator(y1,x1,slope);
            //cout<<"("<<x1<<","<<y1<<") & ("<<x2<<","<<y2<<") -> ";

            str = to_string(slope) + " & " + to_string(intercept);
            //cout<<str<<endl; 

            ump[str]++;
            count = ump[str];
            count_max = max(count_max,count);
            if(count == count_max)
            {
                global_slope = slope;
                global_intercept = intercept;
            }
        }}
    //cout<<endl;printMap(ump);
    cout<<"Slope -> "<<global_slope<<" & Intercept -> "<<global_intercept<<endl;

    //Checking each point on the line 
    for(int i=0;i<n;i++)
    {
        if(PointonLine(X[i],Y[i],global_slope,global_intercept))
            res++;}

    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    // for getting input from input.txt     
    freopen("input1.txt","r",stdin);
    // for writing output to output.txt
    freopen("output.txt","w",stdout);
  #endif

    vector<int> X;
    X.push_back(-6);
    X.push_back(-17);
    X.push_back(5);
    X.push_back(-16);
    X.push_back(-18);
    X.push_back(-17);

    vector<int> Y;
    Y.push_back(2);
    Y.push_back(-4);
    Y.push_back(5);
    Y.push_back(-13);
    Y.push_back(-2);
    Y.push_back(20);

    cout<<"X : ";printVec(X);
    cout<<"Y : ";printVec(Y);

    int ans = maxPoints(X,Y);
    cout << endl <<"Answer : "<<ans<<endl;   

    return 0;
}
/*
Input :(1, 1) (2, 2)                     
Output : 2 

Input :(1, 1) (2, 2) (3, 3)                     
Output : 3

Input :(1, 1) (3, 2) (5, 3) (4, 1) (2, 3) (1, 4)                     
Output : 4

*/

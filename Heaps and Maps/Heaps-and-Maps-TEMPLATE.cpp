#include <iostream>
#include <string>
#include<sstream>
#include <bits/stdc++.h>
#include <stack>
#include<cmath>
#include<iomanip>
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

void printVecvec(vector<vector<int>> &vec)  
{
    for(int i=0;i<vec.size();i++)
    {
        for(int j=0;j<vec[i].size();j++)
            cout << vec[i][j] << " ";
        cout << endl;        
    }}

void showpq(priority_queue<int> gq)
{
    priority_queue<int> g = gq;
    while (!g.empty()) {
        cout << '\t' << g.top();
        g.pop();
    }
    cout << '\n';}

void minshowpq(priority_queue<int, vector<int>, greater<int> > gq)
{
    priority_queue<int, vector<int>, 
                                greater<int> > g = gq;
    while (!g.empty()) {
        cout << '\t' << g.top();
        g.pop();
    }
    cout << '\n';}

//printHeap
    size_t IntegerLogarithm2(size_t arg) 
    {
      size_t logarithm = 0;
      while (arg >>= 1) ++logarithm;
      return logarithm;}   

    size_t IntegerPower2(size_t arg) 
    {
      if(arg)
        return (size_t)2 << (arg-1);
      else
        return 1;}   

    // returns total line length for the level
    size_t LineLength(size_t level, size_t item_width, size_t spaces_between) 
    {return IntegerPower2(level) * (item_width + spaces_between) - spaces_between;}   

    int printHeap(vector<int> &A)
    {
        std::vector<std::vector<int>> levels;

      // Height of the heap
      size_t levels_number = IntegerLogarithm2(A.size() + 1);
      levels.resize(levels_number);

      // Now fill the levels
      for (size_t i = 0; i < levels.size(); ++i) {
        size_t elements_number = IntegerPower2(i);
        levels[i].resize(elements_number);
        for (size_t j = elements_number - 1, p = 0; p < elements_number; ++j, ++p)
          levels[i][p] = A[j];
      }   

      if (levels_number < 1) return 0;

      int magnitude = (abs(A[0]) <= 1 ? 1 : abs(A[0]));
      size_t tab_width = (size_t)floor(log(double(magnitude)) / log(10.0)) + 1;
      // size_t longest_line = LineLength(levels_number - 1, tab_width, tab_width);
      std::vector<std::string> text;
      text.reserve(levels_number * 2 - 1); 

      // Do the aligned output to the strings array
      for (size_t i = 0; i < levels_number; ++i) {
        size_t outer_space_width = IntegerPower2(levels_number - 1 - i) - 1;
        size_t inner_space_width = outer_space_width * 2 + 1;
        std::string outer_space(outer_space_width * tab_width, ' ');
        std::string inner_space(inner_space_width * tab_width, ' ');

        std::ostringstream line;
        line << outer_space;

        if (i > 0) {
          std::ostringstream branchline;
          std::string joint(tab_width, '|');
          std::string branch(inner_space_width * tab_width, '-');

          branchline << outer_space;

          if (levels[i].size() > 0) {
            branchline << joint;
          }

          bool isline = true;
          for (size_t j = 1; j < levels[i].size(); ++j, isline = !isline) {
            if(isline)
              branchline << branch << joint;
            else
              branchline << inner_space << std::setfill(' ') <<
                  std::setw(tab_width) << joint;
          }

          branchline << outer_space;
          text.push_back(branchline.str());
        }

        if (levels[i].size() > 0) {
          line << std::setfill(' ') << std::setw(tab_width) << levels[i][0];
        }

        for (size_t j = 1; j < levels[i].size(); ++j) {
          line << inner_space << std::setfill(' ') <<
              std::setw(tab_width) << levels[i][j];
        }

        line << outer_space;
        text.push_back(line.str());
      }

      // Output the text
      for (auto& i : text)
        std::cout << i << std::endl;}

int solve(vector<int> &A,int K)
{
    int res=0;
    make_heap(A.begin(),A.end());
    printHeap(A);

    for(int i=0;i<K;i++)
    {
        res+=A.front();
        A.front()--;
        make_heap(A.begin(),A.end());    
        cout<<endl;printHeap(A);
    }

    return res;
}

int main()
{
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt     
    freopen("input1.txt","r",stdin);
    // for writing output to output.txt
    freopen("output.txt","w",stdout);
  #endif
  
  vector<int> A = {1, 4};
  int K = 2;
  cout<<"Ques : ";printVec(A);
  cout<<"We need to find "<<K<<"th largest Element"<<endl<<endl;

  int ans = solve(A,K);
  cout<<endl<<"Answer : "<<ans<<endl;

  return 0;
}

/*
Input: seats[] = {2, 1, 1}, N = 3 
Output: 4 
Person 1: Sell the seat in the row with 
2 vacant seats, seats = {1, 1, 1} 
Person 2: All the rows have 1 vacant 
seat each, seats[] = {0, 1, 1} 
Person 3: seats[] = {0, 0, 1}

Input: seats[] = {2, 3, 4, 5, 1}, N = 6 
Output: 22 
*/


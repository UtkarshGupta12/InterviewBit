//Need to do a few minor tweaks , otherwise mostly correct
#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string s)
{
    string ans1 ="",ans2 = "",ans="";
    if(s.size()==0)
        return ans;
    else if(s.size()==1)
        return s;
        
    int count_max1 = -1,count_max2= -1,position1 = -1,position2 = -1;
    int left = -1,right=-1,count;
        
    for(int i=1;i<s.size()-1;i++)
    {
        int start = i-1;
        int end = i+1;
        count = 0;
        
        while(start>=0&&end<s.size())
        {
            if(s[start]==s[end])
                count++;
            else
                break;
                
            start--;
            end++;
            if(count > count_max1)
            {   count_max1 = max(count,count_max1);
                position1 = i;
            }
        }
    }
    ans1 = s.substr(position1-count_max1,2*count_max1+1);
        
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==s[i+1])
        {
            left = i;
            right=i+1;
            count = 0;
            while(s[left]==s[right]&&left>=0&&right<s.size())
            {
                count++;
                left--;
                right++;
                count_max2 = max(count,count_max2);
                if(count_max2==count)
                    position2 = i;
                    
            }
        }
    }
    ans2 = s.substr(position2-count_max2+1,2*count_max2);    
    
    cout <<"Position1 : "<<position1<<" & Position2 : "<<position2<<endl<<"Ans1 Size : "<<ans1.size()<<" & Ans2 Size : "<<ans2.size()<< endl<<endl;
    cout <<"Answer1 : "<<ans1 <<" & Answer2 : "<<ans2<<endl;
    
    if(position1>=0&&position2==-1)
        ans = ans1;
    else if(position2>0&&position1==-1)  
        ans = ans2;
    else if(position2>0&&position1>0)
    {
        if(ans1.size()>ans2.size())
            ans = ans1;
        else if(ans1.size()<ans2.size())  
            ans = ans2;
        else if(ans1.size()==ans2.size()) 
        {
            if(position1>position2)
                ans = ans2;
            else 
                ans = ans1;
        }
    }   
    else if(position1==-1&&position2==-1)
        ans = s[0];
    else    
        ans = ans1;
        
    return ans;
}

int main()
{
    string ans,ques;
    
    // a b c c b a d d
    // 0 1 2 3 4 5 6 7
    ques = "babcaacbccccccabbbbbcabaacbaacacccaaabcacbcc";
    ans = longestPalindrome(ques);
    
    cout <<"Input : "<<ques<<endl<<"Output : "<<ans<<endl;
}

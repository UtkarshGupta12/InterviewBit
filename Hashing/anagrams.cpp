string sortString(const string &A)
{
    string str = "";
    int charCount[26] = {0};

    for(int i=0;i<A.size();i++)
        charCount[A[i]-'a']++;
    
    for(int i=0;i<26;i++)
        for(int j=0;j<charCount[i];j++)
            str += (char)('a'+i);
    
    return str;}

void deletesomeofit(vector<vector<int>> &A,int B)
{
    for(int i=0;i<A.size();i++)
    {
        if(A[i][0]==B)
            A.erase(A.begin()+i);
    }
}

vector<vector<int>> Solution::anagrams(const vector<string> &A)
{
    vector<vector<int>> res;
    vector<int> ans;
    unordered_map<string,vector<int>> ump;

    
    for(int i=0;i<A.size();i++)
    {
        string str = sortString(A[i]);
        //cout<<str<<endl;

        if(ump.find(str)!=ump.end())
        {
            //res.pop_back();
            ans = ump[str];
            ans.push_back(i+1);
            ump[str] = ans;
            deletesomeofit(res,ans[0]);
            ans.clear();
            res.push_back(ump[str]);
        }
        else
        {
            ans.push_back(i+1);
            ump.insert({str,ans});
            ans.clear();
            res.push_back(ump[str]);
        }
    }
    
    return res;
}

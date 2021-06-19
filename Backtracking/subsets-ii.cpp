// TLE

void getallSets(vector<vector<int>> &res,vector<int> &nums,
        vector<int> &subset,int index)
{
    //BASE CASE
    if(index==nums.size())
    {
        if(!subset.empty() && subset==res.back()) return;
        else
            res.push_back(subset);
        return;
    }

    //RECURSION
    getallSets(res,nums,subset,index+1);

    subset.push_back(nums[index]);
    getallSets(res,nums,subset,index+1);

    //BACKTRACKING
    subset.pop_back();    

    return;
}

vector<vector<int>> Solution::subsetsWithDup(vector<int>& nums)
{
    vector<vector<int>> res;
    
    if(nums.empty())
    {
        res.push_back(nums);
        return res;
    }
    
    vector<int> subset;
    sort(nums.begin(),nums.end());

    getallSets(res,nums,subset,0);
    sort(res.begin(),res.end());
    
    //Checking All Elements
    for(int i=0;i<res.size();i++)
    {
        if(res[i]==res[i+1])
        {
            res.erase(res.begin()+i);
            i--;
        }
    }

    return res;
}

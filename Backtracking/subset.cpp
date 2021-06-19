
void getallSets(vector<vector<int>> &res,vector<int> &nums,
        vector<int> &subset,int index)
{
    //BASE CASE
    if(index==nums.size())
    {
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

vector<vector<int>> Solution::subsets(vector<int>& nums)
{
    vector<vector<int>> res;
    vector<int> subset;
    sort(nums.begin(),nums.end());
    getallSets(res,nums,subset,0);
    sort(res.begin(),res.end());

    return res;
}

void getVertical(TreeNode* curr_node, map<int,vector<int>> &mp,
                        vector<int> vec,int level)
{
    if(curr_node==NULL) return;

    mp[level].push_back(curr_node->val);   

    getVertical(curr_node->left ,mp,vec,level-1);
    getVertical(curr_node->right,mp,vec,level);
}

vector<int> Solution::solve(TreeNode* root)
{
    //BASE CASE
    if(root==NULL) return {};

    //Initialising 
    vector<vector<int>> res;
    vector<int> v;
    map<int,vector<int>> mp;
    getVertical(root,mp,{},0);

    //Converting to Vector
    for ( const auto &p : mp)
    {
        v.clear();
        for ( const auto &s : p.second )
            v.push_back(s);
        res.push_back(v);
    }

    v.clear();
    reverse(res.begin(),res.end());
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
            v.push_back(res[i][j]);
    }
    //cout<<endl;printVec(v);

    return v;
}

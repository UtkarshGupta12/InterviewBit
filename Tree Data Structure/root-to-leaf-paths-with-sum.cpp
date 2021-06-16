/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void getallPaths(TreeNode* curr_node,int TargetSum,int CurrSum
                    ,vector<vector<int>> &res,vector<int> path)
{
    if(curr_node==NULL) return;
    CurrSum += curr_node->val;
    path.push_back(curr_node->val);

    if(curr_node->left==NULL && curr_node->right==NULL && 
                                        CurrSum==TargetSum)
        res.push_back(path);

    getallPaths(curr_node->left,TargetSum,CurrSum,res,path);
    getallPaths(curr_node->right,TargetSum,CurrSum,res,path);
}

vector<vector<int>> Solution::pathSum(TreeNode* root, int TargetSum)
{
    vector<vector<int>> res;
    if(root==NULL) return res;
    
    getallPaths(root,TargetSum,0,res,{});

    return res;
}

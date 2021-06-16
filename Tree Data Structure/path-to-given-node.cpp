/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void getPath(TreeNode* curr_node,vector<int> curr_path,vector<int> &res,int B)
{
    if(curr_node==NULL) return;
    
    curr_path.push_back(curr_node->val);
    
    if(curr_node->val==B)
        res = curr_path;
    
    getPath(curr_node->left,curr_path,res,B);
    getPath(curr_node->right,curr_path,res,B);
}
 
vector<int> Solution::solve(TreeNode* root, int B) 
{
    if(root==NULL) return {};
    
    vector<int> res;
    getPath(root,{},res,B);
    
    return res;
}

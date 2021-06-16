/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void PreOrderList(TreeNode* curr_node,vector<TreeNode*> &res)
{
    if(curr_node==NULL) return;

    res.push_back(curr_node);

    PreOrderList(curr_node->left,res);
    PreOrderList(curr_node->right,res);
}

TreeNode* Solution::flatten(TreeNode* root)
{
    //BASE CASE
    if(root == NULL) return root;

    vector<TreeNode*> res;
    PreOrderList(root,res);

    //Converting LinkedList Now
    for(int i=0;i<res.size()-1;i++)
    {
        res[i]->left = NULL;
        res[i]->right = res[i+1];
    }

    res.back()->left = NULL;
    res.back()->right = NULL;

    return root;
}

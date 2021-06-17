/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool ishalfnode(TreeNode* curr_node)
{
    if(curr_node==NULL) return false;

    if(curr_node->left!=NULL && curr_node->right==NULL)
        return true;
    else if(curr_node->left==NULL && curr_node->right!=NULL)
        return true;
    else
        return false;}

void HalfNodes(TreeNode* curr_node)
{
    if(curr_node==NULL) return;

    TreeNode* templ = curr_node->left;
    TreeNode* tempr = curr_node->right;

    if(ishalfnode(templ))
    {
        if(templ->left==NULL)
            curr_node->left = templ->right;    
        else if(templ->right==NULL)
            curr_node->left = templ->left;              
    }
    else if(ishalfnode(tempr))
    {
        if(tempr->left==NULL)
            curr_node->right = tempr->right;
        else if(tempr->right==NULL)
            curr_node->right = tempr->left;                
    }

    HalfNodes(curr_node->left);
    HalfNodes(curr_node->right);
}

TreeNode* Solution::solve(TreeNode* root)
{
    if(root==NULL) return root;
    HalfNodes(root);
    HalfNodes(root);
    HalfNodes(root);
    
    if(root->left!=NULL && root->right==NULL)
    {
        if(root->left->left==NULL && root->left->right==NULL)
            return root->left;
    }
    else if(root->left==NULL && root->right!=NULL)
    {
        if(root->right->left==NULL && root->right->right==NULL)
            return root->right;
    }
    
    return root;
}

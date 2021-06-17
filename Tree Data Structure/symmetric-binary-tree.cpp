/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void switchAllPlaces(TreeNode* curr_node)
{
    if(curr_node==NULL) return;

    TreeNode* temp = curr_node->left;
    curr_node->left = curr_node->right;
    curr_node->right = temp;

    switchAllPlaces(curr_node->left);
    switchAllPlaces(curr_node->right);}

int identicalTrees(TreeNode* a, TreeNode* b) 
{
    /*1. both empty */
    if (a == NULL && b == NULL) 
        return 1;  
    /* 2. both non-empty -> compare them */
    if (a != NULL && b != NULL) 
    { 
        return
        ( 
            a->val == b->val && 
            identicalTrees(a->left, b->left) && 
            identicalTrees(a->right, b->right) 
        ); 
    }     
    /* 3. one empty, one not -> false */
    return 0;} 

int Solution::isSymmetric(TreeNode* root)
{
    switchAllPlaces(root->right);
    int ans = identicalTrees(root->left,root->right);
    
    return ans;
}

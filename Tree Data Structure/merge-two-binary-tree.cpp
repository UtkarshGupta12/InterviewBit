/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void mergeUncommonTrees(TreeNode* currA, TreeNode* currB)
{
    if(currA==NULL||currB==NULL) return;

    if(currA->left==NULL && currB->left!=NULL)
        currA->left = currB->left;
    if(currA->right==NULL && currB->right!=NULL)
        currA->right = currB->right;

    mergeUncommonTrees(currA->left,currB->left);
    mergeUncommonTrees(currA->right,currB->right);
}

void mergeCommonTrees(TreeNode* currA, TreeNode* currB)
{
    if(currA==NULL||currB==NULL) return;

    currA->val += currB->val;

    mergeCommonTrees(currA->left,currB->left);
    mergeCommonTrees(currA->right,currB->right);
}

TreeNode* Solution::solve(TreeNode* A, TreeNode* B)
{
    if(!A) return B;
    else if(!B) return A;
    
    mergeCommonTrees(A,B);
    mergeUncommonTrees(A,B);
    return A;
}

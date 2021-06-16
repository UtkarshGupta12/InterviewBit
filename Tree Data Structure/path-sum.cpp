/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void getPaths(TreeNode* curr_node,int targetSum,
    int sum_so_far,bool &ans)
{
    if(curr_node==NULL) 
        return ;
    
    //InOrder
    sum_so_far += curr_node->val;
    //cout<<"Sum so far : "<<sum_so_far<<endl;

    if(sum_so_far == targetSum && curr_node->right==NULL && curr_node->left==NULL)
    {
        ans = true;
        return ;
    }
    
    if(curr_node->left != NULL)
        getPaths(curr_node->left,targetSum,sum_so_far,ans);
    if(curr_node->right != NULL)
        getPaths(curr_node->right,targetSum,sum_so_far,ans);

}

int Solution::hasPathSum(TreeNode* root, int targetSum)
{
    if(root==NULL) return 0;

    bool ans = false;
    getPaths(root, targetSum, 0, ans);

    if(ans==true) return 1;
    else return 0;
}

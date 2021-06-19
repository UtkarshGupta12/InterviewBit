/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void InorderTravel(TreeNode* curr_node,int &a,int &b,int &prev)
{
    if(curr_node==NULL) return;

    InorderTravel(curr_node->left,a,b,prev);

    if(a == INT_MIN && prev > curr_node->val) a = prev;
    if(prev > curr_node->val) b = curr_node->val;
    prev = curr_node->val;

    InorderTravel(curr_node->right,a,b,prev);
}

vector<int> Solution::recoverTree(TreeNode* root)
{
    vector<int> res;
    int a=INT_MIN,b=INT_MAX,prev=INT_MIN;

    InorderTravel(root,a,b,prev);

    res.push_back(a);
    res.push_back(b);
    sort(res.begin(),res.end());

    return res;
}

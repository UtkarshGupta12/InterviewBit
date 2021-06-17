/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::postorderTraversal(TreeNode* root)
{
    //BASE CASE
    if(root==NULL) return {};

    vector<int> res;
    stack<TreeNode*> s1,s2;
    TreeNode* curr = root;

    s1.push(root);
    TreeNode* temp;

    while(!s1.empty())
    {
        temp = s1.top();
        s1.pop();
        s2.push(temp);

        if (temp->left)
            s1.push(temp->left);
        if (temp->right)
            s1.push(temp->right);
    }

    while (!s2.empty()) {
        temp = s2.top();
        s2.pop();
        res.push_back(temp->val);
    }

    return res;
}

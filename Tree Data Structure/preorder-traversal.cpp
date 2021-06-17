/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::preorderTraversal(TreeNode* root)
{
    //BASE CASE
    if(root==NULL) return {};

    vector<int> res;
    stack<TreeNode*> st;
    st.push(root);

    while(!st.empty())
    {
        TreeNode* temp = st.top();
        st.pop();

        res.push_back(temp->val);

        if(temp->right)
            st.push(temp->right);
        if(temp->left)
            st.push(temp->left);
    }

    return res;
}

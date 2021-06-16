/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void getATree(TreeNode* curr_node,vector<int> &vec)
{
    if(curr_node==NULL) return;

    vec.push_back(curr_node->val);

    getATree(curr_node->left,vec);
    getATree(curr_node->right,vec);
}

int Solution::kthsmallest(TreeNode* root, int k)
{
    if(root==NULL) return -1;

    vector<int> vec;
    getATree(root,vec);

    sort(vec.begin(),vec.end());
    //printVec(vec);

    return vec[k-1];
}

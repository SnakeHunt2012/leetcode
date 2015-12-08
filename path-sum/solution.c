/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode* root, int sum) {
    if (!root)
        return false;
    if (root->val == sum && root->left == NULL && root->right == NULL)
        return true;
    if (root->left && hasPathSum(root->left, sum - root->val))
        return true;
    if (root->right && hasPathSum(root->right, sum - root->val))
        return true;
    return false;
}

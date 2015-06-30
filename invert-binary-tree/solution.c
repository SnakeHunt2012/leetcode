/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root) {

    if (root) {
	struct TreeNode* temp_node = root->left;
	root->left = invertTree(root->right);
	root->right = invertTree(temp_node);
    }
	
    return root;
}

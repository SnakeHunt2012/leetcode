/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool balance(struct TreeNode* root, int *depth) {
    int left_depth, right_depth;
    if (!root) {
        *depth = 0;
        return true;
    }
    
    if (!balance(root->left, &left_depth) || !balance(root->right, &right_depth))
        return false;
    
    switch (left_depth - right_depth) {
    case 0:
        *depth = left_depth + 1;
        return true;
    case 1:
        *depth = left_depth + 1;
        return true;
    case -1:
        *depth = right_depth + 1;
        return true;
    default:
        return false;
    }
}

bool isBalanced(struct TreeNode* root) {
    int depth;
    return balance(root, &depth);
}

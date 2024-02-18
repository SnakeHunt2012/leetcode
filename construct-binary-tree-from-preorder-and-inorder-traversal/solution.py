# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """

        def build_tree(preorder_left, preorder_right, inorder_left, inorder_right):
            if inorder_right - inorder_left < 0:
                return None
            if preorder_right - preorder_left < 0:
                return None

            root_val = preorder[preorder_left]
            root_inorder_index = reverse_index[root_val]
            left_length = root_inorder_index - inorder_left

            left_preorder_left = preorder_left + 1
            left_preorder_right = preorder_left + left_length
            left_inorder_left = inorder_left
            left_inorder_right = inorder_left + left_length - 1
            
            right_preorder_left = preorder_left + 1 + left_length
            right_preorder_right = preorder_right
            right_inorder_left = inorder_left + 1 + left_length
            right_inorder_right = inorder_right

            left = build_tree(left_preorder_left, left_preorder_right, left_inorder_left, left_inorder_right)
            right = build_tree(right_preorder_left, right_preorder_right, right_inorder_left, right_inorder_right)
            return TreeNode(root_val, left, right)

        reverse_index = dict([(inorder[i], i) for i in range(len(inorder))])
        return build_tree(0, len(preorder) - 1, 0, len(preorder) - 1)

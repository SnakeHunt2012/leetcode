# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        def is_valid_bst(root):
            if root is None:
                return True, None, None

            left_valid, left_min, left_max = is_valid_bst(root.left)
            right_valid, right_min, right_max = is_valid_bst(root.right)
            if left_valid and right_valid and (left_max is None or left_max < root.val) and (right_min is None or right_min > root.val):
                min_val = left_min if left_min is not None else root.val
                max_val = right_max if right_max is not None else root.val
                return True, min_val, max_val
            return False, None, None

        return is_valid_bst(root)[0]

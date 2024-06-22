# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def flatten(self, root):
        """
        :type root: TreeNode
        :rtype: None Do not return anything, modify root in-place instead.
        """

        def flatten(root):
            if root is None:
                return root, root

            left_head, left_tail = flatten(root.left)
            right_head, right_tail = flatten(root.right)

            if root.left is not None:
                root.left = None
                root.right = left_head
                left_tail.right = right_head

            return root, right_tail or left_tail or root

        head, tail = flatten(root)
        return head

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        res = []
        if root is None:
            return res

        queue = [root]
        while len(queue) != 0:
            res.append([node.val for node in queue])
            queue = [sub_node for node in queue for sub_node in [node.left, node.right] if sub_node is not None]
            
        return res

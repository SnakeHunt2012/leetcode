# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param {TreeNode} root
    # @param {integer} k
    # @return {integer}

    k = None
    found = False
    value = None
    
    def kthSmallest(self, root, k):

        if root is None:
            return None
        
        self.k = k
        self.found = False
        self.search(root)

        return self.value

    def search(self, root):

        if not self.found and not (root.left is None):
            self.search(root.left)
        if not self.found:
            self.visit(root)
        if not self.found and not (root.right is None):
            self.search(root.right)

    def visit(self, node):

        if self.k > 1:
            self.k -= 1
        else:
            self.value = node.val
            self.found = True


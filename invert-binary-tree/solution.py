# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param {TreeNode} root
    # @return {TreeNode}
    def invertTree(self, root):

        if root is not None:
            root.left, root.right = Solution().invertTree(root.right), Solution().invertTree(root.left)
        return root

def main():

    root = TreeNode(1)
    left = TreeNode(2)
    right = TreeNode(3)
    root.left = left
    root.right = right

    root = Solution().invertTree(root)

    print root.val
    print root.left.val
    print root.right.val

if __name__ == "__main__":

    main()

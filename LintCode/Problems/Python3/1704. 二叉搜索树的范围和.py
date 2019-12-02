"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""

class Solution:
    """
    @param root: the root node
    @param L: an integer
    @param R: an integer
    @return: the sum
    """
    def rangeSumBST(self, root, L, R):
        # write your code here.

        if root is None:
            return 0
        if root.val < L:
            return self.rangeSumBST(root.right, L, R)
        if root.val > R:
            return self.rangeSumBST(root.left, L, R)
        return root.val + self.rangeSumBST(root.right, L, R) + self.rangeSumBST(root.left, L, R)


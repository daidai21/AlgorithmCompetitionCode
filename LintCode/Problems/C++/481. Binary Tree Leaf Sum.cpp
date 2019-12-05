// https://www.lintcode.com/problem/binary-tree-leaf-sum/description


/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: the root of the binary tree
     * @return: An integer
     */
    int leafSum(TreeNode * root) {
        // write your code here
        if (root == nullptr)
            return 0;
        else if (root->left == nullptr && root->right == nullptr)
            return root->val;
        return leafSum(root->left) + leafSum(root->right);
    }
};

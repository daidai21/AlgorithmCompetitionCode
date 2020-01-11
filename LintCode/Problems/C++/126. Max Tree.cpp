// https://www.lintcode.com/problem/max-tree/note
// Time Limit Exceeded

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
     * @param A: Given an integer array with no duplicates.
     * @return: The root of max tree.
     */
    TreeNode* maxTree(vector<int> &A) {
        // write your code here
        return recursion(A, 0, A.size() - 1);
    }

    TreeNode* recursion(vector<int>& A, int left, int right) {
        if (left > right)
            return nullptr;
        int max_idx = max_val_idx(A, left, right);
        TreeNode* node = new TreeNode;
        node->val = A[max_idx];
        node->left = recursion(A, left, max_idx - 1);
        node->right = recursion(A, max_idx + 1, right);
        return node;
    }

    int max_val_idx(vector<int>& A, int left, int right) {
        int max_val = A[left];
        int max_idx = left;
        for (int i = left + 1; i <= right; ++i) {
            if (A[i] > max_val) {
                max_val = A[i];
                max_idx = i;
            }
        }
        return max_idx;
    }
};

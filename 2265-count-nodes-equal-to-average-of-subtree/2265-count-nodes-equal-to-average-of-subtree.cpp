/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;

    pair<int, int> dfs(TreeNode* root) {
        if (root == nullptr) {
            return {0, 0};
        }

        // Get sum and count from left subtree
        auto left = dfs(root->left);

        // Get sum and count from right subtree
        auto right = dfs(root->right);

        // Sum of current subtree
        int sum = left.first + right.first + root->val;

        // Number of nodes in current subtree
        int count = left.second + right.second + 1;

        // Floor average using integer division
        int average = sum / count;

        if (average == root->val) {
            ans++;
        }

        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
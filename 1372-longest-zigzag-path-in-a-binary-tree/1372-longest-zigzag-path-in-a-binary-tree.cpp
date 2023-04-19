class Solution {
public:
    int ans = 0;

    int longestZigZag(TreeNode* root) {
        dfs(root, 0, 0);
        return ans;
    }

    void dfs(TreeNode* root, int l, int r) {
        if (!root) return;
        ans = max(ans, max(l, r));
        dfs(root->left, r + 1, 0);
        dfs(root->right, 0, l + 1);
    }
};
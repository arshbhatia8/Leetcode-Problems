class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return gen(1, n);
    }

    vector<TreeNode*> gen(int left, int right) {
        vector<TreeNode*> ans;
        if (left > right) {
            ans.push_back(nullptr);
        } else {
            for (int i = left; i <= right; ++i) {
                auto leftTrees = gen(left, i - 1);
                auto rightTrees = gen(i + 1, right);
                for (auto& l : leftTrees) {
                    for (auto& r : rightTrees) {
                        TreeNode* node = new TreeNode(i, l, r);
                        ans.push_back(node);
                    }
                }
            }
        }
        return ans;
    }
};
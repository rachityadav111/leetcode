class Solution {
public:
    vector<TreeNode*> buildTrees(int start, int end) {
        vector<TreeNode*> result;
        if (start > end) {
            result.push_back(nullptr);
            return result;
        }
        for (int i = start; i <= end; ++i) {
            
            vector<TreeNode*> leftSubtrees = buildTrees(start, i - 1);
            
            vector<TreeNode*> rightSubtrees = buildTrees(i + 1, end);
            for (TreeNode* leftNode : leftSubtrees) {
                for (TreeNode* rightNode : rightSubtrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftNode;
                    root->right = rightNode;
                    result.push_back(root);
                }
            }
        }
        
        return result;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return buildTrees(1, n);
    }
};
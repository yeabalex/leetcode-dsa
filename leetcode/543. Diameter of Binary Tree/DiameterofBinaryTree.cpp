struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    int res = 0;
    
    int diameterOfBinaryTree(TreeNode* root) {
        this->dfs(root);
        return res;
    }
    
    int dfs(TreeNode* root) {
        if (!root) return -1;
        
        int leftHeight = dfs(root->left);
        int rightHeight = dfs(root->right);
        
        res = max(res, leftHeight + rightHeight + 2);
        
        return max(leftHeight, rightHeight) + 1;
    }
};
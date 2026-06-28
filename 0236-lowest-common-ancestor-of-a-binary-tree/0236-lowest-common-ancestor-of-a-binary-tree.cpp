/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
   public:
    vector<TreeNode*> a, a1;

    bool dfs(TreeNode* root, TreeNode* p) {
        if (!root) return false;

        a.push_back(root);

        if (root == p)
            return true;

        if (dfs(root->left, p))
            return true;

        if (dfs(root->right, p))
            return true;

        a.pop_back();
        return false;
    }

    bool dfs1(TreeNode* root, TreeNode* q) {
        if (!root) return false;

        a1.push_back(root);

        if (root == q)
            return true;

        if (dfs1(root->left, q))
            return true;

        if (dfs1(root->right, q))
            return true;

        a1.pop_back();
        return false;
    }


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        dfs(root, p);
        dfs1(root, q);

        int i = 0;
        while (i < a.size() && i < a1.size() && a[i] == a1[i])
            i++;

        return a[i - 1];
    }
};
    

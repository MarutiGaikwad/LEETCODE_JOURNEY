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
    unordered_map<TreeNode*, TreeNode*> mp;
    void m(TreeNode* root) {
        if (!root)
            return;
        if (root->left) {
            mp[root->left] = root;
            m(root->left);
        }
        if (root->right) {
            mp[root->right] = root;
            m(root->right);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        m(root);
        queue<TreeNode*> q;
        q.push(target);
        int i = 0;
        unordered_set<TreeNode*> visited;
        visited.insert(target);
        while (!q.empty()) {
           
            if (i++ == k)
                break;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* t = q.front();
                q.pop();
                if (t->left && visited.find(t->left) == visited.end()) {
                    visited.insert(t->left);
                    q.push(t->left);
                }
                if (t->right && visited.find(t->right) == visited.end()) {
                    visited.insert(t->right);
                    q.push(t->right);
                }
                if (mp.count(t) && visited.find(mp[t]) == visited.end()) {
                    visited.insert(mp[t]);
                    q.push(mp[t]);
                }
            }
        }
        vector<int> r;
         while (!q.empty()) {
            r.push_back(q.front()->val);
            q.pop();
        }
        return r;
    }
};
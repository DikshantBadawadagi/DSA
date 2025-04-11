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
    private:
    vector<vector<int>> bfs(TreeNode* root){
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            vector<int>temp;
            int size = q.size();
            while(size--){
                TreeNode* top = q.front();
                q.pop();
                if(top == nullptr)continue;
                temp.push_back(top->val);
                q.push(top->left);
                q.push(top->right);
            }
            ans.push_back(temp);
        }
        ans.pop_back();
        return ans;
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        return bfs(root);
    }
};

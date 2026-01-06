#include <iostream>

using namespace std;

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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);

        int max_sum = INT_MIN;
        int max_level = 1;
        int level = 1;

        while(!q.empty()){
            int size = q.size();
            int sum = 0;

            for(int i=0; i<size; i++){
                TreeNode *node = q.front();
                q.pop();

                // cout << node->val << endl;
                sum += node->val;
                
                if(node->left){
                    q.push(node->left);
                }

                if(node->right){
                    q.push(node->right);
                }
            }

            // cout << sum << endl;
            if(sum > max_sum){
                max_sum = sum;
                max_level = level;
            }

            level++;
        }

        return max_level;
    }
};

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(7);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(-8);

    Solution solution;
    int ans = solution.maxLevelSum(root);

    cout << ans << endl;

    return 0;
}
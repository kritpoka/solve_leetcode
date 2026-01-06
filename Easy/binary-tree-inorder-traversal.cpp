#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class solution{
public:
    vector<int> inorderTraversal(TreeNode *root){
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* current = root;

        while(current || !st.empty()) {
            while (current) {
                st.push(current);
                current = current->left;
            }
            current = st.top();
            st.pop();
            result.push_back(current->val);
            current = current->right;
        }

        return result;
    }
};


int main(){
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    solution sol;
    vector<int> result = sol.inorderTraversal(root);

    for(int number : result)
        cout << number << " ";
    cout << endl;

    return 0;
}
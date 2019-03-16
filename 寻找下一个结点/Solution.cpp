#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Successor {
    // in-order traversal
public:
    int findSucc(TreeNode* root, int p) {
        TreeNode* pre = NULL;
        TreeNode* curr;
        stack<TreeNode*> Stack({root});
        while(!Stack.empty()){
            curr = Stack.top();
            Stack.pop();
            while(curr->left) {
                TreeNode* tmp = curr->left;
                curr->left = NULL;
                Stack.push(curr);
                curr = tmp;
            }
            if(pre == NULL) pre = curr;
            else if(pre->val == p) return curr->val;
            
            pre = curr;
            if(curr->right) Stack.push(curr->right);
        }
        return -1;
    }
};
#include <iostream>
#include <tuple>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Balance {
public:
    bool isBalance(TreeNode* root) {
        if(root == NULL) return true;
        int dep; bool balance;
        tie(dep, balance) = depth(root);
        return balance;
    }

    tuple<int, bool> depth(TreeNode* root){
        if(root == NULL) return tuple<int, bool>({0, true});
        int left, right;
        bool leftCheck, rightCheck;

        tie(left, leftCheck) = depth(root->left);
        tie(right, rightCheck) = depth(root->right);
        int dep = max(left, right) + 1;
        if(abs(left-right) <= 1 && leftCheck && rightCheck) 
            return tuple<int, bool>({dep, true});
        return tuple<int, bool>({dep, false});
    }
};

class Balance2 {
public:
    bool isBalance(TreeNode* root) {
        if(root == NULL) return true;
        return depth(root) != -1;
    }

    int depth(TreeNode* root){
        if(root == NULL) return 0;
        int left, right;
        left = depth(root->left);
        right = depth(root->right);
        if(left == -1 || right == -1) return -1;
        if(abs(left - right) > 1) return -1;
        return max(left, right) + 1;
    }
};

int main() {
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);

    bool ans = Balance().isBalance(root);
    cout << ans << "\n";
}
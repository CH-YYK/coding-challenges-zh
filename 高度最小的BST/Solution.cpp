#include <math.h>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};


class MinimalBST {
public:
    int buildMinimalBST(vector<int> vals) {
        int size = vals.size();
        int count = 0;
        while(size > 0) {
            count++;
            size /= 2;
        }
        return count;
    }
};

class MinimalBST2 {
public:
    int buildMinimalBST(vector<int> vals) {
        int height = 0;
        TreeNode* root = buildBST(vals, 0, vals.size()-1, height);
        return height;
    }

    TreeNode* buildBST(vector<int> &vals, int l, int r, int& height) {
        if(l > r){
            height = 0;
            return NULL;
        };
        int m = (l + r) / 2, left, right;
        TreeNode* root = new TreeNode(vals[m]);
        root->left = buildBST(vals, l, m-1, left);
        root->right = buildBST(vals, m + 1, r, right);
        height = max(left, right) + 1;
        return root;
    }
};

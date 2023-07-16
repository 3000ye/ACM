#include "bits/stdc++.h"
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *l, TreeNode *r): val(x), left(l), right(r) {}
};

// 94. 二叉树的中序遍历 https://leetcode.cn/problems/binary-tree-inorder-traversal/
void InOrder(TreeNode *root, vector<int> &ls) {
    if (!root) return ;

    InOrder(root->left, ls);
    ls.push_back(root->val);
    InOrder(root->right, ls);
}

// 144. 二叉树的前序遍历 https://leetcode.cn/problems/binary-tree-preorder-traversal/
void PreOrder(TreeNode *root, vector<int> &ls) {
    if (root == nullptr) return ;
    
    ls.push_back(root->val);
    PreOrder(root->left, ls);
    PreOrder(root->right, ls);
}

// 145. 二叉树的后序遍历 https://leetcode.cn/problems/binary-tree-postorder-traversal/
void PostOrder(TreeNode *root, vector<int> &ls) {
    if (!root) return ;

    PostOrder(root->left, ls);
    PostOrder(root->right, ls);
    ls.push_back(root->val);
}

//-------------------------------------------------------------------------------------------------//

// 94. 二叉树的中序遍历 https://leetcode.cn/problems/binary-tree-inorder-traversal/
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ls;
    InOrder(root, ls);

    return ls;
}

// 100. 相同的树 https://leetcode.cn/problems/same-tree/
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == NULL and q == NULL) return true;
    else if (p == NULL or q == NULL) return false;
    else if (p->val != q->val) return false;
    else {
        return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
    }
}

// 101. 对称二叉树 https://leetcode.cn/problems/symmetric-tree/
bool Symmetric_lr(TreeNode *l, TreeNode *r) {
    if (!l and !r) return true;
    if (!l or !r) return false;

    return l->val == r->val and Symmetric_lr(l->left, r->right) and Symmetric_lr(l->right, r->left);
}

bool isSymmetric(TreeNode* root) {
    return Symmetric_lr(root->left, root->right);
}

// 104. 二叉树的最大深度 https://leetcode.cn/problems/maximum-depth-of-binary-tree/
int maxDepth(TreeNode* root) {
    if (!root) return 0;

    int l = maxDepth(root->left);
    int r = maxDepth(root->right);

    return l > r ? l + 1 : r + 1;
}

// 144. 二叉树的前序遍历 https://leetcode.cn/problems/binary-tree-preorder-traversal/
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ls;
    PreOrder(root, ls);

    return ls;
}

// 145. 二叉树的后序遍历 https://leetcode.cn/problems/binary-tree-postorder-traversal/
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ls;
    PostOrder(root, ls);

    return ls;
}

int main() {
    

    return 0;
}
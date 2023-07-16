#include "bits/stdc++.h"

using namespace std;

// 二叉树的结点（链式存储）
typedef struct BiTNode {
    int val;  // 数据域
    BiTNode *l, *r;  // 左孩子和右孩子
} BiTNode, *BiTree;

// 初始化二叉树
BiTree InitBiTree(int val) {
    BiTree root = new BiTNode;
    root->l = NULL; root->r = NULL;
    root->val = val;

    return root;
}

// 先序遍历
void PreOrder(BiTree root) {
    if (root != NULL) {
        cout << root->val << " ";  // 访问根结点
        PreOrder(root->l);  // 递归遍历左子树
        PreOrder(root->r);  // 递归遍历右子树
    }
}

// 中序遍历
void InOrder(BiTree root) {
    if (root != NULL) {
        InOrder(root->l);  // 递归遍历左子树
        cout << root->val << " ";  // 访问根结点
        InOrder(root->r);  // 递归遍历右子树
    }
}

// 后序遍历
void PostOrder(BiTree root) {
    if (root != NULL) {
        PostOrder(root->l);  // 递归遍历左子树
        PostOrder(root->r);  // 递归遍历右子树
        cout << root->val << " ";  // 访问根结点
    }
}

// 由前序和中序构造二叉树
BiTree BuildTree_PreIn(vector<int> pre, vector<int> in) {
    if (pre.empty()) return NULL;

    int root_val = pre[0];
    vector<int> lr(in.begin(), find(in.begin(), in.end(), root_val));
    vector<int> ll(pre.begin() + 1, pre.begin() + lr.size() + 1);
    vector<int> rl(pre.begin() + ll.size() + 1, pre.end());
    vector<int> rr(in.begin() + lr.size() + 1, in.end());

    BiTree root = InitBiTree(root_val);
    root->l = BuildTree_PreIn(ll, lr);
    root->r = BuildTree_PreIn(rl, rr);

    return root;
}

// 由中序和后序构造二叉树
BiTree BuildTree_InPost(vector<int> in, vector<int> post) {
    if (in.empty()) return NULL;

    int root_val = post[post.size() - 1];
    

    return NULL;
}

int main() {


    return 0;
}
#include <algorithm>
#include <cassert>

using namespace std;

struct AVLTreeNode {
    AVLTreeNode *left = 0;
    AVLTreeNode *right = 0;
    AVLTreeNode *parent = 0;
    int size = 1;
    char balance = 0;
    int val;
    int count = 1;

    ~AVLTreeNode() {
        if (left != 0) {
            delete left;
        }
        if (right != 0) {
            delete right;
        }
    }
};

class AVLTree {
public:
    ~AVLTree() {
        if (root != 0) {
            delete root;
        }
    }

    int size(AVLTreeNode *node) {
        if (node != 0) {
            return node->size;
        } else {
            return 0;
        }
    }

    int height(AVLTreeNode *node) {
        if (node == 0) {
            return -1;
        } else {
            return 1 + max(height(node->left), height(node->right));
        }
    }

    void updateBalance(AVLTreeNode *node) {
        node->balance = height(node->right) - height(node->left);
    }

    AVLTreeNode *rotateLeft(AVLTreeNode *a) {

        AVLTreeNode *b = a->right;
        b->parent = a->parent;

        a->right = b->left;

        if (a->right != 0) {
            a->right->parent = a;
        }

        b->left = a;
        a->parent = b;

        if (b->parent != 0) {
            if (b->parent->right == a) {
                b->parent->right = b;
            } else {
                b->parent->left = b;
            }
        }

        a->size = a->count + size(a->left) + size(a->right);
        b->size = b->count + size(b->left) + size(b->right);
        updateBalance(a);
        updateBalance(b);

        return b;
    }

    AVLTreeNode *rotateRight(AVLTreeNode *a) {

        AVLTreeNode *b = a->left;
        b->parent = a->parent;

        a->left = b->right;

        if (a->left != 0) {
            a->left->parent = a;
        }

        b->right = a;
        a->parent = b;

        if (b->parent != 0) {
            if (b->parent->right == a) {
                b->parent->right = b;
            } else {
                b->parent->left = b;
            }
        }

        a->size = a->count + size(a->left) + size(a->right);
        b->size = b->count + size(b->left) + size(b->right);
        updateBalance(a);
        updateBalance(b);

        return b;
    }

    AVLTreeNode *rotateLeftThenRight(AVLTreeNode *n) {
        n->left = rotateLeft(n->left);
        return rotateRight(n);
    }

    AVLTreeNode *rotateRightThenLeft(AVLTreeNode *n) {
        n->right = rotateRight(n->right);
        return rotateLeft(n);
    }

    void rebalance(AVLTreeNode *node) {
        node->size = size(node->right) + size(node->left) + node->count;
        updateBalance(node);

        if (node->balance == -2) {
            if (height(node->left->left) >= height(node->left->right)) {
                node = rotateRight(node);
            } else {
                node = rotateLeftThenRight(node);
            }
        }
        if (node->balance == 2) {
            if (height(node->right->right) >= height(node->right->left)) {
                node = rotateLeft(node);
            } else {
                node = rotateRightThenLeft(node);
            }
        }
        if (node->parent != 0) {
            rebalance(node->parent);
        } else {
            root = node;
        }
    }


    void insert(int val) {
        if (root == 0) {
            root = new AVLTreeNode();
            root->val = val;
        } else {
            AVLTreeNode *n = root;
            while (true) {
                if (n->val == val) {
                    n->count++;

                    while (n != 0) {
                        n->size++;
                        n = n->parent;
                    }

                    return;
                }
                AVLTreeNode *p = n;

                bool left = val < n->val;
                n = left ? n->left : n->right;

                // isLeaf?
                if (n == 0) {
                    n = new AVLTreeNode();
                    n->val = val;
                    n->parent = p;
                    if (left) {
                        p->left = n;
                    } else {
                        p->right = n;
                    }
                    rebalance(p);
                    return;
                }
            }
        }
    }

    int numSmallerHelper(int v, AVLTreeNode *node) {
        if (node == 0) {
            return 0;
        } else {
            if (node->val < v) {
                return node->count + size(node->left) + numSmallerHelper(v, node->right);
            } else {
                return numSmallerHelper(v, node->left);
            }
        }
    }

    int numSmaller(int v) {
        return numSmallerHelper(v, root);
    }

    AVLTreeNode *root = 0;
};



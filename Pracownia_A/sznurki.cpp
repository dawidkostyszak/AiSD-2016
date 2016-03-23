#include <iostream>

using namespace std;

struct Node {
    Node *left = NULL, *right = NULL, *parent = NULL;
    unsigned long long value = 0, amount = 0;
};

class Tree {
public:
    Tree() {
        root = NULL;
    };

    Node *insert(Node *node) {
        if(root != NULL) {
            return insert(node, root);
        } else {
            root = node;
            return node;
        }
    };

    void solve() {
        Node *node = find_min(root);
        while (node != NULL) {
            solveNode(node);
            if (root != NULL) {
                node = find_min(root);
            } else {
                node = NULL;
            }
        }
        printf("%llu\n", counter);
    };

    Node *root;
    unsigned long long counter = 0;

private:
    Node *insert(Node *node, Node *leaf) {
        if(node->value < leaf->value) {
            if(leaf->left != NULL) {
                return insert(node, leaf->left);
            } else {
                leaf->left = node;
                node->parent = leaf;
                return node;
            }
        } else if(node->value > leaf->value) {
            if(leaf->right != NULL) {
                return insert(node, leaf->right);
            } else {
                leaf->right = node;
                node->parent = leaf;
                return node;
            }
        } else {
            leaf->amount += node->amount;
            return leaf;
        }
    };

    void solveNode(Node *node) {
        Node *tmp_node = new Node();
        tmp_node->value = node->value * 2;
        tmp_node->amount = node->amount / 2;

        if (node->amount % 2 == 0) {
            delete_node(node);
        } else {
            counter++;
            delete_node(node);
        }

        if (tmp_node->amount > 0) {
            node = insert(tmp_node);

            if (node->amount > 1) {
                solveNode(node);
            } else {
                counter++;
                delete_node(node);
            }
        }
    }

    Node *find_min(Node *node) {
        while (node->left != NULL) {
            node = node->left;
        }
        return node;
    };

    Node *find_successor(Node *node) {
        if (node->right != NULL) {
            return find_min(node->right);
        }

        Node *tmp_node = node->parent;
        while (tmp_node != NULL && node == tmp_node->right) {
            node = tmp_node;
            tmp_node = tmp_node->parent;
        }
        return tmp_node;
    };

    void delete_node(Node *leaf) {
        Node *tmp_node, *node;
        if (leaf->left == NULL || leaf->right == NULL) {
            node = leaf;
        } else {
            node = find_successor(leaf);
        }

        if (node->left != NULL) {
            tmp_node = node->left;
        } else {
            tmp_node = node->right;
        }

        if (tmp_node != NULL) {
            tmp_node->parent = node->parent;
        }

        if (node->parent == NULL) {
            root = tmp_node;
        } else if (node == node->parent->left) {
            node->parent->left = tmp_node;
        } else {
            node->parent->right = tmp_node;
        }

        if (node != leaf) {
            leaf->amount = node->amount;
            leaf->value = node->value;
        }
        delete node;
    };
};

int main() {
    unsigned long long n, value, amount;
    Tree tree;

    scanf("%llu",&n);
    for (unsigned long long i=0; i<n; i++) {
        Node *node = new Node();
        scanf("%llu %llu",&value, &amount);
        node->value = value;
        node->amount = amount;
        tree.insert(node);
    }

    tree.solve();
    return 0;
}

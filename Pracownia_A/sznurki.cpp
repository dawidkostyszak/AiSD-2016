#include <iostream>

using namespace std;

struct Node {
    Node *left, *right;
    unsigned long long int value = 0, amount = 0;
};

class Tree {
public:
    Tree() {
        root = NULL;
    };

    void insert(Node *node) {
        if(root != NULL) {
            insert(node, root);
        } else {
            root = node;
            counter = 1;
        }
    };

    Node *search(Node *node) {
        Node *tmp_node = NULL;
        if(node != NULL) {
            if (node->amount > 1) {
                return node;
            }

            if (node->right != NULL) {
                tmp_node = search(node->right);
            }

            if (tmp_node != NULL) {
                return tmp_node;
            } else if (node->left != NULL) {
                tmp_node = search(node->left);
            }
        }

        return tmp_node;
    };

    void solve() {
        solve(root);
    };

    Node *root;
    unsigned long long int counter = 0;

private:
    void insert(Node *node, Node *leaf) {
        if(node->value < leaf->value) {
            if(leaf->left != NULL) {
                return insert(node, leaf->left);
            } else {
                leaf->left = node;
                counter++;
            }
        } else if(node->value > leaf->value) {
            if(leaf->right != NULL) {
                return insert(node, leaf->right);
            } else {
                leaf->right = node;
                counter++;
            }
        } else {
            if (leaf->amount == 0) {
                counter++;
            }
            leaf->amount += node->amount;
        }
    };

    void solve(Node *node) {
        if (node->left != NULL) {
            solve(node->left);
        }
        if (node->amount > 1) {
            solveNode(node);
        }
        if (node->right != NULL) {
            solve(node->right);
        }
    }

    void solveNode(Node *node) {
        Node *tmp_node = new Node();
        tmp_node->value = node->value * 2;
        tmp_node->amount = node->amount / 2;
        insert(tmp_node);

        if (node->amount % 2 == 0) {
            node->amount = 0;
            counter--;
        } else {
            node->amount = 1;
        }
    }
};

int main() {
    unsigned long long int n, value, amount;
    Tree tree;

    scanf("%llu",&n);
    for (unsigned long long int i=0; i<n; i++) {
        Node *node = new Node();
        scanf("%llu %llu",&value, &amount);
        node->value = value;
        node->amount = amount;
        tree.insert(node);
    }

    tree.solve();

    printf("%llu\n", tree.counter);
    return 0;
}

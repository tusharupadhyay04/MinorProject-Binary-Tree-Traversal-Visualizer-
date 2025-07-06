#include <iostream>
using namespace std;

// Define the structure for a tree node
struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Class to represent the binary tree
class BinaryTree {
private:
    Node* root;

public:
    BinaryTree() : root(nullptr) {}

    void addNode(int value) {
        root = addNodeRec(root, value);
    }

    void inorderTraversal() {
        cout << "Inorder Traversal: ";
        inorderRec(root);
        cout << endl;
    }

    void preorderTraversal() {
        cout << "Preorder Traversal: ";
        preorderRec(root);
        cout << endl;
    }

    void postorderTraversal() {
        cout << "Postorder Traversal: ";
        postorderRec(root);
        cout << endl;
    }
private:
    Node* addNodeRec(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->value) {
            node->left = addNodeRec(node->left, value);
        } else {
            node->right = addNodeRec(node->right, value);
        }
        return node;
    }
    // It will perform inorder traversal
    void inorderRec(Node* node) {
        if (node == nullptr) return;
        inorderRec(node->left);
        cout << node->value << " ";
        inorderRec(node->right);
    }
    // It will perform preorder traversal
    void preorderRec(Node* node) {
        if (node == nullptr) return;
        cout << node->value << " ";
        preorderRec(node->left);
        preorderRec(node->right);
    }
    // It will perform postorder traversal
    void postorderRec(Node* node) {
        if (node == nullptr) return;
        postorderRec(node->left);
        postorderRec(node->right);
        cout << node->value << " ";
    }
};

int main() {
    BinaryTree tree;
    int n, value;
    cout << "Enter number of nodes: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << "Enter node value: ";
        cin >> value;
        tree.addNode(value);
    }
    // It will perform traversals function
    tree.inorderTraversal();
    tree.preorderTraversal();
    tree.postorderTraversal();

    return 0;
}

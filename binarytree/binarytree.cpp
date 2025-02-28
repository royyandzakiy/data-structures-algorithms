#include <iostream>
#include <memory>
using namespace std;

struct Node {
    int data;
    shared_ptr<Node> left;
    shared_ptr<Node> right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

    /*
            1
           / \
          2   3
         / \ / \
        4  5 6  7
           /
          8

    tree.preorderTraversal();   // Output: Preorder: 1 2 4 5 3 6 8 7
    tree.inorderTraversal();    // Output: Inorder: 4 2 5 1 8 6 3 7
    tree.postorderTraversal();  // Output: Postorder: 4 5 2 8 6 7 3 1

    */

class BinaryTree {
    public:
        BinaryTree(int data) {
            root = make_shared<Node>(data);
        }

        void rootAction(shared_ptr<Node> node) {
            cout << node->data << " ";
        }

        // traversing the binary tree
        void preorderTraversal(shared_ptr<Node> node) {
            // (Root -> Left -> Right):
            // usecase: copying tree, arithmetic expression, directory traversal
            if (node == nullptr) return;
            rootAction(node);
            preorderTraversal(node->left);
            preorderTraversal(node->right);
        }

        void inorderTraversal(shared_ptr<Node> node) {
            // (Left -> Root -> Right):
            // usecase: binary search tree, sorting
            if (node == nullptr) return;
            inorderTraversal(node->left);
            rootAction(node);
            inorderTraversal(node->right);
        }

        void postorderTraversal(shared_ptr<Node> node) {
            // (Left -> Right -> Root):
            // usecase: deleting tree, garbage collection
            if (node == nullptr) return;
            postorderTraversal(node->left);
            postorderTraversal(node->right);
            rootAction(node);
        }

        shared_ptr<Node> root;
};

int main() {
    BinaryTree tree(1);
    tree.root->left = std::make_shared<Node>(2);
    tree.root->right = std::make_shared<Node>(3);
    tree.root->left->left = std::make_shared<Node>(4);
    tree.root->left->right = std::make_shared<Node>(5);
    tree.root->right->left = std::make_shared<Node>(6);
    tree.root->right->right = std::make_shared<Node>(7);
    tree.root->right->left->left = std::make_shared<Node>(8);

    tree.preorderTraversal(tree.root);
    cout << endl;
    tree.inorderTraversal(tree.root);
    cout << endl;
    tree.postorderTraversal(tree.root);
    return 0;
}
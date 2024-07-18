#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int key) : val(key), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    TreeNode* root;
    BinarySearchTree() : root(nullptr) {}

    void insert(int key) {
        root = insertRec(root, key);
    }

    TreeNode* search(int key) {
        return searchRec(root, key);
    }

    void deleteNode(int key) {
        root = deleteRec(root, key);
    }

    void inorder() {
        inorderRec(root);
        cout << endl;
    }

private:
    TreeNode* insertRec(TreeNode* node, int key) {
        if (node == nullptr) {
            return new TreeNode(key);
        }
        if (key < node->val) {
            node->left = insertRec(node->left, key);
        } else {
            node->right = insertRec(node->right, key);
        }
        return node;
    }

    TreeNode* searchRec(TreeNode* node, int key) {
        if (node == nullptr || node->val == key) {
            return node;
        }
        if (key < node->val) {
            return searchRec(node->left, key);
        } else {
            return searchRec(node->right, key);
        }
    }

    TreeNode* deleteRec(TreeNode* node, int key) {
        if (node == nullptr) {
            return node;
        }
        if (key < node->val) {
            node->left = deleteRec(node->left, key);
        } else if (key > node->val) {
            node->right = deleteRec(node->right, key);
        } else {
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            TreeNode* temp = minValueNode(node->right);
            node->val = temp->val;
            node->right = deleteRec(node->right, temp->val);
        }
        return node;
    }

    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    void inorderRec(TreeNode* node) {
        if (node != nullptr) {
            inorderRec(node->left);
            cout << node->val << " ";
            inorderRec(node->right);
        }
    }
};

int main() {
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    cout << "Inorder traversal of the BST: ";
    bst.inorder();

    cout << "Search for 40: " << (bst.search(40) != nullptr) << endl;
    cout << "Search for 100: " << (bst.search(100) != nullptr) << endl;

    bst.deleteNode(20);
    cout << "Inorder traversal of the BST after deleting 20: ";
    bst.inorder();

    bst.deleteNode(30);
    cout << "Inorder traversal of the BST after deleting 30: ";
    bst.inorder();

    bst.deleteNode(50);
    cout << "Inorder traversal of the BST after deleting 50: ";
    bst.inorder();

    return 0;
}

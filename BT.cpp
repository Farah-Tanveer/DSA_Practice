#include <iostream>
using namespace std;

class BinaryTree {
private:
    struct TreeNode {
        int data;
        TreeNode* left;
        TreeNode* right;
    };

    TreeNode* root;

    // ===== Helper Functions =====
    TreeNode* createNode(int value) {
        TreeNode* newNode = new TreeNode();
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    void inorder(TreeNode* temp) {
        if (temp != NULL) {
            inorder(temp->left);
            cout << temp->data << " ";
            inorder(temp->right);
        }
    }

    void preorder(TreeNode* temp) {
        if (temp != NULL) {
            cout << temp->data << " ";
            preorder(temp->left);
            preorder(temp->right);
        }
    }

    void postorder(TreeNode* temp) {
        if (temp != NULL) {
            postorder(temp->left);
            postorder(temp->right);
            cout << temp->data << " ";
        }
    }

    int countNodes(TreeNode* temp) {
        if (temp == NULL)
            return 0;

        return 1 + countNodes(temp->left) + countNodes(temp->right);
    }

    int sumNodes(TreeNode* temp) {
        if (temp == NULL)
            return 0;

        return temp->data + sumNodes(temp->left) + sumNodes(temp->right);
    }

public:
    // ===== Constructor =====
    BinaryTree() {
        root = NULL;
    }

    // ===== Build Sample Tree =====
    void buildSampleTree() {
        root = createNode(10);
        root->left = createNode(5);
        root->right = createNode(20);
        root->left->left = createNode(3);
        root->left->right = createNode(7);
    }

    // ===== Traversal Wrappers =====
    void inorderTraversal() {
        inorder(root);
        cout << endl;
    }

    void preorderTraversal() {
        preorder(root);
        cout << endl;
    }

    void postorderTraversal() {
        postorder(root);
        cout << endl;
    }

    // ===== Utility Functions =====
    int getTotalNodes() {
        return countNodes(root);
    }

    int getSum() {
        return sumNodes(root);
    }
};
int main() {
    BinaryTree tree;

    tree.buildSampleTree();

    cout << "Inorder: ";
    tree.inorderTraversal();

    cout << "Preorder: ";
    tree.preorderTraversal();

    cout << "Postorder: ";
    tree.postorderTraversal();

    cout << "Total Nodes: " << tree.getTotalNodes() << endl;
    cout << "Sum of Nodes: " << tree.getSum() << endl;

    return 0;
}
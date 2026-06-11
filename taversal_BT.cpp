#include <iostream>
#include <queue>
using namespace std;

// ===== Tree Node =====
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

//
// ===== Depth First Traversals =====
//

// 🔹 Inorder (L V R)
void inorder(TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// 🔹 Preorder (V L R)
void preorder(TreeNode* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// 🔹 Postorder (L R V)
void postorder(TreeNode* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

//
// ===== Level Order (BFS) =====
//
void levelOrder(TreeNode* root) {
    if (root == NULL)
        return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if (temp->left != NULL)
            q.push(temp->left);

        if (temp->right != NULL)
            q.push(temp->right);
    }
}

//
// ===== Sample Tree =====
//
TreeNode* buildSampleTree() {
    TreeNode* root = new TreeNode(10);

    root->left = new TreeNode(5);
    root->right = new TreeNode(20);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);

    return root;
}

//
// ===== Main =====
//
int main() {
    TreeNode* root = buildSampleTree();

    cout << "Inorder: ";
    inorder(root);

    cout << "\nPreorder: ";
    preorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    cout << "\nLevel Order: ";
    levelOrder(root);

    return 0;
}
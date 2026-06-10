#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// ===== Build from Postfix =====
TreeNode* buildFromPostfix(string exp) {
    stack<TreeNode*> st;

    for (int i = 0; i < exp.length(); i++) {
        char ch = exp[i];

        if (isalnum(ch)) {
            st.push(new TreeNode(ch));
        }
        else {
            TreeNode* right = st.top(); st.pop();
            TreeNode* left = st.top(); st.pop();

            TreeNode* node = new TreeNode(ch);
            node->left = left;
            node->right = right;

            st.push(node);
        }
    }

    return st.top();
}

// ===== Evaluate (NUMBERS ONLY) =====
int evaluate(TreeNode* root) {
    if (root == NULL)
        return 0;

    // leaf node (digit)
    if (root->left == NULL && root->right == NULL)
        return root->data - '0';

    int left = evaluate(root->left);
    int right = evaluate(root->right);

    if (root->data == '+') return left + right;
    if (root->data == '-') return left - right;
    if (root->data == '*') return left * right;
    if (root->data == '/') return left / right;

    return 0;
}

// ===== Inorder =====
void inorder(TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    // Use numeric postfix for evaluation
    string exp = "23+5*";   // (2+3)*5 = 25

    TreeNode* root = buildFromPostfix(exp);

    cout << "Inorder: ";
    inorder(root);

    cout << "\nResult: " << evaluate(root);

    return 0;
}
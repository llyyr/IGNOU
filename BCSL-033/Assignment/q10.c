// Q10: Write a program to implement binary search tree (BST). Also, write 
// functions to traverse the BST  in In-order, Pre-order and Post-order forms.

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode TreeNode;

TreeNode *create_node(int data) {
    TreeNode *node = malloc(sizeof(TreeNode));
    if (!node) {
        perror("Memory allocation failed");
        exit(1);
    }
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

TreeNode *insert(TreeNode *root, int data) {
    if (!root)
        return create_node(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data) 
        root->right = insert(root->right, data);
    return root;
}

void in_order(TreeNode *root) {
    if (!root)
        return;
    in_order(root->left);
    printf("%d ", root->data);
    in_order(root->right);
}

void pre_order(TreeNode *root) {
    if (!root)
        return;
    printf("%d ", root->data);
    pre_order(root->left);
    pre_order(root->right);
}

void post_order(TreeNode *root) {
    if (!root)
        return;
    post_order(root->left);
    post_order(root->right);
    printf("%d ", root->data);
}

int main() {
    TreeNode *root = NULL;
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < sizeof(values) / sizeof(values[0]); i++)
        root = insert(root, values[i]);

    printf("In-order traversal: ");
    in_order(root);
    printf("\n");

    printf("Pre-order traversal: ");
    pre_order(root);
    printf("\n");

    printf("Post-order traversal: ");
    post_order(root);
    printf("\n");

    return 0;
}

#include <stdio.h>

struct node {
    int data;
    node* left;
    node* right;
};


node* tree2listUtil(node* root) {

    if (root == NULL)
        return root;

    if (root->left != NULL) {
        node* left = tree2listUtil(root->left);

        for (; left->right != NULL; left = left->right);

        left->right = root;
        root->left  = left;
            
    }

    if (root->right != NULL) {
        node* right = tree2listUtil(root->right);

        for (; right->left != NULL; right = right->left);

        right->left = root;
        root->right = right;
    }

    return root;
}

node* tree2list(node* root) {

    if (root == NULL)
        return root;

    root = tree2listUtil(root);

    while (root->left != NULL)
        root = root->left;

    return root;
}

node* newnode(int data) {
    node* new_node = new node;
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    
    return new_node;
}

void printlist(node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->right;
    }
    printf("\n");
}

int main() {
    node* root        = newnode(10);
    root->left        = newnode(6);
    root->right       = newnode(14);
    root->left->right = newnode(8);
    root->right->left = newnode(12);

    node* head = tree2list(root);

    printlist(head);

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

void inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void mirrorify(node *root, node **mirror)
{
    if (root == NULL)
    {
        *mirror = NULL;
        return;
    }
    *mirror = new node(root->data);
    mirrorify(root->left, &((*mirror)->right));
    mirrorify(root->right, &((*mirror)->left));
}

int main()
{

    node *tree = new node(5);
    tree->left = new node(3);
    tree->right = new node(6);
    tree->left->left = new node(2);
    tree->left->right = new node(4);

    // Print inorder traversal of the input tree
    printf("Inorder of original tree: ");
    inorder(tree);
    node *mirror = NULL;
    mirrorify(tree, &mirror);

    // Print inorder traversal of the mirror tree
    printf("\nInorder of mirror tree: ");
    inorder(mirror);

    return 0;
}
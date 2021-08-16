#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

vector<int> diagonal(Node *root)
{
    vector<int> diagonalVals;
    if (!root)
        return diagonalVals;

    queue<Node *> leftQueue;
    Node *node = root;

    while (node)
    {

        diagonalVals.push_back(node->data);

        if (node->left)
            leftQueue.push(node->left);

        if (node->right)
            node = node->right;

        else
        {

            if (!leftQueue.empty())
            {
                node = leftQueue.front();
                leftQueue.pop();
            }
            else
            {

                node = NULL;
            }
        }
    }
    return diagonalVals;
}

Node *newNode(int data)
{
    Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Driver program
int main()
{
    Node *root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);

    vector<int> diagonalValues = diagonal(root);
    for (int i = 0; i < diagonalValues.size(); i++)
    {
        cout << diagonalValues[i] << " ";
    }
    cout << endl;

    return 0;
}

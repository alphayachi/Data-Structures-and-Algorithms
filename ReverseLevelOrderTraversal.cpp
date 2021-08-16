// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
// Utility function to create a new Tree Node
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
// Function to Build Tree
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

vector<int> reverseLevelOrder(Node *root);

int main()
{

    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);
        vector<int> result = reverseLevelOrder(root);
        for (int i = 0; i < result.size(); ++i)
        {
            cout << result[i] << " ";
        }
        cout << endl;
    }
    return 1;
} // } Driver Code Ends

/*   
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

int height(Node *root)
{
    if (root == NULL)
        return 0;
    int left_height = height(root->left);
    int right_height = height(root->right);

    if (left_height > right_height)
        return 1 + left_height;
    else
        return 1 + right_height;
}

void PrintLevel(Node *root, int level, int h, vector<int> &vect)
{
    if (root == NULL)
        return;
    if (level == h)
        vect.push_back(root->data);
    if (level < h)
    {
        PrintLevel(root->left, level + 1, h, vect);
        PrintLevel(root->right, level + 1, h, vect);
    }
}

vector<int> reverseLevelOrder(Node *root)
{
    int h = height(root);
    vector<int> vect;
    for (int i = 1; i <= h; i++)
    {
        PrintLevel(root, i, h, vect);
    }
    return vect;
}
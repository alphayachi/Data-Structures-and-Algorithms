// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;
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

// } Driver Code Ends

void width(Node *root, int hl, int minMax[])
{
    if (root == NULL)
        return;

    minMax[0] = min(minMax[0], hl);
    minMax[1] = max(minMax[1], hl);

    width(root->left, hl - 1, minMax);
    width(root->right, hl + 1, minMax);
}

void top_view(Node *root, vector<int> &ans)
{
    int minMax[] = {0, 0};
    width(root, 0, minMax);
    int tree_width = minMax[1] + minMax[0] + 1;
    int minWidth = minMax[0];
    int maxWidth = minMax[1];
    pair<Node *, int> p;
    queue<pair<Node *, int>> q;
    map<int, int> rec;
    p.first = root;
    p.second = 0;
    q.push(p);
    while (!q.empty())
    {
        pair<Node *, int> tmp(q.front());
        if (rec.count(tmp.second) == 0)
            rec[tmp.second] = tmp.first->data;
        if (tmp.first->left)
        {
            pair<Node *, int> pl(tmp.first->left, tmp.second - 1);
            q.push(pl);
        }
        if (tmp.first->right)
        {
            pair<Node *, int> pr(tmp.first->right, tmp.second + 1);
            q.push(pr);
        }
        q.pop();
    }
    for (int i = minWidth; i <= maxWidth; i++)
    {
        ans.push_back(rec[i]);
    }
}

class Solution
{
public:
    //Function to return a list of nodes visible from the top view
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        top_view(root, ans);
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int tc;
    cin >> tc;
    cin.ignore(256, '\n');
    while (tc--)
    {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        vector<int> vec = ob.topView(root);
        for (int x : vec)
            cout << x << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends
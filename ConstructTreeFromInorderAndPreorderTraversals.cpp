// { Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printPostOrder(Node *root)
{
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
Node *build(int in[], int pre[], int pre_start, int pre_end, int in_start, int in_end, map<int, int> inorder)
{
    if (in_start > in_end)
        return NULL;
    Node *root = new Node(pre[pre_start]);
    int idx = in_start;
    // while(in[idx]!=pre[pre_start]) idx++;
    map<int, int>::iterator itr = inorder.begin();
    itr = inorder.find(pre[pre_start]);
    idx = itr->second;
    int count_left = idx - in_start;
    root->left = build(in, pre, pre_start + 1, pre_start + count_left, in_start, idx - 1, inorder);
    root->right = build(in, pre, pre_start + count_left + 1, pre_end, idx + 1, in_end, inorder);
    return root;
}

class Solution
{
public:
    Node *buildTree(int in[], int pre[], int n)
    {
        int pre_start = 0, pre_end = n - 1, in_start = 0, in_end = n - 1;
        map<int, int> inorder;

        for (int i = 0; i < n; i++)
            inorder.insert(pair<int, int>(in[i], i));

        Node *root = build(in, pre, pre_start, pre_end, in_start, in_end, inorder);
        return root;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int inorder[n], preorder[n];
        for (int i = 0; i < n; i++)
            cin >> inorder[i];
        for (int i = 0; i < n; i++)
            cin >> preorder[i];
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder, n);
        printPostOrder(root);
        cout << endl;
    }
}
// } Driver Code Ends
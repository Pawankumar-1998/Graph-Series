#include <iostream>
#include <vector>
using namespace std;

//  this is the structure of the ndoe
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    //  this constructor initializing the data part and setting the left and right child as null
    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

//  this is the function for storing the binary search tree in a array
void storeBS(vector<int> &arr, Node *root, int index)
{
    if (root == nullptr)
    {
        return;
    }

    //  insert the data into the index
    arr[index] = root->data;

    // call the function call recursive to plaxe its left child in the array ( formula = 2 * index + 1)
    storeBS(arr, root->left, 2 * index + 1);

    //  call the function recursively to place the right child in the array (formula = 2 * index + 2)
    storeBS(arr, root->right, 2 * index + 2);
}

int main()
{
    //  a simple binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    //  total number of nodes in the tree
    int node = 7;

    //  array for storing the btree
    vector<int> arr(node, -1);

    // calling the function for storing the b tree
    storeBS(arr, root, 0);

    for (int i = 0; i < node; i++)
    {
        if (arr[i] != -1)
            cout << arr[i] << " ";
        else
            cout << "- ";
    }
    cout << endl;
    return 0;
}
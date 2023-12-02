/*  Author: Jovani Benavides
 *  Course: CSCI-41
 *
 *
 */
#include <iostream>
using namespace std;

class BSTNode {
public:
    int key;
    BSTNode* left;
    BSTNode* right;

    // Constructors
    BSTNode() : key(0), left(nullptr), right(nullptr) {}
    BSTNode(int value) : key(value), left(nullptr), right(nullptr) {}

    // Destructor
    ~BSTNode() {}

    // Check if the node is a leaf
    bool isLeaf() {
        return (left == nullptr && right == nullptr);
    }

    // Get the number of children
    int getNumChildren() {
        int count = 0;
        if (left != nullptr) count++;
        if (right != nullptr) count++;
        return count;
    }

    // Get the parent of a given child node
    static BSTNode* Parent(BSTNode* root, BSTNode* child) {
        if (root == nullptr || child == nullptr || root == child)
            return nullptr;

        if ((root->left == child) || (root->right == child))
            return root;

        if (child->key < root->key)
            return Parent(root->left, child);
        else
            return Parent(root->right, child);
    }
};

// Recursive search in BST
bool SearchNodeREC(BSTNode* root, int data) {
    if (root == nullptr)
        return false;

    if (data == root->key)
        return true;
    else if (data < root->key)
        return SearchNodeREC(root->left, data);
    else
        return SearchNodeREC(root->right, data);
}

// Iterative search in BST
bool SearchNodeITE(BSTNode* root, int data) {
    while (root != nullptr) {
        if (data == root->key)
            return true;
        else if (data < root->key)
            root = root->left;
        else
            root = root->right;
    }
    return false;
}

// Recursive insert in BST
void InsertNodeREC(BSTNode** root, int data) {
    if (*root == nullptr) {
        *root = new BSTNode(data);
        return;
    }

    if (data < (*root)->key)
        InsertNodeREC(&((*root)->left), data);
    else if (data > (*root)->key)
        InsertNodeREC(&((*root)->right), data);
}

// Iterative insert in BST
void InsertNodeITE(BSTNode** root, int data) {
    if (*root == nullptr) {
        *root = new BSTNode(data);
        return;
    }

    BSTNode* current = *root;
    while (true) {
        if (data < current->key) {
            if (current->left == nullptr) {
                current->left = new BSTNode(data);
                return;
            }
            current = current->left;
        } else if (data > current->key) {
            if (current->right == nullptr) {
                current->right = new BSTNode(data);
                return;
            }
            current = current->right;
        } else {
            return;
        }
    }
}

// Output information about the node
void OutputNodeInfo(BSTNode* node) {
    if (node == nullptr) {
        cout << "Node: nullptr" << endl;
        return;
    }

    cout << "Node: " << node->key << endl;
    cout << "Is Leaf: " << (node->isLeaf() ? "Yes" : "No") << endl;
    cout << "Number of Children: " << node->getNumChildren() << endl;
}

int main() {
    BSTNode* root = nullptr;

    // Insert nodes into the BST
    InsertNodeREC(&root, 50);
    InsertNodeREC(&root, 30);
    InsertNodeITE(&root, 70);
    InsertNodeITE(&root, 20);
    

    // Output information about the nodes
    cout << "Information about nodes after insertion:" << endl;
    OutputNodeInfo(root);
    OutputNodeInfo(root->left);
    OutputNodeInfo(root->right);
    OutputNodeInfo(root->left->left);
    
    cout<<endl;
    // Search for nodes in the BST
    cout << "Searching for nodes:" << endl;
    cout << "Search (Recursive): " << (SearchNodeREC(root, 60) ? "Found" : "Not Found") << endl;
    cout << "Search (Recursive): " << (SearchNodeREC(root, 30) ? "Found" : "Not Found") << endl;

    cout << "Search (Iterative): " << (SearchNodeITE(root, 75) ? "Found" : "Not Found") << endl;
    cout << "Search (Iterative): " << (SearchNodeITE(root, 20) ? "Found" : "Not Found") << endl;


    // Insert additional nodes
    InsertNodeITE(&root, 65);

    // Output information about the nodes
    cout << "\nInformation about nodes after additional insertions:" << endl;
    OutputNodeInfo(root);
    OutputNodeInfo(root->left);
    OutputNodeInfo(root->right);
    OutputNodeInfo(root->left->left);
    OutputNodeInfo(root->left->right);
    OutputNodeInfo(root->right->left);
    return 0;
}

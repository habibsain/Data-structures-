#include<iostream>

using namespace std;    

//define nodes
struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

void heapify(Node*& root) {
    if (root == nullptr) {
        return;
    }
    //if (root->left != nullptr && root->right != nullptr) {
    //    if (root->left->data > root->right->data) {
    //        swap(root->left->data, root->right->data);
    //    }
    //}
    if (root->left != nullptr && root->data > root->left->data) {
        swap(root->data, root->left->data);
        heapify(root->left);

    }
    if (root->right != nullptr && root->data > root->right->data) {
        swap(root->data, root->right->data);
        heapify(root->right);

    }
}

void insertNode(Node*& root, int value) {
    if (root == nullptr) {
        root = createNode(value);
    }
    else if (value < root->data) {
        insertNode(root->left, value);
    }
    else if (value > root->data) {
        insertNode(root->right, value);
    }
    heapify(root);
}


    // Function to print a node and its children
    void printNode(Node* node) {
        if (node != nullptr) {
            std::cout << node->data << " ";
            printNode(node->left);
            printNode(node->right);
        }
    }
void printHeap(Node* root) {
        printNode(root);
    }

int main() {
    Node* root = nullptr;
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 8);
    insertNode(root, 2);
    insertNode(root, 4);
    insertNode(root, 6);
    insertNode(root, 10);
    insertNode(root, 9);
    printHeap(root);
    return 0;
}
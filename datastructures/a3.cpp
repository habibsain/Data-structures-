#include<iostream>

using namespace std;

//define nodes
struct Node{
    int data;
    Node* left;
    Node* right;
};

//define functions
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

void insert(Node*& root, int value){
    if (root == nullptr) {
        root = createNode(value);
    }
    else if (value < root->data) {
        insert(root->left, value);
    }
    else if (value > root->data) {
        insert(root->right, value);
    }

}

void printTree(Node* root) {
    if (root == nullptr) {
        return;
    }
    printTree(root->left);
    cout << root->data << " ";
    printTree(root->right);
}

int main(){
    Node* root = nullptr;

    insert(root, 5);
    insert(root, 3);
    insert(root, 8);
    insert(root, 2);
    insert(root, 4);
    insert(root, 6);
    insert(root, 9);
    insert(root, 1);

    printTree(root);
    return 0;
}
//Incorrect
#include <iostream>

// Define the structure for a binary heap node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    if (!newNode) {
        std::cout << "Memory error\n";
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
// Function to heapify the binary heap
void heapify(Node*& root) {
    if (root == NULL) {
        return;
    }
    Node* current = root;
    while (true) {
        if (current->left != NULL && current->left->data < current->data) {
            int temp = current->data;
            current->data = current->left->data;
            current->left->data = temp;
            current = current->left;
        } else if (current->right != NULL && current->right->data < current->data) {
            int temp = current->data;
            current->data = current->right->data;
            current->right->data = temp;
            current = current->right;
        } else {
            break;
        }
    }
}

// Function to insert a new node into the binary heap
void insertNode(Node*& root, int data) {
    Node* newNode = createNode(data);
    if (root == NULL) {
        root = newNode;
    } 
    else {
        Node* current = root;
        while (true) {
            if (data < current->data) {
                if (current->left == NULL) {
                    current->left = newNode;
                    break;
                }
                current = current->left;
            } else {
                if (current->right == NULL) {
                    current->right = newNode;
                    break;
                }
                current = current->right;
            }
        }
        heapify(root);
    }
}

// Function to print the binary heap
void printHeap(Node* root) {
    if (root == NULL) {
        return;
    }
    std::cout << root->data << " ";
    printHeap(root->left);
    printHeap(root->right);
}



// Function to extract the minimum value from the binary heap
int extractMin(Node*& root) {
    if (root == NULL) {
        return -1;
    }
    int min = root->data;
    Node* temp = root;
    root = root->right;
    delete temp;
    heapify(root);
    return min;
}

int main() {
    Node* root = NULL;
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 8);
    insertNode(root, 2);
    insertNode(root, 4);
    insertNode(root, 6);
    insertNode(root, 10);
    insertNode(root, 9);
    printHeap(root);
    std::cout << "\n";
    std::cout << "Extracted Min: " << extractMin(root) << "\n";
    printHeap(root);
    return 0;
}
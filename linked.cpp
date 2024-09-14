#include<iostream>
using namespace std;

struct node {
    int data;
    node *next;
    };

node* reverse_linked_list(node* head){
    node* prev = nullptr;
    node* current = head;
    node* next = nullptr;
    
    while (current != nullptr)  
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
    
}
int main(){
    
    node* head = new node{1};
    head->next = new node{2};
    head->next->next = new node{3};
    head->next->next->next = new node{4};

    head = reverse_linked_list(head);

    cout << head->data << endl;
    cout << head->next->data << endl;
    cout << head->next->next->data << endl;
    cout << head->next->next->next->data << endl;
    
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node *next;
};

Node* add_node(Node *curr, int value) {
    
    Node *node = (Node*) malloc(sizeof(Node));
    
    node->data = value;
    node->next = NULL;

    Node *prev;

    while(curr != NULL) {
        prev = curr;
        curr = curr->next;
    }

    prev->next = node;

    return node;
}

int ans;
void print(Node *node) {
    if(node == NULL)
        return;

    cout << node->data << endl;

    if(node->next != NULL) {
        print(node->next);
    }

}

//1 - 2 - 3

void remove(Node **root, int value) {
    Node* node = *root;
    Node *prev = NULL;
    Node *next = NULL;

    while(node != NULL) {
        
        if(node->data == value) {
            // Remove root
            if(prev == NULL) {
                *root = node->next;
                free(node);
                return;
            }

            if(node->next == NULL) {
                free(node);
                prev->next = NULL;
                return;
            }

            // middle element
            prev->next = node->next;
            free(node);
            return;
        }

        prev = node;
        node = node->next;
    }
}

void remove_last(Node *root, int value) {
    Node *curr = root;
    Node *prev = NULL;

    while(curr->next != NULL) {
        prev = curr;
        curr = curr->next;
    }

    free(prev->next);
    prev->next = NULL;
}

bool find_cycle(Node *node) {
    unordered_set<Node*> st;

    Node *curr = node;
    while(curr->next != NULL) {
        if(st.find(curr) != st.end())
            return true;
        
        st.insert(curr);
        curr = curr->next;
    }

    return false;
}


Node* reverse_list(Node *node) {
    Node *curr = node;
    Node *prev= NULL;
    Node *next = NULL;

    while(curr->next != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
}

int main() {

    Node *head;

    head = (Node*) malloc(sizeof(Node));

    head->data = 20;
    head->next = NULL;
    
    add_node(head, 4);
    add_node(head, 5);
    add_node(head, 10);

    //head->next->next->next = head;

    //head = reverse_list(head);

    //if(find_cycle(head)) cout << "Is cycle" << endl;
    //else cout << "It is not" << endl;

    
    print(head);
    cout << endl << endl;
    remove(&head, 4);
    print(head);


    return 0;
}
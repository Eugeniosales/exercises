#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int value) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert(Node *root, int value) {

    if(root == NULL) {
        return;
    }

    if(root->data > value) {
        if(root->left == NULL) {
            Node *node = createNode(value);
            root->left = node;
        } else {
            insert(root->left, value);
        }
    } else {
        if(root->right == NULL) {
            Node *node = createNode(value);
            root->right = node;
        } else {
            insert(root->right, value);
        }
    }
}

bool search(Node *root, int value) {
    if(root->data == value) {
        return true;
    } else if(root->data > value) {
        
        if(root->left == NULL) {
            return false;
        }

        return search(root->left, value);
    } else {
        if(root->right == NULL) {
            return false;    
        }
        return search(root->right, value);
    }

    return false;
} 

void invertBinaryTree(Node* root) {
    if(root) {
        Node* left = root->left;
        Node*right = root->right;
        root->left = right;
        root->right = left;
        invertBinaryTree(root->left);
        invertBinaryTree(root->right);
    }
}

// 1 - left
// 2 - root
// 3 - rigth

void printInOrder(Node *root) {
    if(root->left) printInOrder(root->left);
    cout << root->data << endl;
    if(root->right) printInOrder(root->right);
}

// 2 - root
// 1 - left
// 3 - rigth

void printPreOrder(Node *root) {
    cout << root->data << endl;
    if(root->left) printPreOrder(root->left);
    if(root->right) printPreOrder(root->right);
}

// 1 - left
// 3 - right
// 2 - root
void printPosOrder(Node* root) {
    if(root->left) printPosOrder(root->left);
    if(root->right) printPosOrder(root->right);
    cout << root->data;
}

int find_root_position(string infix, string prefix) {
    for(int i = 0; i < infix.size(); i++) {
        if(infix[i] == prefix[0]){
            return i; 
        }
    }

    return 0;
}

// achar raiz
// posição da raiz na pre order
// criar arvore baseado nos limites da in order
// post order na nova arvore

unordered_set <char> splitSides(string infix, int start, int end) {
    unordered_set <char> st;
    for(int i = start; i < end; i++) {
        st.insert(infix[i]);
    }
    return st;
}

void createTree(Node* root, string prefix, unordered_set <char> side) {
    for(auto chr:prefix) {
        if(side.find(chr) != side.end()) {
            insert(root, chr);
        }
    }
}

void freeTree(Node* root) {
    if(root->left != NULL) freeTree(root->left);
    if(root->right != NULL) freeTree(root->right);
    free(root);
}

int main() {

    string prefix, infix;
    int n, size;

    Node* root = createNode(8);

    insert(root, 6);
    insert(root, 4);
    insert(root, 7);
    insert(root, 10);
    insert(root, 11);
    insert(root, 9);  
    
    // printInOrder(root);
    // cout << endl << endl;
    // invertBinaryTree(root);
    printInOrder(root);
        
    
    cout << endl;
    Node* cp = root;

    printInOrder(cp);
    freeTree(root);
    freeTree(cp);

    return 0;
}
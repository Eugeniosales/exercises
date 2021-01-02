#include <bits/stdc++.h>

using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
};
 
 
Node* CreateNode(char data)
{
    Node* newNode = new Node();
    if (!newNode) {
        return NULL;
    }

    newNode->data = data;
    newNode->left = newNode->right = NULL;
    
    return newNode;
}
  
Node* insertNode(Node* root, char data)
{
    if (root == NULL) {
        root = CreateNode(data);
        return root;
    }
 
    queue<Node*> q;
    q.push(root);
 
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
 
        if(data <= temp->data) {
            if (temp->left != NULL)
                q.push(temp->left);
            else {
                temp->left = CreateNode(data);
                return root;
            }
        } else {
            if (temp->right != NULL)
                q.push(temp->right);
            else {
                temp->right = CreateNode(data);
                return root;
            }
        }
    }
}

bool search(Node* node, char value) {
    if(node == NULL) return false;
    if(node->data == value) return true;

    if(value <= node->data) return search(node->left, value);
    else return search(node->right, value);
}

bool toPrint;

void printSpace() {
    if(toPrint) {
        toPrint = !toPrint;
    } else printf(" ");
}

void preorder(Node* node)
{
    if (node == NULL)
        return;

    printSpace();
    cout << node->data;
    preorder(node->left);
    preorder(node->right);
}

void inorder(Node* node)
{
    if (node == NULL)
        return;

    inorder(node->left);
    printSpace();
    cout << node->data;
    inorder(node->right);
}

void posorder(Node* node)
{
    if (node == NULL)
        return;

    posorder(node->left);
    posorder(node->right);
    printSpace();
    cout << node->data;
}

int main() {
    string s;
    char n;

    bool isFirst = true;
    Node* root;

    while(getline(cin, s)) {
        if(s[0] == 'I' && s.size() == 3) {
            n = s[2];
            if(isFirst) {
                isFirst = !isFirst;
                root = insertNode(NULL, n);
            }
            else {
                root = insertNode(root, n);
            }
        } else if(s[0] == 'P' && s.size() == 3) {
            n = s[2];
            search(root, n) ? printf("%c existe\n", n):printf("%c nao existe\n", n);

        } else if(s == "PREFIXA") {
            toPrint = true;
            preorder(root);
            printf("\n");
        } else if(s == "INFIXA") {
            toPrint = true;
            inorder(root);
            printf("\n");
        } else {
            toPrint = true;
            posorder(root);
            printf("\n");
        }
    }

    return 0;
}
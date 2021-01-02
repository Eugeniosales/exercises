#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};
 
 
Node* CreateNode(int data)
{
    Node* newNode = new Node();
    if (!newNode) {
        return NULL;
    }

    newNode->data = data;
    newNode->left = newNode->right = NULL;
    
    return newNode;
}
  
Node* insertNode(Node* root, int data)
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

Node* maxValueNode(Node* node)
{
    Node* current = node;
 
    while (current && current->right != NULL)
        current = current->right;
 
    return current;
}

Node* deleteNode(Node* root, int key) {

    if (root == NULL)
        return root;
 
    if (key < root->data)
        root->left = deleteNode(root->left, key);
 
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
 
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
 
        struct Node* temp = maxValueNode(root->left);
 
        root->data = temp->data;
 
        root->left = deleteNode(root->left, temp->data);
    }
    return root;
}

bool search(Node* node, int value) {
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
    string s, aux, w;
    char n;
    int num;
    vector <string> xs;
    

    bool isFirst = true;
    Node* root;

    while(getline(cin, s)) {
        if(s[0] == 'I' && s[1] != 'N') {
            int num = stoi(s.substr(2, s.size() - 1));

            if(isFirst) {
                isFirst = !isFirst;
                root = insertNode(NULL, num);
            }
            else {
                root = insertNode(root, num);
            }
        } else if(s[0] == 'P' && s[1] != 'R' && s[1] != 'O') {
            int num = stoi(s.substr(2, s.size() - 1));
            search(root, num) ? printf("%d existe\n", num):printf("%d nao existe\n", num);
        } else if(s[0] == 'R') {
            int num = stoi(s.substr(2, s.size() - 1));
            root = deleteNode(root, num);

        } else if(s == "PREFIXA") {
            toPrint = true;
            preorder(root);
            printf("\n");
        } else if(s == "INFIXA") {
            toPrint = true;
            inorder(root);
            printf("\n");
        } else if(s == "POSFIXA"){
            toPrint = true;
            posorder(root);
            printf("\n");
        }
    }

    return 0;
}
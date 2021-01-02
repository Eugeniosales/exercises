#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    if(!newNode) return NULL; 

    newNode->data= data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int data) {
    if(root == NULL) {
        return createNode(data);
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(data <= temp->data) {
            if(temp->left != NULL){
                q.push(temp->left);
            } else {
                temp->left = createNode(data);
                return root;
            }
        } else {
            if(temp->right != NULL) {
                q.push(temp->right);
            } else {
                temp->right = createNode(data);
                return root;
            }
        }
    }
}

void preorder(Node* node) {
    if(node == NULL) return;

    printf(" %d", node->data);
    preorder(node->left);
    preorder(node->right);
}

void inorder(Node* root) {
    if(root == NULL) return;

    inorder(root->left);
    printf(" %d", root->data);
    inorder(root->right);
}

void posorder(Node* root) {
    if(root == NULL) return;

    posorder(root->left);
    posorder(root->right);
    printf(" %d", root->data);
}

int main() {

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);  

    int c, n, aux;

    scanf("%d", &c);

    int i = 1;
    while(c--) {
        scanf("%d", &n);
        bool isFirst = true;
        Node* root;

        while(n--) {
            scanf("%d", &aux);

            if(isFirst) {
                isFirst = !isFirst;
                root = insertNode(NULL, aux);
            }
            else {
                root = insertNode(root, aux);
            }
        }

        printf("Case %d:\n", i);
        printf("Pre.:");
        preorder(root);
        printf("\n");

        printf("In..:");
        inorder(root);
        printf("\n");

        printf("Post:");
        posorder(root);
        printf("\n\n");
        i++;
    }
    return 0;
}
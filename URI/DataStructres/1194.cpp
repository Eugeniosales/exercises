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
  
Node* InsertNode(Node* root, char data)
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
 

void posorder(Node* node)
{
    if (node == NULL)
        return;

    posorder(node->left);
    posorder(node->right);
    cout << node->data;
}

int preIndex = 0;

int searchInd(string arr, int strt, int end, char value)
{
    int i;
    for(i = strt; i <= end; i++)
    {
        if(arr[i] == value)
            return i;
    }
    return -1;
}

Node* findRoot(string in, string pre, int inStrt, int inEnd)
{
    if(inStrt > inEnd)
        return NULL;
    Node* node = CreateNode(pre[preIndex++]);
    if(inStrt == inEnd)
        return node;
    int inIndex = searchInd(in, inStrt, inEnd, node->data);
    node->left = findRoot(in, pre, inStrt, inIndex - 1);
    node->right = findRoot(in, pre, inIndex + 1, inEnd);
    return node;
}

void show() {
    string s, p;
    int n, aux;

    scanf("%d", &n);

    while(n--) {
        cin >>  aux >> p >> s;

        preIndex = 0;
        Node* root = findRoot(s, p, 0, aux - 1);

        posorder(root);
        printf("\n");
    }

}

int main()
{

    show();
 
    return 0;
}
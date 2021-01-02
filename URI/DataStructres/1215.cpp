#include <bits/stdc++.h>

using namespace std;
 
struct Node {
    string data;
    Node* left;
    Node* right;
};
 
 
Node* CreateNode(string data)
{
    Node* newNode = new Node();
    if (!newNode) {
        return NULL;
    }

    newNode->data = data;
    newNode->left = newNode->right = NULL;
    
    return newNode;
}
  
Node* InsertNode(Node* root, string data)
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
 

void inorder(Node* node)
{
    if (node == NULL)
        return;

    inorder(node->left);
    cout << node->data << "\n";
    inorder(node->right);
}

void show() {
    string s, word;
    map <string, int> xs;

    while(getline(cin, s)) {
        word+= (s + '\n');
    }

    for(int i = 0; i < word.size(); i++) {
        if(!isalpha(word[i])) word[i] = ' ';
        word[i] = tolower(word[i]);
    }

    stringstream ss(word);
    string ans;

    bool isFirst = true;

    Node* root;

    while(ss >> ans) {
        xs[ans] = 1;
    }

    for(auto x:xs) {
        if(isFirst) {
            isFirst = !isFirst;
            root = InsertNode(NULL, x.first);
        } else {
            root = InsertNode(root, x.first);
        }
    }

    inorder(root);

}

int main()
{

    show();
 
    return 0;
}
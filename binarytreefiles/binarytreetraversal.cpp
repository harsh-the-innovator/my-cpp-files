#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node* left,*right;
    Node(int k){
        key = k;
        left = right = NULL;
    }
};

void preorder(Node* root){
    if(root==NULL) return;

    cout<<root->key<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root==NULL) return;

    inorder(root->left);
    cout<<root->key<<" ";
    inorder(root->right);
}

void postorder(Node* root){
    if(root==NULL) return;

   
    postorder(root->left);
    postorder(root->right);
    cout<<root->key<<" ";
}


int main(){
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
}
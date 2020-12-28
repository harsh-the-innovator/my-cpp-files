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


//no. of nodes in binary tree
int getHeight(Node* root){
    if(root==nullptr) return 0;
    
    return 1 + max(getHeight(root->left),getHeight(root->right));
}


int main(){
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left =  new Node(40);
    cout<<"height = "<<getHeight(root)<<endl;
}
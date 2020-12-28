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
int getSize(Node* root){
    if(root==nullptr) return 0;
    
    return 1+getSize(root->left)+getSize(root->right);
}


int main(){
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    cout<<"size = "<<getSize(root)<<endl;
}
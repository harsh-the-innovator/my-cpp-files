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
int getMax(Node* root){
    if(root==nullptr) return INT_MIN;
    
    return max(root->key,max(getMax(root->left),getMax(root->right)));
}


int main(){
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    cout<<"Max element = "<<getMax(root)<<endl;
}
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


// it takes more time  complexity because of pushing and popping extra NULL's
// time complexity = O(n+h) , h is height
void levelOrderMethod1(Node* root){
    if(root==NULL) return;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(q.size()>1){
        Node* curr = q.front();
        q.pop();
        if(curr==NULL){
            cout<<"\n";
            q.push(NULL);
            continue;
        }

        cout<<curr->key<<" ";
        if(curr->left!=NULL) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
}


//Time complexity = O(n)
void levelOrderMethod2(Node* root){
    if(root==NULL) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int count = q.size();
        for(int i=0;i<count;i++){
            Node* curr = q.front();
            q.pop();
            cout<<curr->key<<" ";
            if(curr->left!=NULL) q.push(curr->left);
            if(curr->right!=NULL) q.push(curr->right);
        }
        cout<<"\n";
    }
    
}



int main(){
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);

    levelOrderMethod1(root);
    cout<<endl;
    levelOrderMethod2(root);
}
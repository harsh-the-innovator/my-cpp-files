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

void iterativeInorder(Node* root){
    if(root==nullptr) return;
    stack<Node*> st;
    Node* curr = root;

    while(curr!=nullptr or !st.empty()){
        while(curr!=nullptr){
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();
        cout<<curr->key<<" ";
        curr = curr->right;
    }
}

void iterativePreorder(Node* root){
    if(root==nullptr) return;
    stack<Node*> st;
    Node* curr = root;
    while(curr!=nullptr || !st.empty()){
        while(curr!=nullptr){
            cout<<curr->key<<" ";
            if(curr->right!=nullptr) st.push(curr->right);
            curr = curr->left;
        }

        if(!st.empty()){
            curr = st.top();
            st.pop();
        }
    }
}


int main(){
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);

    iterativeInorder(root);
    cout<<endl;
    iterativePreorder(root);
}
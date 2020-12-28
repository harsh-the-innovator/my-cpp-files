#include <bits/stdc++.h>
using namespace std;
int preIndex = 0;

struct Node
{
    int key;
    struct Node* left,*right;
    Node(int x){
        key = x;
        left = right = NULL;
    }
};


Node* constructBinaryTree(int in[],int pre[],int start,int end){
    if(start>end) return;
    
    Node* root = new Node(pre[preIndex++]);

    int inIndex;
    for(int i = start;i<=end;i++){
        if(in[i]==root->key){
            inIndex = i;
            break;
        }
    }
    
    root->left = constructBinaryTree(in,pre,start,inIndex-1);
    root->right = constructBinaryTree(in,pre,inIndex+1,end);
    
    return root;
}

int main(){
        int pre[] = {10,20,40,50,60,70,30,80,100};
        int in[] = {40,20,60,50,70,10,80,100,30};
        int n = 9;
        Node* root = NULL;
        root = constructBinaryTree(in,pre,0,n-1);
        cout<<endl;
}